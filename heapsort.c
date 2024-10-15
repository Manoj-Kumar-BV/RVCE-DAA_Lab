#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[], int n){
  int i,j,k,v,flag;
  for(i=n/2;i>=1;i--){
    k=i;v=arr[k];flag = 0;
    while(!flag && 2*k<=n){
      j=2*k;
      if(j<n){
        if(arr[j] < arr[j+1])
          j++;
      }
      if(v>=arr[j])
        j++;
      else{
        arr[k] = arr[j];
        k=j;
      }
    }
    arr[k] = v;
  }
}

void heapsort(int arr[], int n){
  int i,temp;
  heapify(arr,n);
  for(i=n;i>=2;i--){
    temp = arr[1];
    arr[1] = arr[i];
    arr[i] = temp;
    heapify(arr,i-1);
  }
}

int main(){
  int i,arr[100],n;
  printf("\n Enter the no of elements : \n");
  scanf("%d",&n);

  printf("\n Enter the array elements : \n");
  for(i=1;i<=n;i++)
    scanf("%d",&arr[i]);

  heapsort(arr,n);

  printf("\n Sorted array Elements are : \n");
  for(i=1;i<=n;i++)
    printf("%d\t",arr[i]);
  printf("\n");

  return 0;
}
