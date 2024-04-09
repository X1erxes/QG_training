#include <stack>
#include <queue>
#include <stdio.h>

#include "Typedef.h"

using namespace std;

void PreOrder (NodePtr P) {
    if (!P)
        return;
    printf("%d\n",P->data);
    PreOrder(P->left);
    PreOrder(P->right);
    return;
}

void InOrder (NodePtr P) {
    if (!P)
        return;
    PreOrder(P->left);
    printf("%d\n",P->data);
    PreOrder(P->right);
    return;
}

void PostOrder (NodePtr P) {
    if (!P)
        return;
    PreOrder(P->left);
    PreOrder(P->right);
    printf("%d\n",P->data);
    return;
}

void PreStack (NodePtr P) {
    NodePtr tmp = P;
    stack<NodePtr> Stack;

    Stack.push(tmp);
    while (!Stack.empty()) {
        tmp = Stack.top();
        printf("%d\n",tmp->data);
        Stack.pop();

        if (tmp->right != NULL) {
            Stack.push(tmp->right);
        }
        if (tmp->left != NULL) {
            Stack.push(tmp->left);
        }
    }
    return;
}

void InStack (NodePtr P) {
    NodePtr tmp = P;
    stack<NodePtr> Stack;

    while (tmp != NULL || !Stack.empty()) {
        if (tmp != NULL) {
            Stack.push(tmp);
            tmp = tmp->left;
        }
        else {
            printf("%d\n",(Stack.top())->data);
            tmp = (Stack.top())->right;
            Stack.pop();
        }
    }
    return;
}

void PostStack (NodePtr P) {
    NodePtr tmp = P,ret;
    stack<NodePtr> Stack;

    while (tmp != NULL || !Stack.empty()) {
        while (tmp != NULL) {
            Stack.push(tmp);
            if (tmp->left != NULL)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }

        ret = Stack.top();
        printf("%d\n",(ret->data));
        Stack.pop();

        if (!Stack.empty() && (Stack.top())->left == ret)
            tmp = (Stack.top())->right;
        else
            tmp = NULL;
    }
    return;
}

void LevelOrder (NodePtr P) {
    NodePtr tmp = P;
    queue<NodePtr> Queue;

    Queue.push(tmp);
    while (!Queue.empty()) {
        tmp = Queue.front();
        Queue.pop();
        
        printf("%d\n",tmp->data);

        if (tmp->left != NULL)
            Queue.push(tmp->left);
        if (tmp->right != NULL)
            Queue.push(tmp->right);
    }
    return;
}


