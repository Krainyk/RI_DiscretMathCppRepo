#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int N = 6;
	const int M = 8;

	int data[15][3] = {
		{1,2,1},
		{1,3,2},
		{1,4,1},
		{1,5,0},
		{1,6,0},
		{2,3,0},
		{2,4,0},
		{2,5,0},
		{2,6,1},
		{3,4,1},
		{3,5,1},
		{3,6,0},
		{4,5,1},
		{4,6,0},
		{5,6,0}
	};

	// Ìàòğèöÿ ñóì³æíîñò³
	int A[N][N] = { 0 };

	int edgeCount = 0;
	for (int i = 0; i < 15; i++) {
		int m = data[i][0] - 1;
		int n = data[i][1] - 1;
		int r = data[i][2];

		A[m][n] = r;
		A[n][m] = r;
		edgeCount += r;
	}

	// ²ncidence matrix
	int I[N][M] = { 0 };

	int e = 0;
	for (int i = 0; i < 15; i++) {
		int m = data[i][0] - 1;
		int n = data[i][1] - 1;
		int r = data[i][2];

		for (int k = 0; k < r; k++) {
			I[m][e] = 1;
			I[n][e] = 1;
			e++;
		}
	}

	cout << "Adjacency matrix A: " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(2) << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Incidence matrix I: " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << setw(2) << I[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
