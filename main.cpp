#include <iostream>
#include <vector>

using namespace std;

unsigned n = 6;

void MooreDijkstra() {
    vector<unsigned> C = vector<unsigned>();
    C.push_back(0);
    unsigned d[n];
    unsigned pere[n];
    for (unsigned i = 0 ; i < n ; ++i) {
        pere[i] = 0;
    }
    unsigned j = 1;
    for (unsigned l = 1 ; l < n ; ++l) {
        
    }
}


int main() {

    for (unsigned i = 0 ; i < n ; ++i) {
        for (unsigned j = 0 ; j < n ; ++j) {
//            c[i][j] = 0;
        }
    }
    MooreDijkstra();
    return 0;
}