#include<stdio.h>

int main(){
  int i;
  scanf("%d",&i);
  while (i != 0){
    int j,x,y,x1,y1;
    scanf("%d %d",&x,&y);
    for (j=0;j<i;j++){
      scanf("%d %d",&x1,&y1);
      if ((x==x1) || (y==y1)){
        printf("divisa\n");  
      }
      else if(x1>x && y1>y){
        printf("NE\n");
      }
      else if(x1>x && y1<y){
        printf("SE\n");

      }
      else if(x1<x && y1>y){
        printf("NO\n");
      }
      else if(x1<x && y1<y){
        printf("SO\n");

      }
    }
    scanf("%d",&i);
  }
  return 0;
}