#include <stdio.h>
#include <stdlib.h>
#include "KNN.h"
#include "array.h"

int main(void)
{
	
	//��ʼ�� ����ȡ���� 
	//countΪ������
	//NΪ���ݸ�����MΪ����ά�ȣ�distΪ���ݼ��
	//arrayΪ�����ԭʼ���ݣ�testdataΪ�������ݣ�karrayΪ�������ݵ�����ԭʼ����֮��ľ���  
	int i,j,count=1;
	int N=0,M=0; 
	float temp;
	float dist;
	float **array = NULL,**karray = NULL,*testdata; 
	KNN_load_data(&N,&M,&array,&karray);
	printf("��ȡ���ݸ�����%d,����ά�ȣ�%d\n",N,M-1);
	printf("���������Ϊ��\n");
	print_2Darray(*array,N,M);
	
	//�ж��������ݹ��м�����
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
	printf("�������ݵķ�����Ϊ��%d\n",count);

	//д��������ݵ�
	testdata = (float *)malloc((M-1) * sizeof(float));
	printf("д��һ��%dά�Ĵ������ݵ㣺",M-1);
	for(i=0;i<M-1;i++)
	{
		scanf("%f",&testdata[i]);
	}
	
	//�������
	for(i=0;i<N;i++)
	{
		dist = distance(M-1,testdata,array[i]);
		karray[i][0] = dist;
		karray[i][1] = array[i][M-1];
	}
	printf("����㵽������ľ��룺\n");
	print_2Darray(*karray,N,2);
	
	//ð������
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
	printf("�����Ĵ���㵽������ľ��룺\n");
	print_2Darray(*karray,N,2);
	

	//�ҳ�ǰK����������Ľ��з���
	//result�������������ֵ�Ƶ�� 
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
	printf("Kȡ%d\n",K);
	printf("���ո�������ֵĴ�����");
	print_1Darray(result,count);
	
	//���ս����� 
	int index;
	index = max_index(result,count);
	printf("\n�����жϸĲ�����������%d��",index);
	return 0;
}




