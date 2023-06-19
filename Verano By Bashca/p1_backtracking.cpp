#include <bits/stdc++.h>
using namespace std;


int f(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return f(n-1) + f(n-2);
}

int main() {

    int n;
    while (cin>>n) {
        auto start = clock();
        cout << f(n) << endl;
        auto en = clock();
        cout << 1.d * (en - start) / CLOCKS_PER_SEC << '\n';
    }
    return 0;
}