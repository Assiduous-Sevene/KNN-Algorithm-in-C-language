#include <stdio.h>
#include <stdlib.h>
#include "KNN.h"
#include "array.h"

int main(void)
{
	
	//初始化 ，读取数据 
	//count为分类数
	//N为数据个数，M为数据维度，dist为数据间距
	//array为导入的原始数据，testdata为测试数据，karray为测试数据到各个原始数据之间的距离  
	int i,j,count=1;
	int N=0,M=0; 
	float temp;
	float dist;
	float **array = NULL,**karray = NULL,*testdata; 
	KNN_load_data(&N,&M,&array,&karray);
	printf("读取数据个数：%d,数据维度：%d\n",N,M-1);
	printf("读入的数据为：\n");
	print_2Darray(*array,N,M);
	
	//判断所给数据共有几个类
	float a[N-1];
	for(i=0;i<N-1;i++)
	{
		a[i] = array[i][M-1];
	}
	bubble_sort(a,N);
	for(i=0;i<N-1;i++)
	{
		if(a[i]!=a[i+1])
		{
			count++;
		}
	}
	printf("所给数据的分类数为：%d\n",count);

	//写入待测数据点
	testdata = (float *)malloc((M-1) * sizeof(float));
	printf("写入一个%d维的待测数据点：",M-1);
	for(i=0;i<M-1;i++)
	{
		scanf("%f",&testdata[i]);
	}
	
	//计算距离
	for(i=0;i<N;i++)
	{
		dist = distance(M-1,testdata,array[i]);
		karray[i][0] = dist;
		karray[i][1] = array[i][M-1];
	}
	printf("待测点到各个点的距离：\n");
	print_2Darray(*karray,N,2);
	
	//冒泡排序
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(karray[j][0]>karray[j+1][0])
			{
				temp = karray[j][0];
				karray[j][0] = karray[j+1][0];
				karray[j+1][0] = temp;
				
				temp = karray[j][1];
				karray[j][1] = karray[j+1][1];
				karray[j+1][1] = temp; 
			}
		}
	}
	printf("排序后的待测点到各个点的距离：\n");
	print_2Darray(*karray,N,2);
	

	//找出前K个距离最近的进行分类
	//result储存各个分类出现的频率 
	float *result;
	int b = count;
	result = (float *)malloc(count*sizeof(float));
	for(i=0;i<K;i++)
	{
		for(b = count;b>0;b--)
		{
			if((int)(karray[i][1]) == b-1)
			{
				result[b-1] ++;
			}
		}
	}
	printf("K取%d\n",K);
	printf("最终各分类出现的次数：");
	print_1Darray(result,count);
	
	//最终结果输出 
	int index;
	index = max_index(result,count);
	printf("\n最终判断改测试数据属于%d类",index);
	return 0;
}




