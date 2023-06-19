#include <iostream>
using namespace std;
using u32 = uint32_t;
using u64 = uint64_t;

const int maxn = INT_MAX;

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
    bool first;
    int n;
    while(cin>>n){
        if (n==0) break;
        
        first=1;
        cout << n << " = " ;        
        
        if (n<0) {
            cout << "-1 x ";
            n = -1*n;
        }
            

        if (millerRabin(n)) cout << n << "\n";
        else {
            for (int i=2; n!=1; i++) {
                while(n % i == 0) {
                    if (first) cout << i;
                    else cout << " x " << i;
                    n /= i;
                    first=0;
                }

                if (millerRabin(n)) {
                    cout << " x " << n;
                    break;
                }; 
            
            }
            cout << "\n";
        }
    }
}