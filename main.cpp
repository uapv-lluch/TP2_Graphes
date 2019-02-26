#include <iostream>
#include <vector>
#include <list>

using namespace std;

const unsigned n = 8;
unsigned c[n][n];


vector<int> mooreDijkstra(unsigned s) {
    vector<unsigned> C;
    list<unsigned> Cbarre;
    for (unsigned i = 0; i < n; ++i) {
        Cbarre.push_back(i);
    }
    C.push_back(s);
    Cbarre.remove(s);
    vector<unsigned> d(n);
    vector<int> pere(n);
    for (unsigned i = 0; i < n; ++i) {
        pere[i] = -1;
    }
    for (unsigned i = 0; i < n; ++i) {
        d[i] = 99999;
    }
    d[s] = 0;
    unsigned j = s;
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


vector<int> bellman(unsigned s) {
    int k = 0;
    vector<vector<unsigned>> d(n+1, vector<unsigned>(n));
    for (unsigned i = 0; i < d[0].size(); ++i) {
        d[0][i] = 99999;
    }
    d[0][s] = 0;
    vector<int> pere(n);
    for (vector<int>::iterator it = pere.begin(); it != pere.end(); ++it) {
        *it = -1;
    }
    bool stop = false;
    while (k < n && !stop) {
        for (unsigned i = 1; i < n; ++i) {
            d[k+1][i] = d[k][i];
            for (unsigned j = 0; j < n; ++j) {
                if (c[j][i] != 0) {
                    if (d[k][j] + c[j][i] < d[k+1][i]) {
                        d[k+1][i] = d[k][j] + c[j][i];
                        pere[i] = j;
                    }
                }
            }
        }
        ++k;
        /*for (unsigned i = 0; i < n; ++i) {
            if (d[k][i] == d[k-1][i]) {
                stop = true;
            }
        }*/
    }
    return pere;
}


void displayShortestPath(vector<int> pere) {
    for (unsigned i = 0; i < pere.size(); ++i) {
        int pereActuel = pere[i];
        int filsActuel = i;
        int chemin = 0;
        while (pereActuel != -1) {
            chemin += c[pereActuel][filsActuel];
            filsActuel = pereActuel;
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

    c[1][0] = 2;
    c[3][0] = 6;
    c[4][1] = 7;
    c[2][1] = 2;
    c[5][2] = 2;
    c[3][2] = 1;
    c[6][3] = 4;
    c[5][4] = 3;
    c[7][4] = 3;
    c[6][5] = 2;
    c[7][6] = 2;

    cout << endl << "Dijkstra" << endl;
    vector<int> pere = mooreDijkstra(0);
    displayShortestPath(pere);

    cout << endl << "Bellman" << endl;
    pere = bellman(0);
    displayShortestPath(pere);
    return 0;
}