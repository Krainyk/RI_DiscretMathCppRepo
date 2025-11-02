#include <iostream>
#include <cmath>
using namespace std;

int variations();
int Binom();
int rekursrivn();
int rekursrivn2();
int rekursrivn3();

// Завдання 1
int main()
{
	int n = 52, k = 15;
	double result = tgamma(n + 1) / (tgamma(k + 1) * tgamma(n - k + 1)); // Обчислення C(n, k), за допомогою функції гамма
	cout << "C(" << n << "," << k << ") = " << fixed << round(result) << endl;

	variations();
	Binom();
	rekursrivn();
	rekursrivn2();
	rekursrivn3();
	return 0;
}

// Завдання 2
static int variations() {
	int m = 2; // Є 2 монети
	int j = 2; // Кількість варіантів випаду "Орел - решка"
	cout << "V(" << m * j << ")" << endl;
	return m * j;
}

// Завдання 3
long long factorial(int n) { // Створення факторіала за допомогою циклу 
	long long res = 1;
	for (int j = 1; j <= n; j++)
		res *= j;
	return res;
}

long long power(long long base, int exp) { // Створення степеня за допомогою циклу
	long long res = 1;
	for (int j = 0; j < exp; j++)
		res *= base;
	return res;
}

static int Binom() {
	int n = 18;
	int i = 8;          // 4(18 - i) = 40 => i = 8; 2i = 16 => i = 8;
	long long C = factorial(n) / (factorial(i) * factorial(n - i)); // Обчислення C(n, k), за допомогою функції гамма
	long long result = C * power(4, 18 - i) * power(8, i);
	cout << "C(" << n << "," << i << ") = " << (result) << endl;
	return result;
}

// Завдання 4
static int rekursrivn() {
	int b = 1;
	int c = 2;
	int d = 8;
	int a_0 = 3;
	int a_1 = 7;
	int a_2 = ((c / b) * a_1 + (d / b) * a_0);
	cout << "a2 = " << a_2 << endl;
	return a_2;
}
static int rekursrivn2() {
	int a_0 = 3;
	int a_1 = 7;
	double c1 = 2, c2 = 8; // r^2 - 2r + 8 = 0
	double D = c1 * c1 + 4 * c2;
	int r1 = (c1 - sqrt(D)) / 2.0;
	int r2 = (c1 + sqrt(D)) / 2.0;

	cout << "r1 = " << r1 << ", r2 = " << r2 << endl;
	return 0;
}

static int rekursrivn3() {
	double  a1 = 1, b1 = 1, c1 = 3;
	double a2 = -2, b2 = 4, c2 = 7;

	double D = (a1 * b2 - a2 * b1);
	double Dx = (b1 * c2 - b2 * c1);
	double Dy = (a1 * c2 - a2 * c1);

	double B1 = Dx / D;
	double B2 = Dy / D;

	cout << "B1 = " << B1 << ", B2 = " << B2 << endl;
	cout << "a_n = 5 / 6 * (-2)^n + 13 / 6 * 4^n";
	return 0;
}