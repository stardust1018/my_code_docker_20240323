#include <iostream>
#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

int g_tick = 0;
int g_score = 0;

int g_piece_cur_column = 431424;
int g_piece_cur_row = 598356;
int g_piece_cur_rotation = 427089;

int pre_row;
int pre_col;
int pre_rotation;

int g_piece = 3;

int ch = 0;

constexpr uint32_t g_board_row_max = 20;
constexpr uint32_t g_board_col_max = 10;
int board[g_board_row_max][g_board_col_max]; // 以单个方块为维度的整个面板

int g_board_1[g_board_row_max][g_board_col_max]; // 以单个方块为维度的整个面板

int g_block[7][4] = {
    {431424, 598356, 431424, 598356},
    {427089, 615696, 427089, 615696},
    {348480, 348480, 348480, 348480},
    {599636, 431376, 598336, 432192},
    {411985, 610832, 415808, 595540},
    {247872, 799248, 247872, 799248},
    {614928, 399424, 615744, 428369}
};

void show_board()
{
  for (int i = 0; i < g_board_row_max; i++) {
    for (int j = 0; j < g_board_col_max; j++) {
      std::cout << g_board_1[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "*****************\n";
}

int NUM(int piece, int rotation, int offset) {
  return (3 & g_block[piece][rotation] >> offset);
}

void set_piece(int x, int y, int r, int v) {
  for (int i = 0; i < 8; i += 2) {
    int boardRow = NUM(g_piece, r, i * 2) + x;
    int boardCol = NUM(g_piece, r, (i * 2) + 2) + y;
    g_board_1[boardRow][boardCol] = v;
  }
}

// draw the board and g_score
void frame() {
    for (int i = 0; i < g_board_row_max; i++) {
        move(1 + i, 1); // otherwise the box won't draw
        for (int j = 0; j < g_board_col_max; j++) {
            if (g_board_1[i][j]) {
                attron(262176 | g_board_1[i][j] << 8);
            }
            printw("--");
            attroff(262176 | g_board_1[i][j] << 8);
        }
    }
    move(21, 1); // 将光标移动到指定位置
    printw("Score: %d", g_score); // 在屏幕上打印格式化的文本
    refresh(); // 刷新屏幕，使之显示最新的更改
}

int check_hit(int x, int y, int r)
{
  if (y + NUM(g_piece, r, 18) > 19) {
    return 1;
  }

  int c = 0;
  set_piece(pre_row, pre_col, pre_rotation, 0);
  for (int i = 0; i < 8; i += 2) {
    if (g_board_1[y + NUM(g_piece, r, i * 2)][x + NUM(g_piece, r, (i * 2) + 2)]) {
      c++;
    }
  }
  set_piece(pre_row, pre_col, pre_rotation, g_piece + 1);

  return c;
}

void update_piece()
{
  // 选择基准形状
  g_piece = rand() % 7; // 获取一个随机方块类型
  pre_row = g_piece_cur_row = 0;
  pre_rotation = g_piece_cur_rotation = rand() % 4;
  pre_col = g_piece_cur_column = rand() % (g_board_col_max - NUM(g_piece, g_piece_cur_rotation, 16));
}

void update_board()
{
  // 更新board
  set_piece(pre_row, pre_col, pre_rotation, 0);
  pre_row = g_piece_cur_row;
  pre_rotation = g_piece_cur_rotation;
  pre_col = g_piece_cur_column;
  set_piece(g_piece_cur_row, g_piece_cur_column, g_piece_cur_rotation, g_piece + 1);
}

void remove_line()
{
  for (int row = g_piece_cur_row; row <= g_piece_cur_row + NUM(g_piece, g_piece_cur_rotation, 18); row++) {
    int isLineFull = 1;
    for (int col = 0; col < g_board_col_max; col++) {
      isLineFull *= g_board_1[row][col];
    }
    if (isLineFull == 0) {
      // 当前行没有被填满
      continue;
    }

    for (int i = row - 1; i > 0; i--) {
      // 从底部开始，逐行拷贝
      memcpy(&g_board_1[i + 1][0], &g_board_1[i][0], 40);
    }
    memset(&g_board_1[0][0], 0, g_board_col_max);
    g_score++;
  }
}

int do_tick() {
    g_tick++;
    if (g_tick > 30) { // 50:控制piece下降速度  下落时间是50 * 10000us = 500ms
        g_tick = 0;
        if (check_hit(g_piece_cur_column, g_piece_cur_row + 1, g_piece_cur_rotation)) {
          if (!g_piece_cur_row) {
            // 触顶，游戏失败
            return 0;
          }
          remove_line();
          update_piece();
        } else {
          g_piece_cur_row++;
          update_board();
        }

    }
    return 1;
}

// main game loop with wasd input checking
void runloop() {
  while (do_tick()) {
    usleep(10000);
    ch = getch();
    if (ch == 'a' && g_piece_cur_column > 0 && !check_hit(g_piece_cur_column - 1, g_piece_cur_row, g_piece_cur_rotation)) {
      g_piece_cur_column--;
    }

    if (ch == 'd') {
      if (g_piece_cur_column + NUM(g_piece, g_piece_cur_rotation, 16) < 9) {
        if (!check_hit(g_piece_cur_column + 1, g_piece_cur_row, g_piece_cur_rotation)) {
          g_piece_cur_column++;
        }
      }
    }
  
    if (ch == 's') {
      while (!check_hit(g_piece_cur_column, g_piece_cur_row + 1, g_piece_cur_rotation)) {
        g_piece_cur_row++; // y表示当前块实时纵向坐标
        update_board();
      }
      remove_line();
      update_piece();
    }

    if (ch == 'w') {
      g_piece_cur_rotation++;
      g_piece_cur_rotation = g_piece_cur_rotation % 4;
      while (g_piece_cur_column + NUM(g_piece, g_piece_cur_rotation, 16) > 9) {
        g_piece_cur_column--;
      }

      if (check_hit(g_piece_cur_column, g_piece_cur_row, g_piece_cur_rotation)) {
        g_piece_cur_column = pre_col;
        g_piece_cur_rotation = pre_rotation;
      }
    }

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
  resizeterm(22, 22); // 调整终端窗口
  noecho(); // 设置终端输入字符为不回显
  timeout(0);
  curs_set(0); // 用于隐藏光标的显示
  box(stdscr, 0, 0); // 在标准屏幕窗口stdscr上绘制一个没有边框字符的边框

  update_piece();
  runloop();

  endwin(); // 清理并关闭curses库，恢复终端到正常状态。

  return 0;
}