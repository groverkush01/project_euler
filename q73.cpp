#include <bits/stdc++.h>
using namespace std;

void solve(int lim) {
    int count = 0;
    for (int d = 2; d <= lim; ++d) {
        int n_min = d / 3 + 1;
        int n_max = (d - 1) / 2;
        for (int n = n_min; n <= n_max; ++n) {
            if (__gcd(n, d) == 1) {
                ++count;
            }
        }
    }
    cout << count << endl;
}

int main() {
    solve(12000);
    return 0;
}