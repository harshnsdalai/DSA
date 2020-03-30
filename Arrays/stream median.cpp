#include <bits/stdc++.h>

using namespace std;

double medians(double *arr, int n)
{
    priority_queue<double>s;
    priority_queue<double, vector<double>, greater<double>>g;

    double med = arr[0];
    s.push(arr[0]);

    cout << med << endl;

    for(int i=1; i<n; i++)
    {

        double x = arr[i];

        if(s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }

            med = (g.top() + s.top())/2.0;
        }
        else if(s.size() < g.size())
        {
            if(x>med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
            {
                s.push(x);
            }

            med = (g.top() + s.top())/2.0;
        }
        else
        {
            if (x < med)
			{
				s.push(x);
				med = (double)s.top();
			}
			else
			{
				g.push(x);
				med = (double)g.top();
			}

        }

        cout << med << endl;
    }
}

int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    medians(arr, n);
    // // stream of integers
    // int t;
    // while(t--)
    // {
    //     int n;
    //     cin>>n;
    //     double arr[n];
    //     for (int i = 0; i < n; ++i)
    //     {
    //         cin>>arr[i];
    //     }
        
    //     medians(arr, n);
    //     return 0;
    // }
}
