#include <string.h>

#include "Swap.h"

void InsertSort(int array[],int len) {
    for (int i = 1; i < len; i++)
    {
        int tmp = array[i];
        int j;
        for ( j = i - 1; j >= 0; j--)
        {
            if ( array[j] > tmp ) {
                array[j+1] = array[j];
            } else break;
        }
        array[j+1] = tmp;
    }
    return;
}

void MergeRecursive (int array[],int ret[],int start,int end) {
    if (start >= end) return;
    
    int len = end - start, mid = len / 2 + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    MergeRecursive(array, ret, start1, end1);
    MergeRecursive(array, ret, start2, end2);
    
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        ret[k++] = array[start1] < array[start2] ? array[start1++] : array[start2++];
    
    while (start1 <= end1) ret[k++] = array[start1++];
    
    while (start2 <= end2) ret[k++] = array[start2++];
    
    for (k = start; k <= end; k++) array[k] = ret[k];
    
    return;
}

void MergeSort(int array[],const int len) {
    int *ret = (int *)malloc(sizeof(int) * len);
    MergeRecursive(array,ret,0,len - 1);
    return;
}

void QuickRecursive(int array[],int start,int end) {
    if (start >= end) return;
    
    int mid = array[end];
    int left = start, right = end - 1;

    while (left < right) {
        while (array[left] < mid && left < right) left++;
        while (array[right] >= mid && left < right) right--;
        swap(&array[left], &array[right]);
    }

    if (array[left] >= array[end]) swap(&array[left], &array[end]);
    else left++;
    
    if (left) {
        QuickRecursive(array, start, left - 1);
    }
    QuickRecursive(array, left + 1, end);
    return;
}

void QuickSort(int array[],int len) {
    QuickRecursive(array,0,len - 1);
    return;
}

void CountSort(int array[],const int len) {
    int maxn = array[0];
    int minn = array[0];
    int *ret = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
    {
        maxn = mmax(maxn,array[i]);
        minn = mmin(minn,array[i]);
    }
    const int count = maxn - minn + 1;
    int *cnt = (int *)malloc(sizeof(int) * count);
    memset(cnt,0,sizeof(int) * count);

    for (int i = 0; i < len; i++) cnt[array[i]-minn]++;
    for (int i = 1; i < count; i++) cnt[i] += cnt[i-1];
    
    for (int i = len - 1; i >= 0; i--)
    {
        int index = --cnt[array[i]];
        ret[index] = array[i];
    }
    
    for (int i = 0; i < len; i++) array[i] = ret[i];
    return;
}

int MaxBit(int array[], int len)
{
    int maxn = array[0];
    int Bit = 0;

    for (int i = 0; i < len; i++) maxn = mmax(maxn,array[i]);

    while ( maxn > 0 ) {
        maxn /= 10;
        Bit++;
    }
    return Bit;
}

void RadixCountSort(int array[],const int len) {
    int Bit = MaxBit(array,len);
    int count[10] = {0},*ret = (int *)malloc(sizeof(int) * len);
    int radix = 1;

    for(int i = 1; i <= Bit; i++) 
    {
        for(int j = 0; j < 10; j++) count[j] = 0;

        for(int j = 0; j < len; j++)
        {
            int index = array[j] / radix % 10;
            count[index]++;
        }

        for(int j = 1; j < 10; j++) count[j] += count[j - 1];
        for(int j = len - 1; j >= 0; j--) 
        {
            int index = array[j] / radix % 10;
            ret[--count[index]] = array[j];
        }

        for(int j = 0; j < len; j++) array[j] = ret[j];
        
        radix *= 10;
    }
    return;
}

int mmin (int x,int y) {
    return x < y ? x : y;
}

int mmax (int x,int y) {
    return x > y ? x : y;
}


