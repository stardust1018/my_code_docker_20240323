#include "stdio.h"

int g_tick;
int g_score = 0;

int g_piece_cur_column = 431424;
int g_piece_cur_row = 598356;

// g_block layout is: {w-1,h-1}{x0,y0}{x1,y1}{x2,y2}{x3,y3} (two bits each)
int r = 427089, px = 247872, py = 799248, pr,
    c = 348480, p = 615696, board[20][10];

// c和c++在全局变量初始化时，有差异
// 在 C 中，全局变量的初始化必须使用编译时常量（constant expressions）来指定初始值
// 在c++中，全局变量的初始值可以关联已经初始化的变量来初始化全局变量，而不仅限于编译时常量
int g_block[7][4] = {
    {g_piece_cur_column, g_piece_cur_row, g_piece_cur_column, g_piece_cur_row},
    {r, p, r, p},
    {c, c, c, c},
    {599636, 431376, 598336, 432192},
    {411985, 610832, 415808, 595540},
    {px, py, px, py},
    {614928, 399424, 615744, 428369}
};

int main()
{
    printf("hello global var\n");
    printf("g_block[0][0]:%u\n", g_block[0][0]);
    g_piece_cur_column = 100;
    printf("g_block[0][0]:%u\n", g_block[0][0]);
    printf("g_piece_cur_column:%u\n", g_piece_cur_column);

    return 0;
}