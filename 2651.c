#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n;
double t;

double f(int k){
    if(k == 0){
        return pow(2,n);
    }else{
        double fa = f(k - 1);
        double p = pow(2,(n-k)) / fa;
                    //exit         //answer
        if(t < p  && p < 1){
            double a = pow(2,(n-k)) * (p - t);
            double b = fa * (1 - p * p) / 2;
            return (1 / (1 - t)) * (a + b);
        }else{
            double a = fa * (1 - t * t) / 2;
            return (1 / (1 - t)) * a; 
        }
    }
}

int main(){
    while(scanf("%d %lf",&n, &t) && n){
        double ans = f(n);
        printf("%.3f\n",ans);
    }
    return 0;
}
