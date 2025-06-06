#include <bits/stdc++.h>
using namespace std;

const int N = 2*1000*1000;
vector<bool> sieve(N+1, true);

void create_sieve(){
    sieve[0] =false;
    sieve[1] =false;

    for(int i = 2; i<=sqrt(N); i++){
        if(sieve[i]){
            for(long long j = i*1LL*i; j <= N; j+=i) sieve[j] = false;
        }
    }
}

void solve(int n){
    long long ans = 0;
    for(int i =0; i<=n; i++){
        if(sieve[i]) ans += i;
    }
    cout << ans << endl;
}

int main(){
    create_sieve();
    solve(10);
    solve(2*1000*1000);

    return 0;
}