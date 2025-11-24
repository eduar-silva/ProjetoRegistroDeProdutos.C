#include <stdio.h>

int main() {
    char nome[50];
    float preco;
    int qtd;
    float total_item, val_desc, val_final;

    printf("\n--- Cálculo de Desconto ---\n");
    
    printf("Digite o nome do produto: ");
    scanf("%s", nome); 
    printf("Digite o preço do produto: ");
    scanf("%f", &preco); 
    printf("Digite a quantidade: ");
    scanf("%d", &qtd); 

    total_item = preco * qtd;

    float perc_desconto;
    if (total_item <= 100) {
        perc_desconto = 0;
    } else if (total_item > 100 && total_item <= 250) {
        perc_desconto = 0.05;
    } else if (total_item > 250 && total_item <= 500) {
        perc_desconto = 0.10;
    } else {
        perc_desconto = 0.15;
    }

    val_desc = total_item * perc_desconto;
    val_final = total_item - val_desc;

    printf("Total: %.2f | Desconto: %.2f | Final: %.2f\n", total_item, val_desc, val_final);

    return 0;
}