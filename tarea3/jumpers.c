#include<stdio.h>
#include <math.h>
int main(){
    int arr[3000];
    int n;
    while (scanf("%d",&n) != EOF ){
        int i,j=0,cont=0,flag=1;
        for (i=0;i<n;i++){
            scanf("%d",&arr[i]);
            }
            
        while(j<n-1 && flag){
            if(fabs(arr[j]-arr[j+1]) < n){
                cont+=1;
              }
              else{
                flag=0;
              }
              j++;
            }
  
        if (cont != n-1){
            printf("Not jolly\n");
            }
        else {
            printf("Jolly\n");
            }
        
        }
    return 0;  
    }