#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
int main(void)
{

    /* The variable groups is uninitialized */
    int classes = 2, groups = 2, students = 280;

    int average_pr_group = 0, average_pr_course = 0;

    average_pr_group = students / groups;
    average_pr_course = students / classes;

    printf("Classes: %d, Groups: %d, Students: %d \n", classes, groups, students);

    printf("There are %d students pr. group.\n", average_pr_group);
    printf("There are %d students pr. class.\n", average_pr_course);

    return EXIT_SUCCESS;
}