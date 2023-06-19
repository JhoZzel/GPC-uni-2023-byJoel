#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5;

int main() {
    int cnt, mov;
    string s, s_pos; cin >> s;
    int n = s.size(), r = 0, res[maxn];
    for (int i=0; i < n; i++) {
        if (s[i] == '0') res[i] = -1;
        else {
            res[i] = (s[i] - '0') % 3;
            r = (r + res[i]) % 3;
        }
    }

    if (r == 0) s;
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

    return 0;
}