#include<iostream>
#include<vector>
using namespace std ;
/*
https://practice.geeksforgeeks.org/problems/equilibrium-point/0
Input:
3
1
1
5
1 3 5 2 2
3
1 2 2
Output:
1
3
-1
*/

int main(){
int t ;
cin>>t ;
while(t--){
	int n ;
	cin>>n;
	vector<int>v(n) ;
	float total = 0;
	for(int i=0;i<n;i++){
		cin>>v[i] ;
		total += v[i] ;
	}
	float half = 0 ;	
	int flag = 0;
	for(int i=0;i<n;i++){
		if(n==1){
			cout<<1<<endl ;
			flag = 1 ;
			break ;
		}
		half += v[i];
		if((i+1) < n && half == ((total-v[i+1])/2.0)){
			cout<<(i+2)<<endl ;
			flag =1;	
			break ;		
		}
	}
	if(flag== 0)
		cout<<-1<<endl ;
}
return 0;
}
