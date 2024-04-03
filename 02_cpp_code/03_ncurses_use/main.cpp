#include <iostream>
#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

int g_tick;
int g_score = 0;

int g_piece_cur_column = 431424;
int g_piece_cur_row = 598356;

// g_block layout is: {w-1,h-1}{x0,y0}{x1,y1}{x2,y2}{x3,y3} (two bits each)
int r = 427089, px = 247872, py = 799248, pr,
    c = 348480, p = 615696, board[20][10];

int g_block[7][4] = {
    {g_piece_cur_column, g_piece_cur_row, g_piece_cur_column, g_piece_cur_row},
    {r, p, r, p},
    {c, c, c, c},
    {599636, 431376, 598336, 432192},
    {411985, 610832, 415808, 595540},
    {px, py, px, py},
    {614928, 399424, 615744, 428369}
};

// extract a 2-bit number from a g_block entry
int NUM(int x, int y) { return 3 & g_block[p][x] >> y; }

// create a new piece, don't remove old one (it has landed and should stick)
void new_piece() {
  g_piece_cur_row = py = 0;
  p = rand() % 7;
  r = pr = rand() % 4;
  g_piece_cur_column = px = rand() % (10 - NUM(r, 16));
}

// set the value fo the board for a particular (x,y,r) piece
void set_piece(int x, int y, int r, int v) {
  for (int i = 0; i < 8; i += 2) {
    board[NUM(r, i * 2) + y][NUM(r, (i * 2) + 2) + x] = v;
  }
}

// move a piece from old (p*) coords to new
int update_piece() {
  set_piece(px, py, pr, 0);
  set_piece(px = g_piece_cur_column, py = g_piece_cur_row, pr = r, p + 1);
}

// check if placing p at (x,y,r) will be a collision
int check_hit(int x, int y, int r) {
  if (y + NUM(r, 18) > 19) {
    return 1;
  }
  set_piece(px, py, pr, 0);
  c = 0;
  for (int i = 0; i < 8; i += 2) {
    if (board[y + NUM(r, i * 2)][x + NUM(r, (i * 2) + 2)]) {
        c++;
    }
  }
  set_piece(px, py, pr, p + 1);
  return c;
}

// remove line(s) from the board if they're full
void remove_line() {
  for (int row = g_piece_cur_row; row <= g_piece_cur_row + NUM(r, 18); row++) {
    c = 1;
    for (int i = 0; i < 10; i++) {
      c *= board[row][i];
    }
    if (!c) {
      continue;
    }
    for (int i = row - 1; i > 0; i--) {
      memcpy(&board[i + 1][0], &board[i][0], 40);
    }
    memset(&board[0][0], 0, 10);
    g_score++;
  }
}

// slowly g_tick the piece y position down so the piece falls
int do_tick() {
    g_tick++;
    if (g_tick > 50) { // 50:控制piece下降速度
        g_tick = 0;
        if (check_hit(g_piece_cur_column, g_piece_cur_row + 1, r)) {
            if (!g_piece_cur_row) {
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
    for (int i = 0; i < 20; i++) {
        move(1 + i, 1); // otherwise the box won't draw
        for (int j = 0; j < 10; j++) {
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
    // update_piece(); // 不知道什么作用
    frame();
    refresh();
  }
}

int main()
{
  srand(time(0));
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