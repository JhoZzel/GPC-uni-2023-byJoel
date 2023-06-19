#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1e3+1;

bool is_prime[maxn];

void findPrimes() {
    int n=1e3;
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main(){
    int t; cin>>t;
    
    findPrimes();

    while(t--) {
        int n; cin>>n;

        for (int i=1; i<=n; i+=2) {
            if (is_prime[i]) 
                cout << i << "\n";
        }
        cout << "\n";
        
    }
    return 0;
}