#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "global.h"


SingleList * AcceptSingleData(void) {
    int num; //数据的数量
    SingleList *head = NULL;
    SingleList *p1,*p2; //构建链表的指针
    printf("数据的个数：\n");
    scanf("%d",&num);
    printf("输入数据：\n");

    p1 = (SingleList *)malloc(sizeof(SingleList));
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&p1->data);
        if ( i == 0 ) {
            head = p1; //特判初始化
        } else p2->next = p1; //连接下一个结点

        p2 = p1; //记录当前结点
        p1 = (SingleList *)malloc(sizeof(SingleList));
    }
    free(p1);
    p2->next = NULL;
    printf("单链表输入完成！\n");

    return head;
}

CoupleList * AcceptCoupleData(void) {
    int num;//数据的数量
    CoupleList *head = NULL;
    CoupleList *p1,*p2,*p3 = NULL; //构建链表的指针
    printf("数据的个数：\n");
    scanf("%d",&num);
    printf("输入数据：\n");

    p1 = (CoupleList *)malloc(sizeof(CoupleList));
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&p1->data);
        if ( i == 0 ) {
            p1->front = NULL;
            head = p1; //特判初始化，头的上一个是空
        } else {
            p2->next = p1; //连接下一个结点
            p3 = p2; //记录上一个结点
        }
        p2 = p1; //记录当前结点
        p2->front = p3; //连接上一个结点
        p1 = (CoupleList *)malloc(sizeof(CoupleList));
    }
    free(p1);
    p2->next = NULL;
    
    printf("双链表输入完成！\n");
    return head;
}

void DeleteSingleNode (SingleList **head){
    SingleList *p1 = *head;
    SingleList *front;
    int target;
    printf("输入要删除的数据：\n");
    scanf("%d",&target);

    while ( p1 != NULL) {
        if ( p1->data == target ) {
            if ( p1 == *head ) {
                *head = p1->next;
                free(p1);
                p1 = *head;
            } else {
                front->next = p1->next;
                free(p1);
                p1 = front->next;
            }
        } else {
            front = p1;
            p1 = p1->next;
        }
    }
    printf("删除成功！\n");
    return;
}

void DeleteCoupleNode (CoupleList **head) {
    CoupleList *p1 = *head;
    CoupleList *front,*next;
    int target;
    printf("输入要删除的数据：\n");
    scanf("%d",&target);

    while ( p1 != NULL) {
        if ( p1->data == target ) {
            if ( p1 == *head ) {
                *head = p1->next;
                (*head)->front = NULL;
                free(p1);
                p1 = *head;
            } else {
                front->next = p1->next;
                if ( next != NULL ) next->front = front;
                free(p1);
                p1 = front->next;
            }
        } else {
            front = p1;
            p1 = p1->next;
        }
        if ( p1 != NULL ) next = p1->next;
    }
    printf("删除成功！\n");
    return;
}

void InsertSingleNode (SingleList **head) {
    SingleList *p1 = *head,*tmp;
    SingleList *target = (SingleList *)malloc(sizeof(SingleList));
    int num,i;

    printf("输入要插入的数据：\n");
    scanf("%d",&target->data);

    printf("输入要插入到第几个结点的后面：\n");
    scanf("%d",&num);


    for (i = 0;p1 != NULL; i++)
    {
        if ( i == 0) {
            if (num == i) {
                target->next = p1;
                *head = target;
            }
            continue;
        }
        if (i == num) {
            tmp = p1->next;
            p1->next = target;
            target->next = tmp;
            i++;
            break;
        }
        p1 = p1->next;
    }

    if (i == num + 1) printf("插入成功！\n");
    else printf("插入失败！\n");
    return;
}

void InsertCoupleNode (CoupleList **head) {
    CoupleList *p1 = *head,*tmp;
    CoupleList *target = (CoupleList *)malloc(sizeof(CoupleList));
    int num,i;

    printf("输入要插入的数据：\n");
    scanf("%d",&target->data);

    printf("输入要插入到第几个结点的后面：\n");
    scanf("%d",&num);


    for (i = 0;p1 != NULL; i++)
    {
        if ( i == 0) {
            if (num == i) {
                target->next = p1;
                target->front = NULL;
                p1->front = target;
                *head = target;
            }
            continue;
        }
        if (i == num) {
            tmp = p1->next;
            if ( tmp != NULL ) tmp->front = target;
            p1->next = target;
            target->next = tmp;
            target->front = p1;
            i++;
            break;
        }
        p1 = p1->next;
    }

    if (i == num + 1) printf("插入成功！\n");
    else printf("插入失败！\n");
    return;
}

void DestroySingleList (SingleList **head) {
    SingleList *p1 = *head,*tmp;

    while ( p1 != NULL ) {
        tmp = p1;
        p1 = p1->next;
        free(tmp);
    }
    *head = NULL;
    printf("销毁成功！\n");
    return;
}

void DestroyCoupleList (CoupleList **head) {
    CoupleList *p1 = *head,*tmp;

    while ( p1 != NULL ) {
        tmp = p1;
        p1 = p1->next;
        free(tmp);
    }
    *head = NULL;
    printf("销毁成功！\n");
    return;
}

void SearchSingleNode (SingleList *head) {
    SingleList *p1 = head;
    int target;

    printf("输入要查找的数据：\n");
    scanf("%d",&target);

    while ( p1 != NULL ) {
        if ( p1->data == target ) {
            printf("存在此数据！\n");
            return;
        }
        p1 = p1->next;
    }
    printf("不存在此数据！\n");
    return;
}

void SearchCoupleNode (CoupleList *head) {
    CoupleList *p1 = head;
    int target;

    printf("输入要查找的数据：\n");
    scanf("%d",&target);

    while ( p1 != NULL ) {
        if ( p1->data == target ) {
            printf("存在此数据！\n");
            return;
        }
        p1 = p1->next;
    }
    printf("不存在此数据！\n");
    return;
}

void PrintSingleList(SingleList *head) {
    SingleList *p = head;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}

void PrintCoupleList(CoupleList *head) {
    CoupleList *p = head;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}


