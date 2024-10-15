#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int subset[MAX], x[MAX], target, solution = 1;
void sum_subset(int s, int k, int total){
  x[k] = 1;
  if(s+subset[k] == target){
    printf("\n SUBSET %d\n",solution++);
    for(int i=1;i<=k;i++){
      if(x[i] == 1)
        printf("%d\t",subset[i]);
    }
    printf("\n");
  }
  else if(s+subset[k]+subset[k+1] <= target)
    sum_subset(s+subset[k],k+1,total-subset[k]);
  if((s+total-subset[k] >= target) && (s+subset[k+1] <= target)){
    x[k] = 0;
    sum_subset(s,k+1,total-subset[k]);
  }
}

int main(){
  int i,n,sum=0;
  printf("\n Enter the no. of values: \n");
  scanf("%d",&n);
  printf("\n Enter the %d values in ascending order : \n",n);
  for(i=1;i<=n;i++){
    scanf("%d",&subset[i]);
    sum += subset[i];
  }
  printf("\n Enter the target value : \n");
  scanf("%d",&target);

  if(sum<target||subset[1]>target)
    printf("\n No Solution\n");
  sum_subset(0,1,sum);
  return 0;
}
