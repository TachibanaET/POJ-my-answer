#include<stdio.h>

int main(){
    int m, n, i, j;
    scanf("%d %d", &m, &n);
    char c[11][11];//文字列
    char a[10][10][10];// b[10][10];//行列
    char d[10];//命令
    for(i = 1; i <= m; i++){
        scanf("%s",c[i]);
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            a[0][i][j] = c[i][j];
        }
    }
    scanf("%s",d);
    int k = 0, l;
    for(l = 0;d[l] !=  '\0'; l++){
        m = sizeof(a[k]);
        n = sizeof(a[k][1]);
        if(d[l] == '1'){
            for(i = 1; i <= m; i++){ // m
                for(j = 1; j <= n; j++){ //n
                    a[k + 1][j][i] = a[k][i][j];
                    printf("%c\n",a[k][j][i]);
                }
            }
        }

        if(d[l] == '2'){
            for(i = 0; i < sizeof(a[k]); i++){
                for(j = 0; j < sizeof(a[k][0]); j++){
                    a[k + 1][sizeof(a[k][0])-j + 1][sizeof(a[k]-i + 1)] = a[k][i][j];
                }
            }
        }

        if(d[l] == 'H'){
            for(i = 0; i < sizeof(a[k]); i++){
                for(j = 0; j < sizeof(a[k][0]); j++){
                    a[k + 1][sizeof(a[k] - i + 1)][j] = a[k][i][j];
                }
            }
        }

        if(d[l] == 'V'){
            for(i = 0; i < sizeof(a[k]); i++){
                for(j = 0; j < sizeof(a[k][0]); j++){
                    a[k + 1][i][sizeof(a[k][0]- j + 1)] = a[k][i][j];
                }
            }
        }

        if(d[l] == 'A' || d[l] == 'Z'){
            for(i = 0; i < sizeof(a[k]); i++){
                for(j = 0; j < sizeof(a[k][0]); j++){
                    a[k + 1][j][sizeof(a[k] - i + 1)] = a[k][i][j];
                }
            }
        }

        if(d[l] == 'B' || d[l] == 'Y'){
            for(i = 0; i < sizeof(a[k]); i++){
                for(j = 0; j < sizeof(a[k][0]); j++){
                    a[k + 1][sizeof(a[k]- i + 1)][sizeof(a[k][0] -j + 1)] = a[k][i][j];
                }
            }
        }

        if(d[l] == 'C' || d[l] == 'X' ){
            for(i = 0; i < sizeof(a[k]); i++){
                for(j = 0; j < sizeof(a[k][0]); j++){
                    a[k + 1][sizeof(a[k][0] - j + 1)][i] = a[k][i][j];
                }
            }
        }

        k++;
    }
    m = sizeof(a[k + 1]);
    n = sizeof(a[k + 1][0]);
    printf("%d %d", m, n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%c",a[k + 1][i][j]);
        }
        printf("\n");
    }
    return 0;
}
