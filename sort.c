#include "student.h"

void sort_ave_sores(void) {   // ����BUG
    /** \brief
     *  ����ƽ���ֽ�ѧ�����н������򣬲���ʾ���
     * \param
        ��
     * \param
     * \return
     *  ��
     */

    struct Student *pStu = pHead;
    int *sums = 0, *stus = 0,
        i, j;
    float *avgs = 0;

    if (!pHead) {
        printf("\n\n\n\tû��ѧ�����ݣ�\n");
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
    printf("\t����\t\tѧ��\t\tƽ����\n\n");
    for (i = 0; i < Student_Count_int; i++) {
        printf("\t%d\t\t%d\t\t%.2f\n", i + 1, stus[i], avgs[i]);
    }
    system("pause");
}
