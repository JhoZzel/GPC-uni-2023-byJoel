#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> qq;
vi v;
int n, m, q, ans = 0;


void bt() {
    int aux = 1;
    
    if (v.size()!=0) aux = v.back();
    
    if (v.size() == n) {
        int sum = 0;
        for (int i=0; i<q; i++) {
            vi x = qq[i];
            if (v[x[1]-1]- v[x[0]-1] == x[2]) sum += x[3];
        }
        ans = max(ans,sum);
        return;
    }

    for (int i = aux; i <= m; i++) {
        v.push_back(i);
        bt();
        v.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;
    
    for (int i=0; i<q; i++) {
        vi x(4);
        for (int i=0; i<4; i++) cin >> x[i];
        qq.push_back(x);
    }

    bt();

    cout << ans << "\n";

    return 0;
}