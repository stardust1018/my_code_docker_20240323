#include <stdio.h>

#define WEEKDAYS \
    DAY(MONDAY) \
    DAY(TUESDAY) \
    DAY(WEDNESDAY) \

#define DAY(x) x,
enum weekday { WEEKDAYS SUM };
/* enum weekday { 
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    SUM 
}; */

#undef DAY

#define DAY(x) #x,
const char *const weekday_name[] = { WEEKDAYS };
/* const char *const weekday_name[] = {
    "MONDAY",
    "TUESDAY",
    "WEDNESDAY",
}; */
#undef DAY

int main(void) {
    printf("%d\r\n", MONDAY);
    printf("The day is %s.\r\n", weekday_name[MONDAY]);
    printf("There are %d weekdays.\r\n", SUM);
}