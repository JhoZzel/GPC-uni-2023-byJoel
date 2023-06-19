#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

const int n = 9;

vvi sudoku(n, vi(n,0));
vvi solution;

void printSudoku(vvi v) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) cout << "- ";
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool validar(int num, int r, int c) {
    for (int i=0; i<n; i++) {
        if (sudoku[r][i] == num) return 0;
        if (sudoku[i][c] == num) return 0;
    }

    int iq = r / 3 * 3;
    int jq = c / 3 * 3;
    
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[iq + i][jq + j] == num) 
                return 0;
        }
    }

    return 1;
}
int bt(int r, int c) { // k columna
    cout << "r:" << r << "\tc:" << c << endl;
    printSudoku(sudoku);
    if (r == n) {
        solution = sudoku;
        return 1;
    }

    int sa = 0;

    int nc = (c == n - 1) ? 0 : c + 1;
    int nr = (c == n - 1) ? r + 1 : r;

    if (sudoku[r][c] != 0) {
        int value = sudoku[r][c];
        sudoku[r][c] = 0;
        if (validar(value,r,c)) {
            sudoku[r][c] = value;
            return bt(nr,nc);
        }
        sudoku[r][c] = value;
        return 0;        
    }
    

    for (int num = 1; num <= n; num++) {
        cout << "\t" << num << endl;
        if (validar(num, r, c)) {
            sudoku[r][c] = num;
            sa += bt(nr,nc);
            sudoku[r][c] = 0;
        }
    }
    
    return sa;
}

int main() {
    int x, k = 0;
    while(cin >> x) {
        sudoku[k / n][k % n] = x;
        k++;

        if (k == n * n) {
            int ans = bt(0,0);
            
            if (ans == 0) cout << "Find another job\n\n";
            else if (ans > 1) cout << "Non-unique\n\n";
            else printSudoku(solution);

            k = 0;
        }
    }
    
    return 0;
}