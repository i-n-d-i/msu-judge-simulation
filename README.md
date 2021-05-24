## Second semester work - Judge simulation
### What is judge?
> Judge - is a program that allows you to test the tasks of several users on different tests. <br>
#### The user must create a folder with the name "contest", in which all information will be stored.
### Here an example of information storage structure:
    *contest/
        *code/
            *user1/
                *A.c
                *B.c 
            *user2/
                *A.c
                *B.c 
            *users.cgf 
        *tests/
            *A/
                *problem.cfg
                *001.dat  - example of test
                *001.ans  - answer for first test
                *002.dat  
                *002.ans 
            *B/ 
                *problem.cfg
                *001.dat  - example of test
                *001.ans  - answer for first test
            *problems.cfg
        *tmp/ - for binary programs
#### Example of "users.cfg":
    *Ivanov
    *Petrov
    *Antipov
    *Morozova
    *Kalinina
    *Samoilov
> The file "users.cfg" stores information about users written in a column one after another. It can be names, surnames or something that user wants.
#### Example of "problems.cfg":
    *A
    *B
    *C
    *D
    *E
    *F
> The file "problems.cfg" stores information about tasks, that users should complete. It can be letters, numbers or something that user wants. 
#### Example of "problem.cfg":
    *2
> The file "problem.cfg" must be in each folder of a separate task. It stores information about number of tests. <br>
#### To compile a program user can download Makefile and use commands: 
    *make judge 
    *make test

#### To run a test user must write full path to files: ./test contest/code/user1/B.c  contest/tests/B 
#### To run a judge user must write only: ./judge contest
#### Results will be written to file "results.csv" 
