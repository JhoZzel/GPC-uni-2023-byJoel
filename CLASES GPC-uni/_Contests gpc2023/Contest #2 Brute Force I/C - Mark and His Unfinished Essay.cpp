#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    int n,c,q; 
    cin >> n >> c >> q >> s;

    vector<pair<ll,ll>> p(40);
    vector<ll> tam(41);
    
    tam[0] = s.size();
    for (int i = 0; i < c; i++) {
        ll l,r; cin >> l >> r;
        tam[i+1] = tam[i] + r - l + 1;
        p[i] = {l-1,r-1};
    }
    
    while(q--) {
        ll k; cin >> k;
        k--;
        int pos;
        for (int i=0; i<=c; i++) {
            if (k < tam[i]) {
                pos = i;
                break;
            }
        }
        if (pos == 0) cout << s[k] << "\n";
        else {
	        for (int i = pos - 1; i>=0; i--) {
	            if (k < tam[0]) {
	                cout << s[k] << "\n"; 
	                break;
	            }
	            k = p[i].first + k - tam[i];
	        }
            if (k < tam[0]) cout << s[k] << "\n"; 
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}