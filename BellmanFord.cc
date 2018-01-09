#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#define INF 10000000
using namespace std;

int dist[5];

void bellmanFord(vector<pair<int,pair<int,int>>> adj, int src) {
	for (int i = 0; i < 5; i++)
		dist[i] = INF;
	dist[src] = 0;
	bool hasNegativeCyle = false;
	//5 is the number of vertex
	for (int i = 0; i < 5-1; i++) {
		for (int j = 0; j < 8; j++) {
			int u = adj[j].second.first;
			int v = adj[j].second.second;
			int w = adj[j].first;

			if (dist[u] != INF && dist[u] + w < dist[v] ) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		int u = adj[i].second.first;
		int v = adj[i].second.second;
		int w = adj[i].first;
		if (dist[u] != INF && dist[u] + w < dist[v]) {
			hasNegativeCyle = true;
		}
	}

	if(!hasNegativeCyle) {
		for (int i = 0; i < 5; i++) {
			cout << i << " - " << dist[i] << endl;
		}
	}
	return;
}

int main() {
	vector<pair<int,pair<int,int>>> adj;
	adj.push_back({-1,{0,1}});
	adj.push_back({4,{0,2}});
	adj.push_back({3,{1,2}});
	adj.push_back({2,{1,3}});
	adj.push_back({2,{1,4}});
	adj.push_back({5,{3,2}});
	adj.push_back({1,{3,1}});
	adj.push_back({-3,{4,3}});
	bellmanFord(adj, 0);
	return 0;
}