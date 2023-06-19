#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3;

void solve() {
    int a[maxn], n, sum=0; 
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    int k = 2;
    while(k < n) {
        cout << "k: " << k << endl;
        for (int i = 0; i < n - k + 1; i++) {
            bool f = 0;
            cout << a[i] << " ";
            for (int j = i + 1; j < n; j++) {
                cout << a[j] << " ";
                if (a[j-1] > a[j]) f = 1;
                if (j - i == k - 1) {
                    if (f) {
                        cout << "NO";
                        sum += k-1;
                        cout << "(sum:" << sum << ")\t";
                    }
                    else cout << "YES\t";
                    break;
                }
            }
        }
        cout << endl;
        k++;
    }
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}