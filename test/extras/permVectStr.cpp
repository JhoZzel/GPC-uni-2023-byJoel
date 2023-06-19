#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> qLetr(vector<string> s, string ss) {
    s.erase(remove(s.begin(), s.end(), ss) , s.end());
    return s;
}

void f(vector<string> s, string crr, int n) {
    if (n==0) cout << crr << "\n";
    else {
        for (int i=0; i<n; i++) {
            f(qLetr(s, s[i]), crr+s[i], n-1);
        }
    }
}

int main() {
    vector<string> ss ({"a", "b","c","d"});
    f(ss,"", ss.size());
    return 0;
}