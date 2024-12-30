#include<stdio.h>
#include<stdlib.h>
void main()
{
    int s1[10],s2[10],u[10],z1[10],z2[10],us,s1s,s2s,sus[10],sns[10];
    printf("Enter the size of universal set: ");
    scanf("%d",&us);
    printf("Enter the elements\n");
    for(int i=0;i<us;i++){
        printf("element %d: ",i+1);
        scanf("%d",&u[i]);
    }
    printf("Enter the size of first set: ");
    scanf("%d",&s1s);
    printf("Enter the elements\n");
    for(int i=0;i<s1s;i++){
        printf("element %d: ",i+1);
        scanf("%d",&s1[i]);
    }
    printf("Enter the size of second set: ");
    scanf("%d",&s2s);
    printf("Enter the elements\n");
    for(int i=0;i<s2s;i++){
        printf("element %d: ",i+1);
        scanf("%d",&s2[i]);
    }
    for(int i=0;i<us;i++){
        z1[i]=0;
        z2[i]=0;
    }
    for(int i=0;i<s1s;i++){
        for(int j=0;j<us;j++){
            if(s1[i]==u[j]){
                z1[j]=1;
            }
        }
    }
    printf("universal set : ");
    for(int i=0;i<us;i++){
        printf("%d ",u[i]);
    }
    printf("\nfirst set : ");
    for(int i=0;i<s1s;i++){
        printf("%d ",s1[i]);
    }
    printf("\nsecond set : ");
    for(int i=0;i<s2s;i++){
        printf("%d ",s2[i]);
    }
    printf("\n set 1 : ");
    for(int i=0;i<us;i++){
        printf("%d ",z1[i]);
    }
    for(int i=0;i<s2s;i++){
        for(int j=0;j<us;j++){
            if(s2[i]==u[j]){
                z2[j]=1;
            }
        }
    }
    printf("\n set 2 : ");
    for(int i=0;i<us;i++){
        printf("%d ",z2[i]);
    }
    for(int i=0;i<us;i++){
        if(z1[i]==0 && z2[i]==0){
            sus[i]=0;
        }
        else if(z1[i]==1 && z2[i]==1){
            sus[i]=1;
        }
        else{
            sus[i]=1;
        }
    }
    printf("\n s1us2 : ");
    for(int i=0;i<us;i++){
        printf("%d ",sus[i]);
    }
    for(int i=0;i<us;i++){
        if(z1[i]==0 && z2[i]==0){
            sns[i]=0;
        }
        else if(z1[i]==1 && z2[i]==1){
            sns[i]=1;
        }
        else{
            sns[i]=0;
        }
    }
    printf("\n s1ns2 : ");
    for(int i=0;i<us;i++){
        printf("%d ",sns[i]);
    }
}

