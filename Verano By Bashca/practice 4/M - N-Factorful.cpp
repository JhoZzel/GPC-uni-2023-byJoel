#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
using u32 = uint32_t;
using u64 = uint64_t;

const int maxn=1e6+1;

bool is_prime[maxn];
int primes[maxn/10];
int cnt=0;

void sieveEratosthenes() {
    int n=maxn-1;
    memset(is_prime, true, maxn);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            primes[cnt++]=i;
            if ((u64)i*i<=n) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }
}

u32 modPower(u32 x,u32 n, u32 mod) {
    u32 result=1;
    x %= mod;
    while(n>0) {
        if(n % 2 ==1)
            result= (u64)result * x % mod;
        x = (u64)x*x % mod;
        n = n/2;
    }
    return result;
}

bool isComposite(u32 n, u32 a, u32 d, int s) {
    u32 x = modPower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u64)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool millerRabin(u32 n) { // n<2^63-1 n:64bits LL
    if (n < 2)
        return false;

    int s = 0;
    u32 d = n - 1;
    while (d % 2 == 0) {
        d/=2;
        s++;
    }

    for (int a : {2, 3, 5, 7}) {
        if (n == a)
            return true;
        if (isComposite(n, a, d, s))
            return false;
    }
    return true;
}


int main(){
    int t; cin>>t;

    sieveEratosthenes();
    
    while(t--) {
        int a,b,n; cin>>a>>b>>n;
        int ans=0;
        for (int i=a; i<=b; i++) {
            int f = 0, num = i;
            for (int j=0; num!=1; j++) {
                if (f>n) break;
                
                if (millerRabin(num)) {
                    f++;
                    break;
                }
                
                if (num % primes[j] == 0) {
                    f++;
                    while(num % primes[j] == 0) {
                        num /= primes[j];
                    }
                }

            }

            if (f==n) ans++;
        
        }

        cout << ans << "\n";

    }

}