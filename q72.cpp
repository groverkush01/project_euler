#include <bits/stdc++.h>
using namespace std;

vector<long long> phi_1_to_n(int n) {
    vector<long long> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }

	return phi;
}

void solve(int n){
	vector<long long> phi = phi_1_to_n(n);
	long long ans = 0;
	for(int i = 2; i<=n; i++) ans += phi[i];
	cout << ans << endl;
}

int main(){
	solve(8);
	solve(1000000);
	return 0;
}