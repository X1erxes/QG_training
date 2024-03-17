#ifndef STRUCT
#define STRUCT

typedef struct 
{
    int data;
    struct SingleList * next;
} SingleList; //单向链表

typedef struct 
{
    struct CoupleList * front;
    int data;
    struct CoupleList * next;
} CoupleList; //双向链表

#endif //避免重复引入头文件

