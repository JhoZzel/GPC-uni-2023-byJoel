#include <bits/stdc++.h>
using namespace std;


char mat[10][10];

int eight_queen_generator(int r[], int c) {
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
        return 1;
    }


    bool vis_r[10] = {1, 0, 0, ...., 0};

    bool vis_d1[15] = {0, 0, ...., }

    vis_d1[c + i]

    vis_d2[c - i + 7]


    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        bool can = true;
        
        if (vis_r[i]) continue;
        if (vis_d1[c + i]) continue;
        ...


        for (int j = 0; j < c; ++j) {
            if (r[j] == i || abs(j - c) == abs(r[j] - i)) {
                can = false;
                break;
            }
        }
        if (can) {
            
            vis_r[i] = 1;
            vis_d1[c+i] = 1;
            vis_d2[c-i+7] = 1;
            r[c] = i;
            cnt += eight_queen_generator(r, c + 1);

            vis_r[i] = 0;
            vis_d1[c+i] = 0;
            vis_d2[c-i+7] = 0;

            //r[c] = -1;
        }
    }
    return cnt;
}



int main() {
    int r[10];
    int ns = eight_queen_generator(r, 0);
    cout << "number of solutions: " << ns << endl;
    return 0;
}