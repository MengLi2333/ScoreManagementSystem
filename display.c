#include "student.h"

void display_stu(void) {   // ����BUG
    /** \brief
     *  ��ʾѧ���ɼ���
     * \param
        ��
     * \param
     * \return
     *  ��
     */

    struct Student *pStu = pHead;

    if (!pHead) {
        printf("\n\n\n\tû��ѧ�����ݣ�\n");
        system("pause");
        return ;
    }

    printf("\n\n\n\t************************************************************\n");
    printf("\tѧ��ѧ��\t������ɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\t�����ɼ�\n\n");
    do {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pStu -> id_int,
               pStu -> sores_int[0], pStu -> sores_int[1],
               pStu -> sores_int[2], pStu -> sores_int[3], pStu -> sores_int[4]);
        pStu = pStu -> next_stu_ptr;
    }while(pStu);
    printf("\n\n\n\t************************************************************\n");
    system("pause");
}
