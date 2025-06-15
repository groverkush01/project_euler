#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long largest_pandigital_prime(int n) {
    string num = "";
    for(int i = n; i >= 1; --i) {
        num += to_string(i);
    }
    long long max_prime = 0;
    do {
        long long num_value = stoll(num);
        if (is_prime(num_value)) {
            max_prime = max(max_prime, num_value);
        }
    } while (prev_permutation(num.begin(), num.end()));
    
    return max_prime;
}

void solve() {
    long long ans = largest_pandigital_prime(4);
    ans = max(ans, largest_pandigital_prime(7));
    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}