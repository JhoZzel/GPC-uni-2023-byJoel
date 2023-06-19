#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    int ans;
    if (n%2 && k == (n+1)/2) ans = 1 + 2 * ((n+1)/2 - 1 + k - 1) / k;
    else ans = 2 * ((n+1)/2 + k -1 / k);   
    cout << ans << "\n";
    return 0;
}