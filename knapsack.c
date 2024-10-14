#include<stdio.h>
#include<stdlib.h>

int n,W,w[10],v[10],V[10][10],x[10] = {};

int max(int a, int b){
  return (a>b) ? a:b;
}

void display(){
  int i=n, j=W;
  while(i>0 && j>0){
    if(V[i][j] != V[i-1][j]){
      x[i] = 1;
      j = j-w[i];
    }
    i=i-1;
  }
}

int main(){
  int i,j;
  
  printf("\n Enter the number of items : \n");
  scanf("%d",&n);
  
  printf("\nEnter the weights of the items : \n");
  for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
  
  printf("\n Enter the profits/values of the items : \n");
  for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
  
  printf("\n Enter the maximum capacity of the knapsack : \n");
  scanf("%d",&W);
  
  for(i=0;i<=n;i++){
    for(j=0;j<=W;j++){
      if(i==0 || j==0)
        V[i][j] = 0;
      else if(w[i]>j)
        V[i][j] = V[i-1][j];
      else
        V[i][j] = max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
    }
  }
  
  display();
  
  printf("\n Maximum capacity of the knapsack is : %d\n",V[n][W]);
  
  printf("\n Items included are : \n");
  for(i=1;i<=n;i++){
    if(x[i]){
      printf("\n Item %d : (Weight: %d, Profit: %d) is included \n",i,w[i],v[i]);
    }
  }
  
  printf("\n Table Values are : \n");
  for(i=0;i<=n;i++){
    for(j=0;j<=W;j++){
      printf("%d\t",V[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
