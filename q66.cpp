#include <bits/stdc++.h>
using namespace std;

string string_add(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long n = a.size();
    long long m = b.size();
    for(int i = n; i<max(n, m); i++){
        a.push_back('0');
    }
    for(int i = m; i<max(n, m); i++){
        b.push_back('0');
    }
    string res = "";
    bool carry = false;
    for(int i=0; i<max(m, n); i++){
        int sum = ((a[i] - '0') + (b[i] - '0'));
        if(carry) {sum++; carry = false;}
        if(sum > 9){
            carry = true;
            sum -= 10;
        }
        res.push_back(sum+'0');
    }
    if(carry) res.push_back('1');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(res.begin(), res.end());
    return res;
}

string string_multiply(string a, string b){
    if(b.size() == 1){
        long long x = stoll(b);
        string res = "0";
        while(x--){
            res = string_add(res, a);
        }
        return res;
    }
    reverse(b.begin(), b.end());
    string res = "0";
    for (char d: b) {
        string xm = string_multiply(a, to_string(d-'0'));
        res = string_add(res, xm);
        a.push_back('0');
    }
    return res;
}

vector<long long> find_continued_fraction(long long D) {
	if(((long long)sqrt(D))*((long long)sqrt(D)) == D) return {};
	vector<long long> num = {D, -((long long)sqrt(D)), 1, 1};
	map<vector<long long>, long long> mp;
	vector<long long> cont_frac;
	long long iter = 0;
	while(true) {
		if(mp.find(num) != mp.end()) {
			return cont_frac;
		}
		mp[num] = iter;
		vector<long long> reciprocal = {num[0], -num[1], num[3]*(num[0]-(num[1]*num[1])), num[2]};
		long long hcf = __gcd(reciprocal[2], reciprocal[3]);
		reciprocal[2] /= hcf;
		reciprocal[3] /= hcf;

		long long res = ((sqrt(reciprocal[0]*1.0) + reciprocal[1]*1.0)/((reciprocal[2]*1.0)/reciprocal[3]));
		cont_frac.push_back((res/reciprocal[3]));
		reciprocal[1] -= ((res*reciprocal[2])/reciprocal[3]);

		iter++;
		num = reciprocal;
	}
}

string solve_pell_equation(vector<long long> cont_frac, long long D, long long len) {
	len--;
	pair<string, string> number = {"1", to_string(cont_frac[len])};
	for(long long i = len-1; i >= 0; i--) {
		pair<string, string> new_num;
		new_num.first = number.second;
		new_num.second = string_add(number.first, string_multiply(number.second, to_string(cont_frac[i])));
		number.first = new_num.first;
		number.second = new_num.second;
	}
	number.first = string_add(number.first, string_multiply(number.second, to_string((long long)sqrt(D))));
	return number.first;
}

bool is_greater(string s1, string s2) {
	if(s1.size() != s2.size()) return s1.size() > s2.size();
	for(size_t i = 0; i < s1.size(); i++) {
		if(s1[i] != s2[i]) return s1[i] > s2[i];
	}
	return false;
}

void solve(){
	string max_answer_x = "0";
	long long ans_d = 0;
	for(long long D = 1; D <= 1000; D++) {
		if(floor(sqrt(D)) == ceil(sqrt(D))) {
			continue;
		}
		vector<long long> cont_frac = find_continued_fraction(D);
		int l = cont_frac.size();
		for(int i = 0; i<l; i++){
			cont_frac.push_back(cont_frac[i]);
		}

		string answer_x = solve_pell_equation(cont_frac, D, l%2 ? 2*l-1 : l-1);
		if(is_greater(answer_x, max_answer_x)) {
			ans_d = D;
			max_answer_x = answer_x;
		}
	}
	cout << ans_d << endl;
}

int main(){
	solve();
	
	return 0;
}