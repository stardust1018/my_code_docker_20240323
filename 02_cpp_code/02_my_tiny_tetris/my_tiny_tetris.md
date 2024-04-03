[toc]

# 一、ncurse的使用
在C语言中，你可以使用#include <curses.h>来包含ncurses库的头文件，并使用其中的函数和数据结构。以下是一些常用接口和函数的示例：

初始化和清理：

initscr(): 初始化curses库，准备创建终端界面。
endwin(): 清理并关闭curses库，恢复终端到正常状态。
屏幕输出：

printw(const char *format, ...): 在屏幕上打印格式化的文本。
mvprintw(int y, int x, const char *format, ...): 在指定位置打印格式化的文本。
refresh(): 刷新屏幕，使之显示最新的更改。
输入处理：

getch(): 从用户获取一个字符输入。
mvgetch(int y, int x): 从指定位置获取一个字符输入。
光标控制：

move(int y, int x): 将光标移动到指定位置。
getyx(WINDOW *win, int y, int x): 获取当前光标位置。
窗口和边框：

WINDOW *newwin(int nlines, int ncols, int begin_y, int begin_x): 创建一个新的窗口。
box(WINDOW *win, chtype verch, chtype horch): 在窗口周围绘制边框。
颜色和属性：

start_color(): 启用颜色功能。
init_pair(short pair, short f, short b): 初始化颜色对。
attron(chtype attrs): 打开指定属性。
attroff(chtype attrs): 关闭指定属性。

int resizeterm(int lines, int columns): 调整终端窗口
int noecho(void); -- 用于控制终端上键盘输入字符的回显行为。当调用 noecho 函数后，键盘输入的字符将不会在终端上显示（不回显），而是直接传递给程序处理。
curs_set(0); // 用于隐藏光标的显示

```
要在 ncurses 窗口内添加文本或其他元素，你可以使用以下几个函数：

mvprintw：在指定位置打印格式化的字符串。
wprintw：在窗口内指定位置打印格式化的字符串。
mvwprintw：在窗口内移动光标到指定位置，并打印格式化的字符串。
mvwaddch：在窗口内移动光标到指定位置，并添加字符。
mvwaddstr：在窗口内移动光标到指定位置，并添加字符串。
mvwaddnstr：在窗口内移动光标到指定位置，并添加指定长度的字符串。
wborder：在窗口周围绘制边框。
wattron 和 wattroff：为窗口启用或禁用文本属性，如粗体、下划线、反转等。
wmove：在窗口内移动光标到指定位置。
```


```
    // 初始化 ncurses
    initscr();

    // 创建一个新的窗口
    WINDOW *win = newwin(10, 30, 5, 5);
    box(win, 0, 0);

    // 在标准屏幕上绘制内容
    mvprintw(0, 0, "Hello, ncurses!");

    // 刷新整个屏幕
    refresh();

    // 在窗口内绘制内容
    mvwprintw(win, 1, 1, "Hello, window!");

    // 刷新窗口
    wrefresh(win);

    // 等待用户按任意键
    getch();

    // 清理 ncurses
    endwin();

```

# 二、cmake编译处理

file(GLOB SRC_FILES *.c *.cpp)
该命令用于在指定目录中获取符合指定模式的文件列表。它会在构建系统生成期间执行一次，并将符合模式的文件路径匹配到一个变量中。这个命令不会递归地搜索子目录，只会在指定目录中进行匹配

file(GLOB_RECURSE SRC_FILES *.c *.cpp)
它会递归地搜索指定目录及其子目录中符合模式的文件。它会在构建系统生成期间执行一次，并将符合模式的文件路径匹配到一个变量中。

# 三、俄罗斯方块逻辑实现
## 1.方块定义
### 1) 方块个数 piece num
方块：游戏中使用七种不同形状的方块，每个方块由四个小方块（俄罗斯方块）组成。每个小方块都由一个颜色标识。玩家可以左右移动方块，将其向下加速下落，并旋转方块的方向。

### 2) 方块形状


## 3)piece color
七个不同的方块，每个方块一种颜色
## 2.方块移动逻辑

## 3.整行消除，计分、结束判定和实现