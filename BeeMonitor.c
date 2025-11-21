#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ABELHAS 50 
#define MAX_SENSORES 100 

typedef struct { 
    int id; 
    char tipo[30];       // temperatura, umidade, luminosidade 
    float valor;         // leitura atual
    int idAbelha;        // vínculo com a abelha 
} Sensor;

typedef struct { 
    int id; 
    char nomePopular[40]; 
    char nomeCientifico[50]; 
    char regiao[30]; 
    float producaoMel;    // produção média em kg/mês 
} Abelha; 

//Funções para assistência no sistema

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar(){
    printf("Pressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

//Funções para Abelhas

int cadastrarAbelha(Abelha tipo_abelha[], int contadorAbelhas){
    int encontrado = 0;
    int opcaoRegiao;
    int i;

    for(i = contadorAbelhas; i <= contadorAbelhas; i++){
        if(contadorAbelhas < MAX_ABELHAS){
            encontrado = 1;
            tipo_abelha[i].id = contadorAbelhas;
            printf("Nome Popular: ");
            scanf(" %39[^\n]",tipo_abelha[i].nomePopular);
            printf("Nome Cientifico: ");
            scanf(" %49[^\n]",tipo_abelha[i].nomeCientifico);
            do{
                printf("Escolha a Regiao:\n");
                printf("1 - Norte\n");
                printf("2 - Nordeste\n");
                printf("3 - Centro-Oeste\n");
                printf("4 - Sudeste\n");
                printf("5 - Sul\n");
                printf("Opcao: ");
                if(scanf("%d", &opcaoRegiao) != 1){
                    limparBuffer(); 
                    opcaoRegiao = -1;
                }
                switch(opcaoRegiao){
                    case 1:
                        strcpy(tipo_abelha[i].regiao, "Norte");
                        break;
                    case 2:
                        strcpy(tipo_abelha[i].regiao, "Nordeste");
                        break;
                    case 3:
                        strcpy(tipo_abelha[i].regiao, "Centro-Oeste");
                        break;
                    case 4:
                        strcpy(tipo_abelha[i].regiao, "Sudeste");
                        break;
                    case 5:
                        strcpy(tipo_abelha[i].regiao, "Sul");
                        break;
                    default:
                        system("clear || cls");
                        printf("Regiao invalida! Digite Novamente!\n");
                }
            }while(opcaoRegiao < 1 || opcaoRegiao > 5);
            do{
                printf("Producao Media de Mel (kg/mes): ");
                if(scanf("%f", &tipo_abelha[i].producaoMel) != 1){
                    limparBuffer(); 
                    tipo_abelha[i].producaoMel = -1;
                }
                system("clear || cls");
                printf("Valor invalido! Digite novamente!\n");
            }while(tipo_abelha[i].producaoMel < 0);
            system("clear || cls");
            printf("\nAbelha cadastrada com sucesso!\n");
            return encontrado;
        } else {
            system("clear || cls");
            printf("Limite maximo de abelhas atingido!\n");
        }
    }    
    return encontrado;
}

void listarAbelhas(Abelha tipo_abelha[], int contadorAbelhas){
    int i;

    if(contadorAbelhas == 0){
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }
    printf("Lista de Abelhas Cadastradas:\n");
    for(i = 0; i < contadorAbelhas; i++){
        printf("ID: %d\n", tipo_abelha[i].id);
        printf("Nome Popular: %s\n", tipo_abelha[i].nomePopular);
        printf("Nome Cientifico: %s\n", tipo_abelha[i].nomeCientifico);
        printf("Regiao: %s\n", tipo_abelha[i].regiao);
        printf("Producao Media de Mel (kg/mes): %.2f\n", tipo_abelha[i].producaoMel);
        printf("-------------------------\n");
    }
}

void buscarPorNomePopular(Abelha tipo_abelha[], int contadorAbelhas){
    char nomeBusca[40];
    char nomeBuscaLower[40];
    char nomeLower[40];
    int encontrado = 0;
    int lenBusca, lenNome;
    int i, j, k;

    printf("Digite o Nome Popular da Abelha para busca: ");
    scanf(" %39[^\n]", nomeBusca);

    lenBusca = strlen(nomeBusca);
    for(i = 0; i < lenBusca && i < 40 - 1; i++){
        nomeBuscaLower[i] = tolower((unsigned char) nomeBusca[i]);
    }
    nomeBuscaLower[i] = '\0';

    for(j = 0; j < contadorAbelhas; j++){
        lenNome = strlen(tipo_abelha[j].nomePopular);
        for(k = 0; k < lenNome && k < 40 - 1; k++){
            nomeLower[k] = tolower((unsigned char) tipo_abelha[j].nomePopular[k]);
        }
        nomeLower[k] = '\0';
        
        if(strstr(nomeLower, nomeBuscaLower) != NULL){
            printf("Abelha Encontrada:\n");
            printf("ID: %d\n", tipo_abelha[j].id);
            printf("Nome Popular: %s\n", tipo_abelha[j].nomePopular);
            printf("Nome Cientifico: %s\n", tipo_abelha[j].nomeCientifico);
            printf("Regiao: %s\n", tipo_abelha[j].regiao);
            printf("Producao Media de Mel (kg/mes): %.2f\n", tipo_abelha[j].producaoMel);
            printf("-------------------------\n");
            encontrado = 1;
        }
    }
    if(encontrado != 1){
        printf("Abelha com o Nome Popular '%s' nao encontrada.\n", nomeBusca);
    }
}

void alterarDadosAbelha(Abelha tipo_abelha[], int contadorAbelhas){
    int idBusca;
    int encontrado = 0;
    int opcaoRegiao;
    int i;

    do{
        printf("Digite o ID da Abelha para alterar dados: ");
        if(scanf("%d", &idBusca) != 1){
            limparBuffer();
            idBusca = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(idBusca < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(idBusca < 0);

    for(i = 0; i < contadorAbelhas; i++){
        if(tipo_abelha[i].id == idBusca){
            printf("Alterando dados da Abelha ID %d:\n", idBusca);
            printf("Novo Nome Popular: ");
            scanf(" %39[^\n]",tipo_abelha[i].nomePopular);
            printf("Novo Nome Cientifico: ");
            scanf(" %49[^\n]",tipo_abelha[i].nomeCientifico);
            do{
                printf("Escolha a Nova Regiao:\n");
                printf("1 - Norte\n");
                printf("2 - Nordeste\n");
                printf("3 - Centro-Oeste\n");
                printf("4 - Sudeste\n");
                printf("5 - Sul\n");
                printf("Opcao: ");
                if(scanf("%d", &opcaoRegiao) != 1){
                    limparBuffer(); 
                    opcaoRegiao = -1;
                }
                switch(opcaoRegiao){
                    case 1:
                        strcpy(tipo_abelha[i].regiao, "Norte");
                        break;
                    case 2:
                        strcpy(tipo_abelha[i].regiao, "Nordeste");
                        break;
                    case 3:
                        strcpy(tipo_abelha[i].regiao, "Centro-Oeste");
                        break;
                    case 4:
                        strcpy(tipo_abelha[i].regiao, "Sudeste");
                        break;
                    case 5:
                        strcpy(tipo_abelha[i].regiao, "Sul");
                        break;
                    default:
                        system("clear || cls");
                        printf("Regiao invalida! Digite Novamente!\n");
                }
            }while(opcaoRegiao < 1 || opcaoRegiao > 5);
            do{
                printf("Nova Producao Media de Mel (kg/mes): ");
                if(scanf("%f", &tipo_abelha[i].producaoMel) != 1){
                    limparBuffer(); 
                    tipo_abelha[i].producaoMel = -1;
                }
                system("clear || cls");
                printf("Valor invalido! Digite novamente!\n");
            }while(tipo_abelha[i].producaoMel < 0);
            system("clear || cls");
            printf("\nDados da Abelha atualizados com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if(encontrado != 1){
        printf("Abelha com o ID '%d' nao encontrada.\n", idBusca);
    }
}

// Funções para remover abelhas e sensores associados

int pedirIdRemocaoAbelha(){
    int idBusca;
    int certeza;

    do{
        printf("Digite o ID da Abelha para remover: ");
        if(scanf("%d", &idBusca) != 1){
            limparBuffer();
            idBusca = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(idBusca < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(idBusca < 0);
    do{
        printf("Deseja realmente remover a Abelha com ID %d? (1-Sim / 2-Nao): ", idBusca);
        if(scanf("%d", &certeza) != 1){
            limparBuffer();
            certeza = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(certeza < 1 || certeza > 2){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(certeza < 1 || certeza > 2);

    if(certeza == 1){ 
        return idBusca;
    }else{
        system("clear || cls");
        printf("Remocao da Abelha cancelada.\n");
        return -1;
    }
}

int removerSensoresPorAbelha(Sensor tipo_sensor[], int contadorSensores, int idRemovida){
    int i = 0, j, k;

    while(i < contadorSensores){
        if(tipo_sensor[i].idAbelha == idRemovida){
            /* remove sensor i */
            for(j = i; j < contadorSensores - 1; j++){
                tipo_sensor[j] = tipo_sensor[j + 1];
            }
            contadorSensores--;
            /* nao incrementa i para verificar o novo elemento que chegou em i */
        } else {
            if(tipo_sensor[i].idAbelha > idRemovida){
                tipo_sensor[i].idAbelha--; /* acompanha a remocao da abelha */
            }
            i++;
        }
    }
    /* renumera ids dos sensores */
    for(k = 0; k < contadorSensores; k++){
        tipo_sensor[k].id = k;
    }
    return contadorSensores;
}

int removerAbelhaPorId(Abelha tipo_abelha[], int contadorAbelhas, int idRemovida){
    int i, j, k;
    int encontrado = 0;

    for(i = 0; i < contadorAbelhas; i++){
        if(tipo_abelha[i].id == idRemovida){
            /* remove abelha i */
            for(j = i; j < contadorAbelhas - 1; j++){
                tipo_abelha[j] = tipo_abelha[j + 1];
            }
            contadorAbelhas--;
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 1){
        /* renumera ids das abelhas */
        for(k = 0; k < contadorAbelhas; k++){
            tipo_abelha[k].id = k;
        }
        system("clear || cls");
        printf("Abelha com o ID '%d' removida com sucesso.\n", idRemovida);
    }else{
        system("clear || cls");
        printf("Abelha com o ID '%d' nao encontrada.\n", idRemovida);
    }
    return contadorAbelhas;
}

//Funções para Sensores

int cadastrarSensores(Sensor tipo_sensor[], int contadorSensores, Abelha tipo_abelha[], int contadorAbelhas){
    int encontrado = 0;
    int i;

    if(contadorAbelhas == 0){
        printf("Nenhuma abelha disponivel para associar. Cadastre uma abelha primeiro.\n");
        return encontrado;
    }
    if(contadorSensores >= MAX_SENSORES){
        printf("Limite maximo de sensores atingido!\n");
        return encontrado;
    }

    int idAbelhaBusca;

    do{
        printf("Digite o ID da Abelha para associar ao sensor: ");
        if(scanf("%d", &idAbelhaBusca) != 1){
            limparBuffer();
            idAbelhaBusca = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!.\n");
        }else if(idAbelhaBusca < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!.\n");
        }
    }while(idAbelhaBusca < 0);
    for(i = 0; i < contadorAbelhas; i++){
        if(tipo_abelha[i].id == idAbelhaBusca){
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0){
        printf("Abelha com o ID '%d' nao encontrada. Nao foi possivel cadastrar o sensor.\n", idAbelhaBusca);
        return encontrado;
    }

    tipo_sensor[contadorSensores].id = contadorSensores;

    int opcaoTipo;

    do{
        printf("Escolha o tipo do Sensor:\n");
        printf("1 - Temperatura\n");
        printf("2 - Umidade\n");
        printf("3 - Luminosidade\n");
        printf("Opcao: ");
        if(scanf("%d", &opcaoTipo) != 1){
            limparBuffer();
            opcaoTipo = -1;
        }
        switch(opcaoTipo){
            case 1:
                strcpy(tipo_sensor[contadorSensores].tipo, "Temperatura");
                break;
            case 2:
                strcpy(tipo_sensor[contadorSensores].tipo, "Umidade");
                break;
            case 3:
                strcpy(tipo_sensor[contadorSensores].tipo, "Luminosidade");
                break;
            default:
                system("clear || cls");
                printf("Tipo invalido! Digite novamente!\n");
        }
    }while(opcaoTipo < 1 || opcaoTipo > 3);
    
    do{
        printf("Valor inicial: ");
        if(scanf("%f", &tipo_sensor[contadorSensores].valor) != 1){
            limparBuffer();
            tipo_sensor[contadorSensores].valor = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(tipo_sensor[contadorSensores].valor < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(tipo_sensor[contadorSensores].valor < 0);
    tipo_sensor[contadorSensores].idAbelha = idAbelhaBusca;
    system("clear || cls");
    printf("\nSensor cadastrado com sucesso!\n");

    return encontrado;
}

void listarSensores(Sensor tipo_sensor[], int contadorSensores){
    int i;

    if(contadorSensores == 0){
        printf("Nenhum sensor cadastrado.\n");
        return;
    }
    printf("Lista de Sensores Cadastrados:\n");
    for(i = 0; i < contadorSensores; i++){
        printf("ID: %d\n", tipo_sensor[i].id);
        printf("Tipo do Sensor: %s\n", tipo_sensor[i].tipo);
        printf("Valor Atual: %.2f\n", tipo_sensor[i].valor);
        printf("ID da Abelha Associada: %d\n", tipo_sensor[i].idAbelha);
        printf("-------------------------\n");
    }
}

void buscarPorIdAbelha(Sensor tipo_sensor[], int contadorSensores){
    int idAbelhaBusca;
    int encontrado = 0;
    int i;

    do{
        printf("Digite o ID da Abelha para buscar sensores associados: ");
        if(scanf("%d", &idAbelhaBusca) != 1){
            limparBuffer();
            idAbelhaBusca = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(idAbelhaBusca < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(idAbelhaBusca < 0);
    printf("Sensores associados a Abelha ID %d:\n", idAbelhaBusca);
    for(i = 0; i < contadorSensores; i++){
        if(tipo_sensor[i].idAbelha == idAbelhaBusca){
            printf("ID do Sensor: %d\n", tipo_sensor[i].id);
            printf("Tipo do Sensor: %s\n", tipo_sensor[i].tipo);
            printf("Valor Atual: %.2f\n", tipo_sensor[i].valor);
            printf("-------------------------\n");
            encontrado = 1;
        }
    }
    if(encontrado != 1){
        printf("Nenhum sensor encontrado para a Abelha com ID '%d'.\n", idAbelhaBusca);
    }
}

void alterarDadosSensores(Sensor tipo_sensor[], int contadorSensores){
    int idBusca;
    int encontrado = 0;
    int opcaoTipo;
    int i;

    do{
        printf("Digite o ID do Sensor para alterar dados: ");
        if(scanf("%d", &idBusca) != 1){
            limparBuffer();
            idBusca = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(idBusca < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(idBusca < 0);
    for(i = 0; i < contadorSensores; i++){
        if(tipo_sensor[i].id == idBusca){
            printf("Alterando dados do Sensor ID %d:\n", idBusca);
            do{
                printf("Escolha o Novo tipo do Sensor:\n");
                printf("1 - Temperatura\n");
                printf("2 - Umidade\n");
                printf("3 - Luminosidade\n");
                printf("Opcao: ");
                if(scanf("%d", &opcaoTipo) != 1){
                    limparBuffer();
                    opcaoTipo = -1;
                }
                switch(opcaoTipo){
                    case 1:
                        strcpy(tipo_sensor[i].tipo, "Temperatura");
                        break;
                    case 2:
                        strcpy(tipo_sensor[i].tipo, "Umidade");
                        break;
                    case 3:
                        strcpy(tipo_sensor[i].tipo, "Luminosidade");
                        break;
                    default:
                        system("clear || cls");
                        printf("Tipo invalido! Digite novamente!\n");
                }
            }while(opcaoTipo < 1 || opcaoTipo > 3);
            do{
                printf("Novo Valor inicial: ");
                if(scanf("%f", &tipo_sensor[i].valor) != 1){
                    limparBuffer();
                    tipo_sensor[i].valor = -1;
                    system("clear || cls");
                    printf("Valor invalido! Digite novamente!\n");
                }else if(tipo_sensor[i].valor < 0){
                    system("clear || cls");
                    printf("Valor invalido! Digite novamente!\n");
                }
            }while(tipo_sensor[i].valor < 0);
            system("clear || cls");
            printf("\nDados do Sensor atualizados com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if(encontrado != 1){
        printf("Sensor com o ID '%d' nao encontrado.\n", idBusca);
    }
}

int removerSensores(Sensor tipo_sensor[], int contadorSensores){
    int idBusca;
    int encontrado = 0;
    int certeza;
    int i, j, k;

    do{
        printf("Digite o ID do Sensor para remover: ");
        if(scanf("%d", &idBusca) != 1){
            limparBuffer();
            idBusca = -1;
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }else if(idBusca < 0){
            system("clear || cls");
            printf("Valor invalido! Digite novamente!\n");
        }
    }while(idBusca < 0);
    do{
        printf("Deseja realmente remover o Sensor com ID %d? (1-Sim / 2-Nao): ", idBusca);
        if(scanf("%d", &certeza) != 1){
            limparBuffer();
            certeza = -1;
        }
        system("clear || cls");
        printf("Valor invalido! Digite novamente!\n");
    }while(certeza < 1 || certeza > 2);
    if(certeza == 1){
        for(i = 0; i < contadorSensores; i++){
            if(tipo_sensor[i].id == idBusca){
                for(j = i; j < contadorSensores - 1; j++){
                    tipo_sensor[j] = tipo_sensor[j + 1];
                }
                contadorSensores--;
            for(k = 0; k < contadorSensores; k++){
                tipo_sensor[k].id = k;
            }
            system("clear || cls");
            printf("\nSensor removido com sucesso!\n");
            encontrado = 1;
            break;
            }else if(encontrado != 1){
                printf("Sensor com o ID '%d' nao encontrado.\n", idBusca);
            }
        }
    }else{
        system("clear || cls");
        printf("Remocao do Sensor cancelada.\n");
    }
    return contadorSensores;
}

//Funções para Relatórios

void relatorioProducaoMel(Abelha tipo_abelha[], int contadorAbelhas){
    int i;

    if(contadorAbelhas == 0){
        printf("Nenhuma abelha cadastrada para gerar relatorio.\n");
        return;
    }
    float somaProducao = 0.0;
    for(i = 0; i < contadorAbelhas; i++){
        somaProducao += tipo_abelha[i].producaoMel;
    }
    float mediaProducao = somaProducao / contadorAbelhas;
    printf("Media Geral de Producao de Mel: %.2f kg/mes\n", mediaProducao);
}

void relatorioMediaTemperatura(Sensor tipo_sensor[], int contadorSensores){
    int i;

    if(contadorSensores == 0){
        printf("Nenhum sensor cadastrado para gerar relatorio.\n");
        return;
    }

    float somaTemperatura = 0.0;
    int contadorTemperatura = 0;
    float mediaTemperatura;

    for(i = 0; i < contadorSensores; i++){
        if(strcmp(tipo_sensor[i].tipo, "Temperatura") == 0){
            somaTemperatura += tipo_sensor[i].valor;
            contadorTemperatura++;
        }
    }
    if(contadorTemperatura == 0){
        printf("Nenhum sensor de temperatura encontrado para gerar relatorio.\n");
        return;
    }
    mediaTemperatura = somaTemperatura / contadorTemperatura;
    printf("Media de Temperatura dos Sensores: %.2f\n", mediaTemperatura);
}

void relatorioQuantidadeAbelhasPorRegiao(Abelha tipo_abelha[], int contadorAbelhas){
    int contadorRegioes[5] = {0}; 
    int i;

    for(i = 0; i < contadorAbelhas; i++){
        if(strcmp(tipo_abelha[i].regiao, "Norte") == 0){
            contadorRegioes[0]++;
        } else if(strcmp(tipo_abelha[i].regiao, "Nordeste") == 0){
            contadorRegioes[1]++;
        } else if(strcmp(tipo_abelha[i].regiao, "Centro-Oeste") == 0){
            contadorRegioes[2]++;
        } else if(strcmp(tipo_abelha[i].regiao, "Sudeste") == 0){
            contadorRegioes[3]++;
        } else if(strcmp(tipo_abelha[i].regiao, "Sul") == 0){
            contadorRegioes[4]++;
        }
    }
    printf("Quantidade de Abelhas por Regiao:\n");
    printf("Norte: %d\n", contadorRegioes[0]);
    printf("Nordeste: %d\n", contadorRegioes[1]);
    printf("Centro-Oeste: %d\n", contadorRegioes[2]);
    printf("Sudeste: %d\n", contadorRegioes[3]);
    printf("Sul: %d\n", contadorRegioes[4]);
}

int main(){
    system("clear || cls");

    Abelha tipo_abelha[MAX_ABELHAS];
    Sensor tipo_sensor[MAX_SENSORES];
    int contadorAbelhas = 0;
    int contadorSensores = 0;

    // Variável para opções do menu
    int opcao;

    // Variável para verificar se incrementa o contador de abelhas e sensores
    int encontradoCadastrar;

    // Variável para remoção de abelha e sensores associados
    int idRemovida;

    do{
        printf("===== SISTEMA BEE MONITOR =====\n");
        printf("1. Gerenciar Abelhas\n");
        printf("2. Gerenciar Sensores\n");
        printf("3. Relatorios\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        if(scanf("%d", &opcao) != 1){
            limparBuffer(); 
            opcao = -1;
            printf("Opcao invalida! Tente novamente.\n");
        }
        
        system("clear || cls");

        switch(opcao){
            case 1:
                do{
                    printf("===== SUBMENU 1 - GERENCIAR ABELHAS =====\n");
                    printf("6. Cadastrar Abelha\n");
                    printf("7. Listar Abelhas\n");
                    printf("8. Buscar por Nome Popular\n");
                    printf("9. Alterar Dados\n");
                    printf("10. Remover Abelha\n");
                    printf("11. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    if(scanf("%d", &opcao) != 1){
                        limparBuffer(); 
                        opcao = -1;
                        printf("Opcao invalida! Tente novamente.\n");
                    }

                    system("clear || cls");

                    switch(opcao){
                        case 6:
                            encontradoCadastrar = cadastrarAbelha(tipo_abelha, contadorAbelhas);
                            if(encontradoCadastrar == 1){
                                contadorAbelhas++;
                            }
                            pausar();
                            system("clear || cls");
                            break;
                        case 7:
                            listarAbelhas(tipo_abelha, contadorAbelhas);
                            pausar();
                            system("clear || cls");
                            break;
                        case 8:
                            buscarPorNomePopular(tipo_abelha, contadorAbelhas);
                            pausar();
                            system("clear || cls");
                            break;
                        case 9:
                            alterarDadosAbelha(tipo_abelha, contadorAbelhas);
                            pausar();
                            system("clear || cls");
                            break;
                        case 10:
                            idRemovida = pedirIdRemocaoAbelha();
                            if(idRemovida >= 0){
                                contadorSensores = removerSensoresPorAbelha(tipo_sensor, contadorSensores, idRemovida);
                                contadorAbelhas = removerAbelhaPorId(tipo_abelha, contadorAbelhas, idRemovida);
                            }
                            pausar();
                            system("clear || cls");
                            break;
                        case 11:
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");        
                    }
                }while(opcao != 11);
                break;    
            case 2:
                do{
                    printf("===== SUBMENU 2 - GERENCIAR SENSORES =====\n");
                    printf("6. Cadastrar Sensor\n");
                    printf("7. Listar Sensores\n");
                    printf("8. Buscar por ID da Abelha\n");
                    printf("9. Alterar leitura\n");
                    printf("10. Remover Sensor\n");
                    printf("11. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    if(scanf("%d", &opcao) != 1){
                        limparBuffer(); 
                        opcao = -1;
                        printf("Opcao invalida! Tente novamente.\n");
                    }

                    system("clear || cls");

                    switch(opcao){
                        case 6:
                            encontradoCadastrar = cadastrarSensores(tipo_sensor, contadorSensores, tipo_abelha, contadorAbelhas);
                            if(encontradoCadastrar == 1){
                                contadorSensores++;
                            }
                            pausar();
                            system("clear || cls");
                            break;
                        case 7:
                            listarSensores(tipo_sensor, contadorSensores);
                            pausar();
                            system("clear || cls");
                            break;
                        case 8:
                            buscarPorIdAbelha(tipo_sensor, contadorSensores);
                            pausar();
                            system("clear || cls");
                            break;
                        case 9:
                            alterarDadosSensores(tipo_sensor, contadorSensores);
                            pausar();
                            system("clear || cls");
                            break;
                        case 10:
                            contadorSensores = removerSensores(tipo_sensor, contadorSensores);
                            pausar();
                            system("clear || cls");
                            break;
                        case 11:
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");        
                    }
                }while(opcao != 11);
                break;
            case 3:
                do{
                    printf("===== SUBMENU 3 - RELATORIOS =====\n");
                    printf("4. Media Geral de Producao de Mel\n");
                    printf("5. Media de Temperatura dos Sensores\n");
                    printf("6. Quantidade de Abelhas por Regiao\n");
                    printf("7. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    if(scanf("%d", &opcao) != 1){
                        limparBuffer(); 
                        opcao = -1;
                        printf("Opcao invalida! Tente novamente.\n");
                    }

                    system("clear || cls");

                    switch(opcao){
                        case 4:
                            relatorioProducaoMel(tipo_abelha, contadorAbelhas);
                            pausar();
                            system("clear || cls");
                            break;
                        case 5:
                            relatorioMediaTemperatura(tipo_sensor, contadorSensores);
                            pausar();
                            system("clear || cls");
                            break;
                        case 6:
                            relatorioQuantidadeAbelhasPorRegiao(tipo_abelha, contadorAbelhas);
                            pausar();
                            system("clear || cls");
                            break;
                        case 7:
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");        
                    }
                }while(opcao != 7);
                break;
            case 4:
                printf("SISTEMA ENCERRADO!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }while(opcao != 4);
    return 0;
}