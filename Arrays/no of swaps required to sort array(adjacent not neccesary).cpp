

#include<bits/stdc++.h> 
using namespace std; 


int findMinSwap(int arr[] , int n) 
{ 
	// Declare a vector of pair	 
	vector<pair<int,int>> vec(n); 
	
	for(int i=0;i<n;i++) 
	{ 
		vec[i].first=arr[i]; 
		vec[i].second=i; 
	} 

	// Sort the vector w.r.t the first 
	// element of pair 
	sort(vec.begin(),vec.end()); 

	int ans=0,c=0,j; 

	for(int i=0;i<n;i++) 
	{ 
		// If the element is not placed 
		// correct, then swap till its placed correct
		if(vec[i].second!=i) 
		{ 
			while(i!=vec[i].second){
			// swap with its respective index 
				swap(vec[i].first,vec[vec[i].second].first); 
				swap(vec[i].second,vec[vec[i].second].second); 
				ans++;
			}
		} 
		
	
	
	} 

	return ans; 
} 
// Driver code 
int main() 
{ 
	int arr[] = {1, 5, 4, 3, 2}; 
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout<<findMinSwap(arr,n); 
	
	return 0; 
} 
