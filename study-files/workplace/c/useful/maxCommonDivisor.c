/*������������ m��n �����Լ��

������
���á�շת����������ֳ�ŷ����·���
1������ m��n 
2���� n �� m ,������ r (0<=r<=n)
3:�ж����� r �Ƿ�Ϊ 0 ����Ϊ 0 ����ǰ���� n ��Ϊ���Լ��������������ִ�� 4 
4��r ��= 0 �����±������ͳ�����������Ϊԭ����������Ϊ����������ִ�� 2 
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int m, n, r, a, b;		//�����ڶ���������������շת��������㣬��Ȼ���һ��printf�������ԭ��
	
	printf("Please input two integer:");
	scanf("%u%u", &m, &n);
	
	a=m;
	b=n;
	
	do
	{
		r = a%b;
		a = b;
		b = r;
	}while(r!=0);
	
	printf("%u��%u�����Լ��Ϊ%u\n", m, n, a);
	
	system("pause");
	return 0;
}
*/
/*���淽��*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int a, b, m;
	int i=0;
	
	printf("Please input two integers:");
	scanf("%u%u", &a, &b);
	
	m=(a>b)?b:a;
	m--;
	
	do
	{
		m--;
	}while((a%m!=0)||(b%m!=0));
	
	printf("%u��%u�����Լ��Ϊ%u\n", a, b, m);
	
	system("pause");
	return 0;
}
*/

/*��չ�������������� m ��n �����Լ������С������*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int a, b, m, n;

	printf("Please input two integers:");
	scanf("%u%u",&a,&b);

	m=(a>b)?a:b;
	n=(a>b)?b:a;

	m++;
	n--;

	do 
	{
		m++;
	} while ((m%a!=0)||(m%b!=0));
	do 
	{
		n--;
	} while ((a%n!=0)||(b%n!=0));
	
	printf("%u��%u�����Լ��Ϊ%u����С������Ϊ%u!\n", a, b, n, m);

	system("pause");
	return 0;
}
*/

/*�������*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int m, n, i;

	printf("Please input two integers:");
	scanf("%u%u",&m,&n);

	for(i=m>n?m:n;!(i%m==0&&i%n==0);i++);
		printf("%u��%u����С������Ϊ��%u\n", m, n, i);

	for(i=m>n?n:m;!(m%i==0&&n%i==0);i--);
		printf("%u��%u�����Լ��Ϊ��%u\n", m, n, i);
	
	system("pause");
	return 0;
}
