
#include "contact.h"

void LoadContact(Contact* pc)
{
    assert(pc);
    pc->count = 0;
    FILE* pf = fopen("contact.txt", "rb");
    if (pf == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    while (fread(&pc->data[pc->count], sizeof(PeoInfo), 1, pf) == 1)
    {
        pc->count++;
    }
    fclose(pf);
    pf = NULL;
}

void AddContact(Contact* pc)
{
    if (pc->count == MAX)
    {
        printf("通讯录已满，无法继续添加");
    }
    else
    {
        assert(pc);
        printf("请输入名字->");
        scanf("%s", pc->data[pc->count].name);
        printf("请输入年龄->");
        scanf("%d", &(pc->data[pc->count].age));
        printf("请输入性别->");
        scanf("%s", pc->data[pc->count].sex);
        printf("请输入电话->");
        scanf("%s", pc->data[pc->count].tele);
        printf("请输入地址->");
        scanf("%s", pc->data[pc->count].address);
        pc->count++;
        printf("添加联系人成功！\n");
    }
}

void ShowContact(const Contact* pc)
{
    assert(pc);
    int i = 0;
    if (pc->count == 0)
    {
        printf("通讯录为空,没有联系人\n");
    }
    else
    {
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
        for (i = 0; i < pc->count; i++)
        {
            printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
                pc->data[i].age,
                pc->data[i].sex,
                pc->data[i].tele,
                pc->data[i].address);
        }
    }
}

static int FindByName(Contact* pc, char name[])
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->count; i++)
    {
        if (strcmp(pc->data[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

static int FindByTele(Contact* pc, char tele[])
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->count; i++)
    {
        if (strcmp(pc->data[i].tele, tele) == 0)
        {
            return i;
        }
    }

    return -1;
}

void DelContact(Contact* pc)
{
    char name[MAX_NAME] = { 0 };
    int i = 0;
    assert(pc);
    printf("请输入删除人的姓名->");
    scanf("%s", name);

    //删除
    // 查找
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
        return;
    }

    //删除
    for (i = pos; i < pc->count - 1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->count--;
    printf("删除联系人成功\n");
}

void SearchContact(Contact* pc)
{
    assert(pc);
    int input = 0;
    printf("根据姓名查询请输入1，根据电话查询请输入2\n");
    printf("请输入您的选择->");
    scanf("%d", &input);
    if (input == 1)
    {
        char name[MAX_NAME] = { 0 };
        printf("请输入要查找人的姓名->");
        scanf("%s", name);
        //查找
        int pos = FindByName(pc, name);
        if (pos == -1)
        {
            printf("要查找的人不存在\n");
            return;
        }
        //打印
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
            pc->data[pos].age,
            pc->data[pos].sex,
            pc->data[pos].tele,
            pc->data[pos].address);
    }
    else
    {
        char tele[MAX_TELE] = { 0 };
        printf("请输入要查找人的电话-> ");
        scanf("%s", tele);
        //查找
        int pos = FindByTele(pc, tele);
        if (pos == -1)
        {
            printf("要查找的人不存在!\n");
            return;
        }
        //打印
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
            pc->data[pos].age,
            pc->data[pos].sex,
            pc->data[pos].tele,
            pc->data[pos].address);
    }
}

void ModifyContact(Contact* pc)
{
    assert(pc);
    char name[MAX_NAME] = { 0 };
    printf("请输入要修改人的姓名->");
    scanf("%s", name);
    //查找
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要修改的人不存在!\n");
        return;
    }
    printf("请输入修改后的名字->");
    scanf("%s", pc->data[pos].name);
    printf("请输入修改后的年龄-> ");
    scanf("%d", &(pc->data[pos].age));
    printf("请输入修改后的性别-> ");
    scanf("%s", pc->data[pos].sex);
    printf("请输入修改后的电话-> ");
    scanf("%s", pc->data[pos].tele);
    printf("请输入修改后的地址-> ");
    scanf("%s", pc->data[pos].address);
    printf("修改联系人成功!\n");
}

void SaveContact(const Contact* pc)
{
    assert(pc);
    FILE* fp = fopen("contact.txt", "wb");
    if (fp == NULL)
    {
        printf("文件保存失败！");
    }
    int i = 0;
    for (i = 0; i < pc->count; i++)
    {
        fwrite(pc->data + i, sizeof(PeoInfo), 1, fp);
    }
    fclose(fp);
    fp = NULL;
}

int CopyFile(char* old_path, char* new_path)
{
    FILE* oldfp = fopen(old_path, "rb");
    FILE* newfp = fopen(new_path, "wb");
    if (oldfp == NULL || newfp == NULL)
    {
        printf("文件打开失败!\n");
        return 1;
    }
    char c;
    while ((c = fgetc(oldfp)) != EOF)
     {
        fputc(c, newfp);
     }
    fclose(oldfp);
    fclose(newfp);
    return 0;
}
int NewFile(char* oldfile, char* newfile)
{
    printf("请输入旧的文件路径以及名称->");
    scanf("%s", oldfile);
    printf("请输入新的文件路径以及名称->");
    scanf("%s", newfile);
    if (CopyFile(oldfile, newfile) == 0)
    {
           printf("创建新文件成功!\n");
    }
    else
    {
            printf("创建新文件失败!\n");
    }
    return 0;
}

