#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256

int Table[SIZE];

void shiftTable(char p[10]){
  int m = strlen(p), i;
  for(i=0;i<SIZE;i++)
    Table[i] = m;
  for(i=0;i<=m-2;i++)
    Table[(int)p[i]]=m-1-i;
}

int horspool(char t[SIZE], char p[10]){
  int m = strlen(p),n = strlen(t),i,k;
  shiftTable(p);
  i = m-1;
  while(i<n){
    k=0;
    while(k < m && p[m-1-k] == t[i-k])
      k++;
    if(k==m)
      return i-m+1;
    else
      i=i+Table[(int)t[i]];
  }
  return -1;
}

int main(){
  char text[SIZE], pattern[SIZE];
  
  printf("\n Enter the text : \n");
  scanf("%s",text);
  
  printf("\n Enter the pattern : \n");
  scanf("%s",pattern);
  
  int result = horspool(text,pattern);
  if(result == -1)
    printf("\n Pattern is not found in the given text\n");
  else
    printf("\n Pattern is found at the index %d in the given text\n",result);
  
  return 0;
}
