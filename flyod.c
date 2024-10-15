#include<stdio.h>
#include<stdlib.h>
#define INF 999

int min(int a, int b){
  return (a<b) ? a : b;
}

void flyod(int **graph, int n){
  int i,j,k;
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(graph[i][k] != INF && graph[k][j] != INF)
          graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
      }
    }
  }
}

int main(){
  int i,j,n;
  printf("\n Enter the no. of vertices : \n");
  scanf("%d",&n);

  int **graph = (int **)malloc(n * sizeof(int *));
  for(i=0;i<n;i++)
    graph[i] = (int *)malloc(n * sizeof(int));

  printf("\n Enter the adjacency matrix -1 for no direct path : \n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&graph[i][j]);
      if(graph[i][j] == -1 && i != j)
        graph[i][j] = INF;
    }
  }

  flyod(graph,n);

  printf("\n Shortest path between pair of vertices are :\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(graph[i][j] == INF)
        printf("INF\t");
      else
        printf("%d\t",graph[i][j]);
    }
    printf("\n");
  }
  for(i=0;i<n;i++)
    free(graph[i]);
  free(graph);

return 0;
}
