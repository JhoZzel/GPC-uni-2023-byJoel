#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

typedef long long ll;
typedef pair<ll,ll> pll;

const u32 MOD = 1000000007;
const ll maxn=1e9;
const int maxN=1e5;

bool is_prime[maxn];

bool isPrime(int n);
bool isComposite(u64 n, u64 a, u64 d, int s);
bool millerRabin(u64 n);
u64 power(ll x,int n);
u64 modPower(u64 x,u64 n, u64 mod);
u64 binpower(u64 base, u64 e, u64 mod);
u64 modInverse(u64 x, u64 mod);
void sieveEratosthenes();


string qLetr(string s, char c) {
    int k, n = s.length();
    for (int i=0; i<n; i++) {
        if (s[i]==c) {
            k=i;
            break;
        } 
    }
    return s.substr(0,k) + s.substr(k+1, n-k-1);
}

int main(){ 
    // lol
    
    return 0;
}






void sieveEratosthenes() {
    memset(is_prime, 1, maxn);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= maxn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = 0;
        }
    }
}

bool isComposite(u64 n, u64 a, u64 d, int s) {
    u64 x = modPower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool millerRabin(u64 n) { // n<2^63-1 n:64bits LL
    if (n < 2)
        return false;

    int s = 0;
    u64 d = n - 1;
    while (d % 2 == 0) {
        d/=2;
        s++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (isComposite(n, a, d, s))
            return false;
    }
    return true;
}

/*
bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    // n-1 = 2^s.d
    int s = 0;
    u64 d = n - 1;
    while (d % 2 == 0) {
        d/=2;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3); // [0,n-2]
        if (isComposite(n, a, d, s))
            return false;
    }
    return true;
}*/


bool isPrime(int n){
    if (n==2) return 1;
    if (n%2==0 || n==1) return 0;
    for (int i=3; i*i<=n; i+=2) 
        if (n%i==0) return 0;
    return 1;
}

u64 power(u64 x,int n) {
    u64 result=1;
    while(n>0) {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}

u64 modPower(u64 x,u64 n, u64 mod) {
    u64 result=1;
    x %= mod;
    while(n>0) {
        if(n % 2 ==1)
            result= (u128)result * x % mod;
        x = (u128)x*x % mod;
        n = n/2;
    }
    return result;
}

u64 modInverse(u64 x, u64 mod) {
    return modPower(x, mod-2, mod);
}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}