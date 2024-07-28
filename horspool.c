#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000

int table[SIZE];
int indices[SIZE];
int j,i,shifts;

void shiftTable(char p[]){
    int m=strlen(p);
    for(int i=0;i<SIZE;i++)
        table[i] = m;
    for(int j=0;j<m-1;j++)
        table[p[j]] = m-1-j;    
}

void horspool(char t[], char p[]){
    int n=strlen(t);
    int m=strlen(p);
    i=m-1;
    int k;

    shiftTable(p);
    while(i<n){
        k=0;
        while(k<m && p[m-1-k]==t[i-k])
            k++;
        if(k==m){
            indices[j++]=i-m+1;
            i=i+table[t[i]];
            shifts++;
        }
        else{
            i=i+table[t[i]];
            shifts++;
        }
    }
}

int main(){
    char p[SIZE],t[SIZE];
    printf("Enter text: ");
    scanf("%[^\n]%*c",t);

    printf("Enter pattern: ");
    scanf("%[^\n]%*c",p);

    j=0;
    horspool(t,p);

    if(j==0)
        printf("Pattern not found");
    else{
        printf("Pattern found at indices: ");
        for(int i=0;i<j;i++){
            printf("%d",indices[i]);
            if(i<j-1)
                printf(", ");
        }
        printf("\n Number of shifts performed are: %d\n",shifts);
    }
    return 0;
}