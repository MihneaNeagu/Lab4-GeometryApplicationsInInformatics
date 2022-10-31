#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

float power(float a, int b)
{
    for (int i=1;i<=b;i++)
        a=a*a;
    return a;
}
int fact(int n){
    int result = 1;
    for (int i =1; i <= n; i++){
        result = result*i;
    }
    return result;
}
int combinations(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

float Bernstein(double t, int k, int n) {
    int C;
    float B;
    if (k == 0) {
        C = 1;
    } else {
        C = combinations(n, k);
    }
    int x = n - k;
        B = C * pow(t, k) * pow((1 - t), x);
    return B;
}

void bezierCurve(int x[] , int y[], double t, int grad)
{
    double xu , yu  ;
    int i ;
    for(i=0;i<=grad;i++)
    {
        xu = xu +  Bernstein(t, i, grad) * x[i];
        yu = yu +  Bernstein(t, i, grad) * y[i];
    }
    printf("X: %i   Y: %i \n" , xu , yu) ;
}
void derivataBezier(int x[], int y[], double t, int grad)
{
    double xd ;
    int i ;
    for(i=0;i<=grad;i++)
    {
        xd = xd+ Bernstein(t, i, grad-1) * (y[i]-x[i]);
    }
    printf("XD: %i  " , xd ) ;
}
int main() {
    int grad;
    int x[4];
    int y[4];
    double t;
    cout<<"Dati gradul curbei: ";
        cin>>grad;
    cout<<"Dati coordonatele punctului de control 1(in spatiu): ";
    for(int i =0;i<4;i++)
        cin>>x[i];
    cout<<"Dati coordonatele punctului de control 2(in spatiu): ";
    for(int i =0;i<4;i++)
        cin>>y[i];
    cout<<"Dati t(valori intre 0 si 1):";
    cin>>t;
    //int x[] = {0,75,50,300};
    //int y[] = {0,2,140,100};
    bezierCurve(x,y,t,grad);
    cout<<'\n';
    derivataBezier(x,y,t,grad);

    return 0;
}