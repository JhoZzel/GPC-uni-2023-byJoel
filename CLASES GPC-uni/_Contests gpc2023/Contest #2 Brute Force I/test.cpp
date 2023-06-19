#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd;

const int maxn = 1e5;

double f(pdd v[], int n, double x) {
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += v[i].second + fabs(x-v[i].first);
    }
    return sum;
}

int main(){
    int t; cin >> t;
    while(t--) {
        int n;
        pdd a[maxn];
        
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i].first;
        for (int i=0; i<n; i++) cin >> a[i].second;

        sort(a,a+n);
        
        double lo = a[0].first, hi = a[n-1].first;
        
        for (int i=0; i<10; i++) {
            cout << lo << "\t" << hi << endl;
            cout << f(a,n,lo) << "\t" << f(a,n,hi) << endl;
            if (f(a,n,lo) < f(a,n,hi)) {
                hi = (lo + hi) / 2;
            }
            else {
                lo = (lo + hi) / 2;
            }            
        }

        cout << fixed << setprecision(8) << "\n";
    }
    

    return 0;
}