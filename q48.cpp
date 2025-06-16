#include <bits/stdc++.h>
using namespace std;

// long long is causing overflow when products are large
// Use a larger type to avoid overflow issues

unsigned long long mod = 1'000'000'000'0;

unsigned long long calc_pow(unsigned long long base, unsigned long long exp) {
    unsigned long long result = 1;
    while (exp > 0) {
        result *= base;
        result %= mod;
        exp--;
    }
    return result;
}

void solve(int n) {
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += calc_pow(i, i);
        sum %= mod;
    }
    cout << sum << endl;
}

int main() {
    solve(10);
    solve(1000);

    return 0;
}