#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1e6+1;

int main(){
    int n, arr[maxn], a[maxn]{}, ans[maxn];
    memset(ans, -1, sizeof(ans));

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        a[arr[i]]++;
        ans[arr[i]]=0;
    }

    for (int i=1; i+i<=1e6; i++) {
        if (a[i] != 0) {
            ans[i] += a[i] - 1;
            for (int j = i+i; j <= 1e6; j += i) {
                if (ans[j] != -1) ans[j] += a[i]; 
            }
        }
    }
    
    for (int i=0; i<n; i++) 
        cout << ans[arr[i]] << "\n";

    return 0;
}