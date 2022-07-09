#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 //���Ա�洢�ռ��ʼ������
#define MAXSIZE 11         //����ʽ�ɴﵽ����󳤶�
#define true 1
#define false 0

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} SqList; //˳�������

typedef struct //����ʽ������Ķ���
{
    float p; //ϵ��
    int e;   //ָ��
} Polynomial;

//����һ���յ����Ա�
void InitList (int *F)
{
    SqList L;
    L.elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
}

//��ʼ���������Ա��Ѵ��ڣ�
//����������������Ա�
int DestroyList(SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
}

//��ʼ���������Ա��Ѵ��ڣ�
//��������������Ա�����Ϊ�ձ�
void ClearList(SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
}

//��ʼ���������Ա��Ѵ��ڣ�
//�����������Ϊ�ձ��򷵻�ture�����򷵻�false��
char ListEmpty(SqList L)
{
    if (L.length == 0)
        return false;
    else
        true;
}

//��ʼ���������Ա��Ѵ��ڣ�
//����������������Ա���Ԫ�ظ�����
int ListLength(SqList L)
{
    if (L.length != 0)
        return L.length;
}

//��ʼ���������Ա��Ѵ��ڣ�1<=i<=ListLenght;
//�����������e�������Ա��е�i�����ݵ�Ԫ��ֵ��
void GetElem(SqList L, int i, int *e)
{
    *e = *(L.elem + i - 1);
}

//��ʼ���������Ա��Ѵ��ڣ�compare()������Ԫ���ж�������
//������������ص�1����e����compare()������Ԫ�ص�λ��������������Ԫ�ز������򷵻�ֵΪ0��
int LocateElem(SqList L, int e, int (*p)(int, int))
{
    int i = 0;
    for (i = 0; i <= L.length; i++)
    {
        if ((*p)(*(L.elem + i), e) == 1)
            return (i + 1);
    }
    return false;
}

//��ʼ���������Ա��Ѵ���;
//�����������cur_e������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�����壻
int PriorElem(SqList L, int cur_e, int *pre_e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (*(L.elem + i) == cur_e && i != 0)
        {
            *pre_e = *(L.elem + i - 1);
            return true;
        }
    }
    printf("Can't find pre_e\n");
}

//��ʼ���������Ա��Ѵ��ڣ�
//�����������cur_e�����ݵ�Ԫ�أ��Ҳ����������next_e�������ĺ�̣��������ʧ�ܣ�next_e�����壻
int NextElem(SqList L, int cur_e, int *next_e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (*(L.elem + i) == cur_e && i != L.length-1)
        {
            *next_e = *(L.elem + i+1);
            return true;
        }
    }
    printf("Can't find next_e\n");
}

//��ʼ���������Ա��Ѵ��ڣ�1<=i<=ListLength(l)+1
//�����������L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�һ��
int ListInsert(SqList *L, int i, int e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length == MAXSIZE)
        return 0;
    for (j = L->length - 1; j >= i - 1; j--)
    {
        *(L->elem + (j + 1)) = *(L->elem + j);
    }
    *(L->elem + (i - 1)) = e;
    L->length++;
    return 1;
}

//��ʼ���������Ա�L�Ѵ��ڣ�
//���������ɾ��L��i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�һ��
int ListDelete(SqList *L, int i, int *e)
{
    int j;
    if (i > L->length || i < 0)
        return 0;
    if (i == L->length)
    {
        *e = *(L->elem + L->length);
        L->length--;
        return 1;
    }
    else
    {
        *e = *(L->elem + i);
        for (; i < L->length; i++)
        {
            *(L->elem + i - 1) = *(L->elem + (i));
        }
        return 1;
    }
}

//��ʼ���������Ա�L�Ѵ��ڣ�
//������������ζ����Ա���ÿ��Ԫ�ص���visited()��
void ListTraverse(SqList *L,int (*p)(int *))
{
    int i;
    for(i=0;i<L->length;i++)
    (*p)(L->elem+i);
}

//�ҵ�һ����n�����
int compare(int x, int y)
{
    if (x > y)
        return true;
    return false;
}

//Ԫ�ص�ֵ��һ
int add(int *x)
{
    *x+=1;
}

int main()
{
    int i, num;
    SqList L;
    L.elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    L.length = 0;
    for (i = 0; i < 10; i++)
    {
        *(L.elem + i) = i; //�������� 0-9
        L.length++;
    }
    printf("before:\n");
    for (i = 0; i < 10; i++) //��ӡ���������
        printf("%d ", *(L.elem + i));

    printf("\nafter:\n");
    // ClearList(&L);
    ListTraverse(&L,add);

    for (i = 0; i < L.length; i++) //��ӡ���������
        printf("%d ", *(L.elem + i));
    return 0;
}
