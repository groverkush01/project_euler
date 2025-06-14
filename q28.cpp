#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    long long sum = 1;
    for(int i = 3; i<=n; i+=2){
        sum += (4*i*i - 6*(i-1));
    }
    cout << sum << endl;
}

int main() {
    solve(5);
    solve(1001);

    return 0;
}