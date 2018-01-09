#include <cstdio>
#include <vector>
using namespace std;

class UnionFind {
	private: vector<int> p, rank;
	public:
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N, 0);
			for (int i = 0; i < N; i++) {
				p[i] = i;
			}
		}
		int findSet(int i) {
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		bool isSameSet(int i, int j) {
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
	UnionFind u(5);
	u.unionSet(0,1);
	u.unionSet(2,3);
	u.unionSet(4,3);
	u.unionSet(0,3);
	if (u.isSameSet(0,3)) printf("yes\n");
	else printf("no\n");
	return 0;
}