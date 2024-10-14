#include<stdio.h>
#include<stdlib.h>
int x[20];

int place(int k, int i){
  for(int j=1;j<k;j++)
    if((x[j]==i) || (abs(x[j]-i) == abs(j-k)))
      return 0;
  return 1;
}

void printQueen(int n){
  static int count =1;
  int i,j;
  printf("\n Solution %d is : \n",count++);
  
  for(i=1;i<=n;++i)
    printf("\t%d",i);
  
  for(i=1;i<=n;++i){
    printf("\n%d",i);
    for(j=1;j<=n;++j)
      if(x[i] == j)
        printf("\tQ");
      else
        printf("\t-");
    }
    printf("\n");
  }

void NQueen(int k, int n){
  for(int i=1;i<=n;i++){
    if(place(k,i)){
      x[k] = i;
      if(k==n)
        printQueen(n);
      else
        NQueen(k+1,n);
    }
  }
}

int main(){
  int n;
  printf("\n Enter the number of queens to be placed : \n");
  scanf("%d",&n);

  if(n==0 || n==2 || n==3)
    printf("\n No solutions possible\n");
  
  NQueen(1,n);
  printf("\n");

  return 0;
}
