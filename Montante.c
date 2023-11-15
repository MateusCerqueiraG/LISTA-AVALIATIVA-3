#include <stdio.h>
#include <math.h>

int main() {
    int meses;
    double aporte_mensal, taxa_juros;

    scanf("%d", &meses);
    
    scanf("%lf", &aporte_mensal);
    
    scanf("%lf", &taxa_juros);

    double montante;
    for (int mes = 1; mes <= meses; mes++) {
        montante = aporte_mensal * (1 + taxa_juros) * (pow((1 + taxa_juros), mes) - 1) / taxa_juros;

        printf("Montante ao fim do mes %d: R$ %.2lf\n", mes, montante);
    }

    return 0;
}