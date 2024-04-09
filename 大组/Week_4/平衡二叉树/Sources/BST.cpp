#include <stdio.h>
#include <stdlib.h>
#include <stack>

#include "Typedef.h"
using namespace std;


NodePtr SearchBST (NodePtr P,int data,NodePtr *current) {
    if (!P) {
        return NULL;
    }

    if (data > P->data) {
        *current = P;
        return SearchBST(P->right, data,current);
    }
    else if (data < P->data) {
        *current  = P;
        return SearchBST(P->left, data,current);
    }
    else
        return P;
}

bool InsertBST (NodePtr *P,int data) {
    NodePtr current = NULL;
    NodePtr tmp = (NodePtr)malloc(sizeof(BSTnode));
    tmp->data = data;
    tmp->left = tmp->right = NULL;

    if (!(*P)) {
        *P = tmp;
        return true;
    }
    else if (!SearchBST(*P,data,&current)) {

        if (current->data > data)
            current->left = tmp;
        else
            current->right = tmp;

        return true;
    }
    else {
        return false;
    }
}

void DeleteBST(NodePtr *P) {
    NodePtr q,tmp;
    if ((*P)->right == NULL) {
        q = *P;
        *P = (*P)->left;
        free(q);
    }
    else if ((*P)->left == NULL) {
        q = *P;
        *P = (*P)->right;
        free(q);
    }
    else {
        q = *P;
        tmp = (*P)->left;

        while (tmp->right) {
            q = tmp;
            tmp = tmp->right;
        }

        (*P)->data = tmp->data;
        if (q != *P) 
            q->right = tmp->left;
        else
            q->left = tmp->left;

        free(tmp);
    }

    return;
}

bool Delete(NodePtr *P,int data) {
    if (!*P)
        return false;
    else {
        if (data == (*P)->data) {
            DeleteBST(P);
            return true;
        }
        else if (data > (*P)->data) {
            return Delete(&(*P)->right,data);
        }
        else if (data < (*P)->data) {
            return Delete(&(*P)->left,data);
        }
    }
}

