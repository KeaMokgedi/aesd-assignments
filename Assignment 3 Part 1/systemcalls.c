#include "systemcalls.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

bool do_system(const char *cmd) {
    int ret = system(cmd);
    if (ret == -1) return false;
    return WIFEXITED(ret) && (WEXITSTATUS(ret) == 0);
}

bool do_exec(int count, ...) {
    va_list args;
    va_start(args, count);
    char * command[count+1];
    for(int i=0; i<count; i++) {
        command[i] = va_arg(args, char *);
    }
    command[count] = NULL;

    pid_t pid = fork();
    if (pid == -1) return false; // Fork failed
    if (pid == 0) {
        // Child process
        execv(command[0], command);
        exit(EXIT_FAILURE); // If execv returns, it failed
    } else {
        // Parent process
        int status;
        if (waitpid(pid, &status, 0) == -1) return false;
        return WIFEXITED(status) && (WEXITSTATUS(status) == 0);
    }
}

bool do_exec_redirect(const char *outputfile, int count, ...) {
    va_list args;
    va_start(args, count);
    char * command[count+1];
    for(int i=0; i<count; i++) {
        command[i] = va_arg(args, char *);
    }
    command[count] = NULL;

    int fd = open(outputfile, O_WRONLY|O_TRUNC|O_CREAT, 0644);
    if (fd < 0) return false;

    pid_t pid = fork();
    if (pid == -1) {
        close(fd);
        return false;
    }
    if (pid == 0) {
        // Redirect stdout to the file
        if (dup2(fd, STDOUT_FILENO) < 0) exit(EXIT_FAILURE);
        close(fd);
        execv(command[0], command);
        exit(EXIT_FAILURE);
    } else {
        close(fd);
        int status;
        if (waitpid(pid, &status, 0) == -1) return false;
        return WIFEXITED(status) && (WEXITSTATUS(status) == 0);
    }
}