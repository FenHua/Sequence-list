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
		printf("��ѡ��Ҫ���еĲ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������һ����Ҫ�����Ԫ��:");
			scanf("%d", &x);
			Push_Back(&pSeq, x);
			break;
		case 2:
			Pop_Back(&pSeq);
			break;
		case 3:
			printf("������һ����Ҫ�����Ԫ��:");
			scanf("%d", &x);
			Push_front(&pSeq, x);
			break;
		case 4:
			Pop_front(&pSeq);
			break;
		case 5:
			printf("������һ����Ҫ�����Ԫ��:");
			scanf("%d", &x);
			printf("��������Ҫ�����λ��:");
			scanf("%d", &pos);
			Insert_SeqList(&pSeq, pos, x);
			break;
		case 6:
			printf("������һ����Ҫɾ����Ԫ��:");
			scanf("%d", &x);
			Remove_SeqList(&pSeq, x);
			break;
		case 7:
			printf("������һ����Ҫɾ����Ԫ��:");
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
			printf("������һ����Ҫ���ҵ�Ԫ��:");
			scanf("%d", &x);
			pos= Binary_Search(&pSeq, x);
			if (pos!=-1)
			{
				printf("���ҳɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
		case 0:
			break;
		default:
			printf("�����������������ѡ��\n");
			break;
		}
	}
	system("pause");//������getchar���ȴ���������
	return 0;
}