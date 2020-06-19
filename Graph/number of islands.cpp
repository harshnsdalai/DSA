#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> A[], int N, int M, vector<vector<bool>> &vis, int i, int j)
{


	vis[i][j] = true;
	for (int x = i-1; x <= i+1; x++)
	{
		for (int y = j-1; y <= j+1; y++)
		{
			if(x>=0 && y>=0 && x<N && y<M)
			{
				
				if (make_pair(x,y)!=make_pair(i,j) && !vis[x][y] && A[x][y]==1)
				{	
					dfs(A, N, M, vis, x, y);
				}
			}
		}
	}
}

int findIslands(vector<int> A[], int N, int M)
{
	vector<vector<bool>> vis(N, vector<bool>(M,false));
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (A[i][j]==1  && !vis[i][j])
			{
				count++;
			
				dfs(A, N, M, vis, i, j);
				
			}
		}
	}
	return count;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		int v, N, M;
		cin >> N >> M;
		vector<int> A [N];
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> v;
				A[i].push_back(v);
				//cout << A[i][j] <<endl;
			}
		}
	cout << findIslands(A, N, M) << endl;
		
	}
	
}
