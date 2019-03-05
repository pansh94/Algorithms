#include <iostream>
#include<vector>
using namespace std;
/*
 * int find(vector<int> &v,int n,int start,int end){
 * LINK : https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array/0
    int mid = start+(end-start)/2;
    if(((mid-1)>=0 && (mid+1)<n && v[mid]>v[mid-1] && v[mid]>v[mid+1]) || (mid==(n-1)) )
        return v[mid];
    else if((mid-1)>=0 && v[mid]>v[mid-1])
        return find(v,n,mid,end);
    else if((mid-1)>=0 && v[mid]<v[mid-1])
        return find(v,n,start,mid);
    
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n ;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin>>v[i] ;
	    cout<<find(v,n,0,n)<<endl ;
	}
	return 0;
}*/
int findExtraElement(vector<int> &v1,vector<int> &v2,int start,int end,int n){
	//https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1
	int mid = start + (end-start)/2;
	if(mid<n && v1[mid]==v2[mid])
		return findExtraElement(v1,v2,mid+1,end,n);
	else if(v1[mid]!=v2[mid]){
		for(int i=start;i<end;i++){
			if(v1[i]!=v2[i])
				return i ;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v1(n);
		vector<int> v2(n-1);
		for(int i=0;i<n;i++)
			cin>>v1[i];
		for(int i=0;i<(n-1);i++)
			cin>>v2[i];
		cout<<findExtraElement(v1,v2,0,n,n)<<endl ;
		
	}
return 0;
}
