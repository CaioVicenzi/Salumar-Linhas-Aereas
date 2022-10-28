/*
	AUTOR: Caio Oliveira Marques
*/

// importando as bibliotecas
#include<stdio.h>
#include<stdlib.h>

// definindo o codigo de cada uma das cores que sera apresentadas no termianal, esses codigos são estaticos
#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"

int main(){
	int quantidadeAssentos = 0, idadeUsuario = 0, opcao = 0, linha, coluna;
	char nomeUsuario[30], nomeDestino[30];
	float preco = 0;
	
	// cadastrando o usuario (recebendo dados do nome e idade do usuario)
	printf("Bem vindo ao sistema de vendas da SALUMAN LINHAS AEREAS\n\n");
	printf("Digite aqui o seu nome: ");
	fgets(nomeUsuario, 30, stdin);
	printf("Digite aqui a sua idade: ");
	scanf("%i", &idadeUsuario);
	fflush(stdin);
	
	printf("Usuario registrado com sucesso\n\n", nomeUsuario);
	system("PAUSE");
	system("CLS");
	
	// Nesta parte do codigo, informacoes sobre o aviao sao coletadas
	printf("============ ESCOLHER AVIAO ============\n\n");
	
	printf("Digite o nome do destino: ");
	fgets(nomeDestino, 30, stdin);
	
	printf("Agora, digite o preco: ");
	scanf("%f", &preco);
	fflush(stdin);
	
	// Se a idade do usuario for menor ou igual a 5, o preco sera descontado na metade do valor.
	if(idadeUsuario <=5) preco = preco / 2;

	//Nesse ponto nos temos a informacao do nome do destino e preco, que usaremos posteriormente.
	
	while(1){
		printf("Para finalizar, digite a quantidade de assentos: ");
		scanf("%i", &quantidadeAssentos);
		fflush(stdin);
		
		// o minimo de assentos dos avioes da salumar sao 90, e o maximo sao 200
		// todos os avioes da salumar tem a quantidade de assentos como sendo divisiveis por 4
		if(quantidadeAssentos >= 90 && quantidadeAssentos <= 200 && quantidadeAssentos%4 == 0) break;
			else {
				printf(VERMELHO "Valor digitado e invalido, todos nossos avioes possuem entre 90 e 200 assentos e a quantidade desses assentos eh divisivel por 4...!\n");	
				printf(RESET);	
			}
	}
	
	// Nessa parte abaixo, a gente divide a quantidade de assentos em 4 filas de assentos, por isso o numero de assentos, nessa
	// empresa ficticia, sao sempre divisiveis por 4.
		
	int quantidadeColunas = quantidadeAssentos/4;
	
	// O mapa dos assentos do aviao eh uma matriz de caracteres com sempre 4 filas, porem a quantidade de colunas varia de
	//acordo com a quantidade de assentos.
	char assentos[4][quantidadeColunas]; 
	
	//preechendo as colunas com 'D' de disponiveis.
	for(linha = 0; linha<4; linha++){
		for (coluna = 0; coluna<quantidadeColunas; coluna++){
			assentos[linha][coluna] = 'D';
		}
	}
	system("CLS");
	
	// Essa matriz funcionara da seguinte forma: o primeiro valor sera o indice, que comecara por 1, 
	// ja o segundo, sera a linha do assento e o terceiro, a coluna do assento.
	int matrizReservas[quantidadeAssentos][3];
	
	int quantasReservasJaForamFeitas = 0, valorFoiEncontrado = 0, opcaoEscolhida, numeroIdentificadorReserva, i, j;
	int quantidadeReservados, quantidadeConfirmados, quantidadeDisponiveis, colunas;
	char confirmar;

	// So sai desse laco se o usuario digitar 4.
	while(1){
		// Menu principal
		printf("---- Menu Principal ----\n\n");
		printf("1- Reservar assento\n");
		printf("2- Confirmar uma reserva\n");
		printf("3- Cancelar uma reserva\n");
		printf("4- Informacoes do aviao\n");
		printf("5- Sair do Programa\n");
		printf("Sua escolha: ");
		scanf("%i", &opcaoEscolhida);
	
		switch (opcaoEscolhida){
			case 1: 
				system("CLS");
				// Exibe o mapa dos assentos do aviao
				printf("========> MAPA DOS ASSENTOS <========\n\n");
				printf("|Colunas:|");
				for(colunas = 0; colunas<quantidadeColunas; colunas++){
					printf("%2i|", colunas + 1);
				}
				printf("\n");
				for(i = 0; i<4; i++){
					printf("|Linha %i:|", i + 1);
					for (j = 0; j < quantidadeColunas; j++){
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
				printf("PS:\nD = ASSENTO DISPONIVEL \nR = ASSENTO RESERVADO\nC = ASSENTO COM RESERVA CONFIRMADA\n");
				
				// Se a linha do assento digitada for valida o laco volta, caso contrario, o programa exibe uma mensagem de
				//erro e o laco se repete, o programa pergunta novamente a linha do assento (processo semelhante acontece com
				//a coluna
				while(1){
					// pedindo para o usuario as posicoes dos assentos
					int linhaAssentoReservado, colunaAssentoReservado;
					while(1){	
						printf("Digite a linha do assento: ");
						scanf("%i", &linhaAssentoReservado);
						fflush(stdin);
						if(linhaAssentoReservado <= 4 && linhaAssentoReservado > 0) break;
							else{
								printf( VERMELHO "Valor de linha digitado eh invalido, existem apenas 4 linhas\n");
								printf(RESET);
							}
					}
	
					while(1){
						printf("Digite a coluna do assento: ");
						scanf("%i", &colunaAssentoReservado);
						fflush(stdin);
						if(colunaAssentoReservado <= quantidadeColunas && colunaAssentoReservado > 0) break;
						else printf(VERMELHO "Valor de coluna digitado eh invalido, existem apenas %i colunas\n", quantidadeColunas);
						printf(RESET);
					}
		
					// verificando se o assento esta disponivel
					if(assentos[linhaAssentoReservado-1][colunaAssentoReservado-1] == 'D'){
						// trocando a posicao para "Reservado"
						assentos[linhaAssentoReservado-1][colunaAssentoReservado-1] = 'R'; 
						// subtrai um da linha assento reservado e coluna para que fique facil para o usuario ter um assento
						// que comece com 1 e termine com 4
						
						matrizReservas[quantasReservasJaForamFeitas][0] = quantasReservasJaForamFeitas + 1;
						matrizReservas[quantasReservasJaForamFeitas][1] = linhaAssentoReservado - 1;
						matrizReservas[quantasReservasJaForamFeitas][2] = colunaAssentoReservado - 1;
						printf("SUA RESERVA POSSUI IDENTIFICACAO %i, USE ESSA IDENTIFICACAO PARA CONFIRMAR OU CANCELAR SUA RESERVA\n", 
							quantasReservasJaForamFeitas + 1);
						printf("PRECO: %.2f\n\n", preco);
						quantasReservasJaForamFeitas++;
						printf(VERDE "--- Reserva concluida com sucesso! ---\n\n");
						printf(RESET);
						
						system("PAUSE");
						system("CLS");
						break;
					} else printf("Assento ja esta reservado ou confirmado, tente outro assento\n");
				}
				break;
	
			case 2: 
				valorFoiEncontrado = 0;
				system("CLS");
				printf("=======> CONFIRMAR UMA RESERVA <========\n\n");
				printf("Digite o numero identificador da reserva: ");
				scanf("%i", &numeroIdentificadorReserva);
				fflush(stdin);
				
				for(i = 0; i < quantasReservasJaForamFeitas; i++){
					if (matrizReservas[i][0] == numeroIdentificadorReserva){
						valorFoiEncontrado = 1;
						linha = matrizReservas[i][1];
						coluna = matrizReservas[i][2]; 
						if(assentos[linha][coluna] == 'R') {
							printf("\n\n------ INFORMAÇOES DA RESERVA -------\n\n");
							printf("Nome do passageiro: %s", nomeUsuario);
							printf("Linha do assento: %i\n", linha + 1);
							printf("Coluna do assento: %i\n", coluna + 1);
							printf("Numero de reserva: %i\n", numeroIdentificadorReserva);
							printf("Destino: %s\n", nomeDestino);
							printf("Preco: %.2f\n\n", preco);
							
							printf("Deseja confirmar a reserva? (S -> SIM, QUALQUER OUTRO -> NAO): ");
							scanf("%c", &confirmar);
							fflush(stdin);
							
							if(confirmar == 'S'){
								assentos[linha][coluna] = 'C';
								printf(VERDE "RESERVA CONFIRMADA COM SUCESSO!\n\n");
								printf(RESET);	
							}	
						} else printf("A RESERVA DIGITADA JA FOI CONFIRMADA OU FOI CANCELADA...\n\n");
					}
				}
				
				if(!valorFoiEncontrado) {
					printf(VERMELHO "A RESERVA DIGITADA NAO FOI ENCONTRADA!\n\n");
					printf(RESET);	
				}
				system("PAUSE");
				system("CLS");
				break;
				
			case 3: 
				valorFoiEncontrado = 0;
				system("CLS");
				printf("=======> CANCELAR UMA RESERVA <========\n\n");
				printf("Digite o numero identificador da reserva: ");
				scanf("%i", &numeroIdentificadorReserva);
				fflush(stdin);
				
				for(i = 0; i < quantasReservasJaForamFeitas; i++){
					if (matrizReservas[i][0] == numeroIdentificadorReserva){
						valorFoiEncontrado = 1;
						linha = matrizReservas[i][1];
						coluna = matrizReservas[i][2]; 
						if(assentos[linha][coluna] == 'R') {
							printf("\n\n------ INFORMACOES DA RESERVA -------\n\n");
							printf("Nome do passageiro: %s", nomeUsuario);
							printf("Linha do assento: %i\n", linha + 1);
							printf("Coluna do assento: %i\n", coluna + 1);
							printf("Numero de reserva: %i\n", numeroIdentificadorReserva);
							printf("Destino: %s\n", nomeDestino);
							printf("Preco: %.2f\n\n", preco);
							
							printf("Deseja cancelar a reserva? (S -> SIM, QUALQUER OUTRO -> NAO): ");
							scanf("%c", &confirmar);
							fflush(stdin);
							
							if(confirmar == 'S'){
								assentos[linha][coluna] = 'D';
								printf(VERDE "RESERVA CANCELADA COM SUCESSO!\n\n");
								printf(RESET);	
								
								matrizReservas[i][0] = 0;
								matrizReservas[i][1] = 0;
							}	
						} else printf("A RESERVA DIGITADA JA FOI CONFIRMADA OU FOI CANCELADA...\n\n");
					}
				}
				
				if(!valorFoiEncontrado) printf(VERMELHO "A RESERVA DIGITADA NAO FOI ENCONTRADA!\n\n");
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
				// Exibe o mapa dos assentos do aviao
				printf("========> MAPA DOS ASSENTOS <========\n\n");
				printf("|Colunas:|");
				for(colunas = 0; colunas<quantidadeColunas; colunas++){
					printf("%2i|", colunas + 1);
				}
				printf("\n");
				for(i = 0; i<4; i++){
					printf("|Linha %i:|", i + 1);
					for (j = 0; j < quantidadeColunas; j++){
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
				
				printf("PS:\nD = ASSENTO DISPONIVEL \nR = ASSENTO RESERVADO\nC = ASSENTO COM RESERVA CONFIRMADA\n");
				
				for(i = 0; i<4; i++){
					for(j = 0; j<quantidadeColunas; j++){
						if(assentos[i][j] == 'C') quantidadeConfirmados++;
							else if(assentos[i][j] == 'D') quantidadeDisponiveis++;
								else quantidadeReservados++;
					}
				}
				
				printf("\n\n");
				printf("=========> INFORMACOES <=========\n\n");
				precoTotal = quantidadeConfirmados * preco;
				printf("DESTINO: %s", nomeDestino);
				printf("ASSENTOS RESERVADOS: %i\n", quantidadeReservados);
				printf("RESERVAS CONFIRMADAS: %i\n", quantidadeConfirmados);
				printf("ASSENTOS DISPONIVEIS: %i\n", quantidadeDisponiveis);
				printf("TOTAL EM REAIS: %.2f\n\n", precoTotal);
				
				system("PAUSE");
				system("CLS");
				break;	
			
			case 5:
				printf("Obrigado pela escolha e volte sempre!"); 
				return 0;
			 
			default: 
				printf(VERMELHO "Valor invalido."); 
				printf(RESET);
				break;
		}
	}
}
