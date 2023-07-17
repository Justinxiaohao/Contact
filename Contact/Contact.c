
#include "contact.h"

void LoadContact(Contact* pc)
{
    assert(pc);
    pc->count = 0;
    FILE* pf = fopen("contact.txt", "rb");
    if (pf == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
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
        printf("ͨѶ¼�������޷��������");
    }
    else
    {
        assert(pc);
        printf("����������->");
        scanf("%s", pc->data[pc->count].name);
        printf("����������->");
        scanf("%d", &(pc->data[pc->count].age));
        printf("�������Ա�->");
        scanf("%s", pc->data[pc->count].sex);
        printf("������绰->");
        scanf("%s", pc->data[pc->count].tele);
        printf("�������ַ->");
        scanf("%s", pc->data[pc->count].address);
        pc->count++;
        printf("�����ϵ�˳ɹ���\n");
    }
}

void ShowContact(const Contact* pc)
{
    assert(pc);
    int i = 0;
    if (pc->count == 0)
    {
        printf("ͨѶ¼Ϊ��,û����ϵ��\n");
    }
    else
    {
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
    printf("������ɾ���˵�����->");
    scanf("%s", name);

    //ɾ��
    // ����
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("Ҫɾ�����˲�����\n");
        return;
    }

    //ɾ��
    for (i = pos; i < pc->count - 1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->count--;
    printf("ɾ����ϵ�˳ɹ�\n");
}

void SearchContact(Contact* pc)
{
    assert(pc);
    int input = 0;
    printf("����������ѯ������1�����ݵ绰��ѯ������2\n");
    printf("����������ѡ��->");
    scanf("%d", &input);
    if (input == 1)
    {
        char name[MAX_NAME] = { 0 };
        printf("������Ҫ�����˵�����->");
        scanf("%s", name);
        //����
        int pos = FindByName(pc, name);
        if (pos == -1)
        {
            printf("Ҫ���ҵ��˲�����\n");
            return;
        }
        //��ӡ
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
            pc->data[pos].age,
            pc->data[pos].sex,
            pc->data[pos].tele,
            pc->data[pos].address);
    }
    else
    {
        char tele[MAX_TELE] = { 0 };
        printf("������Ҫ�����˵ĵ绰-> ");
        scanf("%s", tele);
        //����
        int pos = FindByTele(pc, tele);
        if (pos == -1)
        {
            printf("Ҫ���ҵ��˲�����!\n");
            return;
        }
        //��ӡ
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
    printf("������Ҫ�޸��˵�����->");
    scanf("%s", name);
    //����
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("Ҫ�޸ĵ��˲�����!\n");
        return;
    }
    printf("�������޸ĺ������->");
    scanf("%s", pc->data[pos].name);
    printf("�������޸ĺ������-> ");
    scanf("%d", &(pc->data[pos].age));
    printf("�������޸ĺ���Ա�-> ");
    scanf("%s", pc->data[pos].sex);
    printf("�������޸ĺ�ĵ绰-> ");
    scanf("%s", pc->data[pos].tele);
    printf("�������޸ĺ�ĵ�ַ-> ");
    scanf("%s", pc->data[pos].address);
    printf("�޸���ϵ�˳ɹ�!\n");
}

void SaveContact(const Contact* pc)
{
    assert(pc);
    FILE* fp = fopen("contact.txt", "wb");
    if (fp == NULL)
    {
        printf("�ļ�����ʧ�ܣ�");
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
        printf("�ļ���ʧ��!\n");
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
    printf("������ɵ��ļ�·���Լ�����->");
    scanf("%s", oldfile);
    printf("�������µ��ļ�·���Լ�����->");
    scanf("%s", newfile);
    if (CopyFile(oldfile, newfile) == 0)
    {
           printf("�������ļ��ɹ�!\n");
    }
    else
    {
            printf("�������ļ�ʧ��!\n");
    }
    return 0;
}

