#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "x00000abcdedfgas";
    int n = s.size();
    int i = 9;
    int iz = 6;
    string ans = s.substr(iz,i-iz) + " " + s.substr(i+1,n);

    cout << ans << "\nl";
    return 0;
}