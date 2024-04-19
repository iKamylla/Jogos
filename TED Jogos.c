#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20

int main(){ // Menu
    int op;

    while (op != 4){
        printf("\n===============================================================");
        printf("\n==================|| MENU ||===================\n\n");
        printf("    1 - Jogo de Adivinhacao\n    2 - Jogo de Jokenpon\n    3 - Jogo da Forca\n    4 - Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op){
            case 1:{}
                system("cls");
                adivinhacao(); break;

            case 2:
                system("cls");
                jokenpo(); break;

            case 3:
                system("cls");
                forca(); break;

            case 4:
                break;

            default:
                printf("\nOpcao invalida.\n");
        }
    }
}

void adivinhacao(){ // Jogo de Adivinhação
    int opUser, numAleat, tent, tentRest = 5;

    srand(time(NULL));
    numAleat = rand() % 100 + 1;

    printf("===============================================================");
    printf("\nBem-vindo(a) ao Jogo de Adivinhacao!\n");
    printf("\nTente adivinhar o numero secreto entre 1 e 100.\n");

    do {
        printf("\nVoce tem %d tentativa(s) restante(s).\n", tentRest);
        printf("\nDigite seu palpite: ");
        scanf("%d", &tent);

        if (tent > numAleat){
            printf("\nTente um numero menor.\n");
        } else if (tent < numAleat){
            printf("\nTente um numero maior.\n");
        } else{
            printf("\nParabens! Voce adivinhou o numero secreto %d!\n", numAleat);
            break;
        }
        tentRest--;
    } while (tentRest > 0);
        if (tentRest == 0){
            printf("\nTentativas esgotadas. O numero secreto era %d.\n", numAleat);
    }
    printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
    scanf("%d", &opUser);
        if (opUser == 1){
            return adivinhacao();
        } else {
            printf("\nValeu por jogar! Tmj\n");
            printf("===============================================================");
            Sleep(5000); system("cls");
        }
    return 0;
}

void jokenpo() { // Jogo de Jokenpô
    int opUser, opComp;

    srand(time(NULL));

    printf("\n===============================================================");
    printf("\nBem-vindo(a) ao Jogo de Jokenpo (Pedra, Papel e Tesoura)!\n");

    int obterEscolha(){
    int escolha;
    printf("\nEscolha:\n");
    printf("   1. Pedra\n");
    printf("   2. Papel\n");
    printf("   3. Tesoura\n");
    printf("\nDigite o numero da sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

    do {
        opUser = obterEscolha();
        opComp = rand() % 3 + 1;

        switch (opComp) {
            case 1:
                printf("\nO computador escolheu Pedra.\n"); break;

            case 2:
                printf("\nO computador escolheu Papel.\n"); break;

            case 3:
                printf("\nO computador escolheu Tesoura.\n"); break;

            default:
                printf("\nOpcao invalida.\n");
        }

        void detVenc(int opUser, int opComp) {
            if (opUser == opComp) {
                printf("\n   Empate!\n");
            } else if ((opUser == 1 && opComp == 3) ||
                       (opUser == 2 && opComp == 1) ||
                       (opUser == 3 && opComp == 2)) {
                printf("\n   Voce venceu!\n");
            } else {
                printf("\n   Voce perdeu!\n");
            }
        }

        detVenc(opUser, opComp);

        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        scanf("%d", &opUser);
    } while (opUser == 1);

    printf("\nValeu por jogar! Tmj\n");
    printf("===============================================================");
    Sleep(5000); system("cls");
    return 0;
}

void forca(){ // Jogo da Forca
    char palavra[TAMANHO_PALAVRA];
    char palavraEscondida[TAMANHO_PALAVRA];
    char letra;
    int tentativasRestantes = MAX_TENTATIVAS;
    int palavraRevelada = 0;
    int opUser;

    printf("\n===============================================================");
    printf("\nBem-vindo(a) ao Jogo da Forca!\n");

    printf("\nDigite a palavra para jogar (sem espacos, com no maximo %d caracteres): ", TAMANHO_PALAVRA - 1);
    scanf("%s", palavra);

    memset(palavraEscondida, '-', strlen(palavra));
    palavraEscondida[strlen(palavra)] = '\0';

    while (tentativasRestantes > 0 && !palavraRevelada) {
        printf("\nPalavra: %s\n", palavraEscondida);
        printf("Tentativas restantes: %d\n", tentativasRestantes);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (strchr(palavraEscondida, tolower(letra)) != NULL) {
            printf("Você já tentou esta letra. Tente outra.\n");
            continue;
        }

        int verificarLetra(char letra, char palavra[], char palavraEscondida[]) {
        int i, encontrou = 0;
        for (i = 0; i < strlen(palavra); i++) {
            if (tolower(letra) == tolower(palavra[i])) {
                palavraEscondida[i] = palavra[i];
                encontrou = 1;
            }
        }
        return encontrou;
        }

        if (verificarLetra(letra, palavra, palavraEscondida)) {
            printf("Letra correta!\n");

            if (strcmp(palavra, palavraEscondida) == 0) {
                palavraRevelada = 1;
            }
        } else {
            printf("Letra incorreta.\n");
            tentativasRestantes--;
        }

        void imprimirForca(int tentativasRestantes) {
        printf("\n");
        printf("  +---+\n");
        printf("  |   |\n");

        if (tentativasRestantes < MAX_TENTATIVAS)
            printf("  |   O\n");
        else
            printf("  |\n");

        if (tentativasRestantes < MAX_TENTATIVAS - 1)
            printf("  |   |\n");
        else if (tentativasRestantes < MAX_TENTATIVAS)
            printf("  |  /|\n");
        else
            printf("  |\n");

        if (tentativasRestantes < MAX_TENTATIVAS - 3)
            printf("  |  / ");
        else if (tentativasRestantes < MAX_TENTATIVAS - 2)
            printf("  |  /|");
        else if (tentativasRestantes < MAX_TENTATIVAS - 1)
            printf("  |  /|\\");
        else if (tentativasRestantes < MAX_TENTATIVAS)
            printf("  |  /|\\");
        else
            printf("  |\n");

        printf("  |\n");
        printf("======\n\n");
    }

        imprimirForca(tentativasRestantes);
    }
    if (palavraRevelada){
        printf("\nParabens! Voce adivinhou a palavra \"%s\"!\n", palavra);
    } else {
        printf("\nVoce perdeu! A palavra era \"%s\".\n", palavra);
    }
    printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
    scanf("%d", &opUser);
    if (opUser == 1){
        return forca();
    } else {
        printf("\nValeu por jogar! Tmj\n");
        printf("===============================================================");
        Sleep(5000); system("cls");
    }
    return 0;
}
