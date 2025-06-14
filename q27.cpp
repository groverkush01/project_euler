#include <bits/stdc++.h>
using namespace std;

const int N = 2*1000*1000;
vector<bool> sieve(N+1, true);

void create_sieve(){
    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i<=sqrt(N); i++){
        if(sieve[i]){
            for(long long j = i*1LL*i; j <= N; j+=i) sieve[j] = false;
        }
    }
}

bool is_prime(int x) {
    if(x < 0) return false;
    return sieve[x];
}

int cnt_n(int a, int b) {
    int n = 0;
    while(is_prime(n*n + a*n + b)){
        n++;
    }
    return n;
}

void solve(int n, int m) {
    int ans = 0;
    int mx = 0;
    for(int a = -n; a <= n; a++){
        for(int b = -m; b <= m; b++){
            int curr = cnt_n(a, b);
            if(curr > mx) {
                mx = curr;
                ans = a*b;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    create_sieve();
    solve(1, 41);
    solve(1000, 1000);

    return 0;
}