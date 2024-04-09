#include <windows.h>
#include <stdio.h>

#include "Global.h"
#include "Order.h"
#include "BST.h"

void DisplayMenu(void) {
    system("cls");
    printf("          ********************************               ********************************\n");
    printf("          *         1.初始化树           *               *         2.插入数据           *\n");
    printf("          *         3.查找数据           *  9.退出系统   *         4.删除数据           *\n");
    printf("          *         5.前序遍历           *               *         6.中序遍历           *\n");
    printf("          *         7.后序遍历           *               *         8.层序遍历           *\n");
    printf("          ********************************               ********************************\n");
    printf("请输入对应数字(1-9)：");
    return;
}

void Reset (void) {
    system("pause");
    DisplayMenu();
    return;
}

void Choose (int choice) {
    if (choice == 1) {
        P = NULL;
        printf("初始化成功！\n");
        Reset();
        return;
    }
    else if (choice == 2) {
        int data;
        printf("输入你要插入的数据:\n");
        scanf("%d",&data);
        if (InsertBST(&P,data))
            printf("插入成功！\n");
        else
            printf("插入失败！\n");
        Reset();
        return;
    }
    else if (choice == 3) {
        int data;
        NodePtr current;
        printf("输入你要查找的数据:\n");
        scanf("%d",&data);
        if (SearchBST(P,data,&current))
            printf("存在!\n");
        else
            printf("不存在!\n");
        Reset();
        return;
    }
    else if (choice == 4) {
        int data;
        printf("输入你要删除的数据:\n");
        scanf("%d",&data);
        if (Delete(&P,data))
            printf("删除成功!\n");
        else
            printf("删除失败!\n");
        Reset();
        return;
    }
    else if (choice == 5) {
        int mod;
        printf("选择你要遍历的模式:(0递归 1非递归)\n");
        scanf("%d",&mod);
        if (mod == 0) 
            PreOrder(P);
        else
            PreStack(P);
        Reset();
        return;
    }
    else if (choice == 6) {
        int mod;
        printf("选择你要遍历的模式:(0递归 1非递归)\n");
        scanf("%d",&mod);
        if (mod == 0) 
            InOrder(P);
        else
            InStack(P);
        Reset();
        return;
    }
    else if (choice == 7) {
        int mod;
        printf("选择你要遍历的模式:(0递归 1非递归)\n");
        scanf("%d",&mod);
        if (mod == 0) 
            PostOrder(P);
        else
            PostStack(P);
        Reset();
        return;
    }
    else if (choice == 8) {
        LevelOrder(P);
        Reset();
        return;
    }
    else if (choice == 9) {
        exit(0);
    }
    else {
        printf("输入错误！\n");
        Reset();
        return;
    }
}




