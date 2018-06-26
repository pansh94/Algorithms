#include<iostream>
#include<vector>
/*
link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

*/
using namespace std;

int main(){
int t;
cin>>t ;
while(t--){
	int size ;
	cin>>size ;
	int count0 = 0,count1 = 0,count2 =0 ;
	
	vector<int> arr(size) ;

	for(int i=0;i<size;i++){
		cin>>arr[i];

		if(arr[i] == 0)
			count0++ ;
		else if(arr[i] == 1)
			count1++ ;
		else if(arr[i] == 2)
			count2++ ;
	}
	//cout<<count0<<"-"<<count1<<"-"<<count2<<endl ; 
	for(int i=0;i<count0;i++)
		cout<<0<<" " ;

	for(int i=0;i<count1;i++)
		cout<<1<<" " ;

	for(int i=0;i<count2;i++)
		cout<<2<<" " ;

	cout<<endl ;
	 
}

return 0;
}
