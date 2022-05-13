#include <stdio.h>


int x=0,y=0,v=0,count=0,pos=0,verx=0,vero=0,verv=0;
int linha=0,coluna=0;
char matriz[3][5];


void gerar();
void verificar_velha();
void verificar_linha();
void verificar_coluna();
void verificar_diag();
void receber_jogada();
void jogador1();
void jogador2();
void posicao();
void print_matriz();


int main(void){	

	gerar();
	print_matriz();
	verificar_velha();
	verificar_linha();
	verificar_coluna();
	verificar_diag();
	receber_jogada();
	posicao();
	jogador1();
	jogador2();
	
}


void gerar(){
	matriz[0][1] = matriz[0][3] = matriz[1][1] = matriz[1][3] = matriz[2][1] = matriz[2][3] = '|';
	matriz[0][0] = matriz[0][2] = matriz[0][4] = matriz[1][0] = matriz[1][2] = matriz[1][4] = '_';
	matriz[2][0] = matriz[2][2] = matriz[2][4] = ' ';
}

void print_matriz(){
	system("cls");
	for (x=0;x<3;x++){
		for (y=0;y<5;y++){
			printf("%c", matriz[x][y]);
		}
		printf("\n");
	}
}

void receber_jogada(){
	for(count=0;count<=9;count++){
		if(count%2 == 0){
			jogador1();
			verificar_velha();
			verificar_linha();
			verificar_coluna();
			verificar_diag();
		}
		else{
			jogador2();
			verificar_velha();
			verificar_linha();
			verificar_coluna();
			verificar_diag();
		}
	}
}

void jogador1(){
	if(v==0){
		printf("Jogador 1, Insira uma Posicao de 1 a 9:");
		scanf("%d", &pos);
		posicao();
		if(matriz[linha][coluna] == '_' || matriz[linha][coluna] == ' '){
			matriz[linha][coluna] = 'X';
			print_matriz();
		}
		else{
			print_matriz();
			printf("Jogada Invalida, Tente Novamente !!!\n");
			jogador1();
		}
	}
}

void jogador2(){
	if(v==0){
		printf("Jogador 2, Insira uma Posicao de 1 a 9:");
		scanf("%d", &pos);
		posicao();
		if(matriz[linha][coluna] == '_' || matriz[linha][coluna] == ' '){
			matriz[linha][coluna] = 'O';
			print_matriz();
		}
		else{
			print_matriz();
			printf("Jogada Invalida, Tente Novamente !!!\n");
			jogador2();
		}
	}
}


void posicao(){
	switch(pos){
		case(1):
			linha = 0,coluna = 0;
			break;
		case(2):
			linha = 0,coluna = 2;
			break;
		case(3):
			linha = 0,coluna = 4;
			break;
		case(4):
			linha = 1,coluna = 0;
			break;
		case(5):
			linha = 1,coluna = 2;
			break;
		case(6):
			linha = 1,coluna = 4;
			break;
		case(7):
			linha = 2,coluna = 0;
			break;
		case(8):
			linha = 2,coluna = 2;
			break;
		case(9):
			linha = 2,coluna = 4;
			break;
		default:
			printf("Posição não existe!!");
			break;
	}
}

void verificar_linha(){
	if(v==0){
		for(x=0;x<3;x++){
			for(y=0;y<5;y++){
				if(matriz[x][y] == 'X')
					verx++;
				if (verx >= 3){
					v=1;
					printf("Jogador 1 Venceu!!!\n");
				}
				if(matriz[x][y] == 'O')
					vero++;
				if (vero >= 3){
					v=1;
					printf("Jogador 2 Venceu!!!\n");
				}
			}
			verx = 0;
			vero = 0;
		}
		verx = 0;
		vero = 0;
	}
}

void verificar_coluna(){
	if(v==0){
		for(x=0;x<5;x++){
			for(y=0;y<3;y++){
				if(matriz[y][x] == 'X')
					verx++;
				if (verx >= 3){
					v=1;
					printf("Jogador 1 Venceu!!!\n");}
				if(matriz[y][x] == 'O')
					vero++;
				if (vero >= 3){
					v=1;
					printf("Jogador 2 Venceu!!!\n");}
			}
			verx = 0;
			vero = 0;
		}
		verx = 0;
		vero = 0;
	} 
}

void verificar_diag(){
	if(v==0){
		if(matriz[0][0] == 'X' && matriz[1][2] == 'X' && matriz[2][4] == 'X'){
			v=1;
			printf("Jogador 1 Venceu!!!\n");}
		if(matriz[0][0] == 'O' && matriz[1][2] == 'O' && matriz[2][4] == 'O'){
			v=1;
			printf("Jogador 2 Venceu!!!\n");}
		if(matriz[0][4] == 'X' && matriz[1][2] == 'X' && matriz[2][0] == 'X'){
			v=1;
			printf("Jogador 1 Venceu!!!\n");}
		if(matriz[0][4] == 'O' && matriz[1][2] == 'O' && matriz[2][0] == 'O'){
			v=1;
			printf("Jogador 2 Venceu!!!\n");}
	}
}

void verificar_velha(){
	if(v==0){
		for (x=0;x<3;x++){
			for (y=0;y<5;y++){
				if(matriz[x][y] == 'X' || matriz[x][y] == 'O')
					verv++;
				if(verv>8){
					v=1;
					printf("Deu velha!!!\n");
				}
			}
		}
		verv=0;
	}
}