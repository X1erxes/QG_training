#ifndef TYPEDEF
#define TYPEDEF


typedef struct BSTnode{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
}BSTnode, *NodePtr;


#endif