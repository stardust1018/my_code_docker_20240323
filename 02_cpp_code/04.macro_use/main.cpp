#include <iostream>
#include "task.h"

#define SQUARE(x) ((x) * (x))

#define PRINT(FORMAT, VALUE)      \
    printf("The value of " #VALUE \
    " is " FORMAT "\n", VALUE)

#define ADD_TO_SUM(sum_number, value) \
    sum##sum_number += value

#define DEBUG 1
/* #undef DEBUG */

int main()
{
    std::cout << "hello macro use" << std::endl;

    {
        std::cout << SQUARE(5 + 1) << std::endl;
    }

    {
        uint32_t x = 5;
        PRINT("%d", x + 3);
    }

    {
        std::cout << "\n#undef Use\n";
        uint32_t sum5 = 0;
        ADD_TO_SUM(5, 25); // 将25加到sum5
        PRINT("%d", sum5);
        #undef PRINT
        #define PRINT(FORMAT, VALUE)          \
            printf("The new value of " #VALUE \
            " is " FORMAT "\n", VALUE)
        PRINT("%d", sum5);
    }

    {
        std::cout << "\nUse Macro Init Struct\n";
        ShowTaskName(TASK_ID_TSK1);
        ShowTaskName(TASK_ID_TSK2);
        ShowTaskName(TASK_ID_TSK3);
        ShowTaskName(3);
    }

    {
        std::cout << "\nconditional compilation\n";
        #if DEBUG
            std::cout << "This is Debug Mode\n";
        #endif
    }
    return 0;
}