/*ʵ��1�����Ա�������ʽ�洢�ṹʵ��һ�����Ա�ĳ�
���������ͣ���ʵ�����Ա�ĳ�ʼ�������ҡ����롢ɾ��
�;͵����õȲ�����Ҫ����нϺõ��˻������������*/
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

// this is what has already been defined by default
typedef bool Status;
#define OK 1
#define ERROR 0

// this is what should be defined by user !
typedef int ElemType;

typedef struct LNode { //������洢�ṹ��ʾ
	ElemType data;
	struct LNode * next;
} LNode, * LinkList;

Status ListCreate_L (LinkList &L, int n);// ��ʼ��
Status ListSearch_L (LinkList &L, int &i, ElemType e); // ����
Status ListInsert_L (LinkList &L, int i, ElemType e);// ����
Status ListDelete_L (LinkList &L, int i, ElemType &e);//ɾ��
Status ListReverse_L (LinkList &L);//�͵�����
Status ListTraverse_L (LinkList L); // ����

#endif
