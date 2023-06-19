#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5;

void solve(string s,int r,int res[]) {
    int case = 0;
    string ans = "";
    int n = s.size();
    int iz = 0;
    int rr = (r==1) ? 2 : 1;

    if (res[0] != -1 && res[1] == -1) { // forma: x00000..
        c = 1;
        int i = 2;
        while(res[i] == -1 && i < n)
            i++;
        if (i == n) {
            cout << "-1\n";
            return;
        }
        else iz = i; // x000(iz)...u
    }
    else if (res[0] != -1 && res[1] !=1 && res[2] == -1) { // forma: xy0000...
        int i = 3;
        while(i < n && res[i] == -1)
            i++;
        if (i == n) {
            if (res[0] == 0) cout << res[0] << string(n-1,'0');
            else if (res[1] == 0) cout << res[1] << string(n-1,'0');
            else cout << "-1\n";
            return;
        }
        else iz = i; // xy000(iz)...u
    }
    
    if (r == 0) {
        cout << s << "\n";
        return;
    }
    else {
        if (c) {
            if (res[0] == r) ans = s.substr(iz,n);
            if (iz != n-1) {
                for (int i = iz; i < n; i++) {
                    if (res[i] == r) {
                        cout << s.substr(0,i) << s.substr(i+1,n);
                        return;
                    }
                }
            }

            if (res[0] == rr && iz != n-1) {
                for (int i = iz; i < n; i++) {
                    if (res[i] == rr){
                        ans = s.substr(iz,i-iz) + s.substr(i+1,n);
                    }
                }
            }
            int i_c = -1, i_d = -1;
            for (int i=iz; i<n; i++) {
                if (res[i] == rr) {
                    if (i_c == -1) i_c = i;
                    else if (i_d == -1) i_d = i;
                }
            }
            if (i_c != -1 && i_d !=-1) {
                ans = s.substr(0,iz);
                for (int i = iz; i<n; i++) {
                    if (i!=i_c && i!=i_d) {
                        ans += s[i];
                    }
                }
                cout << ans << "\n";
                return;
            }

            if (ans.size() != 0) cout << ans << "\n"; 
            else cout << "-1\n";
        }
        else {
            for (int i = 0; i < n; i++) {
                if (res[i] == r) {
                    cout << s.substr(0,i) << s.substr(i+1,n);
                    return;
                }
            }

            if (res[0] == rr && res[1] == rr) ans = s.substr(iz,n);
            
            int i_c = -1, i_d = -1;
            if (res[0] == rr) i_c = 0;
            else if (res[1] == rr) i_c = 1;

            for (int i=iz; i<n; i++) {
                if (res[i] == rr) {
                    if (i_c == -1) i_c = i;
                    else if (i_d == -1) i_d = i;
                }
            }

            if (i_c != -1 && i_d != -1) {
                ans = s.substr(0,iz);
                for (int i = iz; i<n; i++) {
                    if (i!=i_c && i!=i_d) {
                        ans += s[i];
                    }
                }
                cout << ans << "\n";
                return;
            }

            if (ans.size() != 0) cout << ans << "\n"; 
            else cout << "-1\n";
        }
    }
}

int main() {
    string s; cin >> s;
    int r = 0, res[maxn];
    for (int i=0; i < s.size(); i++) {
        if (s[i] == '0') res[i] = -1;
        else {
            res[i] = (s[i] - '0') % 3;
            r = (r + res[i]) % 3;
        }
    }
    
    solve(s,r,res);

    return 0;
}