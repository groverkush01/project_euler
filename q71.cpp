#include <bits/stdc++.h>
using namespace std;

vector<long long> extended_gcd(long long a, long long b) {
    if (b == 0) return {a, 1, 0};
    vector<long long> v = extended_gcd(b, a % b);
	long long g = v[0], x1 = v[1], y1 = v[2];
    return {g, y1, x1 - (a / b) * y1};
}

long long modInverse(long long a, long long m) {
    vector<long long> egcd = extended_gcd(a, m);
	long long g = egcd[0], x = egcd[1], y = egcd[2];
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Given reduced a/b and bound k, returns immediate left neighbor p/q in F_k.
// (p,q) are returned via pair; numerator is first.
void solve(long long a, long long b, long long k) {
    // r is inverse of a mod b (1 <= r <= b-1 typically)
    long long r = modInverse(a, b);

    // largest q <= k with q ≡ r (mod b): q = b*floor((k - r)/b) + r
    long long q = b * ((k - r) / b) + r;

    // p = (a*q - 1)/b  (guaranteed integer)
    long long p = (a * q - 1) / b;

    cout << p << endl;
}

int main() {
    solve(3, 7, 1000000);
    return 0;
}
