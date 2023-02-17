#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctime>

using namespace std;

void menu() {


	cout << "\n\t *** ИГРА 'ПЯТНАШКИ' ***" << endl;

	cout << "\n\t * управление стрелками * \n\n" << endl;
	cout << "\n\t [ ВЫБЕРИТЕ РЕЖИМ ИГРЫ ]";

	cout << "\n\n\tЛегкий:  (3х3)\t" << "- нажмите 1";
	cout << "\n\tТяжелый: (4х4) \t" << "- нажмите 2";
	cout << "\n\tВыход :\t" << "\t- нажмите 0" << endl;
}

void initMix(int** masMix, int N) {

	if (N == 3) {
		int X = rand() % 3 + 1;
		int mix_1[3][3]{ {2,3,6},
						 {1,5,8},
						 {4,7,0}
		};
		int mix_2[3][3]{ {3,1,2},
						 {7,5,6},
						 {8,4,0}
		};
		int mix_3[3][3]{ {5,7,2},
						 {1,3,6},
						 {8,4,0}
		};
		if (X == 1) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					masMix[i][j] = mix_1[i][j];
				}
			}

		}

		if (X == 2) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					masMix[i][j] = mix_2[i][j];
				}
			}

		}

		if (X == 3) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					masMix[i][j] = mix_3[i][j];
				}
			}

		}

	}

	if (N == 4) {
		int X = rand() % 3 + 1;
		int mix_1[4][4]{ {6,10,7,14},
						 {2,5,11,8},
						 {1,13,4,3},
						 {9,15,12,0}
		};
		int mix_2[4][4]{ {2,6,11,7},
						 {1,13,10,14},
						 {5,15,8,3},
						 {9,12,4,0}
		};

		int mix_3[4][4]{ {13,1,8,7},
						 {6,11,2,10},
						 {9,5,15,14},
						 {12,4,3,0}
		};

		if (X == 1) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					masMix[i][j] = mix_1[i][j];
				}
			}

		}

		if (X == 2) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					masMix[i][j] = mix_2[i][j];
				}
			}

		}

		if (X == 3) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					masMix[i][j] = mix_3[i][j];
				}
			}

		}

	}


}
void deleteMas(int** masMix, int size) {

	for (int i = 0; i < size; i++)
	{
		delete[]masMix[i];
	}
	delete[]masMix;

}

void sravnenie(int** masMix, int& hod, int& game_mode, int start) {

	if (game_mode == 1) {

		int mas[3][3] = { {1,2,3},
						  {4,5,6},
						  {7,8,0}
		};
		int X = 9, count = 0;
		hod++;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (mas[i][j] == masMix[i][j]) {

					count++;
				}
			}
		}
		if (count == X) {

			int allSec = (clock() - start) / 1000;
			int min = allSec / 60;
			int sec = allSec % 60;

			cout << "\n  You WIN!!!\n\n";
			cout << "Вы сделали " << hod << " ходов\n";
			cout << "Время : " << min << " мин." << sec << " сек";
			cout << "\n\nНажмите 0 для выхода\n ";



		}
	}

	if (game_mode == 2) {


		int mas[4][4] = { {1,2,3,4},
						  {5,6,7,8},
						  {9,10,11,12},
						  {13,14,15,0}
		};
		int X = 15, count = 0;
		hod++;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (mas[i][j] == masMix[i][j]) {

					count++;
				}
			}
		}
		if (count == X) {

			cout << "\n  You WIN!!!\n\n";
			cout << "Вы сделали " << hod << " ходов\n";
			cout << "Время : " << (clock() - start) / 1000 << " сек.";
			cout << "\n\nНажмите 0 для выхода : ";


		}
	}

}

void print(int** masMix, int size) {


	system("cls");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {

			if (masMix[i][j] == 0) {

				cout << "\t";
			}

			else
				cout << masMix[i][j] << "\t";

		}
		cout << "\n\n\n";
	}

}

void swap_down(int** masMix, int size) {

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++) {

			if (masMix[i][j] == 0) {
				masMix[i][j] = masMix[i - 1][j];
				masMix[i - 1][j] = 0;
				break;
			}
		}
		cout << endl;

	}
	//system("cls");
	print(masMix, size);

}
void swap_right(int** masMix, int size) {

	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++) {

			if (masMix[i][j] == 0) {
				masMix[i][j] = masMix[i][j - 1];
				masMix[i][j - 1] = 0;
				break;
			}
		}
		cout << endl;
	}
	//system("cls");
	print(masMix, size);


}
void swap_up(int** masMix, int size) {

	int X = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++) {

			if (masMix[i][j] == 0) {

				masMix[i][j] = masMix[i + 1][j];
				masMix[i + 1][j] = 0;
				X++;
				break;
			}

		}
		cout << endl;

		if (X == 1) {
			break;
		}
	}
	//system("cls");
	print(masMix, size);


}
void swap_left(int** masMix, int size) {

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++) {

			if (masMix[i][j] == 0) {

				masMix[i][j] = masMix[i][j + 1];
				masMix[i][j + 1] = 0;
				break;
			}
		}
		cout << endl;

	}
	//system("cls");
	print(masMix, size);

}



int main() {
	setlocale(0, "");
	srand(time(NULL));

	int game_mode;
	int n;
	int povtor;
	do {
		int hod = 0;
		menu();

		cin >> game_mode;
		cout << endl;


		if (game_mode == 1) {
			int start = clock();
			n = 3;

			int** masMix = new int* [n];
			for (int i = 0; i < n; i++)
			{
				masMix[i] = new int[n] {};
			}

			initMix(masMix, n);

			print(masMix, n);

			int x;

			do {
				x = _getch();

				switch (x)
				{
				case 80:swap_down(masMix, 3);
					sravnenie(masMix, hod, game_mode, start);

					break;
				case 77:swap_right(masMix, 3);
					sravnenie(masMix, hod, game_mode, start);

					break;
				case 75:swap_left(masMix, 3);
					sravnenie(masMix, hod, game_mode, start);

					break;
				case 72:swap_up(masMix, 3);
					sravnenie(masMix, hod, game_mode, start);

					break;
				}

			} while (x != 48);

			cout << "\n\nВы вышли из игры \n";
			deleteMas(masMix, n);

		}

		if (game_mode == 2) {
			int start = clock();
			n = 4;
			int** masMix = new int* [n];
			for (int i = 0; i < n; i++)
			{
				masMix[i] = new int[n] {};
			}
			initMix(masMix, n);
			print(masMix, n);

			int x;
			do {

				x = _getch();


				switch (x)
				{
				case 80:swap_down(masMix, n);
					sravnenie(masMix, hod, game_mode, start);
					break;
				case 77:swap_right(masMix, n);
					sravnenie(masMix, hod, game_mode, start);
					break;
				case 75:swap_left(masMix, n);
					sravnenie(masMix, hod, game_mode, start);
					break;
				case 72:swap_up(masMix, n);
					sravnenie(masMix, hod, game_mode, start);
					break;
				}

			} while (x != 48);
			cout << "\n\nВы вышли из игры \n";
			deleteMas(masMix, n);
		}

		cout << "\n *** Хотите сыграть заново? ***   " << " | 1-ДА  |\t| 0-НЕТ |\n";
		cin >> povtor;
	} while (povtor == 1);
	cout << "\n * GOOD BAY *\n";
}