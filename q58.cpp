#include <bits/stdc++.h>
using namespace std;

unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long result = 0;
    a %= mod;
    while (b) {
        if (b & 1) result = (result + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}

unsigned long long binpower(unsigned long long base, unsigned long long e, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        e >>= 1;
    }
    return result;
}

bool check_composite(unsigned long long n, unsigned long long a, unsigned long long d, int s) {
    unsigned long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = mulmod(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
};


bool MillerRabin(unsigned long long n) {
    if (n < 2)
        return false;

    int r = 0;
    unsigned long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

void solve(){
	long long sz = 1;
	long long incr = sz-1;
	long long num = 1;
	long long primes = 0;
	while(primes == 0 || ((primes*100)/(2*sz - 1)) >= 10) {
		sz += 2;
		incr = sz - 1;
		if(MillerRabin(sz*sz - 1*incr)) primes++;
		if(MillerRabin(sz*sz - 2*incr)) primes++;
		if(MillerRabin(sz*sz - 3*incr)) primes++;
	}
	cout << sz << endl;
}

int main(){
	solve();
	return 0;
}