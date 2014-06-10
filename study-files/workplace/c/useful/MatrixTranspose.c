#include "stdio.h"
#include "math.h"

#define random(x, y) {y=rand()%x;} // get arbitrary number during 0 and 100
#define M 3
#define N 4

void Transpose (int a[M][N], int b[N][M]) {
    int i, j;
    for (i=0; i<N; ++i)
        for (j=0; j<M; ++j)
            b[i][j] = a[j][i];
}

int main(int argc, char *argv[])
{
    int a[M][N];
    int b[N][M];
    int i, j;
    
    printf ("The original array : \n");
    for (i=0; i<M; ++i) {
        for (j=0; j<N; ++j) {
            random(100,a[i][j]);
            printf ("%d\t", a[i][j]);
        }
        printf("\n");
    }
    Transpose(a, b);
    printf ("The transposed array : \n");
    for (i=0; i<N; ++i) {
        for (j=0; j<M; ++j)
            printf ("%d\t", b[i][j]);
        printf ("\n");
    }
    
    return 0;
}
