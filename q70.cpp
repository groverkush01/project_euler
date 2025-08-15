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

bool is_perm(long long a, long long b) {
	string s1 = to_string(a);
	string s2 = to_string(b);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}

void solve(int n){
	vector<long long> phi = phi_1_to_n(n);
	long double conv = 1;
	long double min_n_by_phi = INT_MAX;
	long long ans = 0;
	for(int i = 2; i<=n; i++) {
		if(is_perm(i, phi[i])) {
			long double n_by_phi = ((i*conv)/phi[i]);
			if(n_by_phi < min_n_by_phi) {
				min_n_by_phi = n_by_phi;
				ans = i;
			}
		}
	}
	cout << ans << endl;
}

int main(){
	solve(10000000);
	return 0;
}