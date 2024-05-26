#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu() {
    printf("Bem vindo(a) ao Sistema de Arquivamento de Tarefas!");
    printf("\nEm que posso ajudar hoje?");
    printf("\n1. Inserir nova tarefa;");
    printf("\n2. Consultar tarefas registradas;");
    printf("\n3. Consultar tarefas do dia;");
    printf("\n4. Sair.");
    printf("\nDigite alguma opcao do menu: ");
}

char *criarTarefa() {
    char dataTarefa[20];
    char descricaoTarefa[100];
    static char textoFinal[200];
    
    printf("Informe a data da tarefa (dd/mm/aaaa): ");
    scanf("%s", dataTarefa);
    
    printf("Informe uma descricao para a tarefa: ");
    scanf(" %[^\n]", descricaoTarefa);
    
    strcpy(textoFinal, dataTarefa);
    strcat(textoFinal, " - ");
    strcat(textoFinal, descricaoTarefa);
    
    return textoFinal;
}

void inserirTarefa(char *tarefa) {
    FILE *fp;
    fp = fopen("arquivo.txt", "a+");
    
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo, tente novamente.");
        exit(1);
    }
    
    fprintf(fp, "%s\n", tarefa);
    fclose(fp);
    
    printf("Tarefa adicionada: %s", tarefa);
}

void consultarTarefas() {
    FILE *fp;
    char linha[200];
    
    fp = fopen("arquivo.txt", "r");
    
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo, tente novamente.");
        exit(1);
    }
    
    printf("Tarefas registradas:\n");
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        printf("%s", linha);
    }

    fclose(fp);
}

void consultarTarefasDoDia() {
    FILE *fp;
    char linha[200];
    
    struct tm *dataHoraAtual;
    time_t segundos;
    time(&segundos);
    dataHoraAtual = localtime(&segundos);
    
    fp = fopen("arquivo.txt", "r");
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo, tente novamente.");
        exit(1);
    }
    
    printf("Tarefas do dia:\n");
    char dia[3], mes[3], ano[5];
    sprintf(dia, "%02d", dataHoraAtual->tm_mday);
    sprintf(mes, "%02d", dataHoraAtual->tm_mon + 1);
    sprintf(ano, "%04d", dataHoraAtual->tm_year + 1900);
    
    char dataAtual[11];
    snprintf(dataAtual, sizeof(dataAtual), "%s/%s/%s", dia, mes, ano);
    
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        if (strncmp(linha, dataAtual, 10) == 0) {
            printf("%s", linha);
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int opcao;
    char *tarefa;
    menu();
    
    do {
        scanf("%d", &opcao);
        printf("\n\n");
        
        switch(opcao){
            case 1:
                tarefa = criarTarefa();
                inserirTarefa(tarefa);
                printf("\n\nDigite alguma opcao do menu: ");
                break;
            
            case 2:
                consultarTarefas();
                printf("\nDigite alguma opcao do menu: ");
                break;
            
            case 3:
                consultarTarefasDoDia();
                printf("\nDigite alguma opcao do menu: ");
                break;
            
            case 4:
                break;
            
            default:
                printf("Opcao invalida, tente novamente.\n\n\n");
                printf("Digite alguma opcao do menu: ");
                break;
        }
                
    } while (opcao != 4);
    
    system("cls");
    printf("Programa encerrado com sucesso!");
    
    return 0;
}

