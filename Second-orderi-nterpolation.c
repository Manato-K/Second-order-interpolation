/*Second-order-interpolation*/

#include<stdio.h>

int main(void){
    int i,j;
    float x[3],f[3][3],X,h,r,F,p;
    for(i=0;i<3;i++) {
    printf("input x%d,f%d : ",i,i);
    scanf("%f %f",&x[i],&f[0][i]);
    for(j=1;j<3;j++) f[j][i]=0.0;
    }
    for(j=1;j<3;j++)
        for(i=0;i<3-j;i++) f[j][i]=f[j-1][i+1]-f[j-1][i];
    printf("input X : ");
    scanf("%f",&X);
    h=x[1]-x[0];
    r=(X-x[0])/h;
    F=f[0][0]+r*f[1][0]+r*(r-1)*f[2][0]/2.0;
    printf("補間値 f(%f)=%f\n",X,F);
    printf("真値 f(%f)\n",h);
    printf("誤差 f(%f)\n",r);
}
/*
input x0, f0:9.0 2.197
input x1,f1 : 9.5 2.251
input x : 9.2
補間値 f(9.200000)=2.218600

input x0, f0:0.2 0.98006
input x1,f1 : 0.4 0.92106
input x : 0.28
補間値 f(0.280000)=0.956460
*/