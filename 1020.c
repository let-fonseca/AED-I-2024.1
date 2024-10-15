/* Letícia Fonseca Pereira - RA: 176.561
1020 - Idade em Dias */

#include <stdio.h>
 
int main() {
    int dias, anos, meses, diasr;
    
    scanf("%d", &dias);
    
    anos = dias / 365;
    dias = dias % 365;
    meses = dias / 30;
    diasr = dias % 30;
    
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", diasr);
    
    return 0;
}