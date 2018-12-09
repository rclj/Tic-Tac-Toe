#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

char quadrado[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void board() //mostra o jogo
{
	system("cls");
	printf("\n\n\t\t\t\t\t\tJogo do Galo V. 1.0\n\n");
	printf("\n\nJogador 1- X\nJogador 2- O\n\n\n\n");
	printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", quadrado[1], quadrado[2], quadrado[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", quadrado[4], quadrado[5], quadrado[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", quadrado[7], quadrado[8], quadrado[9]);
    printf("     |     |     \n\n");
}

int vencedor() // 1- o jogo acabou com um vencedor; 2- o jogo acabou empatado; 3- o jogo ainda está em progresso
{
	if (quadrado[1] == quadrado[2] && quadrado[2] == quadrado[3])
	   return 1;
	
	else if (quadrado[4] == quadrado[5] && quadrado[5] == quadrado[6])
	   return 1;
	
	else if (quadrado[7] == quadrado[8] && quadrado[8] == quadrado[9])
	   return 1;
	
	else if (quadrado[1] == quadrado[4] && quadrado[4] == quadrado[7])
	   return 1;
	
	else if (quadrado[2] == quadrado[5] && quadrado[5] == quadrado[8])
	   return 1;
	
	else if (quadrado[3] == quadrado[6] && quadrado[6] == quadrado[9])
	   return 1;
	
	else if (quadrado[1] == quadrado[5] && quadrado[5] == quadrado[9])
	   return 1;
	
	else if (quadrado[3] == quadrado[5] && quadrado[5] == quadrado[7])
	   return 1;
	else if(quadrado[1] != '1' && quadrado[2] != '2' && quadrado[3] != '3' && quadrado[4] != '4' && 
	quadrado[5] != '5' && quadrado[6] != '6' && quadrado[7] != '7' && quadrado[8] != '8' && quadrado[9] != '9')
	
	   return 2;
	else
	   return 3;
}


 main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int primeiroOp, jogador = 1, escolha, verificarGanhou, i;
	
	char selecionado, resposta, a;
	
	do{
		system("cls");
	
		printf("\n\n\t\t\t\t\t\tJogo do Galo V. 1.0\t\t");
		printf("\n\n\n\n\n\n1.Jogar\n2.Como jogar\n3.Sair\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tBy: Rodrigo Santos");
	    //scanf("%d",&primeiroOp);
	    
	   a = getch();
	    
	  primeiroOp = a - 48; //tabela ascii chart
	    
	    if(primeiroOp == 1)
	    {
	    	do
			{
			 do
	    	 {
	    		board();
	    		
	    		jogador = (jogador % 2) ? 1 : 2;
	    		
	    		printf("Jogador %d selecione um quadrado: \n",jogador);
	    		scanf("%d",&escolha);
	    		
	    		selecionado = (jogador == 1) ? 'X' : 'O';
	    		
				if(escolha == 1 && quadrado[1] == '1')
	    		quadrado[1] = selecionado;
	    		else 
	    		if(escolha == 2 && quadrado[2] == '2')
	    		   quadrado[2] = selecionado;
	    		else 
	    		 if(escolha == 3 && quadrado[3] == '3')
	    		   quadrado[3] = selecionado;
	    		else 
	    		 if(escolha == 4 && quadrado[4] == '4')
	    		   quadrado[4] = selecionado;
	    		else 
	    		 if(escolha == 5 && quadrado[5] == '5')
	    		   quadrado[5] = selecionado;
	    		else 
	    		 if(escolha == 6 && quadrado[6] == '6')
	    		   quadrado[6] = selecionado;
	    		else 
	    		 if(escolha == 7 && quadrado[7] == '7')
	    		   quadrado[7] = selecionado;
	    		else 
	    		 if(escolha == 8 && quadrado[8] == '8')
	    		   quadrado[8] = selecionado;
	    		else 
	    		 if(escolha == 9 && quadrado[9] == '9')
	    		   quadrado[9] = selecionado;
	    		else 
	    		{
	    		printf("Quadrado Inválido.\n");	
	    		
	    	    jogador--;
	    	    
	    	    getch();
				}
	    	    
	    		verificarGanhou = vencedor(); //verifica se o jogador ganhou
	    		
				jogador++; //muda o turno
			 }
			  while(verificarGanhou == 3);
			
			board();
			
			if(verificarGanhou == 1)
			  printf("\nO jogador %d ganhou!!\n",--jogador);
			else
			  printf("\nO jogo ficou empatado!!\n");
	    	
	    	sleep(2);
	    	
	    	system("cls");
	    	
	    	fflush(stdin);
	    	
	        printf("Pretende jogar novamente? s/n\n\n");
	    	scanf("%c",&resposta);
	        
	        	for(i=1; i<10; i++)       //mete todos os quadrados a zero 
				{
					quadrado[i] = '0';
				}
				for(i=1; i<10; i++)           //mete todos os quadrados com a posiçao original se o jogar pretender jogar novamente
				{
					quadrado[i] = quadrado[i] + i;
				}
	        
			}
		    while (resposta == 's' || resposta == 'S');
	    	
	    }
		else
		{
		    if (primeiroOp == 2)
		    {
			system("cls");
			printf("\n\nO jogo Tic Tac Toe ou jogo do galo consiste em fazer três X ou três O em linha.\nA linha pode ser horizontal, vertical ou diagonal.\nOs jogadores jogam de forma alternada, fazendo uma marcação ora com um X ora com um O num espaço vazio. O jogador 1 (X) começa em primeiro.\n\n");
		    system("pause");
		    }
		else if (primeiroOp == 3){
		}
		else 
		printf("\nNúmero Inválido.");
		sleep(2);
		}
   }while(primeiroOp != 3); // só sai do programma se for a opção sair
}
