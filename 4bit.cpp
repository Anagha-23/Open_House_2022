/*  TEAM NAME = 4bit
    MEMBERS :
	         Aadhya Subhash 
			 Anagha G
			 Anagha N
			 Chinmayi S Acharya           */



#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
int i, j, height = 20, width = 20;             //for boundary
int score;
bool gameover;
int x, y, fruit_x, fruit_y, flag;                //for fruit
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// code to generate fruit
void setup()
{
	gameover = false;
	x = height / 2;
	y = width / 2;

	label1: 
        fruit_x = rand() % height;     //function to generate random numbers
		    if (fruit_x == 0)
			    goto label1;

	label2: 
        fruit_y = rand() % width;
		    if (fruit_y == 0)
			    goto label2;
		    score = 0;
}

//to create boundaries
void drawe()
{
	system("cls");                              // executes any cmd on the terminal if the system allows
	for (i = 0; i < height; i++)
	{
		cout << "#" << endl;
		for (i = 0; i < height; i++)
		{
		  cout << "#" << endl;
			for (j = 0; j < width; j++)
			{
				if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
				{
					cout << "#";
				}
				else 
        {
					if (i == x && j == y)
						cout << "*";           //snake
					else if (i == fruit_x && j == fruit_y)
						cout << "0";           //fruit
					else
						cout << " ";
				}
			}
		} 	
    cout << endl << endl;
		cout << "a - left \n d - right\n s - down\n w - up " << endl;
		cout << "0 represents the fruit and * represents the snake!" << endl << endl;
		cout << "          SCORE=" << score << endl;
		cout << "Press o to exit game" << endl;
	}
}

void input()
{
	if (_kbhit())                  //determines if a key has been pressed
	{
		switch (_getch())
		{
			case'a': dir = LEFT;
				       break;
		  case'w': dir = UP;
			      	 break;
			case's': dir = DOWN;
				       break;
			case'd': dir = RIGHT;
				       break;
			case'o': gameover = true;
				       break;
		}
	}
}

void logic()
{
	Sleep(0.01);
	switch (dir)
	{
		case LEFT: y--;
			         break;
		case RIGHT: y++;
			          break;
		case UP : x--;
			        break;
		case DOWN: x++;
			         break;
		default:
			        break;
	}

	if (x<0 || x>height || y<0 || y>width)
		gameover = true;
	if (x == fruit_x && y == fruit_y)            //if snake reaches fruit
	{
		label3: fruit_x = rand() % 20;
			      if (fruit_x == 0)
				      goto label3;

		label4:                                          //to generate new fruit
			      fruit_y = rand() % 20;
			      if (fruit_y == 0)
				      goto label4;
			      score += 10;
	}
}


// TIC TAC TOE !!
char A[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';
bool draw = false;

void display_board()
{
	system("cls");
	cout << "\tTIC TAC TOE!!\n";
	cout << "\tPlayer 1 [X]\n\tPlayer 2 [O]\n\n";
	cout << "\t     |     |    \n";
	cout << "  \t  " << A[0][0] << "  |  " << A[0][1] << "  |  " << A[0][2] << "  \n";
	cout << "\t-----|-----|-----\n";
	cout << "\t     |     |    \n";
	cout << "  \t  " << A[1][0] << "  |  " << A[1][1] << "  |  " << A[1][2] << "  \n";
	cout << "\t-----|-----|-----\n";
	cout << "\t     |     |    \n";		cout << "\t  " << A[2][0] << "  |  " << A[2][1] << "  |  " << A[2][2] << "  \n";
	cout << "\t     |     |    \n";
}

void player_turn()
{
  int choice;
	int i, j;
	if (turn == 'X')
    cout << "Player 1 [X] turn: ";
  if (turn == 'O')
		cout << "Player 2 [O] turn: ";
  cin >> choice;

	switch (choice)
	{
	  case 1: i = 0; j = 0; 
            break;
		case 2: i = 0; j = 1; 
            break;
		case 3: i = 0; j = 2; 
            break;
		case 4: i = 1; j = 0; 
            break;
		case 5: i = 1; j = 1; 
            break;
		case 6: i = 1; j = 2; 
            break;
		case 7: i = 2; j = 0; 
            break;
		case 8: i = 2; j = 1; 
            break;
		case 9: i = 2; j = 2; 
            break;
		default: cout << "Invalid :(\n"; 
            break;
	}

	if (turn == 'X' && A[i][j] != 'X' && A[i][j] != 'O')
	{
		A[i][j] = 'X';
		turn = 'O';
	}

	else if (turn == 'O' && A[i][j] != 'X' && A[i][j] != 'O')
	{
		A[i][j] = 'O';
		turn = 'X';
	}

	else
		cout << "Box already filled\nTry another one\n";
}

bool game_over()
{
	for (int m = 0; m < 3; m++)
		if (A[m][0] == A[m][1] && A[m][0] == A[m][2] || A[0][m] == A[1][m] && A[0][m] == A[2][m])
			return false;

  if (A[0][0] == A[1][1] && A[0][0] == A[2][2] || A[0][2] == A[1][1] && A[0][2] == A[2][0])
		return false;

	for (int m = 0; m < 3; m++)
		for (int n = 0; n < 3; n++)
			if (A[m][n] != 'X' && A[m][n] != 'O')
				return true;

	draw = true;
	return false;
}

int ttt()
{
	while (game_over())
	{
		display_board();
		player_turn();
		game_over();
  }
  if (turn == 'X' && draw == false)
		cout << "Player 2 [O] Wins!!:)";
	else if (turn == 'O' && draw == false)
		cout << "Player 1 [X] Wins!!:)";
	else 
		cout << "Game draw!";

	return 0;
}    


// DRUNKEN LETTERS !

int d_l()
{
	srand(time(0));
	//drunk_letters drunk_letters1;
	const int size = 60;
	cout << "Enter a letter to begin \n ";
	char x; cin >> x;
	int position = size / 2;
	while (true)
	{
		cout << "|S|";
		for (int i = 0; i < size; i++)
		{
			if (i == position)
				cout << x;
			else cout << " ";
		}
		cout << "|F|" << endl;
		int move = rand() % 3 - 1;
		position = position + move;
		if(position < 1)
		{
			cout << "You could not finish the race!" << endl; 
			      	break;
		}
		else if(position > size - 1)
		{
			cout << "Yay! You finished the race" << endl; 
			      	break;
		}
		for (int sleep = 0; sleep < 1000000; ++sleep);     //time delay loop
	}
  return 0;

}



int main()
{
	int n;
	cout << "ENTER THE GAME YOU WANT TO PLAY !!\n 1 for SNAKE GAME\n 2 for TIC-TAC-TOE\n 3 for DRUNK LETTERS" << endl;
	cin >> n;
	switch (n)
	{  
    case 1: setup();
		        while (gameover == false)
		        {
			        drawe();
			        input();
			        logic();
		        }
		        break;
	  case 2: display_board();
		        player_turn();
		        game_over();
		        ttt();
		        break;
	  case 3: d_l();
		        break;
	  default: cout << "Sorry ! Game does not exist !" << endl;
	}
}
