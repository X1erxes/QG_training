#include <stdio.h>
#include <windows.h>

#include "Typedef.h"
#include "StackOperation.h"
#include "Calculator.h"
#include "Global.h"

void DisplayMenu(void) {
    system("cls");
    printf("          ********************************               ********************************\n");
    printf("          *         1.初始化链栈         *               *         2.数据入链栈         *\n");
    printf("          *         3.判断空链栈         *               *         4.数据出链栈         *\n");
    printf("          *         5.取栈顶元素         *  11.退出系统  *         6.查看栈长度         *\n");
    printf("          *         7.销毁链栈           *               *         8.打印链栈           *\n");
    printf("          *         9.清空链栈           *               *         10.后缀计算器        *\n");
    printf("          ********************************               ********************************\n");
    printf("请输入对应数字(1-11)：");
    return;
}

void Choose ( int choice , LinkStack *L) {
    if ( choice == 1 ) {
        if ( InitStack(L) ) {
            printf("初始化成功！\n");
            Reset();
            return;
        }
    } 
    else if ( choice == 2 ) {
        char input[MAXCHAR];
        if ( !JudgeInit() ) return;
        printf("输入要入栈的数据：\n");
        scanf("%s",&input);
        PushStack(L,&input);
        printf("入栈成功！\n");
        Reset();
        return;
    } 
    else if ( choice == 3 ) {
        if ( !JudgeInit() ) return;
        if ( EmptyStack(L) ) printf("链栈为空\n");
        else printf("链栈不为空\n");
        Reset();
        return;
    }
    else if ( choice == 4 ) {
        if ( !JudgeInit() ) return;
        PopStack(L);
        printf("出栈成功！\n");
        Reset();
        return;
    }
    else if ( choice == 5 ) {
        char *Output;
        if ( !JudgeInit() ) return;
        memcpy(Output,TopStack(L),sizeof(char) * MAXCHAR);
        printf("栈顶元素为：%s\n",Output);
        Reset();
        return;
    }
    else if ( choice == 6 ) {
        if ( !JudgeInit() ) return;
        printf("链栈的长度为：%d\n",SizeStack(L));
        Reset();
        return;
    }
    else if ( choice == 7 ) {
        if ( !JudgeInit() ) return;
        DestroyStack(L);
        printf("销毁成功！\n");
        Reset();
        return;
    }
    else if ( choice == 8 ) {
        if ( !JudgeInit() ) return;
        PrintStack(L);
        Reset();
        return;
    }
    else if ( choice == 9 ) {
        if ( !JudgeInit() ) return;
        ClearStack(L);
        printf("清空成功！\n");
        Reset();
        return;
    }
    else if ( choice == 10 ) {
        double ret = Calculate();
        printf("结果为：%.3lf(保留三位小数)\n",ret);
        Reset();
        return;
    }
    else if ( choice == 11 ) {
        exit(0);
    }
    return;
}

void Reset (void) {
    printf("请按任意键继续...\n");
    while ( getchar() != '\n' );
    getchar();
    DisplayMenu();
    return;
}

int JudgeInit (void) {
    if (!Init) {
        printf("未初始化链栈！\n");
        Reset();
        return 0;
    }
    return 1;
}