#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;

bool solve(int n, int two, int & mov) {
    if (two >= n) return 1;

    bool p[maxn] = {};
    int lim2 = (int) (log(n)/log(2)) + 1;
    
    while(lim2!=0) {
        cout << "lim2:" << lim2 << "\n";
        int x = pow(2,lim2);            
        for (int i = 1; x <= n; x *= ++i) {
            
            if (!p[x]) {
                cout << "\t" << x << "\n";
                two += lim2;
                mov ++;
                p[x] = 1;
                if (two >= n) return 1;                
            }
        }
        lim2--;
    }
    return 0;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, two = 0, mov = 0;

        cin >> n;

        for (int i=0; i<n; i++) {
            int x; cin >> x;
            while(x % 2 == 0) {
                x /= 2; 
                two ++;
            }
        }

        if (solve(n,two,mov)) cout << mov << "\n";
        else cout << "-1\n";
    }
    

    
    return 0;
}