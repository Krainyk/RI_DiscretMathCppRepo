#include <iostream>
using namespace std;
int main() {
	int U[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // оголошення універсуму
	int A[7] = { 1, 2, 3, 4, 5, 6, 7 }; // оголошення множини A
	int B[6] = { 5, 6, 7, 8, 9, 10 };  // оголошення множини B
	int C[6] = { 1, 2, 3, 8, 9, 10 }; // оголошення множини C
	int f1[10];   // оголошення інших масивів
	int f2[10];
	int f3[10];
	int f4[10];
	int f5[10];
	int f6[10];
	int f7[10];
	int f8[10];
	int f9[10];

	int K, temp, i, j, f1N, f2N, f3N, f4N, f5N, f6N = 0, f7N = 0, f8N = 0, f9N = 0;
	K = 0;
	// Завдання 1: f1 = !B
	for (i = 0; i < 10; i++) { // перебір елементів універсуму
		temp = 0;
		for (j = 0; j < 6; j++) {   // перебір елементів множини B

			if (U[i] == B[j]) {
				temp = 1;
			}
		}
		if (temp == 0) {
			f1[K] = U[i];
			K = K + 1;
		}
	}
	f1N = K;
	cout << "B dopovnenya: " << endl;

	// Завдання 2: f2 = A ∩ B'
	K = 0;
	for (i = 0; i < 7; i++) { // перебір елементів множини A
		temp = 0;
		for (j = 0; j < f1N; j++) {  // перебір елементів множини B'
			if (A[i] == f1[j]) {
				f2[K] = A[i];
				K = K + 1;
				break;
			}
		}

	}
	f2N = K;
	cout << "A pereriz B dopovnenya: " << endl;

	// Завдання 3: f3 = (A ∩ B')'
	K = 0;
	for (i = 0; i < 10; i++) { // перебір елементів універсуму
		temp = 0;
		for (j = 0; j < f2N; j++) { // перебір елементів множини f2
			if (U[i] = f2[j]) { // Якщо знайшли а f2
				temp = 1;
				break;
			}			
		}
		if (temp == 0) { // Якщо не знайшли а f2
			f3[K] = U[i];
			K = K + 1;
		}
	}
	f3N = K;
	cout << "(A pereriz B dopovnenya) dopovnenya: " << endl;

	// Завдання 4: f4 = C'
	K = 0;
	for (i = 0; i < 10; i++) { // перебір елементів універсуму
		temp = 0;
		for (j = 0; j < 6; j++) { // перебір множини C
			if (U[i] == C[j]) { // Якщо знайшли в C
				temp = 1;
			}
			if (temp == 0) { // Якщо не знайшли в C 
				f4[K] = U[i];
				K = K + 1;
			}
		}
	}
	f4N = K;
	cout << "C dopovnenya: " << endl;

	// Завдання 5: f5 = B ∩ C'
	K = 0;
	for (i = 0; i < 6; i++) { // перебір елементів множини B
		temp = 0;
		for (j = 0; j < f4N; j++) {   // перебір елементів множини С'
			if (B[i] == f4[j]) {
				temp = 1;
				break;
			}
			if (temp == 1) {
				f5[K] = B[i];
				K = K + 1;
			}
		}
	}
	f5N = K;
	cout << "B pereriz C dopovnenya: " << endl;

	// Завдання 6: f6 = (A ∩ B')' \ A
	K = 0;
	for (i = 0; i < f3N; i++) { // перебір елементів множини f3
		temp = 0;
		for (j = 0; j < 7; j++) {  // перебір елементів множини A
			if (A[j] == f3[i]) {
				temp = 1;
				break;
			}
		}
		if (temp == 0) {
			f6[K] = f3[i];
			K = K + 1;
		}
	}
	f6N = K;
	cout << "(A pereriz B dopovnenya dopovnenya) riznycha A: " << endl;

	// Завдання 7: f7 = f6 symetrychna riznycha f5
	// Формула: (f6 \ f5) U (f5 \ f6)
	
	// Крок А: Знаходимо (f6 \ f5) і кладемо в f7	
	K = 0;
	for (i = 0; i < f6N; i++) { // перебір елементів множини f6
		temp = 0;
		for (j = 0; j < f5N; j++) { // перебір елементів множини f5
			if (f6[i] == f5[j]) {
				temp == 1;
				break;
			}
		}
		if (temp == 0) {
			f7[K] = f6[i];
			K = K + 1;
		}
	}
	f7N = K;

	// Крок Б: Знаходимо (f5 \ f6) і додаємо в f8
	K = 0;
	for (i = 0; i < f5N; i++) {
		temp = 0;
		for (j = 0; j < f6N; j++) {
			if (f5[i] == f6[j]) {
				temp = 1;
				break;
			}
		}
		if (temp == 0) {
			f8[K] = f5[i];
			K = K + 1;
		}
		
	}
	f8N = K;

	// Крок В: Об'єднуємо f7 та f8 у кінцевий масив f9
	// 1. Копіюємо все з f7 в f9
	K = 0;
	for (i = 0; i < f7N; i++) {
		f9[i] = f7[i];
		K = K + 1;
	}

	// 2. Додаємо все з f8 в f9
    K = 0;
	for (i = 0; i < f8N; i++) {
		f9[i] = f8[i];
		K = K + 1;
	}

	// --- Вивід кінцевого результату ---
	cout << "symetrychna riznycha: " << endl;
	for (i = 0; i < f9N; i++) {
		cout << f9[i];
		if (i < f9N - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}