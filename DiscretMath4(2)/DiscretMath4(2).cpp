#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int V = 7;

void floydWarshall(vector<vector<int>>& dist) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    dist[0][1] = 21; // a -> b
    dist[0][3] = 1;  // a -> d
    dist[3][1] = 16; // d -> b
    dist[1][2] = 2;  // b -> c
    dist[1][4] = 7;  // b -> e
    dist[2][4] = 3;  // c -> e
    dist[4][3] = 9;  // d -> e
    dist[3][5] = 10; // d -> f
    dist[4][5] = 30; // f -> e
    dist[4][6] = 6;  // e -> g
    dist[6][5] = 12; // g -> f

    floydWarshall(dist);

    if (dist[0][6] != INF)
        cout << "The fastest way from a to g: " << dist[0][6] << endl;
    else
        cout << "There`s no existed way from a to g: " << endl;

    return 0;
}
