#include<stdio.h>
#include<stdlib.h>
void main()
{
   int c[4];
   int a[4]={1,2,3,4};
   int b[4]={5,6,7,8};
   for(int i=0;i<4;i++){
    c[i]=a[i]*b[i];
   }
   printf("product array: ");
   for(int i=0;i<4;i++){
     printf("%d ",c[i]);
   }
}   