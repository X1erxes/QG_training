#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "global.h"

void SwapOddEven (SingleList **head) {
    SingleList *p1 = *head,*tmp1,*tmp2;

    for (int i = 1 ;p1 != NULL && p1->next != NULL; i++) {
        if ( i % 2 == 0 ){
            if ( tmp2->next != NULL) p1->next = tmp2->next;
            p1 = tmp2;
        }
        else {
            tmp1 = p1->next;
            tmp2 = tmp1->next;
            tmp1->next = p1;
            p1->next = tmp2;
            if (p1 == *head) *head = tmp1;
        }
    }

    printf("链表奇偶反转完成！\n");
    return;
}

void SearchMid (SingleList *head) {
    SingleList *slow = head,*fast = head;

    for (int i = 0;fast->next != NULL; i++) {
        if ( i % 2 == 0 ) {
            slow = slow->next;
        }
        fast = fast->next;
    }

    printf("中间链表的数据为：%d\n",slow->data);
    return;
}

void JudgeLoop (SingleList *head) {
    SingleList *fast = head,*slow = head;

    for (int i = 0;fast->next != NULL; i++)
    {
        if ( i % 2 == 0 ) {
            slow = slow->next;
        }
        fast = fast->next;

        if ( slow == fast && i > 0 ) {
            printf("链表成环！\n");
            return;
        }
    }
    printf("链表未成环！\n");
    return;
}

void ReverseList (SingleList **head) {
    SingleList *p = head;
    int choice;
    
    printf("选择方法(0递归 1非递归)：\n");
    scanf("%d",&choice);

    if (choice == 0) {
        Recursion(*head);
    } else {
        Circulation(head);
    }
    printf("链表反转成功！\n");
    return;
}

void Recursion (SingleList *node) {
    SingleList *tmp = node->next;

    if ( tmp->next == NULL ) {
        tmp->next = node;
        head = tmp;
    } else {
        Recursion(node->next);
        tmp->next = node;
        node->next = NULL;
    }
    return;
}

void Circulation (SingleList **head) {
    SingleList *p1 = *head,*front = NULL,*next;
    while ( p1 != NULL ) {
        if ( p1->next == NULL ) *head = p1;
        next = p1->next;
        p1->next = front;
        front = p1;
        p1 = next;
    }
    return;
}
