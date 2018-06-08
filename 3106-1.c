#include<stdio.h>
#include<string.h>


int m,n;
char a[300][300],b[300][300];//行列
char c[1000000],d[1000000];//命令
void H();
void V();
void A();
void B():

void H(){
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[m-i-1][j] = a[i][j];
        }
    }
    memcpy(a,b,sizeof(b));
}

void V(){
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[i][n-j-1] = a[i][j];
        }
    }
    memcpy(a,b,sizeof(b));
}

void A(){
    int i,j,temp;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[j][m-i-1] = a[i][j];
        }
    }
    temp = m; m = n; n = temp;
    memcpy(a,b,sizeof(b));
}
void A(){
    int i,j,temp;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[j][m-i-1] = a[i][j];
        }
    }
    temp = m; m = n; n = temp;
    memcpy(a,b,sizeof(b));
}

int main(){
    scanf("%d %d",&m, &n);
    int i,j,k = 0;
    for(i = 0;i < m;i++){
        scanf("%s",a[i]);
    }
    scanf("%s",c);
    for(i = 0;i < strlen(c);i++){
        if(c[i] == '1'){
            d[k] = 'A'; d[k + 1] = 'V'; k+= 2;
        }
        else if(c[i] == '2'){
            d[k + 2] = d[k + 1] = d[k] = 'A';
            d[k + 3] = 'V'; k += 4;
        }
        else if(c[i] == 'A' || c[i] == 'Z'){
            d[k] = 'A'; k++;
        }
        else if(c[i] == 'B' || c[i] == 'Y'){
            d[k + 1] = d[k] = 'A'; k += 2; 
        }
        else if(c[i] == 'C' || c[i] == 'X'){
            d[k + 2] = d[k + 1] = d[k] = 'A'; k += 3;
        }
        else{
            d[k] = c[i]; k++;
        }
    }
    /*for(i = 0;i < strlen(d);i++){
        printf("%c",d[i]);
    }
    putchar('\n');*/
    for(k = 0;k < strlen(d);k++){
        if(d[k] == d[k + 1] && d[k] != 'A'){
            k += 2;
        }
        else if(d[k] == d[k + 1] && d[k + 1] == d[k + 2] && d[k + 2] == d[k + 3] && d[k] == 'A'){
            k += 4;
        }

        if(d[k] == 'H'){ 
             H();
        }
        else if(d[k] == 'V'){
             V();
        }
        else if(d[k] == 'A'){
             A();
        }
        printf("k = %d\n",k);
    }
    printf("%d %d\n",m,n);
    for(i = 0;i < m;i++){
        for(j = 0;j < n; j++){
            printf("%c",a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
