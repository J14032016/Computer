#include "Linear_List.h"
#include <stdio.h>

int main()
{
	LinkList L;
	int i = 0, e = 0, op_select = 0, L_length;
	printf("���ȴ���һ�����Ա�!\n");
	printf("�����������ȣ�");
	scanf("%d", &L_length);
	/*if(L_length<1){
		printf("��������Ч������\n");
		return ERROR;
	}*/
	fflush(stdin);
	ListCreate_L(L, L_length);// ����һ��������������
	printf("����Ϊ��");
	ListTraverse_L(L);

	printf("\n���� 1:����  2:����  3:ɾ��  4:�͵�����\n");
	while (1) {
		printf("\n��������Ҫѡ��Ĳ���:");
		fflush(stdin);
		scanf("%d", &op_select);
		switch (op_select)
		{
		case 1:
			printf("������Ҫ���ҵ�Ԫ��ֵ��");
			scanf("%d", &e);
			ListSearch_L(L, i, e);
			break;
		case 2:
			printf("��������������Ԫ��:");
			scanf("%d", &e);
			printf("�������������ĵط�:");
			scanf("%d", &i);
			ListInsert_L(L, i, e);
			printf("��������Ϊ��");
			ListTraverse_L(L);
			break;
		case 3:
			printf("����������Ҫɾ���ĵط� :");
			scanf("%d", &i);
			if (ListDelete_L(L, i, e)) // ��������1��Ϊ�������������ɾ������
				printf("ɾ����Ԫ���� %d\n", e);
			else // ������ǷǷ�����
				printf("ERROR ! ��������Ч����!\n");
			printf("��������Ϊ��");
			ListTraverse_L(L);
			break;
		case 4:
			ListReverse_L(L);
			printf("��������Ϊ��");
			ListTraverse_L(L);
			break;
		default:
			printf("��������Ч����!\n"); // δ����1~4��Ϊ�Ƿ�����
			break;
		}
	}
	return 0;
}
