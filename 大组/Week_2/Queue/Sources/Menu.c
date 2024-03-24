#include <stdio.h>
#include <windows.h>

#include "Typedef.h"
#include "Global.h"
#include "Queue.h"

void DisplayMenu(void) {
    system("cls");
    printf("          ********************************       |         ********************************\n");
    printf("          *         1.初始化队列         *       |         *         2.数据入队列         *\n");
    printf("          *         3.判断空队列         *       |         *         4.数据出队列         *\n");
    printf("          *         5.取队首元素         *       |         *         6.查看队列长度       *\n");
    printf("          *         7.销毁队列           *       |         *         8.打印队列           *\n");
    printf("          *         9.清空队列           *       |         *         10.退出系统          *\n");
    printf("          ********************************       |         ********************************\n");
    printf("请输入对应数字(1-10)：");
    return;
}

void Choose ( int choice , LQueue *Q) {
    if ( choice == 1 ) {
        if ( InitLQueue(Q) ) {
            printf("初始化成功！\n");
            Reset();
            return;
        }
    }
    else if ( choice == 2 ) {
        char input[MAXCHAR];
        if ( !JudgeInit() ) return;
        printf("输入要入队的数据：\n");
        scanf("%s",&input);
        EnLQueue(Q,&input);
        printf("入队成功！\n");
        Reset();
        return;
    }
    else if ( choice == 3 ) {
        if ( !JudgeInit() ) return;
        if ( IsEmptyLQueue(Q) ) printf("队列为空\n");
        else printf("队列不为空\n");
        Reset();
        return;
    }
    else if ( choice == 4 ) {
        if ( !JudgeInit() ) return;
        DeLQueue(Q);
        printf("出队成功！\n");
        Reset();
        return;
    }
    else if ( choice == 5 ) {
        char *Output;
        if ( !JudgeInit() ) return;
        memcpy(Output,GetHeadLQueue(Q),sizeof(char) * MAXCHAR);
        printf("队首元素为：%s\n",Output);
        Reset();
        return;
    }
    else if ( choice == 6) {
        if ( !JudgeInit() ) return;
        printf("队列的长度为：%d\n",LengthLQueue(Q));
        Reset();
        return;
    }
    else if ( choice == 7 ) {
        if ( !JudgeInit() ) return;
        DestoryLQueue(Q);
        printf("销毁成功！\n");
        Reset();
        return;
    }
    else if ( choice == 8 ) {
        if ( !JudgeInit() ) return;
        LPrint(Q);
        Reset();
        return;
    }
    else if ( choice == 9 ) {
        if ( !JudgeInit() ) return;
        ClearLQueue(Q);
        printf("清空成功！\n");
        Reset();
        return;
    }
    else if ( choice == 10 ) {
        exit(0);
    }
    else {
        printf("输入错误！\n");
        Reset();
        return;
    }
    return;
}

void Reset(void) {
    printf("请按任意键继续...\n");
    while ( getchar() != '\n' );
    getchar();
    DisplayMenu();
    return;
}

int JudgeInit (void) {
    if (!Init) {
        printf("未初始化队列！\n");
        Reset();
        return 0;
    }
    return 1;
}

