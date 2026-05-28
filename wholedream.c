// skytale.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wholedream.h"

#define LINHA "\n--------------------------------\n\n"


void menu(Receptaculo *p){
	
	int opcao;
	
	while(1){
		
		printf("\n-MENU-\n\n");
		printf("1 - Criar receptáculo\n");
		printf("2 - Matar receptáculo\n");
		printf("3 - Ver dados do receptáculo\n");
		printf("4 - Começar campanha\n");
		printf("Digite qualquer número para sair\n");
		
		scanf("%i", &opcao);
		
		switch(opcao){
			
			case 1:
				if(p->senciencia == 1){
					printf("\nVocê já tem um!\n");
					break;
				}
				criar_personagem(p);
				break;

			case 2:
				if(p->senciencia == 0){
					printf("\nNem existe um para morrer.\n");
					break;
				}
				p->HP = 0;
				p->senciencia = 0;
				printf("\nPROJETO %s TERMINADO.\n", p->nome );
				break;

			case 3:
				if(p->senciencia == 0){
					printf("\nNem existe um para analisar.\n");
					break;
				}
				ficha(p);
				break;

			case 4:
				if(p->senciencia == 0){
					printf("\nCrie um receptáculo para começar.\n");
					break;
				}
				return; 

			default:
				return; 
		}
	}
}

void ficha(Receptaculo *p){
	
	printf("%s", LINHA);
	
	printf("Nome: %s\n", p->nome);
	printf("Idade: %i anos\n", p->idade);
	printf("Peso: %.2f kg\n", p->massa_kg);
	printf("Altura: %.2fcm\n\n", p->altura_cm);
	printf("HP: %i\n", p->HP);
	printf("Força: %i\n", p->atributos[0]);
	printf("Destreza: %i\n", p->atributos[1]);
	printf("Resistência: %i\n", p->atributos[2]);
	printf("Inteligência: %i\n", p->atributos[3]);
	printf("Sabedoria: %i\n", p->atributos[4]);
	printf("Carisma: %i\n\n", p->atributos[5]);
	printf("Atletismo: %i\n", p->ATLETISMO);
	printf("Acrobacia: %i\n", p->ACROBACIA);
	printf("Furtividade: %i\n\n", p->FURTIVIDADE);
	printf("Percepção: %i\n", p->PERCEPCAO);
	printf("Investigação: %i\n", p->INVESTIGACAO);
	printf("Conhecimento: %i\n\n", p->CONHECIMENTO);
	printf("Prestidigitação: %i\n", p->PRESTIDIGITACAO);
	printf("Armadilhas: %i\n", p->ARMADILHAS);
	printf("Persuasão: %i\n", p->PERSUASAO);
	printf("Intimidação: %i\n", p->INTIMIDACAO);
	printf("Atuação: %i\n", p->ATUACAO);
	
	printf("%s", LINHA);
	
}

void criar_personagem(Receptaculo *p){
	
	int i, pontos_fisicos, pontos_psiquicos, escolha, horas;
	
	for(i = 0; i < 6; i++){
    	
		if(i >= 3){
			
			p->atributos[i] = 3;
			continue;
			
		} 
		p->atributos[i] = 5;
    
	}

	printf("%s", LINHA);
	
	printf("SINAIS VITAIS RECALIBRADOS\n\n");
	
	printf("O receptáculo a ser criado deverá ser humano (pois a simuação está na demo.)\n\n");
	
	printf("Escolha o seu nome:\n");
	
	getchar();
	
	fgets(p->nome, 50, stdin);
	
	printf("%s", LINHA);
	
	printf("-CARATERÍSTICAS FÍSICAS-\n\n");
	
	do{
		
		printf("Tamanho (de 54,6cm a 251cm): \n");
		scanf("%f", &p->altura_cm);
	
	}while(p->altura_cm < 54.6 || p->altura_cm > 251);
	
	printf("%s", LINHA);
	
	do{
		
		printf("Peso (de 20kg a 250kg): \n");
		scanf("%f", &p->massa_kg);
		
	}while(p->massa_kg < 20 || p->massa_kg > 250);
	
	printf("%s", LINHA);
	
	if(p->massa_kg < 39 && p->altura_cm < 100){
		
		p->atributos[0] -= 1;
		p->atributos[1] += 4;
		p->atributos[2] -= 1;
		
	}else if(p->massa_kg < 97 && p->altura_cm < 100){
		
		p->atributos[0] += 2;
		p->atributos[1] -= 2;
		p->atributos[2] += 2;
		
	}else if(p->altura_cm < 100){
		
		p->atributos[0] += 1;
		p->atributos[1] -= 1;
		p->atributos[2] += 3;
		
	}else if(p->massa_kg < 39 && p->altura_cm < 170){
		
		p->atributos[0] -= 2;
		p->atributos[1] += 4;
		p->atributos[2] -= 2;
		
	}else if(p->massa_kg < 97 && p->altura_cm < 170){
		
		p->atributos[2] += 2;
		
	}else if(p->altura_cm < 170){
		
		p->atributos[0] -= 1;
		p->atributos[1] -= 1;
		p->atributos[2] += 4;
		
	}else if(p->massa_kg < 39){
		
		p->atributos[0] -= 3;
		p->atributos[1] += 8;
		p->atributos[2] -= 3;
		
	}else if(p->massa_kg < 97){
		
		p->atributos[0] += 1;
		p->atributos[1] += 1;
		p->atributos[2] += 1;
		
	} else {
		
		p->atributos[1] -= 3;
		p->atributos[2] += 4;
		
	}
	
	printf("-RESULTADOS-\n\n");
	printf("FORÇA: %i", p->atributos[0]);
	printf("\nDESTREZA: %i", p->atributos[1]);
	printf("\nRESISTÊNCIA: %i\n", p->atributos[2]);
	
	printf("%s", LINHA);
	
	printf("-Você tem 5 pontos para distribuir-\n");
	printf("-Cada atributo tem um limite de 11 pontos por enquanto-\n");
	
	pontos_fisicos = 5;

do{

	printf("\nQuantos pontos deseja colocar em FORÇA?\n");
	scanf("%i", &escolha);

	if(escolha < 0 || pontos_fisicos - escolha < 0) continue;

	p->atributos[0] += escolha;
	pontos_fisicos -= escolha;

	if(p->atributos[0] > 11){
		p->atributos[0] -= escolha;
		pontos_fisicos += escolha;
		continue;
	}

	if(pontos_fisicos == 0) break;

	printf("\nQuantos pontos deseja colocar em DESTREZA?\n");
	scanf("%i", &escolha);

	if(escolha < 0 || pontos_fisicos - escolha < 0) continue;

	p->atributos[1] += escolha;
	pontos_fisicos -= escolha;

	if(p->atributos[1] > 11){
		p->atributos[1] -= escolha;
		pontos_fisicos += escolha;
		continue;
	}

	if(pontos_fisicos == 0) break;

	printf("\nQuantos pontos deseja colocar em RESISTENCIA?\n");
	scanf("%i", &escolha);

	if(escolha < 0 || pontos_fisicos - escolha < 0) continue;

	p->atributos[2] += escolha;
	pontos_fisicos -= escolha;

	if(p->atributos[2] > 11){
		p->atributos[2] -= escolha;
		pontos_fisicos += escolha;
		continue;
	}

}while(pontos_fisicos > 0);

	printf("%s", LINHA);
	
	printf("-RESULTADOS DEPOIS DA DISTRIBUIÇÃO-\n\n");
	printf("FORÇA: %i", p->atributos[0]);
	printf("\nDESTREZA: %i", p->atributos[1]);
	printf("\nRESISTÊNCIA: %i\n", p->atributos[2]);
	
	printf("%s", LINHA);
	
	printf("-CARATERÍSTICAS MENTAIS/SOCIAIS-\n\n");
	
	do{
		
		printf("Idade (de 18 anos a 120 anos): \n");
		scanf("%i", &p->idade);
	
	}while(p->idade < 18 || p->idade > 120);
	
	printf("%s", LINHA);
	
	if(p->idade < 65){
		
		p->atributos[4] -= 1;
		p->atributos[5] += 1;
		
	} else {
		
		p->atributos[4] += 1;
		p->atributos[5] -= 1;
		
	}
	
	printf("-RESULTADOS-\n\n");
	printf("INTELIGÊNCIA: %i", p->atributos[3]);
	printf("\nSABEDORIA: %i", p->atributos[4]);
	printf("\nCARISMA: %i\n", p->atributos[5]);

	printf("-Agora você tem 13 pontos para distribuir-\n");
	printf("-Cada atributo tem um limite de 11 pontos por enquanto-\n");
	
	pontos_psiquicos = 13;

	do{

    	printf("\nQuantos pontos deseja colocar em INTELIGÊNCIA?\n");
    	scanf("%i", &escolha);

    	if(escolha < 0 || pontos_psiquicos - escolha < 0) continue;

    	if(p->atributos[3] + escolha > 11) continue;

    	p->atributos[3] += escolha;
    	pontos_psiquicos -= escolha;

    	if(pontos_psiquicos == 0) break;

    	printf("\nQuantos pontos deseja colocar em SABEDORIA?\n");
    	scanf("%i", &escolha);

    	if(escolha < 0 || pontos_psiquicos - escolha < 0) continue;

    	if(p->atributos[4] + escolha > 11) continue;

    	p->atributos[4] += escolha;
    	pontos_psiquicos -= escolha;

    	if(pontos_psiquicos == 0) break;

    	printf("\nQuantos pontos deseja colocar em CARISMA?\n");
    	scanf("%i", &escolha);

    	if(escolha < 0 || pontos_psiquicos - escolha < 0) continue;

    	if(p->atributos[5] + escolha > 11) continue;

    	p->atributos[5] += escolha;
    	pontos_psiquicos -= escolha;

	}while(pontos_psiquicos > 0);
	
	printf("%s", LINHA);
	
	printf("-RESULTADOS DEPOIS DA DISTRIBUIÇÃO-\n\n");
	printf("INTELIGÊNCIA: %i", p->atributos[3]);
	printf("\nSABEDORIA: %i", p->atributos[4]);
	printf("\nCARISMA: %i\n", p->atributos[5]);
	
	printf("\nRECEPTÁCULO CRIADO\n");
	
	printf("%s", LINHA);
	
	p->HP = 10 + 2*(p->atributos[2]);
	p->HP_var = p->HP;
	
	p->ATLETISMO = (4*p->atributos[0] + p->atributos[4])/5;
	p->ACROBACIA = (4*p->atributos[1] + p->atributos[4])/5;
	p->FURTIVIDADE = (3*p->atributos[1] + 2*p->atributos[3] - 2*(p->altura_cm)/20)/3;
	
	p->PERCEPCAO = (3*p->atributos[4] + 2*(p->altura_cm)/20)/5;
	p->INVESTIGACAO = (p->atributos[3] + p->atributos[4])/2;
	p->CONHECIMENTO = (4*p->atributos[4] + p->atributos[3])/5;
	
	p->PRESTIDIGITACAO = (4*p->atributos[1] + p->atributos[3])/5;
	p->ARMADILHAS = (p->atributos[1] + p->atributos[3])/2;
	
	p->PERSUASAO = (4*p->atributos[5] + p->atributos[4])/5;
	p->INTIMIDACAO = (2*(p->altura_cm)/20 + 2*p->atributos[5] + p->atributos[2])/5;
	p->ATUACAO = (p->PERSUASAO + p->INVESTIGACAO)/2;
	
	p->senciencia = 1;
	
	escrever_ficha("ficha.txt", p);
	menu(p);
}

void escrever_ficha(char *nome, Receptaculo *p){
	
	FILE *arq = fopen(nome, "w");
	
	if(arq == NULL){
		
		printf("\nERROR");
		return;
		
	}
	
	fprintf(arq, "Nome: %s", p->nome);
	fprintf(arq, "Idade: %i anos\n", p->idade);
	fprintf(arq, "Peso: %.2f kg\n", p->massa_kg);
	fprintf(arq, "Altura: %.2fcm\n\n", p->altura_cm);
	fprintf(arq, "HP: %i\n", p->HP);
	fprintf(arq, "Força: %i\n", p->atributos[0]);
	fprintf(arq, "Destreza: %i\n", p->atributos[1]);
	fprintf(arq, "Resistência: %i\n", p->atributos[2]);
	fprintf(arq, "Inteligência: %i\n", p->atributos[3]);
	fprintf(arq, "Sabedoria: %i\n", p->atributos[4]);
	fprintf(arq, "Carisma: %i\n\n", p->atributos[5]);
	fprintf(arq, "Atletismo: %i\n", p->ATLETISMO);
	fprintf(arq, "Acrobacia: %i\n", p->ACROBACIA);
	fprintf(arq, "Furtividade: %i\n", p->FURTIVIDADE);
	fprintf(arq, "Percepção: %i\n", p->PERCEPCAO);
	fprintf(arq, "Investigação: %i\n", p->INVESTIGACAO);
	fprintf(arq, "Conhecimento: %i\n", p->CONHECIMENTO);
	fprintf(arq, "Prestidigitação: %i\n", p->PRESTIDIGITACAO);
	fprintf(arq, "Armadilhas: %i\n", p->ARMADILHAS);
	fprintf(arq, "Persuasão: %i\n", p->PERSUASAO);
	fprintf(arq,"Intimidação: %i\n", p->INTIMIDACAO);
	fprintf(arq, "Atuação: %i\n", p->ATUACAO);
	fprintf(arq, "%i", p->senciencia);
	
	fclose(arq);
	
}

void save_receptaculo(char *nome, Receptaculo *p){
	
	FILE *arq = fopen(nome, "r");
	
	char linha[51];
	
	if(arq == NULL || fgets(linha, sizeof(linha), arq) == NULL){
		
		p->senciencia = 0;
		return;
		
	}
	
	rewind(arq);
	
	fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %[^\n]", p->nome);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->idade);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %f", &p->massa_kg);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %f", &p->altura_cm);

    fgets(linha, sizeof(linha), arq);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->HP);
	p->HP_var = p->HP;

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->atributos[0]); // Força

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->atributos[1]); // Destreza

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->atributos[2]); // Resistência

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->atributos[3]); // Inteligência

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->atributos[4]); // Sabedoria

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->atributos[5]); // Carisma

    fgets(linha, sizeof(linha), arq);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->ATLETISMO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->ACROBACIA);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->FURTIVIDADE);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->PERCEPCAO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->INVESTIGACAO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->CONHECIMENTO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->PRESTIDIGITACAO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->ARMADILHAS);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->PERSUASAO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->INTIMIDACAO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%*[^:]: %d", &p->ATUACAO);

    fgets(linha, sizeof(linha), arq);
    sscanf(linha, "%d", &p->senciencia);
	
	
	fclose(arq);
}
