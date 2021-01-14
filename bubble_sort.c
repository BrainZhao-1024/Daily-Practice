#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int BuildArr(int* p, int len)
{
	srand((int)time(0));
	*p = rand() % 100 - 49;  //���-49��50��Χ�ڵ���
	for (int i = 1; i < len; i++)
		*(p + i) = rand() % 100 - 49;  //���-49��50��Χ�ڵ���
	return 0;
}

void OutputSort(int* p, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d  ", *(p + i));

}

int BubbleSort(void)
{/*
 �ú������������������
 */
	int len;
	printf("��Ҫ�೤�����飿");
	scanf_s("%d", &len);

	int *p = (int*)malloc(sizeof(int)*len);

	BuildArr(p,len);

	printf("������ɵ�%dλ����Ϊ��", len);
	OutputSort(p, len);

	for (int i = 0; i < len; i++)     //����ð���㷨
		for (int j = len-1; j > i; j--)
			if (*(p + j) > *(p + j - 1))
			{
				int temp = *(p + j);
				*(p + j) = *(p + j - 1);
				*(p + j - 1) = temp;
			}

	printf("\n������%dλ����Ϊ��", len);
	OutputSort(p, len);

	return 0;
}