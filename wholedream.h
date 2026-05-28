// skytale.h

typedef struct Receptaculo{
	
	//ATRIBUTOS INATOS
	char nome[51];				
	float altura_cm;			//atributo[0] força
	float massa_kg;				//atributo[1] destreza
	int idade;					//atributo[2] resistência
	int atributos[6];			//atributo[3] inteligência
	int HP;						//atributo[4] sabedoria && atributo[5] carisma
    int HP_var;
	      
	//ATRIBUTOS ADQUIRIDOS
	
	int ATLETISMO;
	int ACROBACIA;
	int FURTIVIDADE;
	
	int PERCEPCAO;
	int INVESTIGACAO;
	int CONHECIMENTO;
	
	int PRESTIDIGITACAO;
	int ARMADILHAS;
		
	int PERSUASAO;
	int INTIMIDACAO;
	int ATUACAO;
	
	// estranho...
	int senciencia;
	             
}Receptaculo;

typedef struct Inventario{
	
	int chave;
	int queijo;
	
}Inventario;

typedef struct Estados{
	
	int mao_quebrada;
	int rato_morto;
	int papel_lido;
	int aranha_morta;
	int envenenado;
	
}Estados;

//save, loads, menus e etc

void menu(Receptaculo *p);
void criar_personagem(Receptaculo *p);
void ficha(Receptaculo *p);
void escrever_ficha(char *nome, Receptaculo *p);
void save_receptaculo(char *nome, Receptaculo *p);

//Outras funções
void digitar(const char *formato, int timer, ...);
int checar_hp(Receptaculo *p, int dano, int cura);

//campanha parte 1
void cabana_de_madeira(Receptaculo *p, Inventario *i, Estados *e);
int porta(Receptaculo *p, Inventario *i, Estados *e);
int escrivaninha(Receptaculo *p, Inventario *i, Estados *e);
int janela(Receptaculo *p, Inventario *i, Estados *e);
int toca_rato(Receptaculo *p, Inventario *i, Estados *e);
int luta_rato(Receptaculo *p, Inventario *i, Estados *e);
