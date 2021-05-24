#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

char *build_path(char *s1, char *s2) {
    int len = strlen(s1) + 1 + strlen(s2) + 1;
    char *path = malloc(len * sizeof(char));
    snprintf(path, len * sizeof(char), "%s/%s", s1, s2);
    return path;
}

char *get_word(int fd) {
    char *str = NULL, c;
    int i;
    for (i = 0; read(fd, &c, 1) > 0 && c != '\n'; i++) {
        str = realloc(str, (i + 1) * sizeof(char));
        str[i] = c;
    }
    if (i) {
        str = realloc(str, (i + 1) * sizeof(char));
        str[i] = '\0';
    }
    return str;
}

char *dot_c(char *str) {
    int len = strlen(str);
    str = realloc(str, len + 3);
    str[len] = '.';
    str[len + 1] = 'c';
    str[len + 2] = '\0';
    return str;
}

void write_res(int fd_results, char *s1, char *s2) {
    int fd_pipe[2];
    pipe(fd_pipe);
    if (fork() == 0) {
        dup2(fd_pipe[1], 1);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        execlp("./test", "./test", s1, s2, NULL);
        printf("*0");
        exit(0);
    }
    wait(NULL);
    close(fd_pipe[1]);
    char c, plus = '+', minus = '-';
    while (1) {
        read(fd_pipe[0], &c, 1);
        if (c == '*') {
            read(fd_pipe[0], &c, 1);
            break;
        }
    }
    close(fd_pipe[0]);
    if (c == '1') {
        write(fd_results, &plus, 1);
    } else {
        write(fd_results, &minus, 1);
    }
}

void judge(char *contest) {
    char *contest_code, *users_cfg, *contest_tests, *problems_cfg;
    contest_code = build_path(contest, "code");
    users_cfg = build_path(contest_code, "users.cfg");
    contest_tests = build_path(contest, "tests");
    problems_cfg = build_path(contest_tests, "problems.cfg");
    int fd_users = open(users_cfg, O_RDONLY);
    int fd_problems;
    char *user_name, *user_path, *problem_name, *problem_path, *user_problem;
    char endl = '\n', comma[] = ", ", start[] = "User";
    int fd_results = open("results.csv",
        O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd_problems = open(problems_cfg, O_RDONLY);
    write(fd_results, start, strlen(start));
    while (1) {
        problem_name = get_word(fd_problems);
        if (!problem_name)
            break;
        write(fd_results, comma, strlen(comma));
        write(fd_results, problem_name, strlen(problem_name));
        free(problem_name);
    }
    write(fd_results, &endl, 1);
    close(fd_problems);
    while (1) {
        user_name = get_word(fd_users);
        if (!user_name)
            break;
        user_path = build_path(contest_code, user_name);
        fd_problems = open(problems_cfg, O_RDONLY);
        write(fd_results, user_name, strlen(user_name));
        while (1) {
            problem_name = get_word(fd_problems);
            if (!problem_name)
                break;
            problem_path = build_path(contest_tests, problem_name);
            user_problem = build_path(user_path, problem_name);
            user_problem = dot_c(user_problem);
            write(fd_results, comma, strlen(comma));
            printf("%s %s\n", user_problem, problem_path);
            write_res(fd_results, user_problem, problem_path);
            free(problem_name);
            free(problem_path);
            free(user_problem);
        }
        write(fd_results, &endl, 1);
        close(fd_problems);
        free(user_name);
        free(user_path);
    }
    close(fd_users);
    close(fd_results);
    free(contest_code);
    free(users_cfg);
    free(contest_tests);
    free(problems_cfg);
}

int main(int argc, char **argv) {
    judge(argv[1]);
    int fd = open("results.csv", O_RDONLY);
    char c;
    while (read(fd, &c, 1) > 0)
        putchar(c);
    close(fd);
    return 0;
}
