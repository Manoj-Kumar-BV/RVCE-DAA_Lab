#include<stdio.h>
#include<stdlib.h>
#define INF 999

void dijkstra(int cost[10][10], int n, int source, int v[10], int d[10]){
  int i,j,u,min;
  for(i=1;i<=n;i++){
    min = INF;
    for(j=1;j<=n;j++){
      if(v[j] == 0 && d[j] < min){
        min = d[j];
        u = j;
      }
    }
    v[u] = 1;
    for(j=1;j<=n;j++){
      if(v[j] == 0 && (d[j] > (d[u] + cost[u][j])))
        d[j] = d[u] + cost[u][j];
    }
  }
}

int main(){
  int cost[10][10], n,sourceNode,v[10],d[10];
  int i,j;
  printf("\n Enter the no. of nodes : \n");
  scanf("%d",&n);
  
  printf("\n Enter the cost adjacency matrix 999 if they are not directly connected : \n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&cost[i][j]);
    }
  }
  
  printf("\n Enter the sourcenode (1 to %d) : \n",n);
  scanf("%d",&sourceNode);
  
  for(i=1;i<=n;i++){
    d[i] = cost[sourceNode][i];
    v[i] = 0;
  }
  dijkstra(cost,n,sourceNode,v,d);
  
  printf("\n Shortest path from SourceNode %d is : \n",sourceNode);
  for(i=1;i<=n;i++)
    printf("%d --> %d = %d\n",sourceNode,i,d[i]);
  return 0;
}
