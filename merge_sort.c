#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

int count;

void merge(int a[SIZE],int low, int mid, int high){
    int b[SIZE];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k++]=a[i++];
            count++;
        }
        else{
            b[k++]=a[j++];
            count++;
        }
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=0;i<k;i++)
        a[i]=b[i];
}

void mergesort(int a[SIZE], int low, int high){
    if(low<high){
        int mid =(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main(){
    int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
    int c1,c2,c3,i,j,n;
    printf("\n Enter no. of elements : ");
    scanf("%d",&n);

    printf("\n Enter the elements : \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Array elements before sort : \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

    mergesort(a,0,n-1);
    printf("\nArray elements after sort : \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    
    printf("\nBasic operation executed for %d times\n",count);

    printf("\n SIZE \tASC \tDESC \tRAND \n");
    for(i=16;i<550;i=i*2){
        for(j=0;j<i;j++){
            b[j] =i;
            c[j]=i-j-1;
            d[j]=rand() % i;
        }

        count = 0;
        mergesort(b,0,i-1);
        c1 = count;

        count=0;
        mergesort(c,0,i-1);
        c2=count;

        count=0;
        mergesort(d,0,i-1);
        c3=count;

        printf("%d \t%d \t%d \t%d\n",i,c1,c2,c3);
    }
    return 0;
}