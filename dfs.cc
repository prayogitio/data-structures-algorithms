#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

vector<vector<int>> adj(4);
vector<int> vis(4);

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	cout << u;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v);
	}
}

int main() {
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(3);
	dfs(2);

	return 0;
}