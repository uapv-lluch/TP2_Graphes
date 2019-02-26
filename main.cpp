#include <iostream>
#include <vector>
#include <list>

using namespace std;

const unsigned n = 8;
unsigned c[n][n];


vector<int> mooreDijkstra(unsigned c[n][n]) {
    vector<unsigned> C;
    list<unsigned> Cbarre;
    for (unsigned i = 0; i < n; ++i) {
        Cbarre.push_back(i);
    }
    C.push_back(0);
    Cbarre.remove(0);
    vector<unsigned> d(n);
    vector<int> pere(n);
    for (unsigned i = 0; i < n; ++i) {
        pere[i] = -1;
    }
    for (unsigned i = 0; i < n; ++i) {
        d[i] = 99999;
    }
    d[0] = 0;
    unsigned j = 0;
    for (unsigned l = 1; l < n; ++l) {
        for (list<unsigned>::iterator it = Cbarre.begin(); it != Cbarre.end(); ++it) {
            if (c[j][*it] != 0) {
                if (d[j] + c[j][*it] < d[*it]) {
                    d[*it] = d[j] + c[j][*it];
                    pere[*it] = j;
                }
            }
        }

        // Argmin
        unsigned min = 99999;
        for (list<unsigned>::iterator it = Cbarre.begin(); it != Cbarre.end(); ++it) {
            if (d[*it] < min) {
                min = d[*it];
                j = *it;
            }
        }

        C.push_back(j);
        Cbarre.remove(j);



    }
    /*for (unsigned i = 0; i < n; ++i) {
        cout << i << ": " << d[i] << endl;
    }*/
    return pere;
}


void displayShortestPath(vector<int> pere) {
    for (unsigned i = 0; i < pere.size(); ++i) {
        int pereActuel = pere[i];
        int pereDePereActuel = i;
        int chemin = 0;
        while (pereActuel != -1) {
            chemin += c[pereActuel][pereDePereActuel];
            pereDePereActuel = pereActuel;
            pereActuel = pere[pereActuel];
        }
        cout << i << " : " << chemin << endl;
    }
}


int main() {

    // Matrice représentative du graphe
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
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

    vector<int> pere = mooreDijkstra(c);
    /*for (auto it = pere.begin(); it != pere.end(); ++it) {
        cout << *it << endl;
    }*/

    displayShortestPath(pere);
    return 0;
}