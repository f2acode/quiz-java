#include <stdio.h> 
#include <locale.h>
#include <string.h>

/*! \brief O programa é um questionário de perguntas sobre Java realizado em C.
* \file Quiz.c
*
* Foi utilizada estrutura de dados e alocação dinâmica de memória
*
* Foi utilizada na estrutura de dados uma lista ligada com memória dinâmica
*
*\autor Felipe Augusto RA: 20417054
*\date 28-11-2016
*\version 1
*
*/

typedef struct prova{
		char perg[800];
		char resp;
		struct prova* prox;
}p;

void main(){

    FILE *prova; 
    FILE *arqPontuacao;
	setlocale(LC_ALL, "Portuguese");

	struct prova *primeiro;
	struct prova *atual;
	
	char nome[20];
	int pontuacao;
	
	primeiro = (p*) malloc(sizeof(p));
	
	atual = primeiro;
	
//Aqui é realizada a leitura das questões do arquivo

	char ch;
    int i;
    int j;
    
    prova = fopen ("questoes.txt", "r");
      
	for(i=0;i<30;i +=1){
    
    	for(j=0;j<700;j+=1){
    		atual->perg[j]= '\0';
		}
		atual->resp='\0';
		
   	j=0;
		while((ch=fgetc(prova))!= '*'){
				atual->perg[j] = ch;
				j++;
		}
		ch=fgetc(prova);
		atual->resp = ch;
		
		atual->prox = (p*) malloc(sizeof(p));
		atual = atual->prox;
	}
		
//Escolhendo o nível que o aluno pode jogar

    printf("Informe o seu RA: \n");
    scanf("%s", &nome);
    
    printf("\nOlá %s! Divirta-se!\n", &nome);
    
    arqPontuacao = fopen(strcat(nome,".txt"), "w");
    
    fflush(stdin);

	int nivel;
    printf("\nEscolha o nível de dificuldade:\n1 - Fácil\n2 - Médio\n3 - Difícil\n\n");
    scanf("%d", &nivel);    
    
    if(nivel==1){
    	atual = primeiro;
	printf("\n");
	char alternativa;
	for(i =0;i<10;i +=1){
		j=0;
		while(atual->perg[j] != '\0'){
				printf("%c", atual->perg[j]);
				j++;
		}
		fflush(stdin); 
		scanf("%c", &alternativa);
		if(atual->resp == alternativa){
			printf("\nParabéns, você acertou!");
			pontuacao++;
		}else{
			printf("\nVocê errou!");
		}
		printf("\nAlternativa certa: %c \n", atual->resp);
		atual = atual->prox;
	}
	}
	
	else if(nivel == 2){
		atual = primeiro;
		
		int i;
		for(i=0;i<10;i++){
			atual = atual->prox;
		}
		
	printf("\n");
	char alternativa;
	for(i =10;i<20;i +=1){
			j=0;
		while(atual->perg[j]!= '\0'){
				printf("%c", atual->perg[j]);
				j++;
		}
		fflush(stdin); 
		scanf("%c", &alternativa);
		if(atual->resp== alternativa){
			printf("\nParabéns, você acertou!");
			pontuacao++;
		}else{
			printf("\nVocê errou!");
		}
		printf("\nAlternativa certa: %c \n", atual->resp);
		atual = atual->prox;
	}
	}
	
	else if(nivel == 3){
		
			atual = primeiro;
		
		int i;
		for(i=0;i<20;i++){
			atual = atual->prox;
		}
		
	printf("\n");
	char alternativa;
	for(i =20;i<30;i +=1){
		j=0;
		while(atual->perg[j] != '\0'){
				printf("%c", atual->perg[j]);
				j++;
		}
		fflush(stdin); 
		scanf("%c", &alternativa);
		if(atual->resp == alternativa){
			printf("\nParabéns, você acertou!");
			pontuacao++;
		}else{
			printf("\nVocê errou!");
		}
		printf("\nAlternativa certa: %c \n", atual->resp);
		atual = atual->prox;
	}
	}
		pontuacao += 48;
		fputc(pontuacao,arqPontuacao);
} 

