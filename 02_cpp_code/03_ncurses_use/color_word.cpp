#include <iostream>
#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // 初始化 ncurses
    initscr();

    // 检查终端是否支持颜色
    if (has_colors() == FALSE) {
        endwin();
        printf("终端不支持颜色。\n");
        return 1;
    }

    // 启用颜色功能
    start_color();

    // 定义颜色对
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    // 设置颜色对
    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "this is red context");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(1, 0, "this is green context");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(2, 0, "this is blue context");
    attroff(COLOR_PAIR(3));

    // 刷新屏幕
    refresh();

    // 等待用户按任意键
    getch();

    // 清理 ncurses
    endwin();

    return 0;
}