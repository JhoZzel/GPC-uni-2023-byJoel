#include <bits/stdc++.h>

#define F first
#define S second
using namespace std;

typedef vector<string> vs;

void printFractal(vs a, int dim) {
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++)
            cout << a[i][j];
        cout << "\n";
    }
    cout << "-\n";
}

void f(int dim, int x, int y, vs & a) {
    if (dim == 1) a[x][y] = 'X';
    else {
        vector<pair<int,int>> D({{0,0},{-1,1},{1,1},{-1,-1},{1,-1}});
        int ndim = dim/3;
        for (int i=0; i<5; i++) f(ndim, x + D[i].F * ndim, y + D[i].S * ndim, a);
    }
}

int main() {
    int n; cin >> n;
    do {
        int dim = pow(3,n-1);
        vs a(dim, string(dim,' '));
        f(dim, dim/2, dim/2, a);
        printFractal(a, dim);
        cin >> n;
    } while(n != -1);
    
    return 0;
}