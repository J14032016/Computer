/*  mrqmin.c  
  
    This is a roughly self-contained code module for  
    Levenberg-Marquardt gradient descent iterative minimization  
    of a nonlinear function.  
    This started with the Numerical Recipes in C code, but uses the  
    double data type defined in matmath.h throught in place of floats.  
  
    Parts of this code Copr. 1986-92 Numerical Recipes Software 2.1.9-153.  
  
    J. Watlington, 12/8/95  
  
    Modified:  
*/   
   
#include <stdio.h>   
#include <stdlib.h>   
#include <math.h>   
#include "Vector.h"   
#include "Matrix.h"   
//using namespace std;   
   
//#include "matmath.h"   
   
/*  Prototypes of internal functions   */   
   
void mrqcof(double x[], double y[], double sig[], int ndata, CVector a,   
            int ia[], int ma, CMatrix alpha, CVector beta, double *chisq,   
            void (*funcs)(double, double [], double *, double [], int));   
void covsrt(CMatrix covar, int ma, int ia[], int mfit);   
   
   
/*  mrqmin  
    This is THE function.  If called with a negative alamda, it initializes.  
    It should be called repeatedly without modifying alamda until it converges.  
    Then it may be called one final time with alamda set to zero to obtain the  
    final covariances.  
  
    See NR in C, pp. 683 - 688 for real documentation, and don't forget to  
    read the note about multi-dimensional use on p. 680.  
*/   
   
void mrqmin( double x[], double y[], double sig[], int ndata, CVector a,   
             int ia[], int ma, CMatrix covar, CMatrix alpha, double *chisq,   
             void (*funcs)(double, double [], double *, double [], int),   
             double *alamda)   
{   
    int j,k,l,m;   
    static int mfit;   
    static double ochisq;   
    CMatrix oneda;   
    CVector atry,beta,da;   
   
    if (*alamda < 0.0) {   
        atry=CVector(1,ma);   
        beta=CVector(1,ma);   
        da=CVector(1,ma);   
        for (mfit=0,j=1;j<=ma;j++)   
            if (ia[j]) mfit++;   
        oneda=CMatrix(1,mfit);   
        *alamda=0.001;   
        mrqcof(x,y,sig,ndata,a,ia,ma,alpha,beta,chisq,funcs);   
        ochisq=(*chisq);   
        for (j=1;j<=ma;j++) atry[j]=a[j];   
    }   
    for (j=0,l=1;l<=ma;l++) {   
        if (ia[l]) {   
            for (j++,k=0,m=1;m<=ma;m++) {   
                if (ia[m]) {   
                    k++;   
                    covar[j][k]=alpha[j][k];   
                }   
            }   
            covar[j][j]=alpha[j][j]*(1.0+(*alamda));   
            oneda[j][1]=beta[j];   
        }   
    }   
    covar.ColMax();   
    for (j=1;j<=mfit;j++) da[j]=oneda[j][1];   
    if (*alamda == 0.0) {   
        covsrt(covar,ma,ia,mfit);   
        return;   
    }   
    for (j=0,l=1;l<=ma;l++)   
        if (ia[l]) atry[l]=a[l]+da[++j];   
    mrqcof(x,y,sig,ndata,atry,ia,ma,covar,da,chisq,funcs);   
    if (*chisq < ochisq) {   
        *alamda *= 0.1;   
        ochisq=(*chisq);   
        for (j=0,l=1;l<=ma;l++) {   
            if (ia[l]) {   
                for (j++,k=0,m=1;m<=ma;m++) {   
                    if (ia[m]) {   
                        k++;   
                        alpha[j][k]=covar[j][k];   
                    }   
                }   
                beta[j]=da[j];   
                a[l]=atry[l];   
            }   
        }   
    } else {   
        *alamda *= 10.0;   
        *chisq=ochisq;   
    }   
}   
   
/*   mrqcof  
     Used by mrqmin to evaluate the linearized fitting matrix (alpha) and  
     vector( beta) and calculate chi squared.  
*/   
void mrqcof(double x[], double y[], double sig[], int ndata, CVector a,   
            int ia[], int ma, CMatrix alpha, CVector beta, double *chisq,   
            void (*funcs)(double, CVector, double *, CVector, int))   
{   
    int i,j,k,l,m,mfit=0;   
    double ymod,wt,sig2i,dy;   
    CVector dyda;   
   
    dyda=CVector(1,ma);   
    for (j=1;j<=ma;j++)   
        if (ia[j]) mfit++;   
    for (j=1;j<=mfit;j++) {   
        for (k=1;k<=j;k++) alpha[j][k]=0.0;   
        beta[j]=0.0;   
    }   
    *chisq=0.0;   
    for (i=1;i<=ndata;i++) {   
        (*funcs)(x[i],a,&ymod,dyda,ma);   
        sig2i=1.0/(sig[i]*sig[i]);   
        dy=y[i]-ymod;   
        for (j=0,l=1;l<=ma;l++) {   
            if (ia[l]) {   
                wt=dyda[l]*sig2i;   
                for (j++,k=0,m=1;m<=l;m++)   
                    if (ia[m]) alpha[j][++k] += wt*dyda[m];   
                beta[j] += dy*wt;   
            }   
        }   
        *chisq += dy*dy*sig2i;   
    }   
    for (j=2;j<=mfit;j++)   
        for (k=1;k<j;k++) alpha[k][j]=alpha[j][k];   
}   
   
/*  covsrt  
    This function expands and contracts the covariance matrix  
    to account for the fact that there may be components of the  
    state which we may hold constant and not optimize.  
*/   
#define SWAP(a,b) {swap=(a);(a)=(b);(b)=swap;}   
   
void covsrt(CMatrix covar, int ma, int ia[], int mfit)   
{   
    int i,j,k;   
    double swap;   
   
    for (i=mfit+1;i<=ma;i++)   
        for (j=1;j<=i;j++) covar[i][j]=covar[j][i]=0.0;   
    k=mfit;   
    for (j=ma;j>=1;j--) {   
        if (ia[j]) {   
            for (i=1;i<=ma;i++) SWAP(covar[i][k],covar[i][j])   
                                    for (i=1;i<=ma;i++) SWAP(covar[k][i],covar[j][i])   
                                                            k--;   
        }   
    }   
}   
   
#undef SWAP   
