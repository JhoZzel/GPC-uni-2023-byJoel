#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;


void solve(int a[], int n) {  
    int i_min = 0, i_max = 1;
    if (a[0] > a[1]) {
        i_max = 0;
        i_min = 1;
    }
    
    if (a[i_max] - a[i_min] >=2 ) {
        cout << "YES\n1 2\n";
        return ;
    }
    
    for (int i = 2; i < n; i++) {
        if (a[i] >= a[i_max]) {
            i_max = i;
        }
        else if (a[i] <= a[i_min]) {
            i_min = i;
        }
        if (a[i_max] - a[i_min] > abs(i_max - i_min)) {
            cout << "YES\n";
            cout << min(i_min,i_max) + 1 << " " << max(i_min,i_max) + 1;
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        int n, a[maxn]; 
        
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        solve(a,n);
    }

    return 0;
}