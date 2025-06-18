#include <bits/stdc++.h>
using namespace std;

long long nCr(long long n, long long r) {
    if(r == 0) return 1;
    if(r == 1) return n;
    return (n*nCr(n-1, r-1))/r;
}

void solve(int n) {
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int j = 0;
        while(j<=i && nCr(i, j) <= 1000000) {
            j++;
        }
        int st = j;
        int end = i - j;
        if(st <= end) ans += end - st + 1;
    }
    cout << ans << endl;
}

int main() {
    solve(100);

    return 0;
}