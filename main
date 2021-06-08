// NOME: Caio Oliveira Marques

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"

int main(){
	setlocale(LC_ALL, "Portuguese");

	int quantidadeAssentos;
	char nomeUsuario[30];
	int idadeUsuario;
	int opcao;
	char nomeDestino[30];
	float preco = 0;
	
	// cadastrando o usuário
	printf("Olá usuário! Bem vindo ao sistema de vendas da SALUMAN LINHAS AÉREAS\n\n");
	printf("Digite aqui o seu nome: ");
	fgets(nomeUsuario, 30, stdin);
	printf("Digite aqui a sua idade: ");
	scanf("%i", &idadeUsuario);
	fflush(stdin);
	
	printf("Usuário %s registrado com sucesso!\n\n", nomeUsuario);
	system("PAUSE");
	system("CLS");
	
	// Nesse ponto aqui nós temos em mãos o nome e a idade do usuário, que será usado posteriormente no cálculo do preço
	
	// Selecionando um avião:
	printf("============ ESCOLHER AVIÃO ============\n\n");
	
	printf("Digite o nome do destino: ");
	fgets(nomeDestino, 30, stdin);
	
	printf("Agora, digite o preço: ");
	scanf("%f", &preco);
	fflush(stdin);
	
	// Se a idade do usuário for menor ou igual a 5, o preço será descontado na metade do valor.
	if(idadeUsuario <=5)
		preco = preco / 2;

	//Nesse ponto nós temos a informação do nome do destino e preço, que usaremos posteriormente.
	
	while(true){
		printf("Para finalizar, digite a quantidade de assentos: ");
		scanf("%i", &quantidadeAssentos);
		fflush(stdin);
		
		// Como terceira condição necessária eu defini que a quantidade de assentos tem que ser divisível por 4.
		if(quantidadeAssentos >= 90 && quantidadeAssentos <= 200 && quantidadeAssentos%4 == 0) break;
			else {
				printf(VERMELHO "Valor digitado é inválido, todos nossos aviões possuem entre 90 e 200 assentos e são divisíveis por 4...!\n");	
				printf(RESET);	
			}
	}
	
	// Nessa parte abaixo, a gente divide a quantidade de assentos em 4 filas de assentos, por isso o número de assentos, nessa
	// empresa fictícia, é sempre divisível por 4.
		
	int quantidadeColunas = quantidadeAssentos/4;
	
	// O mapa dos assentos do avião é uma matriz de caracteres com sempre 4 filas, porém a quantidade de colunas varia de
	//acordo com a quantidade de assentos.
	char assentos[4][quantidadeColunas]; 
	
	//preechendo as colunas com 'D' de disponíveis.
	for(int linha = 0; linha<4; linha++){
		for (int coluna = 0; coluna<quantidadeColunas; coluna++){
			assentos[linha][coluna] = 'D';
		}
	}
	system("CLS");
	
	// Essa matriz funcionará da seguinte forma: o primeiro valor será o índice, que começará por 1, 
	// já o segundo, será a linha do assento e o terceiro, a coluna do assento.
	int matrizReservas[quantidadeAssentos][3];
	
	int quantasReservasJaForamFeitas = 0;
	int opcaoEscolhida;
	int numeroIdentificadorReserva, i, linha, coluna;
	bool valorFoiEncontrado = false;
	char confirmar;
	int quantidadeReservados, quantidadeConfirmados, quantidadeDisponiveis;

	// Só sai desse laço se o usuário digitar 4.
	while(true){
		// Menu principal
		printf("---- Menu Principal ----\n\n");
		printf("1- Reservar assento\n");
		printf("2- Confirmar uma reserva\n");
		printf("3- Cancelar uma reserva\n");
		printf("4- Informações do avião\n");
		printf("5- Sair do Programa\n");
		printf("Sua escolha: ");
		scanf("%i", &opcaoEscolhida);
	
		switch (opcaoEscolhida){
			case 1: 
				system("CLS");
				// Exibe o mapa dos assentos do avião
				printf("========> MAPA DOS ASSENTOS <========\n\n");
				printf("|Colunas:|");
				for(int colunas = 0; colunas<quantidadeColunas; colunas++){
					printf("%2i|", colunas + 1);
				}
				printf("\n");
				for(i = 0; i<4; i++){
					printf("|Linha %i:|", i + 1);
					for (int j = 0; j < quantidadeColunas; j++){
						if(assentos[i][j] == 'D'){
							printf(VERDE "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");
						} else if(assentos[i][j] == 'R'){
							printf(VERMELHO "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						} else {
							printf(AZUL "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						}
					}
					printf("\n");
				}
				printf("PS:\nD = ASSENTO DISPONÍVEL \nR = ASSENTO RESERVADO\nC = ASSENTO COM RESERVA CONFIRMADA\n");
				
				// Se a linha do assento digitada for válida o laço volta, caso contrário, o programa exibe uma mensagem de
				//erro e o laço se repete, o programa pergunta novamente a linha do assento (processo semelhante acontece com
				//a coluna
				while(true){
					// pedindo para o usuário as posições dos assentos
					int linhaAssentoReservado, colunaAssentoReservado;
					while(true){	
						printf("Digite a linha do assento: ");
						scanf("%i", &linhaAssentoReservado);
						fflush(stdin);
						if(linhaAssentoReservado <= 4 && linhaAssentoReservado > 0) break;
							else{
								printf( VERMELHO "Valor de linha digitado é inválido, existem apenas 4 linhas\n");
								printf(RESET);
							}
					}
	
					while(true){
						printf("Digite a coluna do assento: ");
						scanf("%i", &colunaAssentoReservado);
						fflush(stdin);
						if(colunaAssentoReservado <= quantidadeColunas && colunaAssentoReservado > 0) break;
						else printf(VERMELHO "Valor de coluna digitado é inválido, existem apenas %i colunas\n", quantidadeColunas);
						printf(RESET);
					}
		
					// verificando se o assento está disponível
					if(assentos[linhaAssentoReservado-1][colunaAssentoReservado-1] == 'D'){
						// trocando a posição para "Reservado"
						assentos[linhaAssentoReservado-1][colunaAssentoReservado-1] = 'R'; 
						// subtraí um da linha assento reservado e coluna para que fique fácil para o usuário ter um assento
						// que comece com 1 e termine com 4
						
						matrizReservas[quantasReservasJaForamFeitas][0] = quantasReservasJaForamFeitas + 1;
						matrizReservas[quantasReservasJaForamFeitas][1] = linhaAssentoReservado - 1;
						matrizReservas[quantasReservasJaForamFeitas][2] = colunaAssentoReservado - 1;
						printf("SUA RESERVA POSSUI IDENTIFICAÇÃO %i, USE ESSA IDENTIFICAÇÃO PARA CONFIRMAR OU CANCELAR SUA RESERVA\n", 
							quantasReservasJaForamFeitas + 1);
						printf("PREÇO: %.2f\n\n", preco);
						quantasReservasJaForamFeitas++;
						printf(VERDE "--- Reserva concluída com sucesso! ---\n\n");
						printf(RESET);
						
						system("PAUSE");
						system("CLS");
						break;
					} else printf("Assento já está reservado ou confirmado, tente outro assento\n");
				}
				break;
	
			case 2: 
				valorFoiEncontrado = false;
				system("CLS");
				printf("=======> CONFIRMAR UMA RESERVA <========\n\n");
				printf("Digite o número identificador da reserva: ");
				scanf("%i", &numeroIdentificadorReserva);
				fflush(stdin);
				
				for(i = 0; i < quantasReservasJaForamFeitas; i++){
					if (matrizReservas[i][0] == numeroIdentificadorReserva){
						valorFoiEncontrado = true;
						linha = matrizReservas[i][1];
						coluna = matrizReservas[i][2]; 
						if(assentos[linha][coluna] == 'R') {
							printf("\n\n------ INFORMAÇÕES DA RESERVA -------\n\n");
							printf("Nome do passageiro: %s", nomeUsuario);
							printf("Linha do assento: %i\n", linha + 1);
							printf("Coluna do assento: %i\n", coluna + 1);
							printf("Numero de reserva: %i\n", numeroIdentificadorReserva);
							printf("Destino: %s\n", nomeDestino);
							printf("Preço: %.2f\n\n", preco);
							
							printf("Deseja confirmar a reserva? (S -> SIM, QUALQUER OUTRO -> NÃO): ");
							scanf("%c", &confirmar);
							fflush(stdin);
							
							if(confirmar == 'S'){
								assentos[linha][coluna] = 'C';
								printf(VERDE "RESERVA CONFIRMADA COM SUCESSO!\n\n");
								printf(RESET);	
							}	
						} else printf("A RESERVA DIGITADA JÁ FOI CONFIRMADA OU FOI CANCELADA...\n\n");
					}
				}
				
				if(!valorFoiEncontrado) {
					printf(VERMELHO "A RESERVA DIGITADA NÃO FOI ENCONTRADA!\n\n");
					printf(RESET);	
				}
				system("PAUSE");
				system("CLS");
				break;
				
			case 3: 
				valorFoiEncontrado = false;
				system("CLS");
				printf("=======> CANCELAR UMA RESERVA <========\n\n");
				printf("Digite o número identificador da reserva: ");
				scanf("%i", &numeroIdentificadorReserva);
				fflush(stdin);
				
				for(i = 0; i < quantasReservasJaForamFeitas; i++){
					if (matrizReservas[i][0] == numeroIdentificadorReserva){
						valorFoiEncontrado = true;
						linha = matrizReservas[i][1];
						coluna = matrizReservas[i][2]; 
						if(assentos[linha][coluna] == 'R') {
							printf("\n\n------ INFORMAÇÕES DA RESERVA -------\n\n");
							printf("Nome do passageiro: %s", nomeUsuario);
							printf("Linha do assento: %i\n", linha + 1);
							printf("Coluna do assento: %i\n", coluna + 1);
							printf("Numero de reserva: %i\n", numeroIdentificadorReserva);
							printf("Destino: %s\n", nomeDestino);
							printf("Preço: %.2f\n\n", preco);
							
							printf("Deseja cancelar a reserva? (S -> SIM, QUALQUER OUTRO -> NÃO): ");
							scanf("%c", &confirmar);
							fflush(stdin);
							
							if(confirmar == 'S'){
								assentos[linha][coluna] = 'D';
								printf(VERDE "RESERVA CANCELADA COM SUCESSO!\n\n");
								printf(RESET);	
							}	
						} else printf("A RESERVA DIGITADA JÁ FOI CONFIRMADA OU FOI CANCELADA...\n\n");
					}
				}
				
				if(!valorFoiEncontrado) printf(VERMELHO "A RESERVA DIGITADA NÃO FOI ENCONTRADA!\n\n");
				printf(RESET);
				system("PAUSE");
				system("CLS");
				break;
				
			case 4:
				quantidadeConfirmados = 0;
				quantidadeDisponiveis = 0;
				quantidadeReservados = 0;
				float precoTotal;
				
				system("CLS");
				// Exibe o mapa dos assentos do avião
				printf("========> MAPA DOS ASSENTOS <========\n\n");
				printf("|Colunas:|");
				for(int colunas = 0; colunas<quantidadeColunas; colunas++){
					printf("%2i|", colunas + 1);
				}
				printf("\n");
				for(i = 0; i<4; i++){
					printf("|Linha %i:|", i + 1);
					for (int j = 0; j < quantidadeColunas; j++){
						if(assentos[i][j] == 'D'){
							printf(VERDE "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");
						} else if(assentos[i][j] == 'R'){
							printf(VERMELHO "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						} else {
							printf(AZUL "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						}
					}
					printf("\n");
				}
				
				printf("PS:\nD = ASSENTO DISPONÍVEL \nR = ASSENTO RESERVADO\nC = ASSENTO COM RESERVA CONFIRMADA\n");
				
				for(i = 0; i<4; i++){
					for(int j = 0; j<quantidadeColunas; j++){
						if(assentos[i][j] == 'C') quantidadeConfirmados++;
							else if(assentos[i][j] == 'D') quantidadeDisponiveis++;
								else quantidadeReservados++;
					}
				}
				
				printf("\n\n");
				printf("=========> INFORMAÇÕES <=========\n\n");
				precoTotal = quantidadeConfirmados * preco;
				printf("DESTINO: %s", nomeDestino);
				printf("ASSENTOS RESERVADOS: %i\n", quantidadeReservados);
				printf("RESERVAS CONFIRMADAS: %i\n", quantidadeConfirmados);
				printf("ASSENTOS DISPONÍVEIS: %i\n", quantidadeDisponiveis);
				printf("TOTAL EM REAIS: %.2f\n\n", precoTotal);
				
				system("PAUSE");
				system("CLS");
				break;	
			
			case 5:
				printf("Obrigado pela escolha e volte sempre!"); 
				return 0;
			 
			default: 
				printf(VERMELHO "Valor inválido."); 
				printf(RESET);
				break;
		}
	}
}
