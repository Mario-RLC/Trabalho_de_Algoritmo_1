#include <string.h>
#include <stdio.h>

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar(){
    printf("Pressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

if(scanf("%d", &opcao) != 1){
                        while(getchar() != '\n'); // limpar buffer de entrada
                        opcao = -1; // definir uma opção inválida
                    }

                    