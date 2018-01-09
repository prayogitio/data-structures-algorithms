#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 10000000
using namespace std;

int dist[9];

void dijkstra(vector<vector<pair<int,int>>> adj, int src) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < 9; i++) {
		dist[i] = INF;
	}
	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		vector<pair<int,int>>::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = it->second;
			int w = it->first;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		cout << i << " - " << dist[i] << endl;
	}
}

int main() {
	vector<vector<pair<int,int>>> adj(9);
	adj[0].push_back({4,1});
	adj[1].push_back({4,0});
	adj[0].push_back({8,7});
	adj[7].push_back({8,0});
	adj[1].push_back({11,7});
	adj[7].push_back({11,1});
	adj[1].push_back({8,2});
	adj[2].push_back({8,1});
	adj[7].push_back({7,8});
	adj[8].push_back({7,7});
	adj[7].push_back({1,6});
	adj[6].push_back({1,7});
	adj[2].push_back({2,8});
	adj[8].push_back({2,2});
	adj[8].push_back({6,6});
	adj[6].push_back({6,8});
	adj[6].push_back({2,5});
	adj[5].push_back({2,6});
	adj[2].push_back({4,5});
	adj[5].push_back({4,2});
	adj[2].push_back({7,3});
	adj[3].push_back({7,2});
	adj[3].push_back({14,5});
	adj[5].push_back({14,3});
	adj[3].push_back({9,4});
	adj[4].push_back({9,3});
	adj[5].push_back({10,4});
	adj[4].push_back({10,5});
	dijkstra(adj, 0);
	return 0;
}