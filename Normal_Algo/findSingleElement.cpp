#include<iostream>
#include<vector>
using namespace std;
//Link : https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0
int findSingle(vector<int> &v,int n,int start, int end){
	int  mid = start+ (end-start)/2 ;
	if((mid % 2 == 0 && (mid+1)<n && v[mid]==v[mid+1]) || (mid%2!=0 && (mid-1)>=0 && v[mid-1]==v[mid])){
		return findSingle(v,n,mid+1, end);
	}
	else if( ( ((mid-1)>=0 && v[mid] != v[mid-1]) && ((mid+1<n) && v[mid]!=v[mid+1]) )  || ((mid-1)<0 && v[mid]!=v[mid+1]) || ((mid+1>=n) && v[mid]!=v[mid-1])){
		return v[mid];
	}
	else{
		return findSingle(v,n,start,mid-1);
	}
}
int main(){
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<findSingle(v,n,0,n)<<endl;
}
return 0;
}
