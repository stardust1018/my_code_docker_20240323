#include <iostream>
#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

int g_tick;
int g_score = 0;

int g_piece_cur_column = 431424;
int g_piece_cur_row = 598356;
int g_rotation = 427089;

int g_piece = 615696;

constexpr uint32_t g_board_row_max = 20;
constexpr uint32_t g_board_col_max = 10;
int board[g_board_row_max][g_board_col_max]; // 以单个方块为维度的整个面板

// g_block layout is: {w-1,h-1}{x0,y0}{x1,y1}{x2,y2}{x3,y3} (two bits each)
// 应该是{h-1,w-1},之前写的应该有问题
int px = 247872, py = 799248, pr, c = 348480;

// 7: 表示7种方块形状
// 4：表示每个形状有4个角度形态
// 599636 -- 1001 0010 0110 0101 0100 -- 21   02   12    11   10
int g_block[7][4] = {
    {431424, 598356, 431424, 598356},
    {427089, 615696, 427089, 615696},
    {348480, 348480, 348480, 348480},
    {599636, 431376, 598336, 432192},
    {411985, 610832, 415808, 595540},
    {247872, 799248, 247872, 799248},
    {614928, 399424, 615744, 428369}
};

// extract a 2-bit number from a g_block entry
// NUM(g_rotation, 16) -- 指定一个角度，固定偏移16位，是获取方块高度
// NUM(g_rotation, 18) -- 指定一个角度，固定偏移18位，是获取方块宽度
int NUM(int x, int y, int piece) { return 3 & g_block[piece][x] >> y; }

// create a new piece, don't remove old one (it has landed and should stick)
void new_piece() {
  g_piece_cur_row = py = 0;
  g_piece = rand() % 7; // 获取一个随机方块类型
  g_rotation = pr = rand() % 4; // 获取对应方块类型中的一个随机角度
  g_piece_cur_column = px = rand() % (g_board_col_max - NUM(g_rotation, 16, g_piece));
}

// set the value fo the board for a particular (x,y,r) piece
// v表示当前board颜色
// r表示角度，即取第几个形态
// y表示纵向偏移值
// x表示横向偏移值
void set_piece(int x, int y, int r, int v) {
  for (int i = 0; i < 8; i += 2) {
    int boardRow = NUM(r, i * 2, g_piece) + y;
    int boardCol = NUM(r, (i * 2) + 2, g_piece) + x;
    board[boardRow][boardCol] = v;
  }
}

// move a piece from old (g_piece*) coords to new
int update_piece() {
  set_piece(px, py, pr, 0); // 方块向下移动过程中，之前的区域清空
  px = g_piece_cur_column;
  py = g_piece_cur_row;
  pr = g_rotation;
  set_piece(px, py, pr, g_piece + 1); // 在新的区域重新绘制
}

// check if placing g_piece at (x,y,r) will be a collision
int check_hit(int x, int y, int r) {
  if (y + NUM(r, 18, g_piece) > 19) {
    return 1;
  }
  set_piece(px, py, pr, 0);
  c = 0;
  for (int i = 0; i < 8; i += 2) {
    if (board[y + NUM(r, i * 2, g_piece)][x + NUM(r, (i * 2) + 2, g_piece)]) {
        c++;
    }
  }
  set_piece(px, py, pr, g_piece + 1);
  return c;
}

// remove line(s) from the board if they're full
void remove_line() {
  for (int row = g_piece_cur_row; row <= g_piece_cur_row + NUM(g_rotation, 18, g_piece); row++) {
    c = 1;
    for (int i = 0; i < g_board_col_max; i++) {
      c *= board[row][i];
    }
    if (!c) {
      continue;
    }
    for (int i = row - 1; i > 0; i--) {
      memcpy(&board[i + 1][0], &board[i][0], 40);
    }
    memset(&board[0][0], 0, g_board_col_max);
    g_score++;
  }
}

// slowly g_tick the piece y position down so the piece falls
int do_tick() {
    g_tick++;
    if (g_tick > 100) { // 50:控制piece下降速度  下落时间是50 * 10000us = 500ms
        g_tick = 0;
        if (check_hit(g_piece_cur_column, g_piece_cur_row + 1, g_rotation)) {
            if (!g_piece_cur_row) {
              // 触顶，
              return 0;
            }
            remove_line();
            new_piece();
        } else {
            g_piece_cur_row++;
            update_piece();
        }
    }
    return 1;
}

// draw the board and g_score
void frame() {
    for (int i = 0; i < g_board_row_max; i++) {
        move(1 + i, 1); // otherwise the box won't draw
        for (int j = 0; j < g_board_col_max; j++) {
            if (board[i][j]) {
                attron(262176 | board[i][j] << 8);
            }
            printw("--");
            attroff(262176 | board[i][j] << 8);
        }
    }
    move(21, 1); // 将光标移动到指定位置
    printw("Score: %d", g_score); // 在屏幕上打印格式化的文本
    refresh(); // 刷新屏幕，使之显示最新的更改
}

// main game loop with wasd input checking
void runloop() {
  while (do_tick()) {
    usleep(10000);
    c = getch();
    if (c == 'a' && g_piece_cur_column > 0 && !check_hit(g_piece_cur_column - 1, g_piece_cur_row, g_rotation)) {
      g_piece_cur_column--;
    }
    if (c == 'd' && g_piece_cur_column + NUM(g_rotation, 16, g_piece) < 9 && !check_hit(g_piece_cur_column + 1, g_piece_cur_row, g_rotation)) {
      g_piece_cur_column++;
    }
    if (c == 's') {
      while (!check_hit(g_piece_cur_column, g_piece_cur_row + 1, g_rotation)) {
        g_piece_cur_row++; // y表示当前块实时纵向坐标
        update_piece();
      }
      remove_line();
      new_piece();
    }
    if (c == 'w') {
      ++g_rotation %= 4;
      while (g_piece_cur_column + NUM(g_rotation, 16, g_piece) > 9) {
        g_piece_cur_column--;
      }
      if (check_hit(g_piece_cur_column, g_piece_cur_row, g_rotation)) {
        g_piece_cur_column = px;
        g_rotation = pr;
      }
    }
    update_piece();
    frame();
    refresh();
  }
}

int main()
{
  srand(time(0)); // 设置伪随机数生成器的种子值
  initscr(); // 初始化curses库，准备创建终端界面
  start_color(); // 启用颜色功能
  // colours indexed by their position in the g_block
  for (int i = 1; i < 8; i++) {
    init_pair(i, i, COLOR_BLACK); // 初始化颜色对, 0:背景色都是COLOR_BLACK
  }
  new_piece();
  resizeterm(22, 22); // 调整终端窗口
  noecho(); // 设置终端输入字符为不回显
  timeout(0);
  curs_set(0); // 用于隐藏光标的显示
  box(stdscr, 0, 0); // 在标准屏幕窗口stdscr上绘制一个没有边框字符的边框
  runloop();
  endwin(); // 清理并关闭curses库，恢复终端到正常状态。

  return 0;
}