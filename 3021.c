#include<stdio.h>
#define MAX 100000
#define min(a,b) ((a <  b ) ? a : b )
int main(){
    int n,m,s;
    int i,j,k;
    int dp[301][301];
    int a[41],b[41];
    scanf("%d",&n);
    while(n--){
        scanf("%d %d", &m, &s);
        for(i = 0; i< m; i++){
            scanf("%d %d", &a[i], &b[i]);
        }
        for(i = 0; i <= s; i++){
            for(j = 0; j <= s; j++){
                dp[i][j] = MAX;
            }
        }
        dp[0][0] = 0;
        for(i = 0; i <= s;i++){
            for(j = 0; j <= s;j++){
                for(k = 0; k < m;k++){
                    if(i >= a[k] && j >= b[k]){
                        dp[i][j] = min(dp[i][j],dp[i-a[k]][j-b[k]]+ 1);
                       //printf("%d\n",dp[i][j]);
                    }
                }
            }
        }
        int ans = MAX;
        for(i = 0;i <= s;i++){
            for(j = 0; j <= s; j++){
                if(i * i + j * j == s * s){
                    ans = min(dp[i][j],ans);
                }
            }
        }
        if(ans == MAX){
            printf("not possible\n");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
