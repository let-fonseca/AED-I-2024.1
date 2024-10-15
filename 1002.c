/* Letícia Fonseca Pereira - RA: 176.561
1002 - Área do Círculo */

#include <stdio.h>
#include <math.h>
 
int main() {
   double R, A;
   scanf("%lf", &R);
   A = 3.14159 * R * R;
   printf("A=%.4lf\n", A);
   return 0;
}