#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 9;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << "(" << i << ","<< j << ")  "; 
        }
        cout << endl;
    }
    cout << "\n\n";
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int r = i/3*3;
            int c = j/3*3;
            cout << "(" << r << ","<< c << ")  "; 
        }
        cout << endl;
    }

    return 0;
}