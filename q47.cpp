#include <bits/stdc++.h>
using namespace std;

int cnt_prime(int n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        count++;
    }
    return count;
}

void solve(int n) {
    for(int i = 1; ; i++){
        bool found = true;
        for(int j = 0; j<n; j++){
            if(cnt_prime(i + j) != n) {
                found = false;
                break;
            }
        }
        if(found) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    solve(2);
    solve(3);
    solve(4);

    return 0;
}