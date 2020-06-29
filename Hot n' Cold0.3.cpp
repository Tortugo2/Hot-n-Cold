//By Guillem
//v0.2 20-06-2020
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
//colors
#define R 04
#define G 02
#define B 03


using namespace std;

HANDLE  hConsole;
void Title()
{
HANDLE  hConsole;
	
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  

SetConsoleTextAttribute(hConsole, R);
cout << "HOT" <<  endl;

SetConsoleTextAttribute(hConsole, 15);
cout << " n'" << endl;

SetConsoleTextAttribute(hConsole, B);
cout << " COLD" << endl;

SetConsoleTextAttribute(hConsole, 15);
cout << "Input a digit from 1 to 50 and guess the secret random number!\n" << endl;
 
}

float secret_number;
void RNG()
{
	int max;
	max = 50;
	
	srand(time(0));
	secret_number = (rand()%max)+1;
	
	cout << secret_number << endl;
	
}

void Game()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int answer, i;
	for(i=10; i>0; i--){
		cout << "You have " << i << " attempts left!\n"<< endl;
		cin >> answer;
		if(answer!=secret_number){
			if(answer>secret_number){ if(answer-secret_number>=5){SetConsoleTextAttribute(hConsole, B); cout << "COLD!!" <<endl;} if(answer-secret_number<5){SetConsoleTextAttribute(hConsole, R); cout << "HOT!" <<endl;} SetConsoleTextAttribute(hConsole, 15);}
			if(answer<secret_number){ if(secret_number-answer>=5){SetConsoleTextAttribute(hConsole, B); cout << "COLD!!" <<endl;} if(secret_number-answer<5){SetConsoleTextAttribute(hConsole, R); cout << "HOT!" <<endl;} SetConsoleTextAttribute(hConsole, 15);}	
		}
		else{ SetConsoleTextAttribute(hConsole, G); cout << "\nGREAT!\n" << answer << " Was the secret number!" << endl; SetConsoleTextAttribute(hConsole, 15); break;}	
	}
	if(i==0){ cout<< "\nYOU RAN OUT OF ATTEMPTS, THE NUMBER WAS "<< secret_number<< "!\n"<< endl;}
	
}

int main()
{
	Title();
	  RNG();
	 Game();
	 system("pause");
   return 0;
}
