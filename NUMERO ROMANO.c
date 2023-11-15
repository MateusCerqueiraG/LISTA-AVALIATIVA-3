#include <stdio.h>
#include <string.h>
#include <ctype.h>

int romano_para_decimal(char romano) {
    switch (romano) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

void decimal_para_binario(int decimal) {
    int binario[32], i = 0;
    
    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    
    if (i == 0) {
        printf("0");
    } else {
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binario[j]);
        }
    }
}

int main() {
    char numero_romano[13];
    scanf("%s", numero_romano);
    
    int tamanho = strlen(numero_romano);
    int decimal = 0;
    int valor_ant = 0;
    
    for (int i = tamanho - 1; i >= 0; i--) {
        int valor_atual = romano_para_decimal(numero_romano[i]);
        
        if (valor_atual >= valor_ant) {
            decimal += valor_atual;
        } else {
            decimal -= valor_atual;
        }
        
        valor_ant = valor_atual;
    }
    
    printf("%s na base 2: ", numero_romano);
    decimal_para_binario(decimal);
    printf("\n%s na base 10: %d\n%s na base 16: %x\n", numero_romano, decimal, numero_romano, decimal);
    
    return 0;
}