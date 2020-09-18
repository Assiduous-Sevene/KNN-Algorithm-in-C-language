#include<stdio.h>
#include"array.h"
#include<math.h>
void print_1Darray(float *array,int len)
{
	//array是需要打印的数组，len为该数组的长度 
	int i;
	printf("[");
	for(i=0;i<len;i++)
	{
		printf("%.2f",array[i]);
		printf("%c",i<len-1?' ':']');
	}
	printf("\n");
}

void print_2Darray(float *array,int N , int M)
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%.2f%c",array[i*M+j],j==M-1?'\n':' ');
		}
	}
}

void selection_sort(float *array,int len)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(array[j]>array[i])
			{
				swap(&array[j],&array[i]);
			}
		}
	}
}

void bubble_sort(float *array,int len)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-1-i;j++)
		{
			if(array[j+1]>array[j]) swap(&array[j+1],&array[j]);
		}
	}
}

void swap(float *a,float *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}

int max_index(float *a,int len)
{
    int max = a[0];
    int index,i;
    for(i=1;i<len;i++)
	{
        if(max<a[i])
		{
            max = a[i];
            index = i;
        }
    }
	return index;
}


float distance(int dim,float *av, float *bv) //dim代表两个向量的维度 
{
	int i,dist=0;
	for(i=0;i<dim;i++)
	{
		dist += pow(av[i]-bv[i],2);
	}
	return sqrt(dist);
}
