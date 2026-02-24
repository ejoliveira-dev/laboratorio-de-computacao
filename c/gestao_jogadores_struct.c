/* Faça um programa que armazene as informações de 3 jogadores de futebol. Cada jogador é identificado pelo numero da sua camisa, pelo seu peso, e altura 
e pela inicial do seu nome. O programa devera ler todas as informações e imprimir a inicial do jogador mais baixo e o numero mais pesado. Use structs para resolver este exercício. */


#include<stdio.h>
#include<stdlib.h>

// declarando o struct
struct caract_time {// struct agrupa vários dados em um único tipo.
    unsigned int numero_da_camisa; // aqui é pra saber que só vale números não negativos
    float peso;
    float altura;
    char inicial_nome;
 };
 
 /* criando um vetor de struct; aqui diz: crie um tipo chamado "caract_time" que tem essas quatro 
 informações; e quando fazemos "jogadores" crie um vetor de 3 variáveis. */
 
 int main() {
    char confirmacao = 'S'; // para usar isso aqui no final
    while (confirmacao == 'S' || confirmacao == 's') {
    
        struct caract_time jogadores[3]; // caract_time = nome da struct; jogadores = nome da variável.
    
        for (int i = 0; i < 3; i++) { // o laço inicia em zero, vai até o 2 (menor que 3) e incrementa o número de jogadores no final;
            printf("\n---------- Jogador %d ----------\n", i + 1); 
     
            printf("Digite o número da camisa: ");
            scanf("%d", &jogadores[i].numero_da_camisa);
            while (jogadores[i].numero_da_camisa == 0) {
                printf("Número da camisa inválido! Digite novamente: ");
                scanf("%u", &jogadores[i].numero_da_camisa);
            }
            
            printf("Digite o peso do jogador: ");
            scanf("%f", &jogadores[i].peso);
            
            while (jogadores[i].peso <= 0) { // como não dá pra usar "unsigned" aqui, é melhor fazer esse while
                printf("Peso inválido! Digite novamente: ");
                scanf("%f", &jogadores[i].peso);
            }
     
            printf("Digite a altura do jogador: ");
            scanf("%f", &jogadores[i].altura);
            
            while (jogadores[i].altura <= 0) {
                printf("Altura inválida! Digite novamente: ");
                scanf("%f", &jogadores[i].altura);
            }
     
            printf("Agora digite a inicial do nome: ");
            scanf(" %c", &jogadores[i].inicial_nome); // espaço antes do %c para ignorar o enter
        }
        
        // adicionando um relatório, pra visualizar o time por inteiro
        printf("\n*----------------* RELATÓRIO DO TIME *----------------*\n");
        for (int i = 0; i < 3; i++) {
            printf("Jogador %d -> Camisa %u, Peso %.2fkg, Altura %.2fm, Inicial %c\n", i + 1,
            jogadores[1].numero_da_camisa,jogadores[i].peso, jogadores[i].altura, jogadores[i].inicial_nome);
        }
        printf("\n*-----------------------------------------------------*\n");
 
        // assumir que o jogador mais baixo é o [0], depois usar para comparar altura e trocar o índice se algum for mais alto
        int ind_mais_baixo = 0;
 
        for (int i = 1; i < 3; i++) { // aqui conseguimos descobrir o mais baixo
            if (jogadores[i].altura < jogadores[ind_mais_baixo].altura){
                ind_mais_baixo = i;
            }
        }
 
        int ind_mais_pesado = 0;
 
        for (int i = 1; i < 3; i++) { // aqui desobrimos o mais pesado
            if (jogadores[i]. peso > jogadores[ind_mais_pesado].peso) {
                ind_mais_pesado = i;
            }
        }
    
        printf("\n*----------------* RESULTADO DO TIME *----------------*\n");
        printf("A inicial do jogador mais baixo do time é '%c'.\n", jogadores[ind_mais_baixo].inicial_nome);
        printf("O número da camisa do jogador mais pesado do time é '%d'.\n", jogadores[ind_mais_pesado].numero_da_camisa);
        printf("*-----------------------------------------------------*\n");
        
        // repete a coleta de informações de acordo com a resposta
        printf("\nDeseja verificar novos jogadores? (S/N): ");
        scanf(" %c", &confirmacao);
    
        while (confirmacao != 'S' && confirmacao != 's' && confirmacao != 'N' && confirmacao != 'n' ) {
            printf("Entrada inválida! Digite apenas S ou N: ");
            scanf(" %c", &confirmacao);
        }
    }
    
    printf("Fim. \n");
    return 0;
    
}
