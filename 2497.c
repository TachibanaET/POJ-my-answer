#include<stdio.h>

int main(){
    int i,j,k,t,s,totaltime,num,used,sum = 0,pro;
    int a[24];
    scanf("%d",&s);
    for(i = 0 ; i < s;i++){
        scanf("%d %d",&totaltime,&num);
        for(j = 0;j < num;j++){
            scanf("%d",&a[j]);
        }
        for(j = 0;j < num - 1;j++){ //sort
            for(k = j + 1; k < num;k++ ){
                if(a[j] > a[k]){
                    t = a[j];
                    a[j] = a[k];
                    a[k] = t;
                }
            }
        }
        used = 0;
        sum = 0;
        pro = 0;
        for(j = 0;j < num;j++){
            used += a[j];
            if(used > totaltime) break;
            sum += used;
            pro++;
        }
        printf("Scenario #%d:\n",i + 1);
        printf("Steve wins with %d solved problems and a score of %d.\n",pro,sum);
	putchar('\n');
    }
    return 0;
}
