#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2*1000*1000;
vector<bool> sieve(N + 1, true);
vector<int> primes;
vector<long long> prefix_prime;
void create_sieve() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }
}

bool is_prime(int n) {
    if (n < 0) return false;
    return sieve[n];
}

void fill_primes() {
    prefix_prime.push_back(0);
    for (int i = 2; i <= N; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            if (prefix_prime.empty()) {
                prefix_prime.push_back(i);
            } else {
                prefix_prime.push_back(prefix_prime.back() + i);
            }
        }
    }
}

void solve(int n) {
    int ans = 0;
    int len = 0;
    for (int i = 0; i < prefix_prime.size(); i++) {
        for (int j = i + 1; j < prefix_prime.size(); j++) {
            if(prefix_prime[j] - prefix_prime[i] >= n) {
                break;
            }
            if (is_prime(prefix_prime[j] - prefix_prime[i]) && (j - i + 1) > len) {
                len = j - i + 1;
                ans = prefix_prime[j] - prefix_prime[i];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    create_sieve();
    fill_primes();
    solve(100);
    solve(1000);
    solve(1000*1000);

    return 0;
}