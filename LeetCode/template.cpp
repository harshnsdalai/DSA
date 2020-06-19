#include <bits/stdc++.h>
using namespace std;
#define debug_1(a) cerr << #a << " " << a << endl;
#define debug_2(a, n) cerr << #a << " ";for(int i=0; i<n;++i){cerr<<a[i]<<" ";} cerr<<endl;
#define debug_3(a) cerr << #a << " ";for(auto x:a){cerr<<x<<" ";} cerr<<endl;

class Solution {
public:
	int jump(vector<int>& nums) {
		int jumps = 0, curEnd = 0, curFarthest = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		curFarthest = max(curFarthest, i + nums[i]);
		if (i == curEnd) {
			jumps++;
			curEnd = curFarthest;
		}
	}
	return jumps;

	}
};
int main()
{
	vector<int> a =  {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	int target = -1;
	Solution A;
	cout << A.jump(a);
}