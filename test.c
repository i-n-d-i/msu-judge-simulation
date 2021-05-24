#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int pid;
int flag = 0;

void handler(int signo) {
    kill(pid, SIGKILL);
    flag = 1;
}

char *concat(char *s1, char *s2) {
    int len = strlen(s1) + 1 + strlen(s2) + 1;
    char *path = malloc(len * sizeof(char));
    snprintf(path, len * sizeof(char), "%s/%s", s1, s2);
    return path;
}

char *bin_name(char *path) {              // Moldakhmetova_A
    int len = strlen(path);
    int i, j, m;
    for (i = 0, j = 0; j != 2; i++) {
        if (path[i] == '/')
            j++;
    }
    char *ans = malloc((len - i + 1) * sizeof(char));
    for (m = 0; path[i] != '.'; i++, m++) {
        if (path[i] == '/') {
            ans[m] = '_';
        } else {
            ans[m] = path[i];
        }
    }
    ans[m] = '\0';
    return ans;
}

char *tmp_name(char *name) {                       //   ./Moldakhmetova_A
    int len = strlen(name), i = 2;
    char *ans = malloc((len + 3)*sizeof(char));
    ans[0] = '.';
    ans[1] = '/';
    for (int j = 0; j < len; j++) {
        ans[i] = name[j];
        i++;
    }
    ans[i] = '\0';
    return ans;
}

char *get_word(int fd) {
    char *word = NULL, c = ' ';
    while (c == ' ' || c == '\n') {
        if (read(fd, &c, 1) <= 0)
            return word;
    }
    int i = 0;
    for (; c != ' ' && c != '\n'; i++) {
        word = realloc(word, (i + 1) * sizeof(char));
        word[i] = c;
        if (read(fd, &c, 1) <= 0)
            break;
    }
    word = realloc(word, (i + 1) * sizeof(char));
    word[i] = '\0';
    return word;
}

int checker(int fd1, int fd2) {
    char *word1, *word2;
    while (1) {
        word1 = get_word(fd1);
        word2 = get_word(fd2);
        if (!word1 || !word2)
            break;
        if (strcmp(word1, word2) != 0) {
            free(word1);
            free(word2);
            return 0;
        }
        free(word1);
        free(word2);
    }
    if (word1) {
        free(word1);
        return 0;
    }
    if (word2) {
        free(word2);
        return 0;
    }
    return 1;
}

int compile(char *c_file, char *bin_file) {
    if (fork() == 0) {
        execlp("gcc", "gcc", c_file, "-o", bin_file, NULL);
        exit(1);
    }
    int status;
    wait(&status);
    if (WEXITSTATUS(status))
        return 0;
    return 1;
}

char *dat_path(char *path, int i) {
    char dat_name[8];
    memset(dat_name, 0, 8);
    snprintf(dat_name, 8 * sizeof(char), "%03d.dat", i);
    char *problem = concat(path, dat_name);
    return problem;
}

char *ans_path(char *path, int i) {
    char ans_name[8];
    memset(ans_name, 0, 8);
    snprintf(ans_name, 8 * sizeof(char), "%03d.ans", i);
    char *answer = concat(path, ans_name);
    return answer;
}

int main(int argc, char **argv) {
    signal(SIGALRM, handler);
    int right = 1;
    char *name = bin_name(argv[1]);              // user1_A
    char *tmp = concat("tmp", name);             // tmp/user1_A
    free(name);
    if (!compile(argv[1], tmp)) {
        free(tmp);
        printf("*0");
        return 0;
    }
    name = tmp_name(tmp);                         // ./tmp/user1_A
    free(tmp);
    char *problem_cfg = concat(argv[2], "problem.cfg");
    int fd_problem = open(problem_cfg, O_RDONLY);
    free(problem_cfg);
    char *number = get_word(fd_problem);
    int n = atoi(number);
    free(number);
    close(fd_problem);
    char *problem, *answer;
    int fd_dat, fd_ans, status;
    for (int i = 1; i <= n; i++) {
        problem = dat_path(argv[2], i);             // contest/tests/A/001.dat
        answer = ans_path(argv[2], i);              // contest/tests/A/001.ans
        fd_dat = open(problem, O_RDONLY);
        fd_ans = open(answer, O_RDONLY);
        int fd[2];
        pipe(fd);
        pid = fork();
        if (!pid) {
            dup2(fd_dat, 0);
            close(fd_dat);
            dup2(fd[1], 1);
            close(fd[1]);
            close(fd[0]);
            execlp(name, name, NULL);
            exit(0);
        }
        close(fd[1]);
        close(fd_dat);
        free(problem);
        free(answer);
        alarm(2);
        wait(&status);
        if (WEXITSTATUS(status) || flag) {
            close(fd[0]);
            close(fd_ans);
            free(name);
            printf("*0");
            return 0;
        }
        if (checker(fd[0], fd_ans)) {
            putchar('+');
        } else {
            right = 0;
            putchar('-');
        }
        close(fd[0]);
        close(fd_ans);
    }
    free(name);
    if (!right) {
        printf("*0");
    } else {
        printf("*1");
    }
    putchar('\n');
    return 0;
}
