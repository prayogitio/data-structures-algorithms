#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> adj(4);
vector<int> vis(4);

void bfs(int start) {
	queue<int> q;
	vis[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		cout << u;
		q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (vis[v]) continue;
			vis[v] = 1;
			q.push(v);
		}
	}
}

int main() {
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(3);
	bfs(2);

	return 0;
}