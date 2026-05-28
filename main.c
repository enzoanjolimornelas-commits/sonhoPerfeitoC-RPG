#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "wholedream.h"

int main(int argc, char *argv[]) {
	
	Receptaculo personagem = {0};
	Inventario inventario = {0};
	Estados estados = {0};
	
	save_receptaculo("ficha.txt", &personagem);
	
	setlocale(LC_ALL, "Portuguese");

	printf("Bem-vindo a PERFECTDREAM.project!\n");

	menu(&personagem);
	cabana_de_madeira(&personagem, &inventario, &estados);
	
	return 0;
}
