#include<stdio.h>
#include<stdlib.h>
void main()
{
   int c[8];
   int a[4]={1,2,3,4};
   int b[4]={5,6,7,8};
   int q=0;
   for(int i=3;i>-1;i--){
    c[q]=a[i];
    q++;
   }
   int p=0;
   for(int i=4;i<8;i++){
        c[i]=b[p];
        p++;
   }
   printf("Merged array: ");
   for(int i=0;i<8;i++){
       printf("%d ",c[i]);
   }
}