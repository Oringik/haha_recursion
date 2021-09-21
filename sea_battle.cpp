/* пример расстановки кораблей
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0
0 1 0 1 0 0 1 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
0 0 1 0 1 0 0 1 0 0
0 0 1 0 1 0 0 1 0 0
1 0 0 0 0 0 0 1 0 0*/



/* пример игры одного игрока
0 0 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 1 0 0 0 0 0 0 0 
0 1 0 0 1 1 0 0 0 0 
0 0 1 0 0 0 0 0 1 0 
0 1 0 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0 0 
1 0 0 1 0 0 0 0 0 0 
0 0
1 3
1 4
1 6
3 3
3 2
4 1
4 4
9 8
4 5
4 6
5 1
7 4
5 2
5 8
6 1
6 2
6 3
8 7
9 0
9 3
9 4
9 9*/





#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>




int main() {
	using namespace std;

	setlocale(LC_ALL, "Russian");

	int arr[100][100][2], n = 10;


	cout << "Первый игрок расставляет корабли" << endl;
	Sleep(500);
	system("cls");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j][0];
		}
	}
	Sleep(500);
	system("cls");

	int count1 = 0;
	for (int i = 0; i < n; i++) {   //основываясь на том, что кол-во единииц 1 игрока равно кол-ву единиц 2 игрока
		for (int j = 0; j < n; j++) {
			if (arr[i][j][0] == 1)
				count1++;
		}
	}
	cout << "Второй игрок расставляет корабли" << endl;
	Sleep(2000);
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j][1];
		}
	}

	int x1, y1, x2, y2, x, y;
	int count_for_win1 = 0, count_for_win2 = 0;

	while (true) {
		cout << "Первый игрок стреляет" << endl;
		Sleep(2000);
		system("cls");

		cin >> x >> y;
		if (arr[x][y][1] == 1) {
			arr[x][y][1] = 2; //2 - код попадания первого

			count_for_win1++;

	
					cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i << " ";
						for (int j = 0; j < 10; j++) {
							if (arr[i][j][1] == 0) {
								cout << " ";
							}
							else if (arr[i][j][1] == 3) {
								cout << ".";
							}
							else if (arr[i][j][1] == 1) {
								cout << "#";
							}
							else if (arr[i][j][1] == 2) {
								cout << "+";
							}
							cout << " ";
						}
						cout << endl;
					}
		
			Sleep(2000);
			system("cls");
		}


		Sleep(2000);
		system("cls");
		if (arr[x][y][1] != 1) {                         //промах первого
			arr[x][y][1] = 3;
			cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
			for (int i = 0; i < 10; i++) {
				cout << i << " ";
				for (int j = 0; j < 10; j++) {
					if (arr[i][j][1] == 0) {
						cout << " ";
					}
					else if (arr[i][j][1] == 3) {
						cout << ".";
					}
					else if (arr[i][j][1] == 2) {
						cout << "+";
					}
					else if (arr[i][j][1] == 3) {
						cout << ".";
					}
					cout << " ";
				}
				cout << endl;
			}
			Sleep(2000);
			system("cls");

		}


		cout << "Стреляет второй игрок" << endl;
		Sleep(500);
		system("cls");

		cin >> x >> y;
		if (arr[x][y][0] == 1) {
			arr[x][y][0] = 2; //2 - код попадания
			Sleep(500);
			system("cls");

			count_for_win2++;

					cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i << " ";
						for (int j = 0; j < 10; j++) {
							if (arr[i][j][0] == 0) {
								cout << " ";
							}
							else if (arr[i][j][0] == 3) {
								cout << ".";
							}
							else if (arr[i][j][0] == 1) {
								cout << "#";
							}
							else if (arr[i][j][0] == 2) {
								cout << "+";
							}
							cout << " ";
						}
						cout << endl;
					}
		
			Sleep(500);
			system("cls");
		}
		else {
			arr[x][y][0] = 3;
			cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
			for (int i = 0; i < 10; i++) {
				cout << i << " ";
				for (int j = 0; j < 10; j++) {
					if (arr[i][j][0] == 0) {
						cout << " ";
					}
					else if (arr[i][j][0] == 2) {
						cout << "+";
					}
					else if (arr[i][j][0] == 3) {
						cout << ".";
					}
					cout << " ";
				}
				cout << endl;
			}
		}
		Sleep(1000);
		system("cls");


		if (count1 == count_for_win1) {
			cout << "Победил 1 игрок" << endl;
			Sleep(2000);
				system("cls");

			break;
		}
		else if (count1 == count_for_win2) {
			cout << "Победил 2 игрок" << endl;
			Sleep(2000);
				system("cls");

			break;

		}
	}



	cout << "Игра закончена" << endl;
	Sleep(2000);
	system("cls");

	return 0;
}
