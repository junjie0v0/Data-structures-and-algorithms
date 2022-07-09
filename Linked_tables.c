#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 //线性表存储空间初始分配量
#define MAXSIZE 11         //多项式可达到的最大长度
#define true 1
#define false 0

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} SqList; //顺序表类型

typedef struct //多项式非零项的定义
{
    float p; //系数
    int e;   //指数
} Polynomial;

//构造一个空的线性表
void InitList (int *F)
{
    SqList L;
    L.elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
}

//初始条件：线性表已存在；
//操作结果：销毁线性表；
int DestroyList(SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
}

//初始条件：线性表已存在；
//操作结果：将线性表重置为空表：
void ClearList(SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
}

//初始条件：线性表已存在；
//操作结果：若为空表，则返回ture，否则返回false；
char ListEmpty(SqList L)
{
    if (L.length == 0)
        return false;
    else
        true;
}

//初始条件：线性表已存在；
//操作结果：返回线性表中元素个数；
int ListLength(SqList L)
{
    if (L.length != 0)
        return L.length;
}

//初始条件：线性表已存在，1<=i<=ListLenght;
//操作结果：用e返回线性表中第i个数据的元素值；
void GetElem(SqList L, int i, int *e)
{
    *e = *(L.elem + i - 1);
}

//初始条件：线性表已存在，compare()是数据元素判定函数；
//操作结果：返回第1个与e满足compare()的数据元素的位序，若这样的数据元素不存在则返回值为0；
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

//初始条件：线性表已存在;
//操作结果：若cur_e是数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败：pre_e无意义；
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

//初始条件：线性表已存在；
//操作结果：若cur_e是数据的元素，且不是最后，则用next_e返回它的后继，否则操作失败，next_e无意义；
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

//初始条件：线性表已存在，1<=i<=ListLength(l)+1
//操作结果：在L的第i个位置之前插入新的数据元素e，L的长度加一；
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

//初始条件：线性表L已存在；
//操作结果：删除L第i个数据元素，并用e返回其值，L的长度减一；
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

//初始条件：线性表L已存在；
//操作结果：依次对线性表中每个元素调用visited()；
void ListTraverse(SqList *L,int (*p)(int *))
{
    int i;
    for(i=0;i<L->length;i++)
    (*p)(L->elem+i);
}

//找到一个比n大的数
int compare(int x, int y)
{
    if (x > y)
        return true;
    return false;
}

//元素的值加一
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
        *(L.elem + i) = i; //放入数据 0-9
        L.length++;
    }
    printf("before:\n");
    for (i = 0; i < 10; i++) //打印链表的数据
        printf("%d ", *(L.elem + i));

    printf("\nafter:\n");
    // ClearList(&L);
    ListTraverse(&L,add);

    for (i = 0; i < L.length; i++) //打印链表的数据
        printf("%d ", *(L.elem + i));
    return 0;
}
