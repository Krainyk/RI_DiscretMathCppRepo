#include <iostream>
#include <vector>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int N = 4;

void printMatrix(int matrix[N][N]) {
    cout << "Матриця" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printGraph(int matrix[N][N]) {
    cout << "Граф" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                cout << (i + 1) << " -> " << (j + 1) << endl;
            }
        }
    }
    cout << endl;
}


bool Reflexive(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] == 0) return false;
    }
    return true;
}

bool Irreflexive(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] == 1) return false;
    }
    return true;
}

bool Symmetric(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}

bool Asymmetric(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1 && matrix[j][i] == 1) return false;
        }
    }
    return true;
}

bool Antisymmetric(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) return false; // Заборонено назад тільки для різних
        }
    }
    return true;
}

bool Transitive(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (matrix[i][k] == 1 && matrix[k][j] == 1 && matrix[i][j] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int matrix[N][N] = { 0 };

    
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 1;

    
    printMatrix(matrix);
    printGraph(matrix);

    
    cout << setw(25) << "Аналіз властивостей: " << endl;

    bool ref = Reflexive(matrix);
    bool sym = Symmetric(matrix);
    bool trans = Transitive(matrix);
    bool anti = Antisymmetric(matrix);

    cout << "Рефлексивність:   " << (ref ? "Так" : "Ні") << endl;
    cout << "Іррефлексивність: " << (Irreflexive(matrix) ? "Так" : "Ні") << endl;
    cout << "Симетричність:    " << (sym ? "Так" : "Ні") << endl;
    cout << "Антисиметричність:" << (anti ? "Так" : "Ні") << endl;
    cout << "Асиметричність:   " << (Asymmetric(matrix) ? "Так" : "Ні") << endl;
    cout << "Транзитивність:   " << (trans ? "Так" : "Ні") << endl;

    cout << "-------------------------" << endl;

    bool Equivalence(ref && sym && trans);
    bool Partialorder(ref && anti && trans);

 if (Equivalence) {
        cout << "Це відношення ЕКВІВАЛЕНТНОСТІ." << endl;
    }
    else {
        cout << "Це НЕ є відношення еквівалентності." << endl;
    }

    if (Partialorder) {
        cout << "Це відношення ЧАСТКОВОГО ПОРЯДКУ." << endl;
    }
    else {
        cout << "Це НЕ є відношення часткового порядку." << endl;
    }

    cout << "-------------------------" << endl;

    if (!(Equivalence) && !(Partialorder)) {
        cout << "Жодна властивість не виконується." << endl;
    }

    return 0;
}