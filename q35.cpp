#include <bits/stdc++.h>
using namespace std;

const int N = 1*1000*1000;
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

string shift(string s){
    string ret = s;
    for(int i = 0; i<s.size(); i++){
        ret[i] = s[((i+1)%s.size())];
    }
    return ret;
}

bool check(int i) {
    string s = to_string(i);
    string x = shift(s);
    while(x != s){
        if(!is_prime(stoi(x))) return false;
        x = shift(x);
    }
    return true;
}

void solve(int n) {
    int cnt = 0;
    for(int i = 2; i<n; i++){
        if(is_prime(i) && check(i)) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    create_sieve();
    solve(100);
    solve(1000*1000);

    return 0;
}