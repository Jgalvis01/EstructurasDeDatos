#include<stdio.h>
int main(){
    int cases,arr1[100001],arr2[100001],p,cont=1;
    scanf("%d",&cases);
    for (p=0;p<cases;p++){
        int stations,i,j,k,non=0,sis=0,m=0;
        scanf("%d",&stations);
        for (i=0;i<stations;i++){
            scanf("%d",&arr1[i]);
        }
        for(j=0;j<stations;j++){
            scanf("%d",&arr2[j]);
        }

        for(k=0;k<stations;k++){
            sis+= arr1[k]-arr2[k];
            if(sis<0){
                m = k+1;
                non+= sis;
                sis=0;
            }
        }
        if (sis + non >= 0){
            printf("Case %d: Possible from station %d\n",cont,m+1);

        }
        else{
            printf("Case %d: Not possible\n",cont);
        }
        
        cont+=1;
    }
    
    return 0;
}