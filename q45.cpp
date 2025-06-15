#include <bits/stdc++.h>
using namespace std;

bool is_triangular(long long n) {
    if (n < 0) return false;
    long long x = (sqrt(8 * n + 1) - 1) / 2;
    return x * (x + 1) / 2 == n;
}

bool is_pentagonal(long long n) {
    if (n < 0) return false;
    long long x = (sqrt(24 * n + 1) + 1) / 6;
    return x * (3 * x - 1) / 2 == n;
}

void solve() {
    long long n = 144;
    while(true) {
        long long num = n*(2*n-1);
        if(is_triangular(num) && is_pentagonal(num)) {
            cout << num << endl;
            break;
        }
        n++;
    }
}

int main() {
    solve();

    return 0;
}