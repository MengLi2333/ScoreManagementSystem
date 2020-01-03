#include "student.h"

void display_stu(void) {   // 暂无BUG
    /** \brief
     *  显示学生成绩表
     * \param
        无
     * \param
     * \return
     *  无
     */

    struct Student *pStu = pHead;

    if (!pHead) {
        printf("\n\n\n\t没有学生数据！\n");
        system("pause");
        return ;
    }

    printf("\n\n\n\t************************************************************\n");
    printf("\t学生学号\t计算机成绩\t数学成绩\t英语成绩\t语文成绩\t体育成绩\n\n");
    do {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pStu -> id_int,
               pStu -> sores_int[0], pStu -> sores_int[1],
               pStu -> sores_int[2], pStu -> sores_int[3], pStu -> sores_int[4]);
        pStu = pStu -> next_stu_ptr;
    }while(pStu);
    printf("\n\n\n\t************************************************************\n");
    system("pause");
}
