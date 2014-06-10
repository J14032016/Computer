#include "Linear_List.h"
#include <stdio.h>

int main()
{
	LinkList L;
	int i = 0, e = 0, op_select = 0, L_length;
	printf("请先创造一个线性表!\n");
	printf("请输入链表长度：");
	scanf("%d", &L_length);
	/*if(L_length<1){
		printf("请输入有效参数！\n");
		return ERROR;
	}*/
	fflush(stdin);
	ListCreate_L(L, L_length);// 创建一个链表，反向输入
	printf("链表为：");
	ListTraverse_L(L);

	printf("\n操作 1:查找  2:插入  3:删除  4:就地逆置\n");
	while (1) {
		printf("\n请输入你要选择的操作:");
		fflush(stdin);
		scanf("%d", &op_select);
		switch (op_select)
		{
		case 1:
			printf("请输入要查找的元素值：");
			scanf("%d", &e);
			ListSearch_L(L, i, e);
			break;
		case 2:
			printf("请输入你想插入的元素:");
			scanf("%d", &e);
			printf("请输入你想插入的地方:");
			scanf("%d", &i);
			ListInsert_L(L, i, e);
			printf("现在链表为：");
			ListTraverse_L(L);
			break;
		case 3:
			printf("请输入你想要删除的地方 :");
			scanf("%d", &i);
			if (ListDelete_L(L, i, e)) // 函数返回1则为正常结束，完成删除操作
				printf("删除的元素是 %d\n", e);
			else // 否则就是非法操作
				printf("ERROR ! 请输入有效参数!\n");
			printf("现在链表为：");
			ListTraverse_L(L);
			break;
		case 4:
			ListReverse_L(L);
			printf("现在链表为：");
			ListTraverse_L(L);
			break;
		default:
			printf("请输入有效参数!\n"); // 未输入1~4则为非法操作
			break;
		}
	}
	return 0;
}
