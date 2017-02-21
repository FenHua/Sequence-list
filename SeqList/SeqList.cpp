// SeqList.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include"Seqlist.h"
void Init_SeqList(pSeqList pSeq)
{
	pSeq->size = 0;
	memset(pSeq->Data,0,Max*sizeof(DataType));//һ���ڴ�ռ�ȫ������Ϊ0
}
void Print_SeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d", pSeq->Data[i]);
	}
	printf("\n");
}
void Push_Back(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == Max)
	{
		printf("˳�������\n");
		return;
	}
	pSeq->Data[pSeq->size] = x;
	pSeq->size++;
}
void Pop_Back(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	pSeq->size--;
}
void Push_front(pSeqList pSeq, DataType x)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == Max)
	{
		printf("˳�������\n");
		return;
	}
	for (i = pSeq->size; i >= 0; i--)
	{
		pSeq->Data[i + 1] = pSeq->Data[i];
	}
	pSeq->Data[0] = x;
	pSeq->size++;
}
void Pop_front(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		pSeq->Data[i] = pSeq->Data[i + 1];
	}
	pSeq->size--;
}
void Insert_SeqList(pSeqList pSeq, int pos, DataType x)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == Max)
	{
		printf("˳�������\n");
		return;
	}
	for (i = pSeq->size - 1; i >= pos; i--)
	{
		pSeq->Data[i + 1] = pSeq->Data[i];
	}
	pSeq->Data[pos] = x;
	pSeq->size++;
}
void Remove_SeqList(pSeqList pSeq, DataType x)
{
	int i = 0;
	int first_position = 0;
	first_position = Binary_Search(pSeq, x);
	assert(pSeq);
	if (first_position == -1)
	{
		printf("˳�����û�д�Ԫ��\n");
		return;
	}
	else
	{
		for (i = first_position; i < pSeq->size; i++)
		{
			pSeq->Data[i] = pSeq->Data[i + 1];
		}
	}
	pSeq->size--;
	printf("ɾ���ɹ���\n");
}
int Find_position(pSeqList pSeq, DataType x)
{
	int i = 0;
	for (int i = 0; i < pSeq->size; i++)
	{
		if (pSeq->Data[i] == x)
		{
			return i;
		}
		return -1;
	}
}
void RemoveAll_SeqList(pSeqList pSeq, DataType x)
{
	int i = 0;
	int j = 0;
	int pos=0;
	assert(pSeq);
	while (pos < pSeq->size)
	{
		pos = Find_position(pSeq, x);
		if (pos == -1)
		{
			printf("˳�����û�д�Ԫ�أ�\n");
			return;
		}
		else
		{
			for (i = pos; i < pSeq->size; i++)
			{
				pSeq->Data[i] = pSeq->Data[i + 1];
			}
		}
		pSeq->size--;
		pos++;
	}
	printf("ȫ��ɾ���ɹ���\n");
}
void Sort_SeqList(pSeqList pSeq)
{
	//bubble sorting
	int i = 0, j = 0, flag = 0;
	DataType tmp = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < pSeq->size - 1 - i; j++)
		{
			if (pSeq->Data[j]>pSeq->Data[j + 1])
			{
				tmp = pSeq->Data[j];
				pSeq->Data[j] = pSeq->Data[j + 1];
				pSeq->Data[j + 1] = tmp;
				flag = 1;
			}
		}
		// ÿһ��������ȥ
		if (flag == 0)
			break;
	}
}
int Binary_Search(pSeqList pSeq, DataType x)
{
	//�ǵݹ鷨
	int left = 0, mid = 0;
	int right = pSeq->size - 1;
	assert(pSeq);
	Sort_SeqList(pSeq);
	while (left<right)
	{
		mid = (left + right) / 2;
		if (pSeq->Data[mid] < x)
		{
			left = mid;
		}
		else if (pSeq->Data[mid]>x)
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}