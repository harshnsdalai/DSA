#include <iostream>
#include <math.h>
using namespace std;

int max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	return b;
}
int count(int n)
{	
	
	int k = (int)log2(n);

	k++;
	int i = 1, sum = 0, quotient, ans1, ans2;

	while(k--)
	{
		quotient = (n + 1) / pow(2, i);

		ans1 = (quotient) * pow(2, i-1);
		ans2 = max(0, ((n + 1) % (int)pow(2, i)) - pow(2, i-1));
		sum += ans1 + ans2;

		i++;
	} 
	return sum;
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	   
	    cout << count(n) << endl;
	}
	return 0;
}