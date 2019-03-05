#include<iostream>
#include<vector>
#include <cstdlib>
#include <climits>
using namespace std ;
int findMaxProduct(vector<int> &v,int n){
	if(n<2)
		return 0;
	else if(n==2)
		return (v[0]*v[1]);
	else{
		int max1=INT_MIN,max2=INT_MIN,nm1=INT_MIN,nm2= INT_MIN ;
		for(int i=0;i<n;i++){
			if(v[i]<0){
				if(abs(v[i])>abs(nm1)){
					nm2 = nm1 ;
					nm1 = v[i];
				}
				else if(abs(v[i])>abs(nm2)){
					nm2 = v[i];
				}
			}
			else{
				if(v[i]>max1){
					max2 = max1;
					max1 = v[i];
				}
				else if(v[i]>max2){
					max2 = v[i] ;
				}
			}
		}
		if((max1*max2)>=(nm1*nm2))
			return (max1*max2);
		else
			return (nm1*nm2) ;
		
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
		cin>>v[i] ;
	cout<<findMaxProduct(v,n);
	
}
return 0;
}
