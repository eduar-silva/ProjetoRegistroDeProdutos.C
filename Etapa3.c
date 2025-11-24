#include <stdio.h>

int main() {
    char nomes[20][50]; 
    float precos[20];
    int quantidade[20];
    float total[20];
    
    int i = 0;
    int opcao;

    do {
        if (i >= 20) break;

        printf("\n--- Produto %d ---\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", nomes[i]); 
        printf("Digite o preço: ");
        scanf("%f", &precos[i]); 
        printf("Digite a quantidade: ");
        scanf("%d", &quantidade[i]); 

        total[i] = precos[i] * quantidade[i];

        printf("Cadastrar outro? (1-Sim / 0-Não): ");
        scanf("%d", &opcao);
        i++;

    } while (opcao == 1 && i < 20);

    printf("\n--- Lista de Compras ---\n");
    for (int j = 0; j < i; j++) {
        printf("Produto: %s | Qtd: %d | Total: %.2f\n", nomes[j], quantidade[j], total[j]);
    }

    return 0;
}