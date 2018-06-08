#include<stdio.h>
int rad(int n){
    return (n % 40 * 9);
}
int main(){
    int a[4];
    int sum;
    while(1){
      scanf("%d %d %d %d", &a[0], &a[1], &a[2],&a[3]);
      if(a[0]== 0 && a[1] == 0 && a[2] == 0 && a[3] == 0){
	break;
      }
      sum = 720; // clockwise 2full turn
      sum += rad(a[0]-a[1]+ 40); // first number
      sum += 360; // counter-clockwise 1full turn
      sum += rad(40-(a[1]-a[2])); // 2nd number
      sum += rad(a[2]-a[3]+ 40);// 3rd number
      printf("%d\n",sum);
    }
    return 0;
}
