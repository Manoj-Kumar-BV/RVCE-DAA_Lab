#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int count;

int partition(int a[MAX], int l, int r){
  int pivot = a[l], i=l+1,j=r, temp;
  while(1){
    while(pivot >= a[i] && i<=r){
      i++;
      count++;
    }
    while(pivot<a[j] && j != l){
      j--;
      count++;
    }
    if(i<j){
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    else{
      temp = a[j];
      a[j] = a[l];
      a[l] = temp;
      return j;
    }
  }
}

void quicksort(int a[MAX], int l, int r){
  if(l<r){
    int s = partition(a,l,r);
    quicksort(a,l,s-1);
    quicksort(a,s+1,r);
  }
}

int main(){
  int a[MAX], b[MAX], c[MAX], d[MAX], i,j,n,c1,c2,c3;
  
  printf("\n Enter the no. of elements in the array : \n");
  scanf("%d",&n);
  
  printf("\n Enter the array elements : \n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  
  quicksort(a,0,n-1);
  printf("\n Sorted array is : \n");
  for(i=0;i<n;i++)
    printf("%d\t",a[i]);
  
  printf("\n Comparisons made are %d\n",count);
  
  printf("\nSIZE\tASC\tDESC\tRAND\n");
  for(i=2;i<550;i *=2){
    for(j=0;j<i;j++){
      b[j] = j;
      c[j] = i-j-1;
      d[j] = rand() % i;
    }
    count = 0;
    quicksort(b,0,i-1);
    c1 = count;
    
    count = 0;
    quicksort(c,0,i-1);
    c2 = count;
    
    count = 0;
    quicksort(d,0,i-1);
    c3 = count;
    
    printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
  }
  return 0;
}
