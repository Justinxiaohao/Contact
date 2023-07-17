#include "contact.h"

void menu()
{
    printf("******************通讯录******************\n");
    printf("*******1.添加联系人     2.删除联系人******\n");
    printf("*******3.查找联系人     4.修改联系人******\n");
    printf("*******5.展示联系人     6.配置新地址******\n");
    printf("**************0.退出通讯录****************\n");
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
        printf("请输入你的选择->");
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
            printf("您已保存成功并退出通讯录\n");
            break;
        default:
            printf("选择错误，请重新输入\n");
            break;
        }
    } while (n);
    return 0;
}
