#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using u64 = uint64_t;

const int maxn=1e9+1;

bool is_prime[maxn];
int primes[maxn/10];
int cnt=0;

void findPrimes() {
    int n=1e9;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;

    for (int i=2; i<=n; i++) {
        if (is_prime[i]) {
            primes[cnt++]=i;

            if ((u64)i*i<=n) {
                for (int j=i*i; j<=n; j += i)
                    is_prime[j] = false;
            }
        }
    }
}

int main() {
    int t; cin>>t;

    findPrimes();

    while(t--) {
        int m,n; cin>>m>>n;

        while(!is_prime[m]) m++;
        cout << cnt;
        for (auto it=find(primes,primes+cnt,m); *it<=n; it++) {
            cout << *it << "\n";
        }
        
        cout << "\n";
    }

    return 0;
}