#include <stdio.h>

typedef int Status;
long factorial (int);
int Reduction (long , long);
Status Arrange ();
Status Combination ();

int main()
{
    int opt; 
  
    for( ; ; ){
        printf("please select the operation : ");
        fflush(stdin);
        scanf("%d", &opt);
        if(opt == 1)
            Arrange();
        else if(opt == 2)
            Combination();
        else if(opt == 3){
            printf("Exit successful!\n");
            break;
        }
        else{
            printf("Please input valid parameters!\n");
            getchar();
        }
	}
	return 0;
}

long Factorial (int i) {
	if (i==1 || i==0) return 1;
	else return i*Factorial(i-1);
}

Status Arrange () {
    int whole, part, i;
    long muitiply = 1;
	printf("Please input the whole and the part :");
	scanf("%d%d", &whole, &part);
	if (whole<part || whole<=0 || part<=0){
		printf("Please input valid parameters!\n");
        return -1;
	}
    for (i=whole; i>whole-part; --i)
        muitiply *= i;
	printf("A %d %d is %ld\n", whole, part, muitiply);
    return 0;
}

Status Combination() {
    int whole, part, i;
    long muitiply = 1;
    printf("Please input the whole and the part ：");
	scanf("%d%d", &whole, &part);
	if(whole<part || whole<=0 || part<=0){
		printf("Please input valid parameters!\n");
        return -1;
	}
    for (i=whole; i>whole-part; --i)
        muitiply *= i;
    int reduction = Reduction(muitiply, Factorial(part));
	printf("C %d %d is %ld/%ld\n", whole, part,
           muitiply/reduction, Factorial(part)/reduction);
    return 0;
}

int Reduction (long m, long n) {
    int i;
    for(i=m>n?n:m; !(m%i==0 && n%i==0); i--);
    if (i==m || i==n)
        return 1;
    return i;
}
