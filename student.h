#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Subject_Count 5   // 科目数
#define DATA_PATH "C:\\Users\\Meng_Li\\Desktop\\students.dat"

#define DEBUG 0
#define RUN 1

// student.c
extern char *Subject_ptr[];

void print_func_menu(void);
int menu_select(void);
void menu_handle(int option_num);
void save(void);
void load(void);
// static.c
extern float Avg[];

void static_scores(void);
void static_population(void);
// display.c
void display_stu(void);
void display_for_sorting(void);
// input.c
struct Student {
    int id_int;
    int sores_int[Subject_Count];
    struct Student *next_stu_ptr;
};
extern int Student_Count_int;
extern struct Student *pHead;

void input_data(void);
// sort.c
void sort_ave_sores(void);

#endif // STUDENT_H_INCLUDED
