#include <iostream>
#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

int g_tick;
int g_score = 0;

int g_piece_cur_column = 431424;
int g_piece_cur_row = 598356;

int g_piece = 615696;
int g_rotation = 427089;

constexpr uint32_t g_board_row_max = 20;
constexpr uint32_t g_board_col_max = 10;
int board[g_board_row_max][g_board_col_max]; // 以单个方块为维度的整个面板

int g_board_1[g_board_row_max][g_board_col_max] {
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,

  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,

  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,

  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
  0, 1, 2, 3, 4, 5, 6, 7, 0, 1,
}; // 以单个方块为维度的整个面板

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

// main game loop with wasd input checking
void runloop() {
  while (1) {
    usleep(10000);
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
  runloop();
  endwin(); // 清理并关闭curses库，恢复终端到正常状态。

  return 0;
}