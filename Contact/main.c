#include "contact.h"

void menu()
{
    printf("******************ͨѶ¼******************\n");
    printf("*******1.�����ϵ��     2.ɾ����ϵ��******\n");
    printf("*******3.������ϵ��     4.�޸���ϵ��******\n");
    printf("*******5.չʾ��ϵ��     6.�����µ�ַ******\n");
    printf("**************0.�˳�ͨѶ¼****************\n");
}

int main()
{
    int n = 0;
    Contact con;
    LoadContact(&con);
    char oldpath[100];
    char newpath[100];
    do
    {
        menu();
        printf("���������ѡ��->");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            AddContact(&con);
            break;
        case 2:
            DelContact(&con);
            break;
        case 3:
            SearchContact(&con);
            break;
        case 4:
            ModifyContact(&con);
            break;
        case 5:
            ShowContact(&con);
            break;
        case 6:
            NewFile(oldpath,newpath);
        case 0:
            SaveContact(&con);
            printf("���ѱ���ɹ����˳�ͨѶ¼\n");
            break;
        default:
            printf("ѡ���������������\n");
            break;
        }
    } while (n);
    return 0;
}
