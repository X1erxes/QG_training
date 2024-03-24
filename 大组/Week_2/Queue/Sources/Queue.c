#include <stdlib.h>
#include <string.h>

#include "Typedef.h"
#include "Define.h"
#include "Global.h"

Bool InitLQueue (LQueue *Q) {
    Q->front = (Node *)malloc(sizeof(Node));
    Q->rear = (Node *)malloc(sizeof(Node));
    if ( !Q->front || !Q->rear ) return 0;
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
    Init = 1;
    return 1;
}

void DestoryLQueue(LQueue *Q) {
    Node * p = Q->front;
    while ( p != NULL ) {
        Node * tmp = p;
        p = p->next;
        free(tmp);
    }
    free(Q);
    Init = 0;
    return;
}

Bool IsEmptyLQueue(LQueue *Q) {
    if ( Q->length == 0 ) return 1;
    else return 0;
}

ElemType GetHeadLQueue(LQueue *Q) {
    if ( IsEmptyLQueue(Q) ) {
        printf("该队列为空队列，没有队首元素\n");
        return "\0";
    }
    Node * p = Q->front;
    return p->data;
}

int LengthLQueue(LQueue *Q) {
    return Q->length;
}

void EnLQueue(LQueue *Q, ElemType data) {
    Node * p = (Node *)malloc(sizeof(Node));
    p->data = malloc(sizeof(char) * MAXCHAR);
    memcpy(p->data,data, sizeof(data) + 1);
    p->next = NULL;
    if ( IsEmptyLQueue(Q) ) {
        Q->front = p;
        Q->rear = p;
        Q->length++;
    }
    else {
        Q->rear->next = p;
        Q->rear = p;
        Q->length++;
    }
    return;
}

void DeLQueue(LQueue *Q) {
    if ( IsEmptyLQueue(Q) ) {
        printf("该队列为空队列，不能出队列\n");
        return;
    }
    Node * p = Q->front;
    Q->front = p->next;
    if ( Q->length == 1 ) Q->rear = NULL;
    free(p);
    Q->length--;
    return;
}

void ClearLQueue(LQueue *Q) {
    Node * p = Q->front;
    char * zero = "0";
    while ( p != NULL ) {
        memcpy(p->data,&zero,sizeof(&zero) + 1);
        p = p->next;
    }
    return;
}

void LPrint(LQueue *Q) {
    if ( IsEmptyLQueue(Q) ) {
        printf("该队列为空队列\n");
        return;
    }
    Node * p = Q->front;
    for (int i = 1; i <= Q->length; i++)
    {
        char *tmp = (char *)malloc(sizeof(char) * MAXCHAR);
        memcpy(tmp,p->data,sizeof(char) * MAXCHAR);
        printf("从队首开始，第%d个元素为：",i);
        printf("%s\n",tmp);//更改元素类型时，这里也要相应更改格式符
        p = p->next;
    }
    return;
}


