#include<stdio.h>
#include<stdlib.h>
void main()
{
   int c[8];
   int a[4]={1,2,3,4};
   int b[4]={5,6,7,8};
   for(int i=0;i<4;i++){
    c[i]=a[i];
   }
   int p=4;
   for(int i=3;i>-1;i--){
        c[p]=b[i];
        p++;
   }
   printf("Merged array: ");
   for(int i=0;i<8;i++){
       printf("%d ",c[i]);
   }
}