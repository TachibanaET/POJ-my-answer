#include<stdio.h>
#include<string.h>


int m,n;
char a[300][300],b[300][300];//行列
char c[1000000];//命令
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void ord1(){ // 1
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[j][i] = a[i][j];
        }
    }
    swap(&m,&n);
    memcpy(a,b,sizeof(b));
}

void ord2(){ // 2
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[n-j-1][m-i-1] = a[i][j];
        }
    }
    swap(&m,&n);
    memcpy(a,b,sizeof(b));
}

void ord3(){ // H
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[m-i-1][j] = a[i][j];
        }
    }
    memcpy(a,b,sizeof(b));
}

void ord4(){ // V
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[i][n-j-1] = a[i][j];
        }
    }
    memcpy(a,b,sizeof(b));
}

void ord5(){ // A || Z
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[j][m-i-1] = a[i][j];
        }
    }
    swap(&m,&n);
    memcpy(a,b,sizeof(b));
}

void ord6(){ // B || Y
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[m-i-1][n-j-1] = a[i][j];
        }
    }
    swap(&m,&n);
    memcpy(a,b,sizeof(b));
}

void ord7(){ // C || X
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[n-j-1][i] = a[i][j];
        }
    }
    swap(&m,&n);
    memcpy(a,b,sizeof(b));
}

int main(){
    scanf("%d %d",&m, &n);
    int i,j,k = 0;
    for(i = 0;i < m;i++){
        scanf("%s",a[i]);
    }
    scanf("%s",c);

    int t[2][2];
    t[0][0] = 1; t[0][1] = 2; t[1][0] = 3; t[1][1] = 4;
    for(i = 0;i < strlen(c);i++){
        if(c[i] == '1'){
            swap(&t[0][1],&t[1][0]);
        }
        else if(c[i] == '2'){
            swap(&t[0][0],&t[1][1]);
        }
        else if(c[i] == 'H'){
            swap(&t[0][0],&t[1][0]);
            swap(&t[0][1],&t[1][1]);
        }
        else if(c[i] == 'V'){
            swap(&t[0][0],&t[0][1]);
            swap(&t[1][0],&t[1][1]);
        }
        else if(c[i]== 'A' || c[i] == 'Z'){
            swap(&t[1][1],&t[0][1]);
            swap(&t[0][0],&t[0][1]);
            swap(&t[0][0],&t[1][0]);
        }
        else if(c[i] == 'B' || c[i] == 'Y'){
            swap(&t[0][0],&t[1][1]);
            swap(&t[0][1],&t[1][0]);
        }
        else if(c[i] == 'C' || c[i] == 'X'){
            swap(&t[0][0],&t[1][0]);
            swap(&t[0][0],&t[0][1]);
            swap(&t[1][1],&t[0][1]);
        }
       /* int k,l;
        for(k = 0;k< 2;k++){
            for(l = 0;l < 2; l++){
                printf("%d",t[k][l]);
            }
            putchar('\n');
        }*/
    }
        if(t[0][0] == 1 && t[0][1] == 2 && t[1][0] == 3 && t[1][1] == 4){

        }
        else if(t[0][0] == 1 && t[0][1] == 3 && t[1][0] == 2 && t[1][1] == 4){
            ord1();
        }
        else if(t[0][0] == 4 && t[0][1] == 2 && t[1][0] == 3 && t[1][1] == 1){
            ord2();
        }
        else if(t[0][0] == 4 && t[0][1] == 3 && t[1][0] == 2 && t[1][1] == 1){
            ord2();ord1();
        }
        else if(t[0][0] == 2 && t[0][1] == 1 && t[1][0] == 4 && t[1][1] == 3){
            ord4();
        }
        else if(t[0][0] == 3 && t[0][1] == 1 && t[1][0] == 4 && t[1][1] == 2){
            ord5(); 
        }
        else if(t[0][0] == 2 && t[0][1] == 4 && t[1][0] == 1 && t[1][1] == 3){
            ord7();
        }
        else if(t[0][0] == 3 && t[0][1] == 4 && t[1][0] == 1 && t[1][1] == 2){
            ord3();
        }
    
    printf("%d %d\n",m,n);
    for(i = 0;i < m;i++){
        for(j = 0; j < n; j++){
            printf("%c",a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
