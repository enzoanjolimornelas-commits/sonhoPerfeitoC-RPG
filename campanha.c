// campanha.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdarg.h>

#include "wholedream.h"

#define LINHA "\n--------------------------------\n"

void digitar(const char *formato, int timer, ...){
    
    char buffer[1000];
    
    va_list args;
    va_start(args, timer);
    vsprintf(buffer, formato, args);
    va_end(args);

    int i = 0, contador = 0;

    while(buffer[i] != '\0'){
        printf("%c", buffer[i]);
        Sleep(timer);
        contador++;

        if(contador >= 100 && buffer[i] == ' '){
            printf("\n");
            contador = 0;
        }

        i++;
    }
}

int checar_hp(Receptaculo *p, int dano, int cura){
	
	if(cura == 0){
	
		p->HP_var -= dano;
	
		if(p->HP_var <= 0) return 0;
		return 1;
		
	}
	
	p->HP_var += cura;
	
	if(p->HP_var > p->HP){
		
		p->HP_var = p->HP;
		
	}
	
	return 1;
}


void cabana_de_madeira(Receptaculo *p, Inventario *i, Estados *e){
	
	printf("%s", LINHA);
	
	Sleep(1000);
	
	digitar("Atividades neurais inicializando", 20);
	
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(2000);
	
	digitar("\n\nExecução bem-sucedida.", 20);
	
	Sleep(1000);
	
	digitar("\n\nSeus olhos abrem.", 20);
			
	digitar("\n\nVocê enxerga um teto de madeira, e escuta guinchos de rato.", 15);
	
	Sleep(1000);
	
	digitar("\n\nApós se espregiçar, você senta na cama.", 15);
	
	printf("%s", LINHA);
	
	int escolha = 0;
	
	while(escolha == 0){

		digitar("\n\nUma claridade azul intensa está entrando pela janela da direita e ela está iluminando uma toca de rato a esquerda, logo a sua frente tem uma escrivaninha bem rústica e a esquerda dela está a porta da cabana.", 10);
			
		digitar("\n\n1 - Ir para porta.", 20);
		digitar("\n2 - Analizar escrivaninha.", 20);
		digitar("\n3 - Ir para janela.", 20);
		digitar("\nQ.N (Qualquer Número) - Analizar toca.\n", 20);
			
		scanf("%i", &escolha);
		
		switch(escolha){
			
			case 1:
				escolha = porta(p, i, e);
				break;
			case 2:
				escolha = escrivaninha(p, i, e);
				break;
			case 3:
				escolha = janela(p, i, e);
				break;
			default:
				escolha = toca_rato(p, i, e);
				break;
		}
				
	}
	
	Sleep(1000);
	digitar("\n\nVocê sai da cabana de madeira.", 25);
	Sleep(1000);
	digitar("\n\nVê toda a ambientação inóspita, de cogumelos azuis enormes e de pequenas criaturas perigosas.", 25);
	Sleep(500);
	if(e->papel_lido == 1){
		
		digitar("\n\n%s: Por que aquele papel tinha o meu nome?", 25, &p->nome);
		
	} 
	
	Sleep(500);
	digitar("\n\n%s: Não me lembro do que aconteceu antes de eu acordar.", 30, &p->nome);
	Sleep(500);
	digitar("\n\n%s: Por que estou aqui?", 30, &p->nome);
	Sleep(500);
	
	if(e->envenenado == 1){
		
		digitar("\n\nA ferida da picada da aranha começa a doer mais.", 25);
		Sleep(500);
		digitar("\n\nNascem cogumelos em suas mãos e braços...", 25);
		
	}
	
	Sleep(5000);
	digitar("\n\n\nFIM DA BETA (DA BETA).", 25);
	Sleep(2000);
	
}	


int porta(Receptaculo *p, Inventario *i, Estados *e){
	
	int escolha;
	
door:
	
	digitar("\nUma porta antiga, mas aparentemente bem cuidada (como se cuida uma porta?)", 15);
	digitar("\n\nTentar abrir e sair?", 15);
	digitar("\n1 - Sim.", 15);
	digitar("\nQ.N - Não, e irei voltar a cama.\n", 15);
	
	scanf("%i", &escolha);
	
	switch(escolha){
		
		case 1:
			
			Sleep(1000);
			if(i->chave == 1){
				
				digitar("\n\nVocê", 20);
				Sleep(1000);
            	printf(".");
	            Sleep(1000);
	            printf(".");
	            Sleep(1000);
	            printf(".");
	            Sleep(2000);
				
				digitar("girou a chave e conseguiu abrir a porta!", 20);
				return 1;
				
			}
			
			digitar("\n\nVocê tenta girar a maçaneta, mas a porta não abre.\n", 15);
			goto door;
		default:
			return 0;
			
	}
	
}

int escrivaninha(Receptaculo *p, Inventario *i, Estados *e){

door:

    if(i->queijo == 0 && p->PERCEPCAO >= 6){
        
        digitar("\nTeste de PERCEPÇÃO foi bem-sucedido!", 15);
        
        i->queijo = 1;
        
        digitar("\nVocê achou um queijo bem escondido em cima da escrivaninha, aparentemente em bom estado, você pegou ele.", 15);
    }

    int escolha;
    
    digitar("\n\nUma escrivaninha, com aparentes marcas do tempo. Há um papel velho acima, com um tinteiro derramado nele, e uma gaveta abaixo.", 15);
    digitar("\n\n1 - Ler papel.", 15);
    digitar("\n2 - Abrir gaveta.", 15);
    digitar("\nQ.N - Voltar a cama.\n", 15);
    
    scanf("%i", &escolha);
    
    switch(escolha){
        
        case 1:
            
            if(e->papel_lido == 0){
                
                Sleep(500);
            	digitar("\n\n%s", 20, p->nome);
            
            	Sleep(1000);
            	printf(".");
	            Sleep(1000);
	            printf(".");
	            Sleep(1000);
	            printf(".");
	            Sleep(2000);
                
                digitar("\n\nO que você irá fazer...", 20);
                Sleep(1000);
                digitar("\n\nQuando a lua azul se esvanecer?", 20);
                Sleep(1000);
                digitar("\n\nSimples,", 20);
                Sleep(1000);
                digitar(" -TEXTO BORRADO COM TINTA-", 20);
                Sleep(1000);
            
                if(p->INVESTIGACAO >= 8){
                    
                    digitar("\n\nTeste de INVESTIGAÇÃO foi bem-sucedido!", 15);
                    
                    digitar("\nVocê consegue pegar o papel e raspar ele com força na madeira.", 15);
                    digitar("\nAgora é possível ler.", 15);
                    
                    Sleep(1000);
                    
                    digitar("\n\nSimples, jogue a espada no núcleo de tudo e todos.", 15);
                    
                    Sleep(1000);
                    
                    digitar("\n\nVocê ainda pode não entender o que está escrito neste papel.", 15);
                    
                } else {
                    digitar("\n\nVocê não consegue entender o que está borrado.", 15);
                }

            } else {
                digitar("\n\nVocê já leu.", 15);
            }

			e->papel_lido = 1;

            goto door;

        case 2:

		    if(e->aranha_morta == 0 && e->envenenado == 0){
		
		        digitar("\n\nVocê abre a gaveta", 15);
    
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(2000);
				
				digitar("\n\nUma aranha cogumelo pula e tenta picar sua mão!", 5);

		        if(p->PRESTIDIGITACAO >= 6){
		            
		            digitar("\n\nTeste de PRESTIDIGITAÇÃO bem-sucedido!", 15);
		            digitar("\nVocê velozmente tira a mão e esmaga a aranha!", 15);
					
					e->aranha_morta == 1;
		        } else {
		            
		            digitar("\n\nA aranha picou sua mão!", 15);
		            digitar("\n\nVocê sofreu 4 de dano!", 15);
		
		            int morreu = checar_hp(p, 4, 0);
		
		            if(morreu == 0){
		                
		                Sleep(1000);
		                digitar("\n\nSeu corpo se desmonta.", 15);
		                Sleep(1000);
		                exit(0);
		            }
		
		            e->envenenado = 1;
		
		            digitar("\n\nEla rasteja rapidamente para a brecha da porta e foge.", 15);
		            digitar("\n\nIsto pode ter consequências no futuro.", 15);
		        }
		
		    } 
		    
		    else {
		
		        digitar("\n\nA gaveta já está aberta.", 15);
		    
		    }
		
		    goto door;
            
        default:
            return 0;
    }
}

int janela(Receptaculo *p, Inventario *i, Estados *e){
	
	int escolha;
	
window:
	
	digitar("\n\nUma janela fechada, a madeira range com o vento.", 20);
	digitar("\n1 - Ver paisagem.", 20);
	digitar("\n2 - Tentar quebrar janela com a mão e sair.", 20);
	digitar("\nQ.N - Voltar para cama.\n", 20);
	scanf("%i", &escolha);
	
	switch(escolha){
		
		case 1:
			digitar("\n\nVocê vê cogumelos azuis enormes e o que parece ser um milhão de vagalumes por aí, você sente cheiro de barata molhada (ué?)", 20);
			goto window;
		case 2:
			Sleep(1000);	
			if(e->mao_quebrada == 0 && p->ATLETISMO < 9){
				
				digitar("\n\nVocê bate na janela de tão mal jeito que não foi a janela que quebrou, mas sim a sua mão.", 20);
				e->mao_quebrada = 1;
				digitar("\nVocê sofreu 3 de dano!", 20);
				
				int morreu = checar_hp(p, 3, 0);
		
		            if(morreu == 0){
		                
		                Sleep(1000);
		                digitar("\n\nSeu corpo se desmonta.", 15);
		                Sleep(1000);
		                exit(0);
		            }
				goto window;
				
			} else{
				
				digitar("\n\nTeste de ATLETISMO bem-sucedido!", 15);
				
				digitar("\n\nVocê", 20);
				printf(".");
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(2000);
				digitar(" conseguiu!", 20);
				
				return 1;
				
		}
			
			digitar("\n\nPor favor, não tente de novo.", 20);
			
			goto window;
			
		default:
			return 0;	
			
	}

}

int toca_rato(Receptaculo *p, Inventario *i, Estados *e){
	
	int escolha;
	
	digitar("\nHavia um pequeno buraco na parede de madeira, roído de forma irregular, grande o suficiente para um rato passar.", 20);
	
	Sleep(1000);
	
hole:
	
	if(e->rato_morto == 0 && i->chave == 0){
	
		digitar("\n\nDas sombras da parede, algo se moveu. Era um rato não muito comum. Sua boca parecia grande demais para o corpo, escura e profunda como um buraco na realidade, ele também tinha uma antena. Diziam que era um Rato Boca de Abismo, uma criatura que roía não só madeira… mas qualquer coisa que estivesse no caminho.\n", 5);
		
		Sleep(1000);
		
		digitar("\nVocê também avista uma chave atrás dele.", 20);
		
		digitar("\n1 - Ameaçar.", 20);
		digitar("\n2 - Tentar pegar chave.", 20);
		if(i->queijo == 1) digitar("\n3 - Dar queijo!", 20);
		digitar("\nQ.N - Voltar para a cama pacificamente.\n", 20);
		scanf("%i", &escolha);
		
		switch(escolha){
			
			case 1:
				
				if(p->INTIMIDACAO >= 9){
					
					Sleep(1000);
					digitar("\n\nVocê tentou imitar um cachorro assustador chupando manga, o roedor ficou assustado, e se escondeu lá pro fundo do buraco.", 20);
					digitar("\nVocê pegou a CHAVE!", 20);
					
					i->chave = 1;
					return 0;
				}
			
				digitar("\n\nVocê imitou um gato atacando o próprio rabo", 20);
			
				Sleep(1000);
	    		printf(".");
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(1000);
	    		printf(".");
	    		Sleep(1000);
	    		
	    		digitar(" mas não tem um rabo!", 20);
	    		digitar("\nO Boca de Abismo só te olhou com indiferença.", 20);
			
				goto hole;
		
			case 2:
				
				escolha = luta_rato(p, i, e);
				break;
				
			case 3:
				
				if(i->queijo == 0) return 0;
				else{
					
					digitar("\n\nAnimado com o queijo, o rato corre para dentro da toca, deixando a chave parcialmente à mostra.", 20);
					digitar("\nVocê pegou a chave sem problemas.", 20);
					i->chave = 1;
					
				}	
				return 0;
			default:
				return 0;
			
		}
		
	}else {
		
		digitar("\n\nTem mais nada para ser visto aqui.", 15);
		
	}
	
	
	
}

int luta_rato(Receptaculo *p, Inventario *i, Estados *e){
	
	int escolha, inimigo = 8;
	
	digitar("\n\nQuando você se aproxima, o roedor começa a ficar nervoso.", 20);
	digitar("\n-", 20);
		
	Sleep(2000);
				
	digitar("tchi tchi TCHIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII.", 3);
		
	Sleep(500);
				
	digitar("\n\nDezenas de roedores saem correndo da toca, eles parecem hostis.", 20);
	digitar("\n1 - Tentar pisar neles.", 20);
	digitar("\nQ.N - Tentar se defender ficando de côcoras.\n", 20);
	scanf("%i", &escolha);
	
	switch(escolha){
		
		case 1:
			if(p->ACROBACIA >= inimigo){
				
				digitar("\n\nTeste de ACROBACIA bem-sucedido!", 15);
				
				digitar("\n\nVocê pisa em um.", 20);
				
				Sleep(500);
				
				digitar("\nDepois em outro", 20);
				
				Sleep(500);
				
				digitar("\nEm outro.", 20);
				
				Sleep(500);
				
				digitar("\nE em outro.", 20);
				
				digitar("\nAgora tem menos ratos! É mais fácil combatê-lo agora!", 20);
				
				inimigo -= 2;
				
			} else {
				
				digitar("\n\nVocê quase tropeçou, e um dos ratos mordeu a sua canela!", 20);
				digitar("\nVocê sofreu 8 de dano!", 20);
				
				int morreu = checar_hp(p, 8, 0);
		
		            if(morreu == 0){
		                
		                Sleep(1000);
		                digitar("\n\nVocê cai e a colônia de ratos te consome.", 15);
		                Sleep(1000);
		                exit(0);
		            }
					
			}
		
			break;
		default:
			
			if(p->atributos[2] >= inimigo){
				
				digitar("\n\nTeste de RESISTÊNCIA bem-sucedido!", 15);
				
				digitar("\n\nNenhum rato consegue te machucar!", 20);
				
				inimigo -= 2;
				
			} else {
				
				digitar("\nSua defesa foi fraca!", 20);;
				digitar("\nUm rato te morde na coxa!", 20);
				
				digitar("\nVocê sofreu 9 de dano!", 20);
				
				int morreu = checar_hp(p, 9, 0);
		
		            if(morreu == 0){
		                
		                Sleep(1000);
		                digitar("\n\nVocê cai e a colônia de ratos te consome.", 15);
		                Sleep(1000);
		                exit(0);
		            
					}
				
			}
			
	}
	
	digitar("\n\nA antena do rato brilha amarelo.", 20);
	Sleep(600);
	digitar("\n\nTodos os outros ratos se juntam em torno dele.", 20);
	digitar("\nAos poucos.", 20);
	Sleep(600);
	digitar("\nComeçaram a se acumular.", 20);
	Sleep(600);
	digitar("\nUm sobre o outro.", 20);
	Sleep(600);
	digitar("\nSe encaixando.", 20);
	Sleep(600);
	digitar("\nA colônia de ratos formou uma figura humanóide.", 20);
	digitar("\n1 - Lutar.", 20);
	digitar("\nQ.N - Se deixar ser consumido.\n", 20);
	scanf("%i", &escolha);
	
	switch(escolha){
		
		case 1:
			
			if(p->CONHECIMENTO >= inimigo){
				
				digitar("\n\nTeste de CONHECIMENTO bem-sucedido!", 15);
				digitar("\nVocê imaginou ou já sabia que se o rato com a antena morrer, todo o resto morre.", 20);
				Sleep(600);
				digitar("\nVocê se joga na colônia de ratos.", 20);
				Sleep(600);
				digitar("\nPega o rato com a antena na mão e esmaga ele.", 25);
				digitar("\nTodos os ratos caem duro no chão.", 25);
				Sleep(600);
				digitar("\n\nVocê pegou a chave que estava na toca.", 30);
				i->chave = 1;
				e->rato_morto = 1;
				return 0;
				
			} else if (p->ATLETISMO >= inimigo){
				
				digitar("\n\nTeste de ATLETISMO bem-sucedido!", 15);
				digitar("\n%s vai em direção a figura humanóide.", 25, &p->nome);
				digitar("\nOs ratos dão vários socos em sequência no rosto.", 25);
				
				digitar("\nVocê sofreu 6 de dano!", 20);
				
				int morreu = checar_hp(p, 5, 0);
		
		            if(morreu == 0){
		                
		                Sleep(1000);
		                digitar("\n\nVocê cai e a colônia de ratos te consome.", 15);
		                Sleep(1000);
		                exit(0);
		            
					}
				
				digitar("\n\nVocê teve uma certa resistência contra os golpes, tu dá uma joelhada na suposta barriga, a colônia fica um pouco incapacitada e %s finaliza com um soco na cabeça (matando o rato com antena).", 25, &p->nome);
				digitar("\nTodos os ratos caem duro no chão.", 25);
				Sleep(600);
				digitar("\n\nVocê pegou a chave que estava na toca.", 30);
				e->rato_morto = 1;
				i->chave = 1;
				return 0;
			}else{
				
				Sleep(1000);
		        digitar("\n\nVocê perde a luta e a colônia de ratos te consome.", 15);
		        Sleep(1000);
		        exit(0);
				
			}
			break;
		default:
			
			Sleep(1000);
		    digitar("\n\nVocê cai e a colônia de ratos te consome.", 15);
		    Sleep(1000);
		    exit(0);
			
	}
	
}
