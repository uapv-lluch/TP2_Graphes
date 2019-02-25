#include <iostream>
#include <vector>

using namespace std;

unsigned n = 8;

void MooreDijkstra(unsigned c) {
    unsigned C[n];
    C[0] = 0;
    unsigned d[n];
    unsigned pere[n];
    for (unsigned i = 0 ; i < n ; ++i) {
        pere[i] = 0;
    }
    for (unsigned j = 0 ; j < n ; ++j) {
        d[j] = 99999;
    }
    unsigned j = 1;
    for (unsigned l = 1 ; l < n ; ++l) {
        
    }
}


int main() {

    // Matrice représentative du graphe
    unsigned c[n][n];
    for (unsigned i=0; i < n; ++i){
        for(unsigned j=0; j < n; ++j){
            c[i][j] = 0;
        }
    }
    c[0][1] = 2;
    c[0][3] = 6;
    c[1][4] = 7;
    c[1][2] = 2;
    c[2][5] = 2;
    c[2][3] = 1;
    c[3][6] = 4;
    c[4][5] = 3;
    c[4][7] = 3;
    c[5][6] = 2;
    c[6][7] = 2;

    MooreDijkstra(c);
    return 0;
}