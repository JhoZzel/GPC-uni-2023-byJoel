#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef deque<ll> dll;

void f(dll a, dll b, int n, int ans) {
    
    for (int i = 0; i < a.size(); i++) {
        
        if (a[i] > b[i]) {
            dll aux = a;
        }
    }
}

int main() {
    int n; 
    dll a,b;

    cin >> n;
    for (int i=0; i<n; i++) {
        ll x; cin >> x;
        a.push_back(x);
    }
    for (int i=0; i<n; i++) {
        ll x; cin >> x;
        b.push_back(x);
    }
    sort(all(a));
    sort(all(b));

    return 0;
}