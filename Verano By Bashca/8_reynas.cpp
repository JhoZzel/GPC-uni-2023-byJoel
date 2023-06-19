#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char mat[10][10];

void solve_8_reynas(int r[], int c) {
    if (c == 8) {
        memset(mat, '_', sizeof mat);
        for (int i=0; i<8; ++i) {
            mat[r[i]][i] = 'Q';
        }
        cout << endl;
        cout << endl;
        cout << "NEW SOLUTION: " << endl;
        for (int i=0; i<8; ++i) {
            cout << "|";
            for (int j = 0; j < 8; ++j) {
                cout << mat[i][j];
                cout << "|";
            }
            cout << endl;
        }
    }

    for (int i=0; i<8; i++) {
        bool can = true;
        for (int j=0; j<c; j++) {
            if (r[j]==i || abs(j-c)==abs(r[j]-i)) {
                can = false;
                break;
            }
        }
        if (can) {
            r[c]=i;
            solve_8_reynas(r, c + 1);
        }
    }
}


int main() {
    int r[10];
    solve_8_reynas(r,0);
    return 0;
}