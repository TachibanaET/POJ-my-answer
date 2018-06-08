#include<stdio.h>
int main(){
  int i,j = 2,k,n = 1; // innshi
  int a[10000]= {0};
  int b[10];
  for(i = 0;i < 10;i++){
    scanf("%d",&b[i]);
  }
  for(i = 0;i < 10; i++){
    for(j;j <= b[i];j++){
      while(b[i] % j == 0){	
	    a[j] += 1;
	    b[i] /= j;
	    printf("a[%d] = %d\n",j,a[j]);
      }
      if(b[i] == 1) break;
    }
  }
  for(i = 0;i < 10000;i++){
    if(a[i]!= 0) printf("a[%d] = %d\n",i,a[i]);
    n *= a[i] + 1;
  } 
  printf("%d\n", n);
  return 0;
}
