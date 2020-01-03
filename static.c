#include "student.h"

float Avg[Subject_Count];

void static_scores(void) {   // 暂无BUG
    /** \brief
     *  统计并显示最高分、最低分、平均分、最高分学生学号,
        并将数据传入全局变量
     * \param
        无
     * \param
     * \return
     *  无
     */

    struct Student *pStu = pHead;
    int max[Subject_Count] = {0}, min[Subject_Count] = {0}, max_stu[Subject_Count] = {0}, sum[Subject_Count] = {0},
        i;

    if (!pHead) {
        printf("\n\n\n\t没有学生数据！\n");
        return ;
    }

    for (i = 0; i < Subject_Count; i++) {
        max[i] = pStu -> sores_int[i];
        min[i] = pStu -> sores_int[i];
        sum[i] = pStu -> sores_int[i];
        max_stu[i] = pStu -> id_int;
    }
    while (pStu = pStu -> next_stu_ptr) {
        for (i = 0; i < Subject_Count; i++) {
            if (max[i] < pStu -> sores_int[i]) {
                max[i] = pStu -> sores_int[i];
                max_stu[i] = pStu -> id_int;
            }
            if (min[i] > pStu -> sores_int[i])
                min[i] = pStu -> sores_int[i];
            sum[i] += pStu -> sores_int[i];
        }
    }
    for (i = 0; i < Subject_Count; i++)
        Avg[i] = (double)sum[i] / Student_Count_int;

    printf("\n\n\n\t************************************************************\n");
    printf("\t学科\t\t最高分\t\t最高分学号\t\t平均分\n\n");
    for (i = 0; i < Subject_Count; i++) {
        printf("\t%s\t\t%d\t\t%d\t\t\t%.2f\n", Subject_ptr[i], max[i], max_stu[i], Avg[i]);
    }
    system("pause");
}

void static_population(void) {   // 暂无BUG
    /** \brief
     *  统计并显示优秀和不及格人数
     * \param
        无
     * \param
     * \return
     *  无
     */

    struct Student *pStu = pHead;
    int above_avgs[Subject_Count] = {0}, failing_stus[Subject_Count] = {0},
        i, j;

    if (!pHead) {
        printf("\n\n\n\t没有学生数据！\n");
        system("pause");
        return ;
    }
    if (!Avg[0]) {
        printf("\n\n\n\t没有统计数据！\n");
        system("pause");
        return ;
    }
    for (i = 0; i < Student_Count_int; i++) {
        if (i != 0)
            pStu = pStu -> next_stu_ptr;
        for (j = 0; j < Subject_Count; j++) {
            if (pStu -> sores_int[j] >= Avg[j])
                above_avgs[j]++;
            if (pStu -> sores_int[j] < 60)
                failing_stus[j]++;
        }
    }

    printf("\n\n\n\t************************************************************\n");
    printf("\t学科\t\t优秀人数\t不及格人数\n\n");
    for (i = 0; i < Subject_Count; i++) {
        printf("\t%s\t\t%d\t\t%d\n", Subject_ptr[i], above_avgs[i], failing_stus[i]);
    }
    system("pause");
}
