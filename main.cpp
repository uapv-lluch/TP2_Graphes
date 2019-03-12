#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

const int n = 8;
int cOld[n][n];
vector<int> d;

struct arc {
    int noeud;
    int val;
};

vector<string> split(string str, char delimiter) {
    vector <string> result;
    size_t begin = 0;
    size_t index = str.find(delimiter);
    while (index != string::npos) {
        string sub = str.substr(begin, index-begin);
        result.push_back(sub);
        begin = index+1;
        index = str.find(delimiter, begin);
    }
    string sub = str.substr(begin, str.find('\n')-begin);
    result.push_back(sub);
    return result;
}

void display(vector<int> & v)
{
    int n = v.size();

    for(int i = 0; i < (n-1); i++)
        cout << v[i] << " ; ";

    cout << v[n-1] << endl;
}

bool cmp(const int & i, const int & j) {
    return(d[i] < d[j]);
}

vector<int> mooreDijkstra(int s, vector<vector<int>> c) {
    vector<int> C;
    list<int> Cbarre;
    for (int i = 0; i < n; ++i) {
        Cbarre.push_back(i);
    }
    C.push_back(s);
    Cbarre.remove(s);
    vector<int> d(n);
    vector<int> pere(n);
    for (int i = 0; i < n; ++i) {
        pere[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        d[i] = 99999;
    }
    d[s] = 0;
    int j = s;
    for (int l = 1; l < n; ++l) {
        for (list<int>::iterator it = Cbarre.begin(); it != Cbarre.end(); ++it) {
            if (c[j][*it] != 0) {
                if (d[j] + c[j][*it] < d[*it]) {
                    d[*it] = d[j] + c[j][*it];
                    pere[*it] = j;
                }
            }
        }
        // Argmin
        int min = 99999;
        for (list<int>::iterator it = Cbarre.begin(); it != Cbarre.end(); ++it) {
            if (d[*it] < min) {
                min = d[*it];
                j = *it;
            }
        }
        C.push_back(j);
        Cbarre.remove(j);
    }
    /*for (int i = 0; i < n; ++i) {
        cout << i << ": " << d[i] << endl;
    }*/
    return pere;
}

vector<int> mooreDijkstas(int s, vector<vector<int>> c) {
//    vector<int> C;
//    list<int> Cbarre;
    /*for (int i = 0; i < n; ++i) {
        Cbarre.push_back(i);
    }*/
//    C.push_back(s);
//    Cbarre.remove(s);
//    vector<int> d(n);


    d.resize(n);
    vector<int> pere(n);
    vector<int> T;
    for (int i = 0; i < n; ++i) {
        pere[i] = -1;
        d[i] = 99999;
    }
    d[s] = 0;
    for (int i = 0; i < n ; ++i) {
        T.push_back(i);
    }
    make_heap(T.begin(), T.end(), cmp);
    int j = s;
    for (int l = 1; l < n; ++l) {
        for (vector<int>::iterator it = T.begin(); it != T.end(); ++it) {
            if (c[j][*it] != 0) {
                if (d[j] + c[j][*it] < d[*it]) {
                    d[*it] = d[j] + c[j][*it];
                    pere[*it] = j;
                }
            }
        }
        sort_heap(T.begin(), T.end(), cmp);

        pop_heap(T.begin(), T.end(), cmp);

        j = T.back();

        T.pop_back();



        /*int min = 99999;
        for (list<int>::iterator it = Cbarre.begin(); it != Cbarre.end(); ++it) {
            if (d[*it] < min) {
                min = d[*it];
                j = *it;
            }
        }


        C.push_back(j);
        Cbarre.remove(j);*/
    }
    /*for (int i = 0; i < n; ++i) {
        cout << i << ": " << d[i] << endl;
    }*/
    return pere;
}


vector<int> bellman(int s, vector<vector<int>> c) {
    int k = 0;
    vector<vector<int>> d(n+1, vector<int>(n));
    for (int i = 0; i < d[0].size(); ++i) {
        d[0][i] = 99999;
    }
    d[0][s] = 0;
    vector<int> pere(n);
    for (vector<int>::iterator it = pere.begin(); it != pere.end(); ++it) {
        *it = -1;
    }
    bool stop = false;
    while (k < n && !stop) {
        for (int i = 1; i < n; ++i) {
            d[k+1][i] = d[k][i];
            for (int j = 0; j < n; ++j) {
                if (c[j][i] != 0) {
                    if (d[k][j] + c[j][i] < d[k+1][i]) {
                        d[k+1][i] = d[k][j] + c[j][i];
                        pere[i] = j;
                    }
                }
            }
        }
        ++k;
        stop = true;
        for (int i = 0; i < n; ++i) {
            if (d[k][i] != d[k-1][i]) {
                stop = false;
            }
        }
    }
    return pere;
}


void displayShortestPath(vector<int> pere, vector<vector<int>> c) {
    for (int i = 0; i < pere.size(); ++i) {
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



vector<list<arc>> makeList() {
    vector<list<arc>> T;
    ifstream file("../resources/USA-road-d.NY.gr", ios::in);
    if (file) {
        string line;
        while (getline(file, line)) {
            vector <string> splited = split(line, ' ');
            if (splited[0] == "p") {
                T.resize(stoul(splited[2]));

            } else if (splited[0] == "a") {
                arc a = {stoi(splited[2]), stoi(splited[3])};
                T[stoi(splited[1])-1].push_back(a);
            }
        }
    } else {
        cerr << "Error file";
    }
    return T;
}


int main() {

    vector<vector<int>> c(n, vector<int>(n));

    // Matrice représentative du graphe
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
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

    vector<list<arc>> arcs = makeList();

    vector<int> pere;

    cout << endl << "Dijkstra" << endl;
    pere = mooreDijkstra(0, c);
    displayShortestPath(pere, c);

    cout << endl << "Dijkstra (tas)" << endl;
    pere = mooreDijkstas(0, c);
    displayShortestPath(pere, c);

    cout << endl << "Bellman" << endl;
    pere = bellman(0, c);
    displayShortestPath(pere, c);
    return 0;
}