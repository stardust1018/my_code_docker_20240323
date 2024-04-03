#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

void eval(char *cmdline);

int main()
{
    char cmdline[MAXLINE];

    while(1) {
        printf("mysh> ");
        fflush(stdout); // printf函数会将输出缓存起来，知道遇到换行符才真正输出，使用fflush函数强制进行输出
        fgets(cmdline, MAXLINE, stdin);
        cmdline[strcspn(cmdline, "\n")] = '\0';
        eval(cmdline);
    }
}

void eval(char *cmdline)
{
    char *argv[2] = {cmdline, NULL};
    if (strcmp(cmdline, "quit") == 0) {
        exit(0);
    }

    pid_t pid;
    posix_spawn(&pid, cmdline, NULL, NULL, argv, NULL);
    int exit_status;
    waitpid(pid, &exit_status, 0);
    if (!WIFEXITED(exit_status)) {
        printf("program terminated unexpectedly!\n");
    }
}