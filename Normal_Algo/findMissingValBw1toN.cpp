#include<iostream>
#include<vector>
using namespace std;
/*
3
3
1 3
>>2
5
1 2 3 5
>>4
10
1 2 3 4 5 6 7 8 10
>>9
link :https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
*/

int main()
{
int t;
cin>>t ;
while(t--){
	int n ;
	cin>>n ;
	vector<int> arr(n-1) ;
	int sumArr = 0 ;
	for(int i=0;i<(n-1);i++){
		cin>>arr[i] ;
		sumArr+=arr[i] ;
	}
	int sum = n*(1+n)/2 ;
	cout<<(sum-sumArr)<<endl ;
	
}

return 0 ;
}
