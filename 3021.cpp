# MLE  bfs搜索

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;

int map[301][301]; // S: 0 - 300
int u[41],v[41]; // m: 0 - 40
int m,n,s;
int used[301][301] = {0};

struct point{
  int x,y,step;
};

void route(){
  queue<point>  q;
  point now, temp;
  now.x = 0;
  now.y = 0;
  now.step = 0;
  used[0][0] = 1;
  q.push(now);
  while(!q.empty()){
    now = q.front();
    q.pop();
    //printf("%d %d----\n",now.x,now.y);
    if(sqrt(now.x * now.x + now.y * now.y) == s){
      printf("%d\n",now.step);
      return;
    }
    int i;
    for(i = 0; i < m; i++){
      int tpx = now.x + u[i];
      int tpy = now.y + v[i];
      if(sqrt(tpx * tpx + tpy * tpy) <= s && used[tpx][tpy] == 0){
        used[tpx][tpy] == 1;
        temp.x = tpx;
        temp.y = tpy;
        temp.step = now.step + 1;
        q.push(temp);
      }
    }
  }
  printf("not possible\n");
}

int main(){
  scanf("%d",&n);
  int i;
  while(n--){
    scanf("%d %d", &m, &s);
    for(i = 0;i < m;i++){
      scanf("%d %d", &u[i], &v[i]);
    }
    route();
  }
}
