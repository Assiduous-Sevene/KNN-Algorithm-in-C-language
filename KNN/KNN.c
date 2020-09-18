#include<stdio.h>
#include<stdlib.h>
#include"KNN.h"
#include"array.h"
//������̬��ά���� 
float **dynamic_array(int n,int m)//n�����ݸ�����m��ά�� 
{
	int i;
	float **array;
	array=(float **)malloc(n*sizeof(float *));    
    array[0]=(float *)malloc(n*m*sizeof(float));
	for(i=1;i<n;i++)
	{
		array[i] = array[i-1] + m;
	}
	return array;
}


void KNN_load_data(int *data_num,int *dimension,float ***array,float ***karray)
{
	FILE *fp;
	int i=0,j=0;
	if((fp = fopen("data.txt","r")) == NULL) printf("�ļ���ʧ��\n");
	if((fscanf(fp,"N=%d,D=%d",data_num,dimension)) != 2) printf("�ļ���ʧ��\n");

	*array = dynamic_array(*data_num,*dimension);
	*karray = dynamic_array(*data_num,2);
	
	for(i=0;i<*data_num;i++)
	{
		for(j=0;j<*dimension;j++)
		{
			fscanf(fp,"%f",&(*array)[i][j]);
		}
	}
	for(i=0;i<*data_num;i++)
	{
		for(j=0;j<2;j++)
		{
			(*karray)[i][j]=999.0;
		}
	}

}
