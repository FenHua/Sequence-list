#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define Max 100
typedef int DataType;
typedef struct SeqList
{
	DataType Data[Max];
	int size;
}SeqList,*pSeqList;
void Print_SeqList(pSeqList pSeq);
void Init_SeqList(pSeqList pSeq);
void Push_Back(pSeqList pSeq, DataType x);//��β����
void Pop_Back(pSeqList pSeq);//��β����
void Push_front(pSeqList pSeq, DataType x);//��ͷ����
void Pop_front(pSeqList pSeq);
void Insert_SeqList(pSeqList pSeq, int pos, DataType x);
void Remove_SeqList(pSeqList pSeq, DataType x);//��һ�γ��֣�ɾ
void RemoveAll_SeqList(pSeqList pSeq, DataType x);//ɾ�������ض�Ԫ��
void Sort_SeqList(pSeqList pSeq);
int Binary_Search(pSeqList pSeq, DataType x);

