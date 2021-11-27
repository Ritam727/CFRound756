#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define pf push_front
using namespace std;

void solve() {
	int n; cin >> n;
	vi p(n); for(int& i : p) cin >> i;
	if(p[0] != n && p[n-1] != n) {
		cout << "-1\n";
		return;
	}
	int i = 0, j = n-1;
	deque<int> dq;
	while(i <= j) {
		if(p[i] > p[j]) {
			dq.pf(p[i]);
			i++;
		} else {
			dq.pb(p[j]);
			j--;
		}
	}
	while(!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
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
