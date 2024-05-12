#include "task.h"

TASK_STK_CFG

static _TASK_INFO_T g_taskTable[TASK_ID_END] = {TASK_OBJS};

void ShowTaskName(uint32_t idx)
{
    if (idx >= TASK_ID_END) {
        std::cout << "invalid task idx" << std::endl;
        return;
    }
    std::cout << g_taskTable[idx].name << std::endl;
}