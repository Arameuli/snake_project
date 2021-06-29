#include <iostream>
#include<string>
#include <conio.h>
#include<Windows.h>
using namespace std;
const int sigrdze = 27, simagle = 20;
int a, b, sawmelia, sawmelib, qula, kudia[1000], kudib[1000], kudiszoma;
bool dasrulda;
enum mimartuleba {STOP=0, LEFT, RIGHT, UP, DOWN};
mimartuleba dir;
void awyoba() {
	dasrulda = false;   
	dir = STOP;
	a = 1; 
	b = 1;
	sawmelia = rand() % 27; 
	sawmelib = rand() % 20;
	qula = 0; 
}
void map() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	for (int i = 0; i < 29; i++) {  
		cout << "-";             
	}
	cout << endl;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 27; j++) { 
			if (j == 0)                 
				cout << "|"; 
			if (i == b && j == a) {
				cout << "O"; 
			}
			else if (i == sawmelib && j == sawmelia)
				cout << "*"; 
			else {
				bool dabewdva = false;
				for (int h = 0; h < kudiszoma; h++) {
					if (kudia[h] == j && kudib[h] == i) {
						cout << "o";
						dabewdva = true;
					}
				}
				if (!dabewdva)  
					cout << " ";
			}

				if (j == 26)
					cout << "|";  
			}
			cout << endl;
		}

		for (int i = 0; i < 29; i++) {
			cout << "-";            
		}
		cout << endl;
		cout << "qula :" << qula << endl; 
	}

	void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w' :
			dir = UP;
			break;
		case 's':
			dir = DOWN; 
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			dasrulda = true;
			break;
		}
	}
}
	void logika() {
	int tavd2A, tavd2B;
	int tavdA = kudia[0];
	int tavdB = kudib[0];
	kudia[0] = a;
	kudib[0] = b;
	for (int i = 1; i < kudiszoma; i++) {
		tavd2A = kudia[i];
		tavd2B = kudib[i];
		kudia[i] = tavdA;
		kudib[i] = tavdB;
		tavdA = tavd2A;
		tavdB = tavd2B;
	}
	switch (dir){
	case LEFT:
		a--;
		break;
	case RIGHT:
		a++;
		break;
	case UP:
		b--;
		break;
	case DOWN:
		b++;
		break;
	default:
		break;
	}
	if (a > 27 || a < 0 || b > 20 || b < 0)
		dasrulda = true;
	if (a == sawmelia && b == sawmelib) {
		qula += 5;
		kudiszoma++;
		sawmelia = rand() % 27;
		sawmelib = rand() % 20;
	}
   int z = 700;
	if (qula <= 15) {
		Sleep(z);
	}
	else if (qula > 15 && qula <= 25) {
		Sleep(z - 200);
	}
	else if (qula > 25 && qula <= 50) {
		Sleep(z - 400);
	}
	else Sleep(z - 600);
}

	int main(){
	awyoba();
	while (!dasrulda) {
		map();
		input();
		logika();
	}
}
