#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17};

bool check_property(string s) {
    for (int i = 1; i <= 7; ++i) {
        int num = stoi(s.substr(i, 3));
        if (num % primes[i - 1] != 0) return false;
    }
    return true;
}

void solve(int n) {
    string s = "";
    for (int i = 0; i <= n; ++i) {
        s += to_string(i);
    }
    long long sum = 0;
    while(next_permutation(s.begin(), s.end())) {
        if(check_property(s)) sum += stoll(s);
    }

    cout << sum << endl;
}

int main() {
    solve(9);

    return 0;
}