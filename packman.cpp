// PACMAN 3.0.cpp: archivo de proyecto principal.

#include"stdafx.h" //Visual Studio
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<windows.h>//Color




//declaracion de teclas
//Key Declaration
#define ARR 72
#define ABJ 80
#define DER 77
#define IZQ 75


//Funciones
//Fucntions
bool comprueba(char av[][80], char av2[][80], int num, int num2);
void muestra(char av[][80], int c);
void Menu();
int timemuestra(char av2[][80], int c);
void Highscores();

//Global Variables
int hs=0;
bool stop=false;
int opc2, opc;
int acum;


#define FC BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY //Color

int main (int argc, char *argv[]) //MAIN FUCNTION
{
    //matriz del juego
    //Game "Board" with the dots
	char av[25][80]=
	{
		"*******************************************************************************",
		"*.............................................................................*",
		"*...***********.............***********..................***** *****..........*",
		"*...***********.............***********..................*...*.*...*..........*",
		"*...**......................***********..................*.........*..........*",
		"*...**.********.............***********..................*...*.*...*..........*",
		"*...**......................***********..................***** *****..........*",
		"*...***********...............................................................*",
		"*...***********...............*********............*********..................*",
		"*............**...............*********............*********..................*",
		"*...***********...............*********............*********..................*",
		"*...***********...............................................................*",
		"*..............................*************************************..........*",
		"*..............................*************************************..........*",
		"*....***********...............*************************************..........*",
		"*....***********..............................................................*",
		"*....***********...................................................******.....*",
		"*........................*******************.......................******.....*",
		"*.....****...............*******************.*********************.******.....*",
		"*.....******.............***.............***.......................******.....*",
		"*.....*********..........***....*****....***.......................******.....*",
		"*.....*********..........***....*****....***.......................******.....*",
		"*.............................................................................*",
		"*******************************************************************************",
	};
	//matriz del juego 
	//Game "Board" with the dots
	char av2[25][80]= 
	{
		"*******************************************************************************",
		"*                                                                             *",
		"*   ***********             ***********                  ***** *****          *",
		"*   ***********             ***********                  *   * *   *          *",
		"*   **                      ***********                  *         *          *",
		"*   ** ********             ***********                  *   * *   *          *",
		"*   **                      ***********                  ***** *****          *",
		"*   ***********                                                               *",
		"*   ***********               *********            *********                  *",
		"*            **               *********            *********                  *",
		"*   ***********               *********            *********                  *",
		"*   ***********                                                               *",
		"*                              *************************************          *",
		"*                              *************************************          *",
		"*    ***********               *************************************          *",
		"*    ***********                                                              *",
		"*    ***********                                                   ******     *",
		"*                        *******************                       ******     *",
		"*     ****               ******************* ********************* ******     *",
		"*     ******             ***             ***                       ******     *",
		"*     *********          ***    *****    ***                       ******     *",
		"*     *********          ***    *****    ***                       ******     *",
		"*                                                                             *",
		"*******************************************************************************",
	};
	char ce=16;
	int num=1;
	int op;
	int num2=1;
	
	HANDLE hOut;//Color
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Color
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);//Color
	
	Menu(); //Menu function

	switch(opc){

	case 1:
		clock_t d;
		d=clock();
	av[1][1]=ce;
	if (hs<1175)
	{
		muestra(av, d);

		while(stop==false)
		{
			if (getch() == 224)
			{
				op = getch();
			}
			else
			{
				op = -1;
			}

			switch (op)
			{//verifica que tecla se preciono y realiza el movimiento
				//Check which key was pressed and moves
			case ARR:
				if (comprueba(av, av2, num, num2-1)==true)
				{//pregunta si el movimiento es posible o no, para no salirse de los muros
					//Checks if the move is valid, avoiding crossing the walls
					av[num2][num]=' ';
					num2--;
					ce=30;
					av[num2][num]=ce;
				}
				break;

			case ABJ:
				if (comprueba(av, av2, num, num2+1)==true)
				{
					av[num2][num]=' ';
					num2++;
					ce=31;
					av[num2][num]=ce;
				}
				break;

			case DER:
				if (comprueba(av, av2, num+1, num2)==true)
				{
					av[num2][num]=' ';
					num++;
					ce=16;
					av[num2][num]=ce;
				}
				break;

			case IZQ:
				if (comprueba(av, av2, num-1, num2)==true){
					av[num2][num]=' ';
					num--;
					ce=17;
					av[num2][num]=ce;
				}
				break;
			}
			muestra(av,d);
		}


	}

	if (hs==1175)
	{
		system("CLS");
		Highscores();
	}

	return 0;
	break;

	case 2:	
		clock_t a;
		a=clock();
	av2[1][1]=ce;

	if (hs<1175)
	{
		timemuestra(av2, a);

		while(stop==false)
		{
			if (getch() == 224)
			{
				op = getch();
			}
			else
			{
				op = -1;
			}

			switch (op)
			{//verifica que tecla se preciono y realiza el movimiento
				
			case ARR:
				if (comprueba(av, av2, num, num2-1)==true)
				{//pregunta si el movimiento es posible o no, para no salirse de los muros
					av2[num2][num]=' ';
					num2--;
					ce=30;
					av2[num2][num]=ce;
				}
				break;

			case ABJ:
				if (comprueba(av, av2, num, num2+1)==true)
				{
					av2[num2][num]=' ';
					num2++;
					ce=31;
					av2[num2][num]=ce;
				}
				break;

			case DER:
				if (comprueba(av, av2, num+1, num2)==true)
				{
					av2[num2][num]=' ';
					num++;
					ce=16;
					av2[num2][num]=ce;
				}
				break;

			case IZQ:
				if (comprueba(av, av2, num-1, num2)==true){
					av2[num2][num]=' ';
					num--;
					ce=17;
					av2[num2][num]=ce;
				}
				break;
			
			}
			
			timemuestra(av2, a);
		}

	
	}
	int time;
	time=timemuestra(av2,a);
	if (time>=12)
	{
		system("CLS");		
		Highscores();
		getchar();
		getchar();
	}
	return 0;
}
}
//Funcion que comprueba si se puede realizar el movimiento
//Function that checks if the move is valid
bool comprueba(char av[][80],char av2[][80], int num, int num2)
{

	if (av[num2][num]=='*'){
		return(false);
	}else
	{
		if (av[num2][num]!=' ')
		{hs+=1;}
		return(true); 
	}
	if (av2[num2][num]=='*'){
		return(false);
	}else
	{
		if (av2[num2][num]!=' ')
		{hs+=1;}
		return(true); 
	}
}

//Funcion para mostrar el tablero de juego
//Function that shows the "Board"
void muestra (char av[][80], int c)
{
	system("cls");
	int i;
	int n1=0;
	clock_t b;
	int r=1;

	for (i=0;i<24;i++)
	{
		puts(av[i]);
	}

	printf("\t\t\tPoints: %d   ", hs);

	if (hs==1175)
	{
		stop=true;
	}

	b=clock();
	n1=(b-c)/700;
	printf ("\t\tTime: %ld", n1);
}

int timemuestra(char av2[][80],int c) //For the Time version of the game
{
	system("cls");
	int n1=0;
	int i;
	clock_t b;
	int r=1;
	for (i=0;i<24;i++)
	{
		puts(av2[i]);
	}
		printf("\t\t\tPoints: %d   ", hs);
		
	
	b=clock();
	
	n1=(b-c)/700;
	printf ("\t\tTime: %ld", n1);
	if (n1==12)
	{
		stop=true;
	}
	return n1;
	
}
void Menu() //MENU
{
	printf("Como desea jugar: \n");
	printf("1.Por Puntos\n");
	printf("2.Por Tiempo\n");
	printf("3.HighScores\n");
	printf("4.Salir\n");
	scanf("%d",&opc);


}

void Highscores() //HighScore Panel
{
	system("cls");
		printf("*******************************************************************************\n");
		printf("*                       .         .                                           *\n");
		printf("*                      .  .     .  .                                          *\n");
		printf("*                      .   .   .   .                                          *\n");
		printf("*                       .  .   .  .                                           *\n");
		printf("*                       .         .                                           *\n");
		printf("*                      .   O    O  .                                          *\n");
		printf("*     YOU WIN!         .     Y     .                                          *\n");
		printf("*                       . ( ___ ) .                                           *\n");
		printf("*                         .     .                                             *\n");
		printf("*                        .  . .  .                                            *\n");
		printf("*                       .   >o<   .                                           *\n");
		printf("*                                                                             *\n");
		printf("*                                      HIGHSCORE: %d                          *\n",hs);
		printf("*******************************************************************************\n");
	system("pause");
}


