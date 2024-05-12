#include <iostream>

#define OS_TCB uint32_t
#define CPU_STK uint32_t

typedef void (*TASK_FUNC_F)(void *);

typedef enum _TASK_ID_E {
    TASK_ID_TSK1 = 0,
    TASK_ID_TSK2,
    TASK_ID_TSK3,

    TASK_ID_END
} TASK_ID_E;

typedef struct _TASK_INFO_T {
    const char *name;       /* task名字 */
    uint8_t id;             /* 数组索引 */
    uint8_t prio;           /* task优先级 */
    uint16_t stkSize;       /* task使用的栈大小 */
    uint32_t *pStkBase;     /* task栈的基地址 */
    OS_TCB  tcb;            /* task控制块 */
    void *pArg;             /* task主函数的参数 */
    TASK_FUNC_F func;       /* task主函数 */
} TASK_INFO_T;


#define GEN_TASK_STK(name, _stkSize)    \
    CPU_STK TASK_##name##_STK[_stkSize]

#define GEN_TASK_OBJ(_name, _id, _prio, _stkSize)                       \
    { .name = #_name, .id = _id, .prio = _prio, .stkSize = _stkSize,    \
     .pStkBase = TASK_##_name##_STK,                                    \
     .tcb = 0, .pArg = nullptr, .func = nullptr }

#define TASK_STK_CFG            \
    GEN_TASK_STK(TSK1, 128);    \
    GEN_TASK_STK(TSK2, 256);    \
    GEN_TASK_STK(TSK3, 512);

#define TASK_OBJS                               \
    GEN_TASK_OBJ(TSK1, TASK_ID_TSK1, 3, 128),   \
    GEN_TASK_OBJ(TSK2, TASK_ID_TSK2, 4, 256),   \
    GEN_TASK_OBJ(TSK3, TASK_ID_TSK3, 5, 512),


void ShowTaskName(uint32_t idx);