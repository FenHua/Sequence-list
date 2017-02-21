#include "stdafx.h"
#include"Seqlist.h"
void menu()
{
	printf("*****0.exit****1.Push_Back****2.Pop_Back***********\n");
	printf("*****3.Push_front*************4.Pop_front**********\n");
	printf("*****5.Insert_SeqList**********6.Remove_SeqList*****\n");
	printf("*****7.RemoveAll_SeqList*****8.Sort_SeqList*******\n");
	printf("*****9.Print_SeqList***********10. Binary_Search****\n");
}
int main()
{
	int x = 0, input = 1, pos = 0;
	SeqList pSeq;
	Init_SeqList(&pSeq);
	while (input)
	{
		menu();
		printf("请选择要进行的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入一个你要插入的元素:");
			scanf("%d", &x);
			Push_Back(&pSeq, x);
			break;
		case 2:
			Pop_Back(&pSeq);
			break;
		case 3:
			printf("请输入一个你要插入的元素:");
			scanf("%d", &x);
			Push_front(&pSeq, x);
			break;
		case 4:
			Pop_front(&pSeq);
			break;
		case 5:
			printf("请输入一个你要插入的元素:");
			scanf("%d", &x);
			printf("请输入你要插入的位置:");
			scanf("%d", &pos);
			Insert_SeqList(&pSeq, pos, x);
			break;
		case 6:
			printf("请输入一个你要删除的元素:");
			scanf("%d", &x);
			Remove_SeqList(&pSeq, x);
			break;
		case 7:
			printf("请输入一个你要删除的元素:");
			scanf("%d", &x);
			RemoveAll_SeqList(&pSeq, x);
			break;
		case 8:
			Sort_SeqList(&pSeq);
			break;
		case 9:
			Print_SeqList(&pSeq);
			break;
		case 10:
			printf("请输入一个你要查找的元素:");
			scanf("%d", &x);
			pos= Binary_Search(&pSeq, x);
			if (pos!=-1)
			{
				printf("查找成功\n");
			}
			else
			{
				printf("查找失败\n");
			}
		case 0:
			break;
		default:
			printf("您的输入错误请重新选择\n");
			break;
		}
	}
	system("pause");//类似于getchar，等待按键结束
	return 0;
}