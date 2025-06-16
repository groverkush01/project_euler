#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000;
vector<bool> sieve(N + 1, true);
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
    if (n < 0 || n > N) return false;
    return sieve[n];
}

void solve() {
    for (int i = 1000; i < 3340; ++i) {
        if(i == 1487) continue;
        string s1 = to_string(i);
        string s2 = to_string(i + 3330);
        string s3 = to_string(i + 6660);
        if (is_prime(i) && is_prime(i+3330) && is_prime(i+6660)
            && is_permutation(s1.begin(), s1.end(), s2.begin(), s2.end())
            && is_permutation(s3.begin(), s3.end(), s2.begin(), s2.end()))
            cout << s1 + s2 + s3 << endl;
    }
}

int main() {
    create_sieve();
    solve();

    return 0;
}