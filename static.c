#include "student.h"

float Avg[Subject_Count];

void static_scores(void) {   // ����BUG
    /** \brief
     *  ͳ�Ʋ���ʾ��߷֡���ͷ֡�ƽ���֡���߷�ѧ��ѧ��,
        �������ݴ���ȫ�ֱ���
     * \param
        ��
     * \param
     * \return
     *  ��
     */

    struct Student *pStu = pHead;
    int max[Subject_Count] = {0}, min[Subject_Count] = {0}, max_stu[Subject_Count] = {0}, sum[Subject_Count] = {0},
        i;

    if (!pHead) {
        printf("\n\n\n\tû��ѧ�����ݣ�\n");
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
    printf("\tѧ��\t\t��߷�\t\t��߷�ѧ��\t\tƽ����\n\n");
    for (i = 0; i < Subject_Count; i++) {
        printf("\t%s\t\t%d\t\t%d\t\t\t%.2f\n", Subject_ptr[i], max[i], max_stu[i], Avg[i]);
    }
    system("pause");
}

void static_population(void) {   // ����BUG
    /** \brief
     *  ͳ�Ʋ���ʾ����Ͳ���������
     * \param
        ��
     * \param
     * \return
     *  ��
     */

    struct Student *pStu = pHead;
    int above_avgs[Subject_Count] = {0}, failing_stus[Subject_Count] = {0},
        i, j;

    if (!pHead) {
        printf("\n\n\n\tû��ѧ�����ݣ�\n");
        system("pause");
        return ;
    }
    if (!Avg[0]) {
        printf("\n\n\n\tû��ͳ�����ݣ�\n");
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
    printf("\tѧ��\t\t��������\t����������\n\n");
    for (i = 0; i < Subject_Count; i++) {
        printf("\t%s\t\t%d\t\t%d\n", Subject_ptr[i], above_avgs[i], failing_stus[i]);
    }
    system("pause");
}
