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
	long double conv = 1;
	long double max_n_by_phi = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		long double n_by_phi = ((i*conv)/phi[i]);
		if(n_by_phi > max_n_by_phi) {
			max_n_by_phi = n_by_phi;
			ans = i;
		}
	}
	cout << ans << endl;
}

int main(){
	solve(10);
	solve(1000000);
	return 0;
}