#include<stdio.h>

int main(){
  int cases;
  scanf("%d",&cases);
  while (cases>0){
    int stores,n,i;
    int min=99;
    int max=0;
    scanf("%d",&stores);
    for (i=0;i<stores;++i){
      scanf("%d",&n);
      if (n>max){
        max=n;
      }
      if(n<min){
        min=n;
      }
    }
    int result = (max-min)*2;
    printf("%d\n",result);
    --cases;
  }
  return 0;
}