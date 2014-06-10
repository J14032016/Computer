/*求两个正整数 m，n 的最大公约数

分析：
采用“辗转相除法”（又称欧几里德法）
1：输入 m，n 
2：以 n 除 m ,得余数 r (0<=r<=n)
3:判断余数 r 是否为 0 ，若为 0 ，当前除数 n 即为最大公约数，结束。否者执行 4 
4：r ！= 0 ，更新被除数和除数（被除数为原除数，除数为余数），在执行 2 
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int m, n, r, a, b;		//另外在定义两个数来参与辗转相除法运算，不然最后一个printf不能输出原数
	
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
	
	printf("%u和%u的最大公约数为%u\n", m, n, a);
	
	system("pause");
	return 0;
}
*/
/*常规方法*/
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
	
	printf("%u和%u的最大公约数为%u\n", a, b, m);
	
	system("pause");
	return 0;
}
*/

/*扩展：求两个正整数 m ，n 的最大公约数和最小公倍数*/
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
	
	printf("%u和%u的最大公约数为%u，最小公倍数为%u!\n", a, b, n, m);

	system("pause");
	return 0;
}
*/

/*最佳做法*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int m, n, i;

	printf("Please input two integers:");
	scanf("%u%u",&m,&n);

	for(i=m>n?m:n;!(i%m==0&&i%n==0);i++);
		printf("%u和%u的最小公倍数为：%u\n", m, n, i);

	for(i=m>n?n:m;!(m%i==0&&n%i==0);i--);
		printf("%u和%u的最大公约数为：%u\n", m, n, i);
	
	system("pause");
	return 0;
}
