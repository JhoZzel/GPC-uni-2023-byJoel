#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 1;

int main() {
    srand(time(nullptr));

    ifstream fin("test_input.txt");
    ofstream fout("out.txt");

    int n = 100;
    fout << n << "\n";
    for (int i=0; i<n; i++) {
        int x,y,z;
        x = rand()%100;
        y = rand()%100;
        z = rand()%100;
        int a,b,c;
        a = x+y+z;
        
    }
    


    cout << "FINISH\n";

    return 0;
}