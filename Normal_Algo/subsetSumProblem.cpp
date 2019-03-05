#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findSubset(vector<int> arr, int size, int pointer,int tempSum,int totalSum){
	if((totalSum - (2*tempSum))==0){
		cout<<"Yes"<<endl ;		
		return  ;
	}
	else{
		if(pointer<size && ((tempSum+arr[pointer]) <= totalSum) ){
			for(int i = pointer;i < size;i++){
				return findSubset(arr,size,pointer+1,tempSum+arr[i],totalSum) ;			
			}		
		}
	}
	
}
int main(){
int t;
cin>>t;
while(t--){
	int size;
	cin>>size;
	vector<int> arr(size) ;
	int sum =0;
	for(int i=0;i<size;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr.begin(),arr.end());
	findSubset(arr,size,0,0,sum);
}
return 0;
}
