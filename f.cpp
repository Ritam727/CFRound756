#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		int n; ll s;
		cin >> n >> s;
		vll v(n); for(ll& i : v) cin >> i;
		int i = 0, j = 0, l = 0, r = 0, len = 0;
		ll sum = 0;
		while(i < n) {
			if(j < i) {
				sum += v[j++];
				continue;
			}
			while(j < n && -sum-v[j] <= s) {
				sum += v[j++];
			}
			if(len < j-i) {
				len = j-i;
				l = i+1; r = j;
			}
			sum -= v[i++];
		}
		if(len > 0) {
			cout << l << " " << r << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}
