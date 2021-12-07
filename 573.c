#include <stdio.h>

int main(){
  int h, d, f, u, dia;
  float rate, altura, avance;

  do{
    scanf("%d %d %d %d", &h, &u , &d, &f);
    if(h){
      rate=(float)(f*u)/100;
      dia=1;
      avance=(float)u;
      altura=0;
      while(1){
        if(avance>0)
          altura+=avance;
          if(altura>h)
            break;
        altura-=d;
        if(altura<0)
          break;
        dia++;
        if(altura==0)
          break;
        avance-=rate;

      }


      if(altura>=h)
        printf("success on day %d\n", dia);
      else
        printf("failure on day %d\n", dia);

    }
  }while(h);


  return 0;
}
