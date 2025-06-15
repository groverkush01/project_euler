#include <bits/stdc++.h>
using namespace std;

int digit(int n) {
    int digs = 9;
    int cnt = 1;
    while (n > digs*cnt) {
        n -= digs*cnt;
        digs *= 10;
        cnt++;
    }
    if(n == 0) return 9;
    else {
        int numbers_to_skip = (n-1)/cnt;
        int number = pow(10, cnt - 1) + numbers_to_skip;
        int digit_index = n % cnt;
        if (digit_index == 0) {
            return number % 10;
        } else {
            string s = to_string(number);
            return s[digit_index - 1] - '0';
        }
    }
}

void solve(vector<int> nums) {
    long long ans = 1;
    for (auto x : nums) {
        ans *= digit(x);
    }
    cout << ans << endl;
}

int main() {
    solve({1, 10, 100, 1000, 10000, 100000, 1000000});

    return 0;
}