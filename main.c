#include <stdio.h>

// Definição da Struct
struct Produto {
    char nome[50];
    int quantidade;
    float preco;
    float ValorFinal;
    float desconto;
    float total;
};

// Declaração das variáveis (variáveis globais)
struct Produto produtos[20]; // Vetor da struct substituindo os vetores paralelos
float totalGeral = 0;
int opcao, i = 0;

// Função que faz o cálculo do preço total do produto atual sendo cadastrado
void calcularTotal() {
    produtos[i].total = produtos[i].preco * produtos[i].quantidade;
}

// Aplicação do desconto
void aplicarDesconto() {
    if (produtos[i].total <= 100) {
        produtos[i].desconto = 0;
    } else if (produtos[i].total > 100 && produtos[i].total <= 250) {
        produtos[i].desconto = 0.05;
    } else if (produtos[i].total > 250 && produtos[i].total <= 500) {
        produtos[i].desconto = 0.10;
    } else {
        produtos[i].desconto = 0.15;
    }
    
    produtos[i].ValorFinal = produtos[i].total - (produtos[i].total * produtos[i].desconto);
    
    // Cálculo do total geral (soma de todos os valores finais dos produtos)
    totalGeral += produtos[i].ValorFinal;
}

void adicionarProduto() {
    int opcao;

    do {
        if (i >= 20) {
            printf("Limite de produtos atingido!\n");
            break;
        }

        printf("\n--- Produto %d ---\n", i + 1);
        
        printf("Digite o nome do produto: ");
        scanf("%s", produtos[i].nome);

        printf("Digite o preço do produto: ");
        scanf("%f", &produtos[i].preco);

        printf("Digite a quantidade de produtos: ");
        scanf("%d", &produtos[i].quantidade);

        // Chamando as funções para uso
        calcularTotal();   
        aplicarDesconto();

        printf("Deseja cadastrar outro produto? (1-Sim / 0-Não): ");
        scanf("%d", &opcao);
    
        // Continuação do cadastro
        if (opcao == 1) {
            i++; 
        } else {
            i++;
            break; 
        }

    } while (i < 20);
}

void emitirNotaFiscal() {
    printf("\n------- Dados dos Produtos -------");
    for (int j = 0; j < i; j++) {
        printf("\nProduto %d: ", j + 1);
        // Acesso alterado para usar a struct (ponto .)
        printf("Nome: %s ", produtos[j].nome);
        printf("Preço: %.2f ", produtos[j].preco);
        printf("Qtd: %d ", produtos[j].quantidade);
        printf("Bruto: %.2f ", produtos[j].total);
        printf("Desc: %.0f%% ", produtos[j].desconto * 100);
        printf("Final: %.2f ", produtos[j].ValorFinal);
        printf("\n----------------------------------");
    }
    
    printf("\nValor TOTAL da compra: %.2f ", totalGeral);
    printf("\n----------------------------------\n");
}

// Execução do programa
int main() {
    adicionarProduto();
    emitirNotaFiscal();
    return 0;
}