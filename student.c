#include "student.h"

char *Subject_ptr[] = {"�����",   // �γ̱�� 0
                        "��ѧ",   // �γ̱�� 1
                        "Ӣ��",   // �γ̱�� 2
                        "����",   // �γ̱�� 3
                        "����"};   // �γ̱�� 4

int main(void) {
    int option_num;
    /** \brief
     *  ����������������ʱ��ȡ���ݣ��ڽ���ʱ��������أ�
        ���������������ݲ���ȫ�ֱ�������
     * \param
        ��
     * \param
     * \return
     *  0 -- ������
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

void print_func_menu(void) {   // ����BUG
    /** \brief
     *  ��ӡ���ܲ˵�
     * \param
        ��
     * \param
     * \return
     *  ��
     */

    system("cls");
    printf("\n\n\n\t************************************************************\n");
    printf("\t1. ����ԭʼ����\n");
    printf("\t2. ͳ�Ʋ���ʾ��߷֡���ͷ֡�ƽ���֡���߷�ѧ��ѧ��\n");
    printf("\t3. ͳ�Ʋ���ʾ����Ͳ���������\n");
    printf("\t4. ��ƽ�������򣬲���ʾ������\n");
    printf("\t5. ��ʾѧ���ɼ���\n");
    printf("\t6. �˳�����\n");
    printf("\t************************************************************\n");
    printf("\t��ѡ���ܣ�");
}

int menu_select(void) {   // ����BUG
    /** \brief
     *  ��ӡ�˵������û�ѡ���ܣ���������Ӧ�Ĺ������
     * \param
        ��
     * \param
     * \return
     *  ���ع������
     */

    int option_num;

    system("cls");
    print_func_menu();
    while (fflush(stdin), option_num = getchar(), !('1' <= option_num && option_num <= '6'))
        printf("\t����Ƿ���\n\t������ѡ���ܣ�");

    return option_num - '0';   // ���ַ���option_numתΪ��Ӧ����
}

void menu_handle(int option_num) {
    /** \brief
     *  ���ݹ�����ŵ�����Ӧ����
     * \param
        option_num -- �������
     * \param
     * \return
     *  ��
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

void save(void) {   // ����BUG
    struct Student *pNext = 0, *pNow = 0;
    FILE *file = 0;

    file = fopen(DATA_PATH, "wb");
    pNext = pHead;
    fwrite(&Student_Count_int, sizeof(Student_Count_int), 1, file);   // д��Student_Count_int
    if (pHead == 0) return ;   // ��ѧ������Ϊ��ʱ��ֹͣд��
    do {   // д������student
        pNow = pNext;
        fwrite(pNow, sizeof(struct Student), 1, file);
        pNext = pNow -> next_stu_ptr;
        free(pNow);
    }while (pNext);

    fclose(file);
}

void load(void) {   // ����BUG
    struct Student *pNext = 0, *pNow;
    FILE *file = 0;
    int i;

    if (!(file = fopen(DATA_PATH, "rb"))) {   // �򿪳ɹ�ʱ������ִ�У�ʧ��ʱ�������ļ�
        fopen(DATA_PATH, "wb");
        return ;
    }
    fread(&Student_Count_int, sizeof(Student_Count_int), 1, file);   // ����Student_Count_int
    if (!Student_Count_int) return ;   // ���ļ�û��ѧ����Ϣʱ������������
    pHead = pNext = (struct Student *)malloc(sizeof(struct Student));
    for (i = 0; i < Student_Count_int; i++) {   // ��������student
        pNow = pNext;
        fread(pNow, sizeof(struct Student), 1, file);
        pNext = (struct Student *)malloc(sizeof(struct Student));
        pNow -> next_stu_ptr = pNext;
    }   // ����ʱ���һ���ռ�
    pNow -> next_stu_ptr = 0;
    free(pNext);
}

void show_first(void) {
	printf("\n\n\n\t************************************************************\n");
	printf("\t��ӭʹ��ѧ���ɼ�����ϵͳ\n");
	printf("\n\n\n\t�����������ò���ѧ���ɼ��ṩ���ԣ������ٴ�¼��\n");
	printf("\n\n\t\t\t\t\t�����ˣ���193 �����\n");
	printf("\t************************************************************\n");
	system("pause");
}
