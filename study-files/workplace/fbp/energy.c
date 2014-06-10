#include "stdio.h"
#include "stdlib.h"

#define GET_ARRAY_LEN(array,len){len=(sizeof(array)/sizeof(array[0]));}
#define N 25

void polarValue(float *a, int len, float *max, float *min);
void findPeaks(int *a, int len,float *peaks, int pks_len);
void smooth (int *a, int len, int *b);

int main(int argc, char *argv[])
{
    FILE *fp = fopen("Th232_11_MVT_energy_corrected.txt", "r");
    float energy[160000] = {0.0};
    float energy_valid[160000] = {0.0};
    int i = 0, j = 0;
    while (!feof(fp))
        fscanf(fp,"%f", &energy[i++]);
    int engLen = i;

    printf ("energy 3 is %f\n\n",energy[3]); // energy read in test
    
    for (i=0; i<engLen; ++i) // transfrom the data 
        energy[i] = energy[i]*661.5/1.25e6;
    for (i=0; i<engLen; ++i) // take out the infinite value
        if (energy[i] < 3000)
            energy_valid[j++] = energy[i];
    j--; // get the size of the data
    printf ("The size of the data is %d\n\n",j); // data size test
    printf ("energy_valid test 30 : %f\n\n",energy_valid[30]);
    
    float max,min;
    polarValue(energy_valid,j,&max,&min); // get the polar value
    int xSize = (int)(max-min); // set the x axis value
    int *img; // set the y axis and initialize
    img = (int*)malloc(sizeof(int)*xSize);
    for (i=0;i<xSize;++i)
        img[i] = 0;

    for (i=0;i<j;++i) {
        int tmp = (int)(energy_valid[i]-min);
        img[tmp]++;
    }
    printf ("img test from 1 to 10 \n"); // test
    for (i=0;i<10;++i) 
        printf ("%d\t",img[i+100]);

    float peaks[50] = {0};
    findPeaks(img, xSize, peaks, 50);
    for (i=0; i<50; ++i)
        peaks[i] += min;

    printf ("\n\nThe peaks is : \n"); // test 
    for (i=0;i<50;++i) 
        printf ("%f\n",peaks[i]);

    // do the smooth
    int *iSmooth;
    iSmooth = (int*)malloc(sizeof(int)*xSize);
    smooth(img, xSize, iSmooth);

    printf ("\n\nSmooth test from 110 to 120\n");
    for (i=110;i<120;++i) // test
        printf ("%d\t",iSmooth[i]);
    float pksSmooth[50] = {0};
    findPeaks(iSmooth, xSize, pksSmooth, 50);
    for (i=0; i<50; ++i)
        pksSmooth[i] += min;
    printf ("\n\nThe smooth peaks is : \n"); // test
    for (i=0;i<50;++i) 
        printf ("%f\n",pksSmooth[i]);
    
    return 0;
}

void polarValue(float *a, int len, float *max, float *min) {
    int i=0;
    *max = *min = a[0];
    for (i=0; i<len; ++i)
        if (a[i]>*max) *max = a[i];
    for (i=0; i<len; ++i)
        if (a[i]<*min) *min = a[i];
}

void findPeaks(int *a, int len, float *peaks, int pks_len) {
    int setSize = 50;
    int x, y, z;
    int peaks_size = 0;
    for (x=10; x<len-10; ++x) {
        float tmp[21] = {0};
        z = 0;
        for (y=x-10; y<x+11; ++y) tmp[z++] = a[y];
        float max,min;
        polarValue(tmp,21,&max,&min);

        for (y=x-10; y<x+10; ++y) 
            if ((max==a[x]) && (max>=setSize)) {
                peaks[peaks_size++] = x;
                break;
            }
    }
}

void smooth (int *a, int len, int *b) {
    int i, j;
    for (i=0; i<(N-1)/2; ++i) b[i] = a[i];
    for (i=(N-1)/2; i<len-(N-1)/2; ++i) {
        for (j=i-(N-1)/2; j<i+(N+1)/2; ++j) b[i] += a[j];
        b[i] /= N;
    }
    for (i=len-(N-1)/2; i<len; ++i) b[i] = a[i];
}
