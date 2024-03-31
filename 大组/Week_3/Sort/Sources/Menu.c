#include <windows.h>
#include <stdio.h>

#include "Test.h"
#include "Global.h"
#include "Application.h"

void DisplayMenu(void) {
    system("cls");
    printf("          **********************************      |        ********************************\n");
    printf("          *        1.生成数据并保存        *      |        *        2.读取数据并排序      *\n");
    printf("          *        3.大数据量排序          *      |        *        4.小数据量排序        *\n");
    printf("          *        5.颜色排序              *      |        *        6.第K小数             *\n");
    printf("          *        7.输出数据              *      |        *        8.退出系统            *\n");
    printf("          **********************************      |        ********************************\n");
    printf("请输入对应数字(1-8)：");
    return;
}


void Choose (int choice) {
    if ( choice == 1 ) {
        int len;
        printf("输入数据量:\n");
        scanf("%d",&len);
        if ( len <= 0 ) {printf("数据量只能为正整数!\n");Reset();return;}

        int *array = (int *)malloc(sizeof(int) * len);
        RandomData(array,len,0,len);

        SaveToFile(array,len);
        printf("保存成功!\n");
        
        Init = len;
        Reset();
        return;
    } 
    else if ( choice == 2 ) {
        if ( !JudgeInit() ) return;
        int choice;
        
        if (! (choice = ChooseSort()) ) {Reset();return;}

        int *array = (int *)malloc(sizeof(int) * Init);
        GetFromFile(array,Init,choice);
        printf("排序成功!\n");

        Reset();
        return;
    } 
    else if ( choice == 3 ) {

        printf("10000数据量用时:\n");
        RandomData(a1,10000,0,10000);
        for (int i = 0; i < 10000; i++) t1[i] = a1[i];
        printf("插入排序:%dms\n",TestLarge(t1,10000,1));
        for (int i = 0; i < 10000; i++) t1[i] = a1[i];
        printf("归并排序:%dms\n",TestLarge(t1,10000,2));
        for (int i = 0; i < 10000; i++) t1[i] = a1[i];
        printf("快速排序:%dms\n",TestLarge(t1,10000,3));
        for (int i = 0; i < 10000; i++) t1[i] = a1[i];
        printf("计数排序:%dms\n",TestLarge(t1,10000,4));
        for (int i = 0; i < 10000; i++) t1[i] = a1[i];
        printf("基数计数排序:%dms\n",TestLarge(t1,10000,5));

        printf("50000数据量用时:\n");
        RandomData(a2,50000,0,50000);
        for (int i = 0; i < 50000; i++) t2[i] = a2[i];
        printf("插入排序:%dms\n",TestLarge(t2,50000,1));
        for (int i = 0; i < 50000; i++) t2[i] = a2[i];
        printf("归并排序:%dms\n",TestLarge(t2,50000,2));
        for (int i = 0; i < 50000; i++) t2[i] = a2[i];
        printf("快速排序:%dms\n",TestLarge(t2,50000,3));
        for (int i = 0; i < 50000; i++) t2[i] = a2[i];
        printf("计数排序:%dms\n",TestLarge(t2,50000,4));
        for (int i = 0; i < 50000; i++) t2[i] = a2[i];
        printf("基数计数排序:%dms\n",TestLarge(t2,50000,5));

        printf("200000数据量用时:\n");
        RandomData(a3,200000,0,200000);
        for (int i = 0; i < 200000; i++) t3[i] = a3[i];
        printf("插入排序:%dms\n",TestLarge(t3,200000,1));
        for (int i = 0; i < 200000; i++) t3[i] = a3[i];
        printf("归并排序:%dms\n",TestLarge(t3,200000,2));
        for (int i = 0; i < 200000; i++) t3[i] = a3[i];
        printf("快速排序:%dms\n",TestLarge(t3,200000,3));
        for (int i = 0; i < 200000; i++) t3[i] = a3[i];
        printf("计数排序:%dms\n",TestLarge(t3,200000,4));
        for (int i = 0; i < 200000; i++) t3[i] = a3[i];
        printf("基数计数排序:%dms\n",TestLarge(t3,200000,5));

        Reset();
        return;
    }
    else if ( choice == 4 ) {
        int len,fre;

        printf("输入数据量:\n");
        scanf("%d",&len);
        if ( len <= 0 ) {printf("数据量只能为正整数!\n");Reset();return;}
        printf("输入排序数:\n");
        scanf("%d",&fre);
        if ( fre <= 0 ) {printf("排序数只能为正整数!\n");Reset();return;}
        
        TestSmall(len,fre);

        Reset();
        return;
    }
    else if ( choice == 5 ) {
        int N;
        printf("输入数据量:\n");
        scanf("%d",&N);
        if ( N <= 0 ) {printf("数据量只能为正整数!\n");Reset();return;}
        int *array = (int *)malloc(sizeof(int) * N);
        
        printf("依次输入元素:\n");
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&array[i]);
        }
        
        ColourSort(array,N);
        printf("排序成功!\n");

        Reset();
        return;
    }
    else if ( choice == 6 ) {
        int len,K;
        
        printf("输入数据量:\n");
        scanf("%d",&len);
        if ( len <= 0 ) {printf("数据量只能为正整数!\n");Reset();return;}
        int *array = (int *)malloc(sizeof(int) * len);

        printf("输入第几小:\n");
        scanf("%d",&K);
        if ( K < 0 || K >= len ) {printf("输入错误!\n");Reset();return;}

        printf("依次输入元素:\n");
        for (int i = 0; i < len; i++)
        {
            scanf("%d",&array[i]);
        }

        printf("第%d小的元素为:\n",K);
        Top_K(array,0,len - 1,K - 1);

        Reset();
        return;
    }
    else if ( choice == 7 ) {
        if ( !JudgeInit() ) return;

        printf("数据依次是:\n");
        OutPutFile(Init);
        
        Reset();
        return;
    }
    else if ( choice == 8 ) {
        exit(0);
    }
    else {
        printf("输入错误！\n");
        Reset();
        return;
    }
    return;
}

void Reset (void) {
    system("pause");
    DisplayMenu();
    return;
}

int JudgeInit (void) {
    if (!Init) {
        printf("未生成数据!\n");
        Reset();
        return 0;
    }
    return 1;
}

int ChooseSort(void) {
    int choice;
    
    printf("选择排序方法:\n1插入排序 2归并排序 3快速排序 4计数排序 5基数计数排序\n");
    scanf("%d",&choice);
    if (! (choice <= 5 && choice >= 1) ) {printf("输入错误!\n");return 0;}
    else return choice;
}

