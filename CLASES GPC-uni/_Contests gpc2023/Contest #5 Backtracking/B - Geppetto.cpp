#include <bits/stdc++.h>
using namespace std;

int ans = 1;
vector<pair<int,int>> p;

bool validar(vector<int> v, vector<bool> is_used, int x) {
    for (int i=0; i<p.size(); i++) {
        if (p[i].first == x && is_used[p[i].second]) return 0;
        if (p[i].second == x && is_used[p[i].first]) return 0;
    }
    return 1;
}

void back(vector<int> v, vector<bool> is_used, int n) {
    int aux = 0;
    if (v.size()!=0) aux = v.back();
    
    for (int i = aux + 1; i <= n; i++) {
        if (validar(v,is_used,i)) { // ¿se puede agregar el i?
            ans++;
            v.push_back(i);
            is_used[i] = 1;   
            back(v, is_used, n);
            is_used[i] = 0;   
            v.pop_back();
        }
    }
}

int main() {
    int n, m; cin >> n >> m;

    for (int i=0; i<m; i++) {
        int x,y; cin >> x >> y;
        p.push_back(make_pair(x,y));
    }

    back({}, vector<bool>(n + 1,0), n);

    cout << ans << "\n";
    return 0;
}