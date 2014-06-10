/*实验1（线性表）：以链式存储结构实现一个线性表的抽
象数据类型，并实现线性表的初始化、查找、插入、删除
和就地逆置等操作，要求具有较好的人机交互处理过程*/
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

// this is what has already been defined by default
typedef bool Status;
#define OK 1
#define ERROR 0

// this is what should be defined by user !
typedef int ElemType;

typedef struct LNode { //单链表存储结构表示
	ElemType data;
	struct LNode * next;
} LNode, * LinkList;

Status ListCreate_L (LinkList &L, int n);// 初始化
Status ListSearch_L (LinkList &L, int &i, ElemType e); // 查找
Status ListInsert_L (LinkList &L, int i, ElemType e);// 插入
Status ListDelete_L (LinkList &L, int i, ElemType &e);//删除
Status ListReverse_L (LinkList &L);//就地逆置
Status ListTraverse_L (LinkList L); // 遍历

#endif
