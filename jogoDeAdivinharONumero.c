#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_header()
{
	printf("-----------------------------------------------\n");
    printf("---------- JOGO DE ADIVINHAR O NUMERO ---------\n");
    printf("-----------------------------------------------\n");	
}

int raffle_number()
{
	int secretNumber = 0, segundo = 0;
	
	segundo = time(0);
    srand(segundo);
    secretNumber = rand() % 100;
    return secretNumber;
}

void person_playing(int attempts, int secretNumber)
{
	int i, cont = 0;
    int chute = 0, acertou = 0, maior = 0;
    double points = 1000;
	
	game_header();
	
	printf("Voce tem %d tentativas\n", attempts);
	
    for (i = 1; i <= attempts; i++)
    {
    	cont +=1;
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = chute == secretNumber;
        maior = chute > secretNumber;

        if (acertou)
        {
            printf("Parabens! Voce acertou!\n");
            printf("Voce fez: %2.0f pontos e acertou em %d tentativas!.\n", points, cont);
            printf("Jogue de novo, voce e um bom jogador!\n");
            printf("-----------------------------------------------\n");

            break;
        }

        else if (maior)
        {
            printf("Seu chute foi maior que o numero secreto\n");
            printf("-----------------------------------------------\n");
        }
        
        else
        {
            printf("Seu chute foi menor que o numero secreto\n");
            printf("-----------------------------------------------\n");
        }

        points = points - (abs(secretNumber - chute) / 2.0);
    }
}


int main()
{
	int level = 0, attempts = 1, secretNumber, flag = 0;
	do {
		system("cls");
		game_header();
	
		printf("Difculdade: [1] Dificil - [2] Medio - [3] Facil\n");
    	scanf("%d", &level);
    	system("cls");
    
    	secretNumber = raffle_number();

    	switch (level)
    	{
    	case 1:
        	attempts = 5;
        	person_playing(attempts, secretNumber);
        	break;

    	case 2:
        	attempts = 10;
        	person_playing(attempts, secretNumber);
        	break;

    	case 3:
        	attempts = 15;
        	person_playing(attempts, secretNumber);
        	break;
    	}
    	printf("Digite: [1] continuar e [0] sair:");
    	scanf("%d", &flag);
	} while(flag == 1);
	
    return 0;
}
