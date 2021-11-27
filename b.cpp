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
		ll a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		ll r = max(0LL, (3*a-b+3)/4);
		if(min(a-2*r, b-2*r) < 0) r--;
		a -= 2*r; b -= 2*r;
		if(a+b >= 4) {
			cout << r+a << "\n";
		} else {
			cout << r << "\n";
		}
	}
	return 0;
}
