/*
	HES1300 Assignment : The Mastermind Game
	Author : Nimesh Abeysinghe
	ID : 100060428
	Last update : 9/12/2014 5:35p.m
This program is written to play Mastermind which is a code guessing game.
This program generates 4 random numbers (from 1 to 6) which the user must guess in the correct oreder.
Hints are provided by the program for every guess.
The user is given a maximum of 10 guesses and isalso allowed to give up or retry the game at any point
*/

#include <stdio.h>
#include <stdlib.h>
/*all functions outside the main function have been written below the main function therefore it has been prototyped*/

void printHeader();
void instructions();
void exit_before_start();
void exit_after_start();
void difficulty();
void easy();
void medium();
void hard();

int main ()
{
	/*variables declared for use in the main function*/
	char name[50];
	char option;
	
	system ("color 1F");/*To change the screen colour to blue and text color to white*/
	printHeader();
	
	puts("\nPlease Enter your name: ");
	gets( name);/*used instead of the scanf function to allow the user to enter his/her name with spaces if the user wishes to*/
	
	printf("\nWelcome to mastermind %s\n", name);/*Welcoming message mentioning the users name*/
	instructions();
	printf ("Do you want to continue? (y/n)\n");
	scanf (" %c", &option);
	/*Reads the character entered and performs the commands depending on the input of the user*/
	
	switch (option)
	{
	case 'y' :
	case 'Y' :
		difficulty();
		break;
	case 'n' :
	case 'N' :
		exit_before_start();
		break;
	default :
		exit_before_start();
	}
	return 0;
}
/*The header used for the entire game*/
void printHeader()
{
	printf("*******************************************************************************\n");
	printf("***********************************MASTERMIND**********************************\n");
	printf("*******************************************************************************\n");
	return;
}

/*prints the instructions on the screen*/
void instructions()
{
	
	printf("\nGuess the combination of 4 numbers in the correct order\n");
	printf("You are allowed 10 guesses\n");
	printf("Hints will be provided for each guess\n\n");
	printf("For the Easy level the random numbers generated range from 1 - 4\n");
	printf("For the Medium level the random numbers generated range from 1 - 6\n");
	printf("For the Hard level the random numbers generated range from 1 - 8\n");
	printf("Sample guess : 5362\n\n");
	printf("Hints\n");
	printf("* = a correct number placed in the correct position\n");
	printf("@ = a correct number placed in the wrong position\n\n");
	return;
}


/*The function to display a message if the user decides not to proceed in playing the game*/
void exit_before_start()
{
	system ("cls");
	printf ("\n\n\n\n\n\n\n\n\t\t\t Please come back later\n\n\n\n\n\n\n\n\n");
	return;
}
/*The function to display a message if the user decides not to retry the game*/

void exit_after_start()
{
	system ("cls");
	printf ("\n\n\n\n\n\n\n\n\t\t\tThank you for playing Mastermind\n");
	printf ("\t\t\t      Please try again later\n\n\n\n\n\n\n\n");
	return;
}

void easy()
{
	int i;
	int random[4];
	int guess[4];
	int count;
	char retry;
	srand((unsigned)time(NULL));/*Prevents the same random numbers from generating the next time the game is played*/
	system ("cls");
	system ("color 2F");
	printHeader();
	for (i = 0;i < 4;i++)
	{
		do
		{
			random[i] = (rand() % 4 + 1);
		}
		while (random[0] == random[1] || random[0] == random[2] || random[0] == random[3] || random[1] == random[2] || random[1] == random[3] || random[2] == random[3]);
		/*the do while loop is used to prevent the random numbers generated from being the same*/
		/*printf ("%i\n",random[i]);remove later*/
	}
	/*for loop used to prevent the user from guessing more than ten times*/
	for (count = 0; count < 10; count++)
	{
		printf("\nEnter a guess or Enter 9999 to quit:\n");
		scanf("%1i%1i%1i%1i", &guess[0], &guess[1], &guess[2], &guess[3]);
		/*Reads the 4 numbers entered by the user. The user should only enter 4 integers. Characters of floating point numbers should not be entered*/
		if (guess[0] == random[0] && guess[1] == random[1] && guess[2] == random[2] && guess[3] == random[3])
		{
			printf("Congratulations!!!You win!\n");
			printf("No of guesses: %i", count + 1);
			break;/*Breaks the loop if the user wins before completing ten guesses*/
		}
		else
		{
			if (guess[0] == 9 && guess[1] == 9 && guess[2] == 9 && guess[3] == 9)/*this function allows the user to quit at any point while playing the game by entering 9999*/
			{
				printf("The solution is %i%i%i%i\n", random[0], random[1], random[2], random[3]);/*displays the solution if the user has quit*/
				printf("No of guesses: %i", count);
				break;
			}
			/*The following conditions are checked and the hints are displayed to the user after every guess*/
			else
			{
				if (guess[0] == random[0])
				{
					printf("*");
				}
				if (guess[1] == random[1])
				{
					printf("*");
				}
				if (guess[2] == random[2])
				{
					printf("*");
				}
				if (guess[3] == random[3])
				{
					printf("*");
				}
				if ((guess[1] == random[0] || guess[2] == random[0] || guess[3] == random[0]) && guess[0] != random[0])
				{
					printf("@");
				}
				if ((guess[0] == random[1] || guess[2] == random[1] || guess[3] == random[1]) && guess[1] != random[1])
				{
					printf("@");
				}
				if ((guess[0] == random[2] || guess[1] == random[2] || guess[3] == random[2]) && guess[2] != random[2])
				{
					printf("@");
				}
				if ((guess[0] == random[3] || guess[1] == random[3] || guess[2] == random[3]) && guess[3] != random[3])
				{
					printf("@");
				}
			}
			printf ("\n");
		}
	}
	if (count == 10)
	{
		printf("The solution is %i%i%i%i\n", random[0], random[1], random[2], random[3]);
		printf("\nYou have made %i guesses", count);
		printf("\nYou lost!!!\n");
	}
	printf("\n\nEnter R to Retry or Enter Q to Exit or Enter C to change difficulty :\n");
	scanf(" %c", &retry);
	/*allows the user to retry the game by entering 'R' or 'r' if the user gives up*/
	switch (retry)
	{
	case 'R' :
	case 'r' :
		system("cls");/* To clear the screen */
		easy();
		break;
	case 'Q' :
	case 'q' :
		exit_after_start();
		break;
	case 'C' :
	case 'c' :
		difficulty();
		break;
	default :
		exit_after_start();
	}
	return ;
}

void medium()/*This function is almost the same as void easy() except it generates 4 numbers in the range of 1-6*/
{
	int i;
	int random[4];
	int guess[4];
	int count;
	char retry;
	system ("color 1F");
	srand((unsigned)time(NULL));
	system ("cls");
	printHeader();
	for (i = 0;i < 4;i++)
	{
		do
		{
			random[i] = (rand() % 6 + 1);
		}
		while (random[0] == random[1] || random[0] == random[2] || random[0] == random[3] || random[1] == random[2] || random[1] == random[3] || random[2] == random[3]);
	
	}
	
	for (count = 0; count < 10; count++)
	{
		printf("\nEnter a guess or Enter 9999 to quit:\n");
		scanf("%1i%1i%1i%1i", &guess[0], &guess[1], &guess[2], &guess[3]);
	
		if (guess[0] == random[0] && guess[1] == random[1] && guess[2] == random[2] && guess[3] == random[3])
		{
			printf("Congratulations!!!You win!\n");
			printf("No of guesses: %i", count + 1);
			break;
		}
		else
		{
			if (guess[0] == 9 && guess[1] == 9 && guess[2] == 9 && guess[3] == 9)
			{
				printf("The solution is %i%i%i%i\n", random[0], random[1], random[2], random[3]);
				printf("No of guesses: %i", count);
				break;
			}
		
			else
			{
				if (guess[0] == random[0])
				{
					printf("*");
				}
				if (guess[1] == random[1])
				{
					printf("*");
				}
				if (guess[2] == random[2])
				{
					printf("*");
				}
				if (guess[3] == random[3])
				{
					printf("*");
				}
				if ((guess[1] == random[0] || guess[2] == random[0] || guess[3] == random[0]) && guess[0] != random[0])
				{
					printf("@");
				}
				if ((guess[0] == random[1] || guess[2] == random[1] || guess[3] == random[1]) && guess[1] != random[1])
				{
					printf("@");
				}
				if ((guess[0] == random[2] || guess[1] == random[2] || guess[3] == random[2]) && guess[2] != random[2])
				{
					printf("@");
				}
				if ((guess[0] == random[3] || guess[1] == random[3] || guess[2] == random[3]) && guess[3] != random[3])
				{
					printf("@");
				}
			}
			printf ("\n");
		}
	}
	if (count == 10)
	{
		printf("\nThe solution is %i%i%i%i", random[0], random[1], random[2], random[3]);
		printf("\nYou have made %i guesses", count);
		printf("\nYou lost!!!\n");
	}
	printf("\n\nEnter R to Retry or Enter Q to Exit or Enter C to change difficulty :\n");
	scanf(" %c", &retry);
	switch (retry)
	{
	case 'R' :
	case 'r' :
		system("cls");
		medium();
		break;
	case 'Q' :
	case 'q' :
		exit_after_start();
		break;
	case 'C' :
	case 'c' :
		difficulty();
		break;
	default :
		exit_after_start();
	}
	return ;
}
void hard()/* this function generates 4 random numbers in the range 1-8*/
{
	int i;
	int random[4];
	int guess[4];
	int count;
	char retry;
	srand((unsigned)time(NULL));
	system ("cls");
	system ("color 4F");
	printHeader();
	if (count == 10)
	{
		printf("\nThe solution is %i%i%i%i", random[0], random[1], random[2], random[3]);
		printf("\nYou have made %i guesses", count);
		printf("\nYou lost!!!\n");
	}
	for (i = 0;i < 4;i++)
	{
		do
		{
			random[i] = (rand() % 8 + 1);
		}
		while (random[0] == random[1] || random[0] == random[2] || random[0] == random[3] || random[1] == random[2] || random[1] == random[3] || random[2] == random[3]);
		
	}
	for (count = 0; count < 10; count++)
	{
		printf("\nEnter a guess or Enter 9999 to quit:\n");
		scanf("%1i%1i%1i%1i", &guess[0], &guess[1], &guess[2], &guess[3]);
		if (guess[0] == random[0] && guess[1] == random[1] && guess[2] == random[2] && guess[3] == random[3])
		{
			printf("Congratulations!!!You win!\n");
			printf("No of guesses: %i", count + 1);
			break;
		}
		else
		{
			if (guess[0] == 9 && guess[1] == 9 && guess[2] == 9 && guess[3] == 9)
			{
				printf("The solution is %i%i%i%i\n", random[0], random[1], random[2], random[3]);
				printf("No of guesses: %i", count);
				break;
			}
			
			else
			{
				if (guess[0] == random[0])
				{
					printf("*");
				}
				if (guess[1] == random[1])
				{
					printf("*");
				}
				if (guess[2] == random[2])
				{
					printf("*");
				}
				if (guess[3] == random[3])
				{
					printf("*");
				}
				if ((guess[1] == random[0] || guess[2] == random[0] || guess[3] == random[0]) && guess[0] != random[0])
				{
					printf("@");
				}
				if ((guess[0] == random[1] || guess[2] == random[1] || guess[3] == random[1]) && guess[1] != random[1])
				{
					printf("@");
				}
				if ((guess[0] == random[2] || guess[1] == random[2] || guess[3] == random[2]) && guess[2] != random[2])
				{
					printf("@");
				}
				if ((guess[0] == random[3] || guess[1] == random[3] || guess[2] == random[3]) && guess[3] != random[3])
				{
					printf("@");
				}
			}
			printf ("\n");
		}
	}
	if (count == 10)
	{
		printf("\nThe solution is %i%i%i%i", random[0], random[1], random[2], random[3]);
		printf("\nYou have made %i guesses", count);
		printf("\nYou lost!!!\n");
	}
	printf("\n\nEnter R to Retry or Enter Q to Exit or Enter C to change difficulty :\n");
	scanf(" %c", &retry);

	switch (retry)
	{
	case 'R' :
	case 'r' :
		system("cls");
		hard();
		break;
	case 'Q' :
	case 'q' :
		exit_after_start();
		break;
	case 'C' :
	case 'c' :
		difficulty();
		break;
	default :
		exit_after_start();
	}
	return ;
}

void difficulty()/* allows the  user to enter which difficulty level he prefers*/
{
	char level;
	printf("\nEnter E for Easy , M for Medium or H for Hard\n");
	scanf(" %c", &level);
	switch (level)
	{
	case 'e' :
	case 'E' :
		easy();
		break;
	case 'm' :
	case 'M' :
		medium();
		break;
	case 'h' :
	case 'H' :
		hard();
		break;
	}
	return;
}

