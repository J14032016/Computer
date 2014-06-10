#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define random(x, y) {y = rand()%x;}
#define N 3
#define EPS 1e-5

double Determinant (double a[N][N], int n) { // get the determinant
    if (n == 1) return a[0][0];
    double result = 0;
    double tmp[N][N];
    int i, j, k;

    for (i=0; i<n; ++i) { // 按第一行展开
        for (j=0; j<n-1; ++j)
            for (k=0; k<n-1; ++k) // k比i大时，第i行被划去，赋值时为k+1
                tmp[j][k] = a[j+1][(k>=i)?(k+1):k]; 
        double itera = Determinant(tmp, n-1); // iteraction
        if (i%2 == 0) // 偶数行系数为正
            result += a[0][i]*itera;
        else
            result -= a[0][i]*itera;
    }
    return result;
}

void Adjoint (double a[N][N], int n, double aj[N][N]) { // get the adjoint matrix
    if (n == 1) {
        aj[0][0] = 1;
        return;
    }
    int i, j, k, t;
    double tmp[N][N];
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            for (k=0; k<n-1; ++k)
                for (t=0; t<n-1; ++t)
                    tmp[k][t] = a[k>=i?(k+1):k][t>=j?(t+1):t];
            aj[j][i] = Determinant(tmp, n-1);
            if ((i+j)%2 == 1) {
                aj[j][i] = -aj[j][i];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    double a[N][N];
    double aInv[N][N];
    int i, j;
    printf ("The original array : \n");
    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            random(100, a[i][j]);
            printf ("%lf\t",a[i][j]);
        }
        printf ("\n");
    }
    double det = Determinant(a, N);
    printf ("The determinant of matrix a is %lf\n", det);
    if (fabs(det-0) <= EPS)
        printf ("The determinant is 0! Cannot invert!\n");
    else
        Adjoint(a, N, aInv);
    
    printf ("The inverted array : \n");
    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            aInv[i][j] /= det;
            printf ("%lf\t", aInv[i][j]);
        }
        printf ("\n");
    }
    return 0;
}

