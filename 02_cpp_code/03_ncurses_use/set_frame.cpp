#include <iostream>
#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // 初始化 ncurses
    initscr();

    // 启用颜色功能
    start_color();

    resizeterm(10, 10); // 调整终端窗口
    box(stdscr, 0, 0); // 在标准屏幕窗口stdscr上绘制一个没有边框字符的边框

    // 刷新屏幕
    refresh();

    // 等待用户按任意键
    sleep(5);

    // 清理 ncurses
    endwin();

    return 0;
}