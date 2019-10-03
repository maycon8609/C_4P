#include <stdio.h>
#include <stdlib.h>

void ordenar(int a, int b, int c){
  if(a <= b && b <= c)
    printf("%d %d %d", a, b,c);
  else if(a <= c && c <= b)
    printf("%d %d %d", a, c,b);
  else if(b <= c && c <= a)
    printf("%d %d %d", b, c, a);
  else if(b <= a && a <= c)
    printf("%d %d %d", b, a, c);
  else if(c <= b && b <= a)
    printf("%d %d %d", c, b, a);
  else
    printf("%d %d %d", c, a, b);

}


int main() {
    ordenar(2,1,1);

    return 0;
}
