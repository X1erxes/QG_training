#ifndef TYPEDEF
#define TYPEDEF

typedef void* ElemType;
typedef int Bool;


typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
}LinkStack;



#endif //避免重复引入头文件

