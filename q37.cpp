#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2*1000*1000;
vector<bool> sieve(MAXN+1, true);
void create_sieve() {
    sieve[0] = sieve[1] = false;
    for(int i = 2; i * i <= MAXN; ++i) {
        if(sieve[i]) {
            for(int j = i * i; j <= MAXN; j += i) {
                sieve[j] = false;
            }
        }
    }
}

bool is_truncable_left(int n) {
    string s = to_string(n);
    for(int i = 0; i < s.size(); ++i) {
        if(!sieve[stoi(s.substr(i))]) return false;
    }
    return true;
}

bool is_truncable_right(int n) {
    string s = to_string(n);
    for(int i = s.size() - 1; i >= 0; --i) {
        if(!sieve[stoi(s.substr(0, i + 1))]) return false;
    }
    return true;
}

void solve(int n) {
    int num = 10;
    long long ans = 0;
    while(n && num <= MAXN) {
        if(sieve[num] && is_truncable_left(num) && is_truncable_right(num)) {
            ans += num;
            --n;
        }
        ++num;
    }
    cout << ans << endl;
}

int main() {
    create_sieve();
    solve(11);

    return 0;
}