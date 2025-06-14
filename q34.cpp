#include <bits/stdc++.h>
using namespace std;

vector<int> factorials;

void compute_factorials() {
    int fact = 1;
    factorials.push_back(fact);
    for(int i = 1; i<10; i++){
        fact *= i;
        factorials.push_back(fact);
    }
}

int fact_sum(int x) {
    int ret = 0;
    while(x) {
        ret += factorials[x%10];
        x /= 10;
    }
    return ret;
}

void solve() {
    long long ans = 0;
    for(int i = 10; i<1000*1000; i++){
        if(fact_sum(i) == i) ans += i;
    }
    cout << ans << endl;
}

int main() {
    compute_factorials();
    solve();

    return 0;
}