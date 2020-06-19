#include <bits/stdc++.h>
using namespace std;

int ne_x[] = {-1, +1, 0, 0};
int ne_y[] = {0, 0, -1 , +1};
int ans = 0;
void pathExists(vector<int> A[],int N, vector<vector<bool>>&vis, int si, int sj, int di, int dj)
{
	//cout << si << sj << "entry" << endl;
	if (si==di && sj==dj)
	{
		//cout<<"chutiya"<<endl;
		ans = 1;
	}
	vis[si][sj] = true;
	
	for (int k = 0; k < 4; ++k)
	{
		int i = si + ne_x[k];
		int j = sj + ne_y[k];
			//cout<< i << j << "hi1" << endl;
		if (i>=0 && j>=0 && j<N && i<N)
		{//cout<< i << j << "hi2" << endl;
			if (!vis[i][j] && (A[i][j]==3 || A[i][j]==2 || A[i][j]==1))
			{
				//cout<< i << j << "hi3" << endl;
				//cout<< "entry at pathhhhhh" << endl;
				pathExists(A, N, vis, i, j, di, dj);
				//cout << "Exit at pathhhhhh " << endl;
			}
		}
	}
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		int v, N;
		cin >> N;
		vector<int> A [N];
		pair<int, int> src, dest;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> v;
				A[i].push_back(v);
				if (v == 1)
				{
					src = make_pair(i, j);
				}
				else if (v==2)
				{
					dest = make_pair(i ,j) ;
				}
			}
		}

	//cout<<src.first << src.second << dest.first << dest.second << endl;
	vector<vector<bool>> vis(N, vector<bool>(N, false));
	pathExists(A, N, vis, src.first, src.second, dest.first, dest.second);
	cout << ans << endl;
	ans = 0;
		
	}
}
 