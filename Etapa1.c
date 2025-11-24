#include <stdio.h>

int main() {
    char nome[50];
    float preco;
    int qtd;
    float total_item; 

    printf("\n--- Cadastro de Produto ---\n");
    
    printf("Digite o nome do produto: ");
    scanf("%s", nome); 

    printf("Digite o preço do produto: ");
    scanf("%f", &preco); 

    printf("Digite a quantidade de produtos: ");
    scanf("%d", &qtd); 

    total_item = preco * qtd;

    printf("\nProduto: %s | Total Bruto: %.2f\n", nome, total_item);

    return 0;
}