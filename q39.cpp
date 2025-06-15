#include <bits/stdc++.h>
using namespace std;

int pythagorean_solutions(int peri) {
    int count = 0;
    for (int a = 1; a < peri / 2; a++) {
        for (int b = a; b < peri / 2; b++) {
            int c = peri - a - b;
            if (c <= 0) break;
            if (a * a + b * b == c * c) {
                count++;
            }
        }
    }
    return count;
}

void solve(int n) {
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int curr = pythagorean_solutions(i);
        if (curr > mx) {
            mx = curr;
            ans = i;
        }
    }
    cout << ans << endl;
}

int main() {
    solve(1000);

    return 0;
}