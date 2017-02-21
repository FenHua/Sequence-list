// SeqList.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"Seqlist.h"
void Init_SeqList(pSeqList pSeq)
{
	pSeq->size = 0;
	memset(pSeq->Data,0,Max*sizeof(DataType));//一段内存空间全部设置为0
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
		printf("顺序表已满\n");
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
		printf("顺序表为空\n");
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
		printf("顺序表已满\n");
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
		printf("顺序表已满\n");
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
		printf("顺序表中没有此元素\n");
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
	printf("删除成功！\n");
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
			printf("顺序表中没有此元素！\n");
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
	printf("全部删除成功！\n");
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
		// 每一次最大的上去
		if (flag == 0)
			break;
	}
}
int Binary_Search(pSeqList pSeq, DataType x)
{
	//非递归法
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