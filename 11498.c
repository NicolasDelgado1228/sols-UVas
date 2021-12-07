#include <stdio.h>

int main(){
  int queries, i, divPoint, x, y, points[2];
  struct coord{
    int x, y;
  };
  do{
    scanf("%d",&queries);
    if(queries!=0){
      scanf("%d %d", points,points+1);
    }
    for(i=0;i<queries;i++){
      scanf("%d %d",&x, &y);
      struct coord point={x, y};
      if(point.x==points[0] || point.y==points[1])
        printf("divisa\n");
      else if(point.x<points[0] && point.y<points[1])
        printf("SO\n");
      else if(point.x>points[0] && point.y<points[1])
        printf("SE\n");
      else if(point.x>points[0] && point.y>points[1])
        printf("NE\n");
      else
        printf("NO\n");
    }

  }while(queries);


  return 0;
}
