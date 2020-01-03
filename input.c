#include "student.h"

int Student_Count_int = 0;   // 还需要在初始化时确定
struct Student *pHead = 0;   // 初始化时确定

void input_data(void) {   // 暂无BUG
    /** \brief
     *  让用户输入学生成绩信息，并将数据传入全局变量
     * \param
        无
     * \param
     * \return
     *  无
     */

    #if DEBUG
    ;
    #endif // DEBUG

    char is_exit;
    struct Student *pNow = 0, *pNext = 0;

    if (pHead) {   // 当已有数据时，申请新的内存空间，并将地址赋值给之前的最后一名学生的next_stu_ptr
        int i;

        pNow = pHead;
        for (i = 0; i < Student_Count_int - 1; i++) {
            pNow = pNow -> next_stu_ptr;
        }   // 退出循环后pNow指向最后一名学生
        pNext = (struct Student *)malloc(sizeof(struct Student));
        pNow -> next_stu_ptr = pNext;
    }
    else   // 没有数据时
        pHead = pNext = (struct Student *)malloc(sizeof(struct Student));   // 申请动态内存空间
    // 以上保证pHead和pNext均有值

    system("cls");
    printf("\n\n\n\t************************************************************\n");
    printf("\t\t学生成绩录入\n");

    is_exit = '0';
    while (is_exit == '0') {
        int i;

        pNow = pNext;   // 将上次申请的空间地址给pNow
        // 开始成绩录入
        printf("\t请输入第 %d 个学生的成绩：\n", ++Student_Count_int);
        fflush(stdin);
        for (i = 0; i < Subject_Count; i++) {
            printf("\t请输入 %s 成绩：", Subject_ptr[i]);
            scanf("%d", &(pNow -> sores_int[i]));
        }
        pNow -> id_int = Student_Count_int - 1;

        // 继续申请动态内存空间
        pNext = (struct Student *)malloc(sizeof(struct Student));
        pNow -> next_stu_ptr = pNext;   // 将下一个空间的地址给上一个空间

        printf("\n\t*****若退出录入请输入1，若继续请输入0*****\n");
        fflush(stdin);
        printf("\t请输入：");
        is_exit = getchar();
    }
    // 结束后会多一块内存空间，需要释放，且最后一名学生的next_stu_ptr需要赋值为0
    pNow -> next_stu_ptr = 0;
    free(pNext);
    pNext = 0;
}
