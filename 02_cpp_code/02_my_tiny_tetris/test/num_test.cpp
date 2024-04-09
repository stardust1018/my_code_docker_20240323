#include "gtest/gtest.h"

using namespace std;

int g_piece = 615696;

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
int NUM(int x, int y) { return 3 & g_block[g_piece][x] >> y; }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// NUM(g_rotation, 0) -- 指定一个角度，固定偏移0位，获取第1个方块格的纵向坐标
TEST(SolutionTest, piece0_NUM_0_0) {
    g_piece = 0;
    int para = NUM(0, 0); // 0,0 -- 0110 1001 0101 0100 0000 -- 0
    EXPECT_EQ(para, 0);
}

// NUM(g_rotation, 2) -- 指定一个角度，固定偏移2位，获取第1个方块格的横向坐标
TEST(SolutionTest, piece0_NUM_0_2) {
    g_piece = 0;
    int para = NUM(0, 2); // 0,0 -- 0110 1001 0101 0100 0000 -- 0
    EXPECT_EQ(para, 0);
}

// NUM(g_rotation, 4) -- 指定一个角度，固定偏移4位，获取第2个方块格的纵向坐标
TEST(SolutionTest, piece0_NUM_0_4) {
    g_piece = 0;
    int para = NUM(0, 4); // 0,0 -- 0110 1001 0101 0100 0000 -- 0
    EXPECT_EQ(para, 0);
}

// NUM(g_rotation, 6) -- 指定一个角度，固定偏移6位，获取第2个方块格的横向坐标
TEST(SolutionTest, piece0_NUM_0_6) {
    g_piece = 0;
    int para = NUM(0, 6); // 0,0 -- 0110 1001 0101 0100 0000 -- 1
    EXPECT_EQ(para, 1);
}

// NUM(g_rotation, 8) -- 指定一个角度，固定偏移8位，获取第3个方块格的纵向坐标
TEST(SolutionTest, piece0_NUM_0_8) {
    g_piece = 0;
    int para = NUM(0, 8); // 0,0 -- 0110 1001 0101 0100 0000 -- 1
    EXPECT_EQ(para, 1);
}

// NUM(g_rotation, 10) -- 指定一个角度，固定偏移10位，获取第3个方块格的横向坐标
TEST(SolutionTest, piece0_NUM_0_10) {
    g_piece = 0;
    int para = NUM(0, 10); // 0,0 -- 0110 1001 0101 0100 0000 -- 1
    EXPECT_EQ(para, 1);
}

// NUM(g_rotation, 12) -- 指定一个角度，固定偏移12位，获取第4个方块格的纵向坐标
TEST(SolutionTest, piece0_NUM_0_12) {
    g_piece = 0;
    int para = NUM(0, 12); // 0,0 -- 0110 1001 0101 0100 0000 -- 1
    EXPECT_EQ(para, 1);
}

// NUM(g_rotation, 14) -- 指定一个角度，固定偏移14位，获取第4个方块格的横向坐标
TEST(SolutionTest, piece0_NUM_0_14) {
    g_piece = 0;
    int para = NUM(0, 14); // 0,0 -- 0110 1001 0101 0100 0000 -- 2
    EXPECT_EQ(para, 2);
}

// NUM(g_rotation, 16) -- 指定一个角度，固定偏移16位，是获取方块高度
TEST(SolutionTest, piece0_NUM_0_16) {
    g_piece = 0;
    int para = NUM(0, 16); // 0,0 -- 0110 1001 0101 0100 0000 -- 12
    EXPECT_EQ(para, 2);
}

// NUM(g_rotation, 18) -- 指定一个角度，固定偏移18位，是获取方块宽度
TEST(SolutionTest, piece0_NUM_0_18) {
    g_piece = 0;
    int para = NUM(0, 18); // 0,0 -- 0110 1001 0101 0100 0000 -- 12
    EXPECT_EQ(para, 1);
}