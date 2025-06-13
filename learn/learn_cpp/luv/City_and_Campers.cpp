#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
multiset<int> sizes;
int parent[N];
int sz[N];

void make(int v){
	parent[v] = v;
	sz[v] = 1;
    sizes.insert(1);
}

int find(int v){
	if (v == parent[v]){return v;}
	return parent[v] = find(parent[v]);
}

void Union(int i, int j){
    int p = find(i);
    int q = find(j);
	if (p != q){
		if (sz[p] > sz[q]){
            parent[q] = p;
            sizes.erase(sizes.find(sz[q]));
            sizes.erase(sizes.find(sz[p]));
            sz[p] += sz[q];
            sizes.insert(sz[p]);
        }else{
            parent[p] = q;
            sizes.erase(sizes.find(sz[q]));
            sizes.erase(sizes.find(sz[p]));
            sz[q] += sz[p];
            sizes.insert(sz[q]);
        }
	}
}


int main() {
	int n, k;
	cin >> n >> k;

	for (int i=1;i<=n;i++){
		make(i);
	}

	for (int i=0;i<k;i++){
		int a, b;
		cin >> a >> b;
		Union(a, b);
		cout << abs(*(sizes.begin()) - *(--sizes.end())) << endl;
	}

}