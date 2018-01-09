#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited;
priority_queue<pair<int,int>> pq;
vector<vector<pair<int,int>>> adj(5);

void process(int vtx) {
	visited[vtx] = 1;
	for (int i = 0; i < adj[vtx].size(); i++) {
		pair<int,int> v = adj[vtx][i];
		if (!visited[v.first])
			pq.push({-v.second, -v.first});
	}
}

int main() {
	visited.assign(5, 0);
	adj[0].push_back({1,4});
	adj[1].push_back({0,4});
	adj[0].push_back({2,4});
	adj[2].push_back({0,4});
	adj[0].push_back({3,6});
	adj[3].push_back({0,6});
	adj[0].push_back({4,6});
	adj[4].push_back({0,6});
	adj[1].push_back({2,2});
	adj[2].push_back({1,2});
	adj[2].push_back({3,8});
	adj[3].push_back({2,8});
	adj[3].push_back({4,9});
	adj[4].push_back({3,9});
	process(0);
	int mst_cost = 0;
	while (!pq.empty()) {
		pair<int,int> front = pq.top(); pq.pop();
		int u = -front.second;
		int w = -front.first;
		if (!visited[u]) {
			mst_cost += w;
			process(u);
		}
	}
	printf("MST cost = %d\n", mst_cost);
	return 0;
}