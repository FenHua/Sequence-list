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
void Push_Back(pSeqList pSeq, DataType x);//表尾插入
void Pop_Back(pSeqList pSeq);//表尾弹出
void Push_front(pSeqList pSeq, DataType x);//表头插入
void Pop_front(pSeqList pSeq);
void Insert_SeqList(pSeqList pSeq, int pos, DataType x);
void Remove_SeqList(pSeqList pSeq, DataType x);//第一次出现，删
void RemoveAll_SeqList(pSeqList pSeq, DataType x);//删除所有特定元素
void Sort_SeqList(pSeqList pSeq);
int Binary_Search(pSeqList pSeq, DataType x);

