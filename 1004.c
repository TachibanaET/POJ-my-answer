#include<stdio.h>

int main(){
    float a[12];
    int i;
    float sum = 0.00;
    for(i = 0; i < 12; i++){
        scanf("%f",&a[i]);
    }
    for(i = 0; i < 12; i++){
        sum += a[i];
    }
    printf("$%.2f\n",sum/12.0);
    return 0;
}
