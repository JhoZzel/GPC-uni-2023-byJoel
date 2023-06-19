#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a, ll b) {
    return (a+b)*(a*a + b*b);
}

int main() {
    ll N; cin >> N;
    ll i, j, x = 1e18, a_0 = (cbrt(N/4) - 1 < 0) ? 0 : cbrt(N/4) - 1;
    i = j = a_0;
    while(f(i,j)<N) {
        while(f(i,j)<N) 
            j++;
        x = min(x,f(i,j));

        j = a_0;
        i++;
    }
    
    cout << min(x,f(i,j)) << endl;    

    return 0;
}