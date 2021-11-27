#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

int n, k, cnt = 0, pos, ans;
vector<vi> adj;
vector<bool> vis, frnd;
vector<int> dp;

void min_friend_dist(int u) {
	if(!vis[u]) {
		vis[u] = true;
		for(int v : adj[u]) {
			if(!vis[v]) {
				min_friend_dist(v);
				dp[u] = min(dp[u], dp[v]+1);
			}
		}
		if(frnd[u]) {
			dp[u] = 0;
		}
	}
}

void dfs(int u, int lvl) {
	if(!vis[u]) {
		vis[u] = true;
		if(dp[u] <= lvl) {
			ans++;
			return;
		}
		if(adj[u].size() == 1 && u != 1) {
			pos = 1;
			return;
		}
		for(int v : adj[u]) {
			dfs(v, lvl+1);
		}
	}
}

void solve() {
	cin >> n >> k; pos = 0; ans = 0;
	adj.assign(n+1, vi());
	vis.assign(n+1, false);
	dp.assign(n+1, n+2);
	frnd.assign(n+1, false);
	for(int i = 0; i < k; i++) {
		int x; cin >> x;
		frnd[x] = true;
	}
	for(int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	min_friend_dist(1);
	vis.assign(n+1, false);
	dfs(1, 0);
	if(pos) cout << "-1\n";
	else cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		solve();
	}
	return 0;
}
