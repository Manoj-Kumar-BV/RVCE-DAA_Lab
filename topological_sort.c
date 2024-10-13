#include<stdio.h>
#include<stdlib.h>
int topo[10],k;
int cycle_detected = 0;

void dfs(int a[][10], int n, int visited[], int rec_stack[], int source){
  int i;
  visited[source] = 1;
  rec_stack[source] = 1;
  for(i=1;i<=n;i++){
    if(a[source][i]){
      if(!visited[i]){
        dfs(a,n,visited,rec_stack,i);
      }
      else if(rec_stack[i]){
        cycle_detected = 1;
      }
    }
  }
  rec_stack[source] = 0;
  topo[++k] = source;
}

int main(){
  int i,j,n,a[10][10], visited[10]={}, rec_stack[10]={};
  
  printf("\n Enter the number of nodes in the graph : \n");
  scanf("%d",&n);
  
  printf("\n Enter the adjacency matrix of the graph : \n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&a[i][j]);
    }
  }
  
  for(i=1;i<=n;i++){
    if(!visited[i]){
      dfs(a,n,visited,rec_stack,i);
    }
  }
  
  if(cycle_detected){
    printf("\n Cycle detected in the graph\n");
  }
  else{
    printf("\n Topological Ordering is : \n");
    for(i=k;i>=1;i--)
      printf("%d\t",topo[i]);
    printf("\n");
  }
  return 0;
}
