#include <windows.h>
#include <stdio.h>
#include <time.h>

#include "Sort.h"

void RandomData(int array[], int len, int minn, int maxn) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        array[i] = minn + rand() % (maxn - minn + 1);
    }
    return;
}

clock_t TestLarge (int array[],int len,int choice) {
    clock_t start = clock();

    if ( choice == 1) InsertSort(array,len);
    else if ( choice == 2 ) MergeSort(array,len);
    else if ( choice == 3 ) QuickSort(array,len);
    else if ( choice == 4 ) CountSort(array,len);
    else if ( choice == 5 ) RadixCountSort(array,len);

    clock_t diff = clock() - start;
    return diff;
}

clock_t Accumulation(int array[],const int len,int choice) {
    int *tmp = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        tmp[i] = array[i];
    }
    clock_t start = clock();
    
    if ( choice == 1 ) InsertSort(tmp,len);
    else if ( choice == 2 ) MergeSort(tmp,len);
    else if ( choice == 3 ) QuickSort(tmp,len);
    else if ( choice == 4 ) CountSort(tmp,len);
    else if ( choice == 5 ) RadixCountSort(tmp,len); 
    
    clock_t diff = clock() - start;
    return diff;
}

void TestSmall (const int len,int fre) {
    clock_t sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0,sum5 = 0;
    int *array = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < fre; i++)
    {
        RandomData(array,len,0,len);

        sum1 += Accumulation(array,len,1);
        sum2 += Accumulation(array,len,2);
        sum3 += Accumulation(array,len,3);
        sum4 += Accumulation(array,len,4);
        sum5 += Accumulation(array,len,5);

    }
    printf("插入排序总用时%dms\n",sum1);
    printf("归并排序总用时%dms\n",sum2);
    printf("快速排序总用时%dms\n",sum3);
    printf("计数排序总用时%dms\n",sum4);
    printf("基数计数排序总用时%dms\n",sum5);
    return;
}

void SaveToFile (int array[],int len) {
    FILE *fp;

    fp = fopen(".\\data.txt","w");
    if ( fp == NULL ) {printf("未能成功打开文件！\n");return;}

    for (int i = 0; i < len; i++)
    {
        fprintf(fp,"%d ",array[i]);
    }

    if ( fclose(fp) == EOF ) {printf("未能成功关闭文件！\n");return;}

    return;
}

void GetFromFile (int array[],int len,int choice) {
    FILE *fp;

    if ( ( fp = fopen(".\\data.txt","r") ) == NULL ) {printf("未能成功打开文件！\n");return;}

    for (int i = 0; i < len; i++)
    {
        fscanf(fp,"%d",&array[i]);
    }
    
    if ( choice == 1) InsertSort(array,len);
    else if ( choice == 2 ) MergeSort(array,len);
    else if ( choice == 3 ) QuickSort(array,len);
    else if ( choice == 4 ) CountSort(array,len);
    else if ( choice == 5 ) RadixCountSort(array,len);

    if ( fclose(fp) == EOF ) {printf("未能成功关闭文件！\n");return;}

    SaveToFile(array,len);

    return;
}

void OutPutFile (const int len) {
    int *array = (int *)malloc(sizeof(int) * len);
    FILE *fp;

    if ( ( fp = fopen(".\\data.txt","r") ) == NULL ) {printf("未能成功打开文件！\n");return;}

    for (int i = 0; i < len; i++)
    {
        fscanf(fp,"%d",&array[i]);
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d\n",array[i]);
    }

    if ( fclose(fp) == EOF ) {printf("未能成功关闭文件！\n");return;}
    return;   
}
