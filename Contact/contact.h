#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char address[MAX_ADDR];
}PeoInfo;


typedef struct Contact
{
    PeoInfo data[MAX];//存放人的信息
    int count;//记录当前通讯录中实际人数
}Contact;

int NewFile(char* oldpath,char* newpath );

void AddContact(Contact* pc);

void ShowContact(const Contact* pc);

void DelContact(Contact* pc);

void SearchContact(Contact* pc);

void ModifyContact(Contact* pc);

void LoadContact(Contact* pc);

void SaveContact(const Contact* pc);




