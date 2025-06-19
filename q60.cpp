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

bool check_composite(unsigned long long n, unsigned long long a, unsigned long long d, unsigned long long s) {
    unsigned long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (unsigned long long r = 1; r < s; r++) {
        x = mulmod(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
};


bool is_prime(unsigned long long n) {
    if (n < 2)
        return false;

    unsigned long long r = 0;
    unsigned long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (unsigned long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int count_digits(long long num) {
    int count = 0;
    
    if (num < 0){
        num *= -1;
    }
    
    while (num != 0) {
        num /= 10;
        count++;
    }
    
    return count;
}



long long check_pairs(long long a, long long b, long long c, long long d, long long e) {
    long long arr[5];
    long long num1, num2;
    
    long long length = 5;
    if (e == -1) length = 4;
    if (d == -1) length = 3;
    if (c == -1) length = 2;
    if (b == -1) length = 1;
    if (a == -1) length = 0;
    
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;
    
    for (long long i = 0; i < length; i++) {
        for (long long j = i + 1; j < length; j++) {
            num1 = (arr[i] * binpower(10, count_digits(arr[j]), 1LL<<63)) + arr[j];
            num2 = (arr[j] * binpower(10, count_digits(arr[i]), 1LL<<63)) + arr[i];
            if (!is_prime(num1) || !is_prime(num2)) {
                return 0;
            }
        }
    }
    
    return 1;
}

void solve() {
	vector<long long> primes;
	for(int i = 1; i<=10000; i++){
		if(is_prime(i)) primes.push_back(i);
	}
	for (int i = 0; i<primes.size(); i++) {
		long long a = primes[i];
        for (int j = i + 1; j < primes.size(); j++) {
			long long b = primes[j];
			if (!check_pairs(a, b, -1, -1, -1)) {
				continue;
            }
            for (int k = j + 1; k < primes.size(); k++) {
				long long c = primes[k];
                if (!check_pairs(a, b, c, -1, -1)) {
					continue;
                }
                for (int l = k + 1; l < primes.size(); l++) {
					long long d = primes[l];
                    if (!check_pairs(a, b, c, d, -1)) {
						continue;
                    }
                    for (int m = l + 1; m < primes.size(); m++) {
						long long e = primes[m];
                        if (!check_pairs(a, b, c, d, e)) {
                            continue;
                        }
						cout << a + b + c + d + e << endl;
						return;
                    }
                }
            }
        }
    }
}

int main(){
	solve();

	return 0;
}