#include "student.h"

int Student_Count_int = 0;   // ����Ҫ�ڳ�ʼ��ʱȷ��
struct Student *pHead = 0;   // ��ʼ��ʱȷ��

void input_data(void) {   // ����BUG
    /** \brief
     *  ���û�����ѧ���ɼ���Ϣ���������ݴ���ȫ�ֱ���
     * \param
        ��
     * \param
     * \return
     *  ��
     */

    #if DEBUG
    ;
    #endif // DEBUG

    char is_exit;
    struct Student *pNow = 0, *pNext = 0;

    if (pHead) {   // ����������ʱ�������µ��ڴ�ռ䣬������ַ��ֵ��֮ǰ�����һ��ѧ����next_stu_ptr
        int i;

        pNow = pHead;
        for (i = 0; i < Student_Count_int - 1; i++) {
            pNow = pNow -> next_stu_ptr;
        }   // �˳�ѭ����pNowָ�����һ��ѧ��
        pNext = (struct Student *)malloc(sizeof(struct Student));
        pNow -> next_stu_ptr = pNext;
    }
    else   // û������ʱ
        pHead = pNext = (struct Student *)malloc(sizeof(struct Student));   // ���붯̬�ڴ�ռ�
    // ���ϱ�֤pHead��pNext����ֵ

    system("cls");
    printf("\n\n\n\t************************************************************\n");
    printf("\t\tѧ���ɼ�¼��\n");

    is_exit = '0';
    while (is_exit == '0') {
        int i;

        pNow = pNext;   // ���ϴ�����Ŀռ��ַ��pNow
        // ��ʼ�ɼ�¼��
        printf("\t������� %d ��ѧ���ĳɼ���\n", ++Student_Count_int);
        fflush(stdin);
        for (i = 0; i < Subject_Count; i++) {
            printf("\t������ %s �ɼ���", Subject_ptr[i]);
            scanf("%d", &(pNow -> sores_int[i]));
        }
        pNow -> id_int = Student_Count_int - 1;

        // �������붯̬�ڴ�ռ�
        pNext = (struct Student *)malloc(sizeof(struct Student));
        pNow -> next_stu_ptr = pNext;   // ����һ���ռ�ĵ�ַ����һ���ռ�

        printf("\n\t*****���˳�¼��������1��������������0*****\n");
        fflush(stdin);
        printf("\t�����룺");
        is_exit = getchar();
    }
    // ��������һ���ڴ�ռ䣬��Ҫ�ͷţ������һ��ѧ����next_stu_ptr��Ҫ��ֵΪ0
    pNow -> next_stu_ptr = 0;
    free(pNext);
    pNext = 0;
}
