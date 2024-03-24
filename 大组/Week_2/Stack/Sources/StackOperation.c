#include <stdlib.h>
#include <string.h>

#include "Typedef.h"
#include "Define.h"
#include "Global.h"

Bool InitStack (LinkStack *L) {
    L->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if ( !L->top ) return 0;
    L->top = NULL;
    L->count = 0;
    Init = 1;

    return 1;
}

void PushStack (LinkStack *L,ElemType target) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = malloc(sizeof(char) * MAXCHAR);
    memcpy(p->data,target, sizeof (target) + 1);
    p->next = L->top;
    L->top = p;
    L->count++;
    return;
}

Bool EmptyStack (LinkStack *L) {
    if (L->count == 0) return 1;
    else return 0;
}

void PopStack (LinkStack *L) {
    if ( EmptyStack(L) ) {
        printf("该栈为空栈，不能出栈\n");
        return;
    }
    LinkStackPtr p = L->top;
    L->top = p->next;
    free(p);
    L->count--;
    return;
}

ElemType TopStack (LinkStack *L) {
    if ( EmptyStack(L) ) {
        printf("该栈为空栈，没有栈顶元素\n");
        return "\0";
    }
    LinkStackPtr p = L->top;
    return p->data;
}

int SizeStack (LinkStack *L) {
    return L->count;
}

void DestroyStack (LinkStack *L) {
    LinkStackPtr p = L->top;
    while ( p != NULL ) {
        LinkStackPtr temp = p;
        p = p->next;
        free(temp);
    }
    free(L);
    Init = 0;
    return;
}

void PrintStack (LinkStack *L) {
    if ( EmptyStack(L) ) {
        printf("该栈为空栈\n");
        return;
    }
    LinkStackPtr p = L->top;
    for (int i = 1; i <= L->count; i++)
    {
        char *tmp = (char *)malloc(sizeof(char) * MAXCHAR);
        memcpy(tmp,p->data,sizeof(char) * MAXCHAR);
        printf("从栈顶开始，第%d个元素为：",i);
        printf("%s\n",tmp);//更改元素类型时，这里也要相应更改格式符
        p = p->next;
    }
    return;
}

void ClearStack (LinkStack *L) {
    LinkStackPtr p = L->top;
    char *zero = "0";
    while ( p != NULL ) {
        memcpy(p->data,&zero, sizeof (&zero) + 1);
        p = p->next;
    }
    return;
}


