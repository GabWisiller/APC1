#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para armazenar os dados
struct JogoDaForca {
    char palavra[20];
    char palavraAdivinhada[20];
    int tentativas;
};

int main() {
    // Inicializando a estrutura do jogo
    struct JogoDaForca jogo;
    strcpy(jogo.palavra, "CELULAR");// Palavra a ser adivinhada
    memset(jogo.palavraAdivinhada, '_', sizeof(jogo.palavraAdivinhada)); // Inicializando com underscores
    jogo.tentativas = 15; // Número máximo de tentativas

    // Variáveis para armazenar a entrada do jogador
    char letra;
    int opcao;

    do {
        // Exibindo o menu
        printf("JOGO DA FORCA\n");
        printf("1. Tentar uma letra\n");
        printf("2. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        // Executando a opção escolhida
        switch (opcao) {
            case 1:
                printf("\nPalavra: ");
                for (int i = 0; i < strlen(jogo.palavraAdivinhada); i++) {
                    printf("%c ", jogo.palavraAdivinhada[i]);
                }

                printf("\nTentativas restantes: %d\n", jogo.tentativas);

                // Solicitando ao jogador uma letra
                printf("Digite uma letra: ");
                scanf(" %c", &letra);

                // Verificando se a letra está na palavra
                int letraEncontrada = 0;
                for (int i = 0; i < strlen(jogo.palavra); i++) {
                    if (jogo.palavra[i] == letra) {
                        jogo.palavraAdivinhada[i] = letra;
                        letraEncontrada = 1;
                    }
                }

                // Reduzindo o número de tentativas se a letra não for encontrada
                if (!letraEncontrada) {
                    jogo.tentativas--;
                }

                // Verificando se o jogador ganhou
                if (strcmp(jogo.palavra, jogo.palavraAdivinhada) == 0) {
                    printf("Parabens! Voce ganhou!\n");
                    opcao = 2; // Encerrando o jogo
                }

                // Verificando se o jogador perdeu
                if (jogo.tentativas == 0) {
                    printf("Voce perdeu! A palavra era: %s\n", jogo.palavra);
                    opcao = 2; // Encerrando o jogo
                }

                break;

            case 2:
                printf("Jogo encerrado. Ate a proxima!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 2);

    return 0;
}
