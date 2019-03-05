#include<iostream>
#include<vector>
using namespace std;
//link :: https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0
int main(){
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i] ;
	for(int i=0;i<n;i++){
		if(i%2==0){
			if( ( ((i-1)>=0 && v[i]<v[i-1]) || ((i-1)<0) ) && ( ((i+1)<n && v[i]<v[i+1]) || ((i+1)>=n))  ){
			}
			else{
				int temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp; 
			}
			
		}
		else{
			if( ( ((i-1)>=0 && v[i]>v[i-1]) || ((i-1)<0) ) && ( ((i+1)<n && v[i]>v[i+1]) || ((i+1)>=n))  ){
			}
			else{
				int temp = v[i+1];
                                v[i+1] = v[i];
                                v[i] = temp; 
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<v[i]<<" " ;
	cout<<endl;
}
return 1 ;
}
