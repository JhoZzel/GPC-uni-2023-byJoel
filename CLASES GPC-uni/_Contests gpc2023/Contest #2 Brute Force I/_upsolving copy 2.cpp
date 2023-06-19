#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5;

void solve(string s,int r,int res[]) {
    int n = s.size();
    int iz = -1;

    if (res[0] != -1 && res[1] == -1) { // forma: x00000..
        int i = 2;
        while(res[i] == -1 && i < n)
            i++;
        if (i == n) {
            cout << "-1\n";
            return;
        }
        else iz = i; // x000(iz)...
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
        else iz = i; // xy000(iz)...
    }
    else { // forma: xyz00000...
        if (r == 0) {
            cout << s << "\n";
            return;
        }
        else if (r == 1) {
            string ans = "";
            cnt = 0;
            for (int i=0; i<n; i++) {
                if (cnt == 1) ans += s[i];
                else if ((s[i] - '0') % 3 == 1) {
                    
                    cnt ++;
                }
                else ans += s[i];
            }
            
            if (ans.size() == 0) cout << "-1\n";
            else if (cnt == 1) cout << ans << "\n";
            else {
                ans = "";
                cnt = 0;
                for (int i=0; i<n; i++) {
                    if (cnt == 2) ans += s[i];
                    else if ((s[i] - '0') % 3 == 2) {
                        cnt ++;
                    }
                    else ans += s[i];
                }
                if (ans.size()==0) cout << "-1\n";
                else if (cnt == 2) cout << ans << "\n";
                else cout << "-1\n";
            }
        }
        else { // r = 2
            string ans = "";
            cnt = 0;
            for (int i=0; i<n; i++) {
                if (cnt == 1) ans += s[i];
                else if ((s[i] - '0') % 3 == 2) {
                    cnt ++;
                }
                else ans += s[i];
            }
            if (ans.size() == 0) cout << "-1\n";
            else if (cnt == 1) cout << ans << "\n";
            else {
                ans = "";
                cnt = 0;
                for (int i=0; i<n; i++) {
                    if (cnt == 2) ans += s[i];
                    else if ((s[i] - '0') % 3 == 1) {
                        cnt ++;
                    }
                    else ans += s[i];
                }
                if (ans.size()==0) cout << "-1\n";
                else if (cnt == 2) cout << ans << "\n";
                else cout << "-1\n";
            }
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