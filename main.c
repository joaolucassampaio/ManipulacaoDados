#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//Ponteiro para arquivo
	//O tipo FILE está definido na biblioteca stdio.h
	//fp = file pointer
	FILE *fp;
	char frase[50];
	int i;
	int tamanho;

	//Função usada para criar um arquivo ou abrir um arquivo existente	
	//Para trabalhar com um arquivo, a primeira operação necessária é abrir este arquivo
	//Sintaxe de abertura de arquivo: <ponteiro> = fopen("nome do arquivo", "tipo de abertura");
	//fp = fopen(const char filename,const char mode);
	fp = fopen("arquivo.txt", "w"); //Abrindo o arquivo
	
	//Verificação de problemas na abertura:
	//Quando o arquivo não pode ser aberto, a função fopen retorna o valor NULL
	if(fp == NULL){
		printf("Erro ao abrir o arquivo. Por favor, tente novamente.");
		exit(1);
	}else {
		printf("O arquivo foi criado com sucesso...");	
	};
	
	printf("\nDigite a frase a ser escrita no arquivo: ");
	gets(frase);
	//scanf("%s", palavra); // "%s" armazena dados do tipo string
	
	//Gravando dados em arquivos
	//Para isso, usa-se a função fprint
	//Sintaxe: fprint(nomeDoPonteiroParaOArquivo, "%s", variavel_string);
	//fprint(fp, "%s", palavra);
	
	//verificando a quantidade de caracteres da string frase
	tamanho = strlen(frase);
	
	//gravando caracter por caracter
	for(i = 0; i < tamanho; i++) {
		fputc(frase[i], fp);
	}
	
	//Fechando arquivo
	fclose(fp);
	
	printf("Dados gravados com sucesso!");
	
	
	
	return 0;
}
