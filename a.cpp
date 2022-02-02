#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
using namespace std;

void solve() {
	string n; cin >> n;
	int l = n.length();
	if((n[l-1]-'0')%2 == 0) {
		cout << "0\n";
		return;
	}
	if((n[0]-'0')%2 == 0) {
		cout << "1\n";
		return;
	}
	for(int i = 0; i < l; i++) {
		if((n[i]-'0')%2 == 0) {
			cout << "2\n";
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		solve();
	}
	return 0;
}
