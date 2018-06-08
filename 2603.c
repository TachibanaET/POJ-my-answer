//memory:360K	time:16MS
#include<stdio.h>
int main(){
  int i,j,k,n = 1; // innshi
  int a[10000]= {0};
  for(i = 0;i < 10; i++){
    scanf("%d",&k);
    for(j = 2;j <= k;j++){
      while(k % j == 0){	
	a[j] += 1;
	k /= j;
	//printf("a[%d] = %d\n",j,a[j]);
      }
      if(k == 1) break;
    }
  }
  for(i = 0;i < 10000;i++){
    //if(a[i]!= 0) printf("a[%d] = %d\n",i,a[i]);
    n *= a[i] + 1;
  } 
  printf("%d\n", n % 10);
  return 0;
}
