//meth_cook
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

class graph {
	int V;
	list<int> *adj;
	bool cutil(int u, bool visited[], bool recstack[]);
	
	public :
		graph(int V);
		void add(int u, int v);
		bool cyclic();
};

graph :: graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void graph :: add(int u, int v) {
	adj[u].push_back(v);
}

bool graph :: cutil(int u, bool visited[], bool recstack[]) {
	if (visited[u] == false) {
		visited[u] = true;
		recstack[u] = true;
		list<int> :: iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			if (!visited[*i] && cutil(*i,visited,recstack)) {
				return true;
			} else if(recstack[*i]) {
				return true;
			}
		}
	}
	recstack[u] = false;
	return false;
}

bool graph :: cyclic() {
	bool *visited = new bool[V];
	bool *recstack = new bool[V];
	
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		recstack[i] = false;
	}
	for (int i = 0; i < V; i++) {
		if(cutil(i,visited,recstack)) {
			return true;				
		}
	}
	return false;
}

int main ()
{
	graph g(6);
	int e, u, v;
	cout << "The number of edges are :" << endl;
	cin >> e;
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		g.add(u, v);
	}
	if (g.cyclic()) {
		cout << "there is a cyclic! ohh yo";
	} else {
		cout << "nopes! no yo!";
	}
	return 0;
}
