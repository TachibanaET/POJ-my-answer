#include<stdio.h>

int main(){
    double f[10],r[10];
    double ans[100];
    int i,j,k,n,m; // n = f, m = r
    double max;
    scanf("%d",&n);
    while(n){
        scanf(" %d",&m);
        for(i = 0;i < n;i++){
            scanf("%lf",&f[i]);
        }
        for(i = 0;i < m;i++){
            scanf("%lf",&r[i]);
        }
        k = 0;
        for(i = 0;i < n;i++){
            for(j = 0;j < m;j++){
                ans[k++] = r[j] / f[i];
                //printf("ans = %lf  k = %d\n",ans[k],k);
            }
        }
        float temp;
        for(i = 0;i < k - 1; i++){ // sort
            for(j = i + 1;j < k; j++ ){
                if(ans[i]> ans[j]){
                    temp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = temp;
                }
            }
        }
        max = 0.0;
        for(i = 0;i < k - 1;i++){
            if(max < (ans[i+1] / ans[i])){
                max = ans[i+1] / ans[i];
                //printf("%f\n",max);
            }
        }
        int t = (int)(max * 1000) % 100 % 10; //なくでもaccepted
        if(t > 4){
            max = (float)((int)(max * 100) + 1) / 100;
        }else{
            max = (float)((int)(max * 100)) / 100;
        }
        printf("%.2f\n",max);
        scanf("%d",&n);
    }
    return 0;
}
