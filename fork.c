// C standard library
#include <stdio.h>
#include <stdlib.h>

// POSIX.1 Header files
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t fpid;
    int status, i;


    printf("eg. 1\n");
    // fork will reture twice, each per process
    fpid = fork();
    // from this statement on, 2 processes are running parallelly
    if (fpid < 0) {
        printf("fork error\n");
    } else if (fpid == 0) {
        printf("child process %d\n", getpid());
        exit(1);
    } else {
        fpid = wait(&status);
        i = WEXITSTATUS(status);
        printf("parent process, %d, child process %d status is %d\n", getpid(), fpid, i);

        printf("eg. 2\n");
        // 8 "-" will be printed, printf buffer is also forked
        for (int i=0; i<2; i++) {
            // fflush(stdout) here will flush buffer
            fork();
            printf("-");
        }
    }

    return 0;
}
