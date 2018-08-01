#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std ;
/*
Input
1
4
1 3 2 4 

Output
3 4 4 -1
Link : https://practice.geeksforgeeks.org/problems/next-larger-element/0
*/

int main(){
int t;
cin>>t ;
while(t--){
	int n ;
	cin>>n ;
	vector<int> v(n) ;
	stack<int> s ;
	map<int,int> m ;
	for(int i=0;i<n;i++)
		cin>>v[i] ;
	for(int i=0 ; i<n;i++){
		if(s.empty() || s.top()>=v[i])
			s.push(v[i]) ;
		else{
			m[s.top()] = v[i] ;
			s.pop();
			i--;		
		}	
	}
	for(int i=0;i<n;i++){
		if(m.find(v[i]) == m.end())
			cout<<-1<<" " ;
		else
			cout<<m[v[i]]<<" " ;
	}
	cout<<endl ;
	
}
return 0;
}

