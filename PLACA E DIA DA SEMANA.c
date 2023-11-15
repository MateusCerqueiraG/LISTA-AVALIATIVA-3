#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarDiaSemana(char *dia) {
    char *diasSemana[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(dia, diasSemana[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int validarPlaca(char *placa) {
    int tamanho = strlen(placa);

    if (tamanho == 8 || tamanho == 7) {
        for (int i = 0; i < tamanho; i++) {
            if (i == 3 && placa[i] == '-') {
                continue;
            }
            if (!isalnum(placa[i])) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    char placa[20];
    char dia[20];
    
    fgets(placa, sizeof(placa), stdin);
    fgets(dia, sizeof(dia), stdin);

    placa[strcspn(placa, "\n")] = '\0';
    dia[strcspn(dia, "\n")] = '\0';

    int indiceDia = validarDiaSemana(dia);
    int placaValida = validarPlaca(placa);

    if (!placaValida && indiceDia == -1) {
        printf("Placa invalida\nDia da semana invalido\n");
        return 0;
    } else if (!placaValida) {
        printf("Placa invalida\n");
        return 0;
    } else if (indiceDia == -1) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    char *nomesDiasSemana[] = {"segunda-feira", "terca-feira", "quarta-feira", "quinta-feira", "sexta-feira", "sabado", "domingo"};

    int ultimoDigitoPlaca = placa[strlen(placa) - 1] - '0';

    if ((indiceDia == 0 && (ultimoDigitoPlaca == 0 || ultimoDigitoPlaca == 1)) ||
        (indiceDia == 1 && (ultimoDigitoPlaca == 2 || ultimoDigitoPlaca == 3)) ||
        (indiceDia == 2 && (ultimoDigitoPlaca == 4 || ultimoDigitoPlaca == 5)) ||
        (indiceDia == 3 && (ultimoDigitoPlaca == 6 || ultimoDigitoPlaca == 7)) ||
        (indiceDia == 4 && (ultimoDigitoPlaca == 8 || ultimoDigitoPlaca == 9))) {
        printf("%s nao pode circular %s\n", placa, nomesDiasSemana[indiceDia]);
    } else if (indiceDia == 5 || indiceDia == 6) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        printf("%s pode circular %s\n", placa, nomesDiasSemana[indiceDia]);
    }

    return 0;
}