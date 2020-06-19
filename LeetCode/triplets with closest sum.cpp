#include <bits/stdc++.h>
using namespace std;
#define debug_1(a) cerr << #a << " " << a << endl;
#define debug_2(a, n) cerr << #a << " ";for(int i=0; i<n;++i){cerr<<a[i]<<" ";} cerr<<endl;
#define debug_3(a) cerr << #a << " ";for(auto x:a){cerr<<x<<" ";} cerr<<endl;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int first = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n ; ++i)
        {

        	int li = i+1;
        	int ri = n-1;
        	int sum = 0;
        	while(li<ri)
        	{
        		sum = nums[li] + nums[ri] + nums[i];
        		if (abs(target- first) > abs(target-(sum)))
	        	{
	        		//cout << nums[i] << li << ri << sum;
	        		first = sum;
	        	}
        		if (sum<target)
        		{
        			li++;
        		}else if (sum>target)
        		{
        			ri--;
        		}else break;
        	}
        	

        }
        return first;
    }
};

int main()
{
	vector<int> a =  {-3,-2,-5,3,-4};
	int target = -1;
	Solution A;
	cout << A.threeSumClosest(a, target);

}