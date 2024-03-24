#ifndef TYPEDEF
#define TYPEDEF

typedef void* ElemType;
typedef int Bool;

typedef struct node
{
    ElemType data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;            //队列长度
} LQueue;


#endif //避免重复引入头文件


