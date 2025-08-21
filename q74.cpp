#include <bits/stdc++.h>
using namespace std;

long long fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
vector<int> distances;

long long next(long long n) {
    long long ret = 0;
    while (n)
    {
        ret += fact[n % 10];
        n /= 10;
    }
    return ret;
}

int distance(long long n) {
    if (distances[n] != -1)
        return distances[n];
    distances[n] = 1 + distance(next(n));
    return distances[n];
}

void solve() {
    distances.resize(3000000, -1);
    distances[0] = distances[1] = distances[2] = distances[145] = distances[40585] = 1;
    distances[871] = distances[872] = distances[45361] = distances[45362] = 2;
    distances[169] = distances[363601] = distances[1454] = 3;
    long long counter = 0;
    for (int i = 0; i <= 1000000; i++) {
        if (distance(i) == 60) counter++;
	}
    cout << counter << endl;
}

int main() {
    solve();
    return 0;
}