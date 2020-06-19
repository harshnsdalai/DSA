#include <bits/stdc++.h>
using namespace std;
bool vis[1000] = {false};
vector<int> adj[1000];
int v1, v2, V, E;
void topo(int i,int V, int vis[],vector<int> adj[], stack<int> &s)
{
    vis[i]=1;
    for(int j =0 ;j<adj[i].size();j++)
    {
        if(!vis[adj[i][j]])
        topo(adj[i][j],V,vis,adj,s);
    }
    s.push(i);
}
int* topoSort(int V, vector<int> adj[])
{
 stack<int> s;
 int vis[V] = {0};
 for(int i =0;i<V;i++)
 {
     if(!vis[i])
     topo(i,V,vis,adj,s);
 }
 int *a = ((int*)malloc(sizeof(int)*V));
 int j=0;
 while(!s.empty())
 {
    a[j] = s.top();
    s.pop();
    j++;
 }
 return a;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		
		cin >> V >> E;
		
		for (int i = 0; i < E; ++i)
		{
			cin >> v1 >> v2;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
		int *f = topoSort(V,adj);
		for (int i = 0; i < V; ++i)
		{
			cout << f[i];
		}
		
		cout << endl;

	}
	
}
