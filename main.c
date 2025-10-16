#include <stdio.h>

int main() {
    float salario, inss, ir, sal_liquido;

    printf("Calculo de Salario Liquido com desconto do IR e INSS\n\n");
    printf("Digite seu salario bruto: ");
    scanf("%f", &salario);

    // Calcular INSS (tabela simplificada)
    if (salario <= 1320)
        inss = salario * 0.075;
    else if (salario <= 2571.29)
        inss = (1320 * 0.075) + ((salario - 1320) * 0.09);
    else if (salario <= 3856.94)
        inss = (1320 * 0.075) + ((2571.29 - 1320) * 0.09) + ((salario - 2571.29) * 0.12);
    else if (salario <= 7507.49)
        inss = (1320 * 0.075) + ((2571.29 - 1320) * 0.09) + ((3856.94 - 2571.29) * 0.12) + ((salario - 3856.94) * 0.14);
    else
        inss = 877.05; // teto do INSS

    // Calcular IRRF (com deduções)
    if (salario <= 2112)
        ir = 0;
    else if (salario <= 2826.65)
        ir = salario * 0.075 - 158.40;
    else if (salario <= 3751.05)
        ir = salario * 0.15 - 370.40;
    else if (salario <= 4664.68)
        ir = salario * 0.225 - 651.73;
    else
        ir = salario * 0.275 - 884.96;

    // Calculo do salario liquido
    sal_liquido = salario - inss - ir;

    // Exibir resultados
    printf("\nDesconto do INSS: R$ %.2f\n", inss);
    printf("Desconto do IR: R$ %.2f\n", ir);
    printf("Salario liquido: R$ %.2f\n", sal_liquido);

    return 0;
}
