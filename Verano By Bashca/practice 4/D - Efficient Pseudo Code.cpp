#include <iostream>
using namespace std;
using u32 = uint32_t;
using u64 = uint64_t;

const u32 MOD = 1000000007;

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

u32 modInverse(u32 x, u32 mod) {
    return modPower(x, mod-2, mod);
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


bool millerRabin(u32 n) { 
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
    int t, step=1; 
    
    cin>>t;
    
    while(t--){
        int k;
        u32 n,m,sum=1;
        cin>>n>>m;
        
        k=0;
        if (n%2==0) {
            while (n%2==0) {
                k++;
                n/=2;
            }
            sum = (u64)sum * (modPower(2, k*m+1, MOD) - 1) % MOD;
            k=0;
        }
            
        for (int i=3; !millerRabin(n); i+=2) {
            if (millerRabin(i) && n%i==0) {
                while (n%i==0) {
                    k++;
                    n/=i;
                }
                sum = (u64)sum * (modPower(i, k*m+1, MOD) - 1) * modInverse(i-1,MOD) % MOD;
                if (n==1) break;
                k=0;
            }
        }

        if (n!=1) sum = (u64)sum * (modPower(n, m+1, MOD) - 1) * modInverse(n-1,MOD) % MOD;
        
        cout << "Case " << step << ": " << sum << "\n";
        step++;
    }
    return 0;
}