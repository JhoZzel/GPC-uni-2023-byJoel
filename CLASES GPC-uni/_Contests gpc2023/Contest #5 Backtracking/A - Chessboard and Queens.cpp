#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int ans = 0;
int board[n][n];


bool validar(int r, int c) { // 0:free   1:ocupado   -1:reservado
    if (abs(board[r][c])) return 0;

    for (int i=0; i<n; i++) {
        if (board[r][i] == 1) return 0;
        if (board[i][c] == 1) return 0;
    }
    
    int Dx[] = {1,1,-1,-1};
    int Dy[] = {1,-1,1,-1};

    for (int i=0; i<4; i++) {
        for (int jump = 1; jump <= n; jump++) {
            int rr = r + Dx[i] * jump;
            int cc = c + Dy[i] * jump;
            if (rr < 0 || cc < 0 || rr >= n || cc >= n) break;
            if (board[rr][cc] == 1) return 0;
        }
    }

    return 1;
}
void bt(int k) { // k columna
    if (k == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (validar(i,k)) {
            int prev = board[i][k];
            board[i][k] = 1;
            bt(k+1);
            board[i][k] = prev;
        }
    }
}

int main() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char c; cin >> c;
            if (c == '*') board[i][j] = -1;
        }
    }

    bt(0);

    cout << ans << "\n";
    
    return 0;
}