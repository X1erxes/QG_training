
#include "Swap.h"

void ColourSort(int array[],int N) {
	
	for (int i = 0; i < N; i++) 
		if (array[i] != 1 && array[i] != 2 && array[i] != 0) { printf("数据只能包含0 1 2！"); return; }
	
	int p0 = 0;
	int p2 = N;
	for (int i = 0; i < p2; ++i)
	{
		if (array[i] == 0)
		{
			int tmp = array[p0];
			array[p0] = array[i];
			array[i] = tmp;
			++p0;
		}
		else if (array[i] == 2)
		{
			--p2;
			int tmp = array[p2];
			array[p2] = array[i];
			array[i] = tmp;
			--i;
		}
	}
	printf("排序后的数据为:\n");
	for (int i = 0; i < N; i++) printf("%d ", array[i]);
	return;
}

void Top_K(int array[],int l,int r,int K)
{
	int i = l , j = r , mid=array[ ( l + r ) / 2 ];

	do{
		while( array[j] > mid ) j--;
		while( array[i] < mid ) i++;
		if( i <= j )
		{
			swap( &array[i] , &array[j] );
			i++;
			j--;
		}
	} while( i <= j );

	if( K <= j ) Top_K(array,l,j,K);
	else if( i <= K ) Top_K(array,i,r,K);
	else 
	{
		printf("%d\n",array[j+1]);
		return;
	}
	return;
}


