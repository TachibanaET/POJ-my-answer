#有问题
#include<stdio.h>

int main(){
    int a,i,j = 2,n = 1;
    int b[10000] = {0};
    for(i = 0;i < 10;i++){
        scanf("%d",&a);
        for(j;j <= a;j++){
            while(a % j == 0){
                a /= j;
                b[j]++;
            }
        }
    }
    for(i = 2;i < 10000;i++){
        n *= b[i] + 1;
    }
    printf("%d\n",n);
    return 0;
}
