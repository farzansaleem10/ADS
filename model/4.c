#include<stdio.h>
#include<stdlib.h>
void main()
{
   int c[8],q=0,r=0;
   int a[4]={1,2,3,4};
   int b[4]={5,6,7,8};
   for(int i=0;i<8;i++){
    if(i%2==0){
        c[i]=a[q];
        q++;
    }
    else{
        c[i]=b[r];
        r++;
    }
   }
   printf("Merged array: ");
   for(int i=0;i<8;i++){
       printf("%d ",c[i]);
   }
}   