#include <bits/stdc++.h>
using namespace std;

const int n = 8;

bool board[n][n];

void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) cout << "X ";
            else cout << "o ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool validar(int r, int c) {
    if (board[r][c]) return 0;

    for (int i=0; i<n; i++) {
        if (board[r][i]) return 0;
        if (board[i][c]) return 0;
    }
    
    for (int jump = 0; jump <= n; jump++) {
        int Dx[] = {1,1,-1,-1};
        int Dy[] = {1,-1,1,-1};

        for (int i=0; i<4; i++) {
            int rr = r + Dx[i] * jump;
            int cc = c + Dy[i] * jump;
            if (rr >= n || cc >= n) break;
            if (board[rr][cc]) return 0;
        }
    }

    return 1;
}
void bt(int k) { // k columna
    if (k == n) {
        printBoard();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (validar(i,k)) {
            board[i][k] = 1;
            bt(k+1);
            board[i][k] = 0;
        }
    }
}

int main() {
    bt(0);
    return 0;
}