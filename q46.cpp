#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2*1000*1000;
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
    if (n < 0) return false;
    if (n > N) {
        cerr << "Error: n is too large for the sieve." << endl;
        return false;
    }
    return sieve[n];
}

bool check_goldbach(int n) {
    for (int i = 1; i * i < n; ++i) {
        int square = i * i;
        if (square >= n) break;
        if (is_prime(n - 2*square)) return true;
    }
    return false;
}

void solve() {
    for(int i = 9; ; i+=2){
        if(is_prime(i)) continue;
        if(!check_goldbach(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    create_sieve();
    solve();

    return 0;
}