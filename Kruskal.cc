#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
	private : vector<int> p, rank;
	public :
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N, 0);
			for (int i = 0; i < N; i++) p[i] = i;
		}
		int findSet(int i) {
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		int isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i);
				int y = findSet(j);
				if (rank[x] > rank[y]) {
					p[y] = x;
				} else {
					p[x] = y;
					if (rank[x] == rank[y]) rank[y]++;
				}
			}
		}
};

int main() {
	vector<pair<int,pair<int,int>>> EdgeList;
	int u, v, w;
	for (int i = 0; i < 7; i++) {
		scanf("%d %d %d", &u, &v, &w);
		EdgeList.push_back({w,{u,v}});
		EdgeList.push_back({w,{v,u}});
	}
	sort(EdgeList.begin(), EdgeList.end());
	int mst_cost = 0;
	UnionFind uf(5);
	for (int i = 0; i < 14; i++) {
		pair<int, pair<int, int>> front = EdgeList[i];
		if (!uf.isSameSet(front.second.first, front.second.second)) {
			mst_cost += front.first;
			uf.unionSet(front.second.first, front.second.second);
		}
	}
	printf("MST cost = %d\n", mst_cost);
	return 0;
}