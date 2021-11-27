#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

void solve() {
	int n, r = 1, maxDist = 1; cin >> n;
	vi b(n), ans(n+1, -1), distRoot(n+1, 0), p(n);
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		if(b[i] == i+1) r = i+1;
	}
	ans[r] = 0;
	for(int& i : p) cin >> i;
	for(int i = 1; i < n; i++) {
		if(ans[b[p[i]-1]] == -1 || ans[p[i]] != -1) {
			cout << "-1\n";
			return;
		}
		ans[p[i]] = maxDist-distRoot[b[p[i]-1]]+1;
		distRoot[p[i]] = distRoot[b[p[i]-1]]+ans[p[i]];
		maxDist++;
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		solve();
	}
	return 0;
}
