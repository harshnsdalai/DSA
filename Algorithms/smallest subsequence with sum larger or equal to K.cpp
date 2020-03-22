#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define tie() ios_base :: sync_with_stdio(0) ; cin.tie(0); cout.tie(0)
#define ld long double
#define mod 1000000007
#define big 1e18+10
#define small -big
#define endl "\n"

int lengthOfSmallestSubsequence(int K, vector<int> v)
{
	sort(v.begin(), v.end(), greater<int>());
	int s = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		s = s + v[i];
		
		if (s>=K)
		{
			return i+1;
		}

	}
	return -1;
}
int32_t main()
{
    tie();
    vector<int> v{2, 3, 1, 5, 6, 3, 7, 9, 14, 10, 2, 5}; 
    int K = 35; 
  
    cout << lengthOfSmallestSubsequence(K, v); 
  
    return 0; 
}
