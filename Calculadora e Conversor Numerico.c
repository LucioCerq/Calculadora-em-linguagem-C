// Calculadora e Conversor Numerico
// Lucio Ferreira de Cerqueira
// 25NOV2023


#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void menu();
void realizarOperacao(int escolha);
void converterDecimalParaBinario(int decimal);
void converterDecimalParaHexadecimal(int decimal);
void converterDecimalParaOctal(int decimal);
void converterBinarioParaDecimal(char *binario);
void converterHexadecimalParaDecimal(char *hexadecimal);
void converterOctalParaDecimal(char *octal);

int main() {
    menu();
    return 0;
}

void menu() {
    int escolha;

    do {
        // Exibe o menu
        printf("Selecione a operacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Converter Decimal para Binario\n");
        printf("6. Converter Decimal para Hexadecimal\n");
        printf("7. Converter Decimal para Octal\n");
        printf("8. Converter Binario para Decimal\n");
        printf("9. Converter Hexadecimal para Decimal\n");
        printf("10. Converter Octal para Decimal\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Saindo da calculadora.\n");
            break;
        }

        realizarOperacao(escolha);
        system("pause");
        system("clear||cls");

    } while (1);
}

void realizarOperacao(int escolha) {
    int num1, num2, resultado;
    char binario[100], hexadecimal[100], octal[100];

    switch (escolha) {
        case 1:
        case 2:
        case 3:
        case 4:
            // Operações básicas
            printf("Digite o primeiro numero: ");
            scanf("%d", &num1);

            printf("Digite o segundo numero: ");
            scanf("%d", &num2);

            switch (escolha) {
                case 1:
                    resultado = num1 + num2;
                    break;
                case 2:
                    resultado = num1 - num2;
                    break;
                case 3:
                    resultado = num1 * num2;
                    break;
                case 4:
                    if (num2 != 0) {
                        resultado = num1 / num2;
                    } else {
                        printf("Erro! Divisao por zero.\n");
                        return;
                    }
                    break;
            }

            printf("Resultado: %d\n", resultado);
            break;

        case 5:
            // Converter Decimal para Binario
            printf("Digite o numero decimal: ");
            scanf("%d", &num1);
            converterDecimalParaBinario(num1);
            break;

        case 6:
            // Converter Decimal para Hexadecimal
            printf("Digite o numero decimal: ");
            scanf("%d", &num1);
            converterDecimalParaHexadecimal(num1);
            break;

        case 7:
            // Converter Decimal para Octal
            printf("Digite o numero decimal: ");
            scanf("%d", &num1);
            converterDecimalParaOctal(num1);
            break;

        case 8:
            // Converter Binario para Decimal
            printf("Digite o numero binario: ");
            scanf("%s", binario);
            converterBinarioParaDecimal(binario);
            break;

        case 9:
            // Converter Hexadecimal para Decimal
            printf("Digite o numero hexadecimal: ");
            scanf("%s", hexadecimal);
            converterHexadecimalParaDecimal(hexadecimal);
            break;

        case 10:
            // Converter Octal para Decimal
            printf("Digite o numero octal: ");
            scanf("%s", octal);
            converterOctalParaDecimal(octal);
            break;

        default:
            printf("Escolha invalida.\n");
            break;
    }
}

void converterDecimalParaBinario(int decimal) {
    printf("Binario: ");
    if (decimal == 0) {
        printf("0");
    } else {
        int binario[32];
        int i = 0;

        while (decimal > 0) {
            binario[i] = decimal % 2;
            decimal /= 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binario[j]);
        }
    }
    printf("\n");
}

void converterDecimalParaHexadecimal(int decimal) {
    printf("Hexadecimal: %X\n", decimal);
}

void converterDecimalParaOctal(int decimal) {
    printf("Octal: %o\n", decimal);
}

void converterBinarioParaDecimal(char *binario) {
    int decimal = strtol(binario, NULL, 2);
    printf("Decimal: %d\n", decimal);
}

void converterHexadecimalParaDecimal(char *hexadecimal) {
    int decimal = strtol(hexadecimal, NULL, 16);
    printf("Decimal: %d\n", decimal);
}

void converterOctalParaDecimal(char *octal) {
    int decimal = strtol(octal, NULL, 8);
    printf("Decimal: %d\n", decimal);
}
