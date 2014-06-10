#include "stdio.h"
#include "math.h"

#define EPS 1e-5
#define SETSIZE 1e-2
#define PARANUM 3
#define N 9
#define PI 3.141592653

double Gauss (double a, double b, double c, double x) {
    return a*exp(-(x-b)*(x-b)/(c*c));
}

double ADerivative (double (*Gauss)(double,double,double,double),
                   double a, double b, double c, double x) {
    return ((*Gauss)(a+EPS, b, c, x)-(*Gauss)(a, b, c, x))/EPS;
}
double BDerivative (double (*Gauss)(double,double,double,double),
                   double a, double b, double c, double x) {
    return ((*Gauss)(a, b+EPS, c, x)-(*Gauss)(a, b, c, x))/EPS;
}
double CDerivative (double (*Gauss)(double,double,double,double),
                   double a, double b, double c, double x) {
    return ((*Gauss)(a, b, c+EPS, x)-(*Gauss)(a, b, c, x))/EPS;
}

double Determinant (double a[3][3], int n) { // get the determinant
    if (n == 1) return a[0][0];
    double result = 0;
    double tmp[3][3];
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
void Adjoint (double a[3][3], int n, double aj[3][3]) { //get the adjoint matrix
    int i, j, k, t;
    if (n == 1) {
        aj[0][0] = 1;
        return;
    }
    double tmp[3][3];
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

void NewtonIteration (int x0[N], double y0[N],
                      double d0[PARANUM], double dn[PARANUM], double* rsos) {
    int i, j, k;
    double Fx[N] = {0}; // get  (y-f)
    printf (" y-f  is \n");
    for (i=0; i<N; ++i) {
        Fx[i] = Gauss(d0[0], d0[1], d0[2], x0[i]) - y0[i];
        printf ("%lf\t", Fx[i]);
    }
    
    double Jacobian[PARANUM][N];  // get the jacobian A
    for (i=0; i<N; ++i) {
        Jacobian[0][i] = ADerivative(Gauss,1,1,2,x0[i]);
        Jacobian[1][i] = BDerivative(Gauss,1,1,2,x0[i]);
        Jacobian[2][i] = CDerivative(Gauss,1,1,2,x0[i]);
    }
    printf ("\n\nThe Jacobian is : \n");
    for (i=0; i<3; ++i) {
        for (j=0; j<N; ++j)
            printf ("%lf\t", Jacobian[i][j]);
        printf ("\n");
    }

    double JacobianT[N][PARANUM];  // get the transpose of jacobian
    printf ("\nThe transpose of the Jacobian is : \n");
    for (i=0; i<N; ++i) {
        for (j=0; j<PARANUM; ++j) {
            JacobianT[i][j] = Jacobian[j][i];
            printf ("%lf\t", JacobianT[i][j]);
        }
        printf ("\n");
    }

    static double tmp1[PARANUM][PARANUM]; //get jacobian multiplied by JacobianT
    printf ("\nJacobian multiplied by JacobianT is : \n");
    for (i=0; i<PARANUM; ++i) {
        for (j=0; j<PARANUM; ++j) {
            for (k=0; k<N; ++k)
                tmp1[i][j] += Jacobian[i][k]*JacobianT[k][j];
            printf ("%lf\t", tmp1[i][j]);
        }
        printf ("\n");
    }

    double det = Determinant(tmp1, PARANUM); // get the invert of above matrix
    double tmp1Inv[PARANUM][PARANUM];
    printf ("\nThe determinant of matrix tmp1 is %lf!\n", det);
    Adjoint(tmp1, PARANUM, tmp1Inv);
    printf ("\nThe inverted tmp1 : \n");
    for (i=0; i<PARANUM; ++i) {
        for (j=0; j<PARANUM; ++j) {
            tmp1Inv[i][j] /= det;
            printf ("%lf\t", tmp1Inv[i][j]);
        }
        printf ("\n");
    }

    static double tmp2[PARANUM]; // get Jacobian * (y-f)
    printf ("\n The transpose of Jacobian multiplied by  y-f  is : \n");
    for (i=0; i<PARANUM; ++i) {
        for (j=0; j<N; ++j)
            tmp2[i] += Jacobian[i][j]*Fx[j];
        printf ("%lf\t", tmp2[i]);
        printf ("\n");
    }

    // dn = inv(Jacoian*JacobianT) * Jacobian * (y-f) + d0
    printf ("\nThe next value of the parameter is :\n"); // get the final result
    for (i=0; i<PARANUM; ++i) {
        for (j=0; j<PARANUM; ++j)
            dn[i] -= tmp1Inv[i][j]*tmp2[j];
        printf ("%lf\t", dn[i]);
        printf ("\n");
    }

    double yn[N] = {0};
    *rsos = 0;
    for (i=0; i<N; ++i) {
        yn[i] = Gauss(dn[0], dn[1], dn[2], x0[i]);
        *rsos += (yn[i]-y0[i])*(yn[i]-y0[i]);
    }
}

int main(int argc, char *argv[])
{
    int x0[N]={-3, -2, -1, 0, 1, 2, 3, 4, 5};
    double y0[N]={0.0010,0.0039,0.0500,0.2419,0.3990,0.2420,0.0540,0.0040,0.0001};
    double d0[PARANUM], dn[PARANUM];
    
    int i;
    int avg = 0;
    for (i=0; i<N; ++i) avg += x0[i];
    avg /= N;
    d0[0] = y0[(avg-x0[0])]; d0[1] = avg; d0[2] = 1/(d0[0]*sqrt(PI));
    for (i=0; i<PARANUM; ++i) {
        dn[i] = d0[i];
        printf ("%lf\t", d0[i]);
    }
    int iteTime = 0;
    for (iteTime=0; iteTime<10; iteTime++) {
        printf ("\n\nThe %d iteration start : \n\n",iteTime+1);
        double rsos = 0;
        for (i=0; i<PARANUM; ++i) d0[i] = dn[i];
        //        for (i=0; i<PARANUM; ++i) dn[i] = d0[i];
        NewtonIteration(x0, y0, d0, dn, &rsos);
        printf ("\n\nresidual sum of squares is %lf\n", rsos);
    }

    return 0;
}
