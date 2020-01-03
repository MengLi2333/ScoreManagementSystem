#include "student.h"

void sort_ave_sores(void) {   // 暂无BUG
    /** \brief
     *  根据平均分将学生进行降序排序，并显示结果
     * \param
        无
     * \param
     * \return
     *  无
     */

    struct Student *pStu = pHead;
    int *sums = 0, *stus = 0,
        i, j;
    float *avgs = 0;

    if (!pHead) {
        printf("\n\n\n\t没有学生数据！\n");
        return ;
    }

    sums = (int *)malloc(sizeof(int) * Student_Count_int);
    for (i = 0; i < Student_Count_int; i++)
        sums[i] = 0;
    stus = (int *)malloc(sizeof(int) * Student_Count_int);
    for (i = 0; i < Student_Count_int; i++)
        stus[i] = i;
    avgs = (float *)malloc(sizeof(float) * Student_Count_int);

    for (i = 0; i < Student_Count_int; i++) {
        for (j = 0; j < Subject_Count; j++) {
            sums[i] += pStu -> sores_int[j];
        }
        avgs[i] = (float)sums[i] / Subject_Count;
        pStu = pStu -> next_stu_ptr;
    }

    for (i = Student_Count_int - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (avgs[j] < avgs[j + 1]) {
                float temp = avgs[j];
                int temp2 = stus[j];
                avgs[j] = avgs[j + 1];
                avgs[j + 1] = temp;
                stus[j] = stus[j + 1];
                stus[j + 1] = temp2;
            }
        }
    }

    printf("\n\n\n\t************************************************************\n");
    printf("\t排名\t\t学号\t\t平均分\n\n");
    for (i = 0; i < Student_Count_int; i++) {
        printf("\t%d\t\t%d\t\t%.2f\n", i + 1, stus[i], avgs[i]);
    }
    system("pause");
}
