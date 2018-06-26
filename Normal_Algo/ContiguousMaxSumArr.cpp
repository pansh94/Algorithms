#include<iostream>
#include<vector>
using namespace std ;

int main(){
int t ;
cin>>t ;
while(t--){
	int size;
	cin>>size;
	vector< int > arr(size) ;

	for(int i=0;i<size;i++)
		cin>>arr[i] ;
	int maxSum = arr[0];
	int tempMax = 0;
	
	for(int i=0;i<size;i++){
		tempMax+= arr[i];
		if(tempMax>maxSum)
			maxSum=tempMax ;
		if(tempMax<0)
			tempMax=0;		
	}
	
	cout<<maxSum<<endl ;
	
}

return 0 ;
}
