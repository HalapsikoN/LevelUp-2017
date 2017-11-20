#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>

char A[16][16];
int i, j;

int symbleX(int i, int j) {
	int ia, jb, b;
	jb = j;
	for (ia = i; ia <= i + 3; ia++) {
		A[ia][jb] = '\\';
		jb++;
	}
	b = 0;
	for (ia = i; ia <= i + 3; ia++) {
		jb = j + 3 - b;
		A[ia][jb] = '/';
		b++;
	}
	return 0;
}

int symbleO(int i, int j) {
	int ia, jb;
	for (ia = i; ia <= i + 3; ia += 3)
		for (jb = j + 1; jb <= j + 2; jb++)
			A[ia][jb] = '_';
	for (ia = i + 1; ia <= i + 3; ia++)
		for (jb = j; jb <= j + 3; jb += 3)
			A[ia][jb] = '|';
	return 0;
}

int zapis(int hodf, int mi, int nj) {
	if (hodf % 2 == 0)
		symbleO(mi, nj);
	else
		symbleX(mi, nj);
	for (i = 0; i < 16; i++) {
		printf("\n");
		for (j = 0; j < 16; j++)
			printf("%c", A[i][j]);
	}
	printf("\n");
	return 0;
}




int main() {
	setlocale(LC_ALL, "RUS");
	int hod = 0, klet, n1, f1 = 1, f2 = 1, f3 = 1, f4 = 1, f5 = 1, f6 = 1, f7 = 1, f8 = 1, f9 = 1;
	// очищение поля
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
			A[i][j] = ' ';
	//создание рамки (строки затем столбцы)
	for (i = 0; i < 16; i += 5)
		for (j = 0; j < 16; j++)
			A[i][j] = '#';
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j += 5)
			A[i][j] = '#';
	while (hod < 9) {
		do {
			printf("Выберите клеточку\n");
			rewind(stdin);
			n1 = scanf_s("%d", &klet);
		} while (!n1 || klet < 1 || klet>9);
		system("CLS");
		hod++;
		switch (klet) {
		case 1: { if (f1 == 1) {
			zapis(hod, 1, 1);
			f1 = 0;
		}
				else
					hod--;
		}break;
		case 2: { if (f2 == 1) {
			zapis(hod, 1, 6);
			f2 = 0;
		}
				else
					hod--;
		}break;
		case 3: { if (f3 == 1) {
			zapis(hod, 1, 11);
			f3 = 0;
		}
				else
					hod--;
		}break;
		case 4: { if (f4 == 1) {
			zapis(hod, 6, 1);
			f4 = 0;
		}
				else
					hod--;
		}break;
		case 5: { if (f5 == 1) {
			zapis(hod, 6, 6);
			f5 = 0;
		}
				else
					hod--;
		}break;
		case 6: { if (f6 == 1) {
			zapis(hod, 6, 11);
			f6 = 0;
		}
				else
					hod--;
		}break;
		case 7: { if (f7 == 1) {
			zapis(hod, 11, 1);
			f7 = 0;
		}
				else
					hod--;
		}break;
		case 8: { if (f8 == 1) {
			zapis(hod, 11, 6);
			f8 = 0;
		}
				else
					hod--;
		}break;
		default: { if (f9 == 1) {
			zapis(hod, 11, 11);
			f9 = 0;
		}
				 else
					 hod--;
		}
		}
		// проверка на победку
		if (hod >= 5) {
			if ((A[4][4] + A[4][9] + A[4][14]) / 3.0 == '\\' || (A[9][4] + A[9][9] + A[9][14]) / 3.0 == '\\' || (A[14][4] + A[14][9] + A[14][14]) / 3.0 == '\\' || (A[4][4] + A[9][4] + A[14][4]) / 3.0 == '\\' || (A[4][9] + A[9][9] + A[14][9]) / 3.0 == '\\' || (A[4][14] + A[9][14] + A[14][14]) / 3.0 == '\\' || (A[4][4] + A[9][9] + A[14][14]) / 3.0 == '\\' || (A[4][14] + A[9][9] + A[14][4]) / 3.0 == '\\') {
				printf("\n");
				printf("Крестики победили\n");
				system("pause");
				return 0;
			}
			if ((A[4][4] + A[4][9] + A[4][14]) / 3.0 == '|' || (A[9][4] + A[9][9] + A[9][14]) / 3.0 == '|' || (A[14][4] + A[14][9] + A[14][14]) / 3.0 == '|' || (A[4][4] + A[9][4] + A[14][4]) / 3.0 == '|' || (A[4][9] + A[9][9] + A[14][9]) / 3.0 == '|' || (A[4][14] + A[9][14] + A[14][14]) / 3.0 == '|' || (A[4][4] + A[9][9] + A[14][14]) / 3.0 == '|' || (A[4][14] + A[9][9] + A[14][4]) / 3.0 == '|') {
				printf("\n");
				printf("Нолики победили\n");
				system("pause");
				return 0;
			}
		}
	}
	printf("\n");
	printf("Ничья\n");
	system("pause");
	return 0;

}

