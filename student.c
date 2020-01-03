#include "student.h"

char *Subject_ptr[] = {"计算机",   // 课程编号 0
                        "数学",   // 课程编号 1
                        "英语",   // 课程编号 2
                        "语文",   // 课程编号 3
                        "体育"};   // 课程编号 4

int main(void) {
    int option_num;
    /** \brief
     *  主调函数，在启动时读取数据，在结束时将数据落地，
        本程序绝大多数数据采用全局变量保存
     * \param
        无
     * \param
     * \return
     *  0 -- 无意义
     */

    #if DEBUG
    struct Student *student_temp = (struct Student*)malloc(sizeof(struct Student));
    student_temp -> next_stu_ptr = 0;
    student_temp ->id_int = 233;
    student_temp ->sores_int[0] = 123;

    pHead = student_temp;

    save();

    Student_Count_int = 0;
    student_temp -> id_int = 0;

    load();
    printf("%d---%d", Student_Count_int, student_temp -> id_int);

    free(student_temp);
    #endif // DEBUG

    #if RUN
    load();
	system("color 0e");
	show_first();
    while (1) {
        option_num = menu_select();
        if (option_num == 6)
            break;
        system("cls");
        menu_handle(option_num);
    }
    save();

    return 0;
    #endif
}

void print_func_menu(void) {   // 暂无BUG
    /** \brief
     *  打印功能菜单
     * \param
        无
     * \param
     * \return
     *  无
     */

    system("cls");
    printf("\n\n\n\t************************************************************\n");
    printf("\t1. 输入原始数据\n");
    printf("\t2. 统计并显示最高分、最低分、平均分、最高分学生学号\n");
    printf("\t3. 统计并显示优秀和不及格人数\n");
    printf("\t4. 按平均分排序，并显示排序结果\n");
    printf("\t5. 显示学生成绩表\n");
    printf("\t6. 退出程序\n");
    printf("\t************************************************************\n");
    printf("\t请选择功能：");
}

int menu_select(void) {   // 暂无BUG
    /** \brief
     *  打印菜单，让用户选择功能，并返回相应的功能序号
     * \param
        无
     * \param
     * \return
     *  返回功能序号
     */

    int option_num;

    system("cls");
    print_func_menu();
    while (fflush(stdin), option_num = getchar(), !('1' <= option_num && option_num <= '6'))
        printf("\t输入非法！\n\t请重新选择功能：");

    return option_num - '0';   // 将字符型option_num转为对应数字
}

void menu_handle(int option_num) {
    /** \brief
     *  根据功能序号调用相应函数
     * \param
        option_num -- 功能序号
     * \param
     * \return
     *  无
     */

    #if DEBUG
    ;
    #endif // DEBUG

    switch (option_num) {
        case 1: input_data(); break;
        case 2: static_scores(); break;
        case 3: static_population(); break;
        case 4: sort_ave_sores(); break;
        case 5: display_stu(); break;
    }
}

void save(void) {   // 暂无BUG
    struct Student *pNext = 0, *pNow = 0;
    FILE *file = 0;

    file = fopen(DATA_PATH, "wb");
    pNext = pHead;
    fwrite(&Student_Count_int, sizeof(Student_Count_int), 1, file);   // 写入Student_Count_int
    if (pHead == 0) return ;   // 当学生数据为空时，停止写入
    do {   // 写入所有student
        pNow = pNext;
        fwrite(pNow, sizeof(struct Student), 1, file);
        pNext = pNow -> next_stu_ptr;
        free(pNow);
    }while (pNext);

    fclose(file);
}

void load(void) {   // 暂无BUG
    struct Student *pNext = 0, *pNow;
    FILE *file = 0;
    int i;

    if (!(file = fopen(DATA_PATH, "rb"))) {   // 打开成功时，继续执行；失败时，创建文件
        fopen(DATA_PATH, "wb");
        return ;
    }
    fread(&Student_Count_int, sizeof(Student_Count_int), 1, file);   // 读入Student_Count_int
    if (!Student_Count_int) return ;   // 当文件没有学生信息时，不继续读入
    pHead = pNext = (struct Student *)malloc(sizeof(struct Student));
    for (i = 0; i < Student_Count_int; i++) {   // 读入所有student
        pNow = pNext;
        fread(pNow, sizeof(struct Student), 1, file);
        pNext = (struct Student *)malloc(sizeof(struct Student));
        pNow -> next_stu_ptr = pNext;
    }   // 结束时多出一个空间
    pNow -> next_stu_ptr = 0;
    free(pNext);
}

void show_first(void) {
	printf("\n\n\n\t************************************************************\n");
	printf("\t欢迎使用学生成绩管理系统\n");
	printf("\n\n\n\t本程序已内置部分学生成绩提供测试，无需再次录入\n");
	printf("\n\n\t\t\t\t\t制作人：软工193 温龙睿\n");
	printf("\t************************************************************\n");
	system("pause");
}
