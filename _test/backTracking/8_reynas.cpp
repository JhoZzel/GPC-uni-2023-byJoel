#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};
int board[n][n]={};

bool validarReyna(int x, int y) {
    int ret = 1;
    for (int i=0; i<n; i++)
        if (board[i][y] || board[x][i]) return 0;
    
    for (int i=0; i<n; i++) {
        for (int jump = 0; jump < n; jump++) {
            int nx, ny;
            nx = x + jump*dx[i];
            ny = y + jump*dy[i];
            if (nx < 0 || ny < 0 || nx > n || ny > n) break;
            if (board[nx][ny]) return 0;
        }
    }
    return ret;
}

void back(int fila) {
    if (fila == n) {
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        cout << "------------------\n";
    } 
    for (int col = 0; col < n; col++) {
        if (validarReyna(fila,col)) {
            board[fila][col] = 1;
            back(fila+1);
            board[fila][col] = 0;
        }
    }
}

int main() {
    back(0);   
    return 0;
}