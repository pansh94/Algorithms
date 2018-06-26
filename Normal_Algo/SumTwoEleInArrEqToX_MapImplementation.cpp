#include<iostream>
#include<vector>
#include<map>
using namespace std ;

int main(){
/*
2
6 16
1 4 45 6 10 8 --> Yes
5 10
1 2 4 3 6 --> Yes
Link : https://practice.geeksforgeeks.org/problems/key-pair/0
*/


int t;
cin>>t ;
while(t--){
	int size,x ;
	cin>>size>>x ;
	vector< int > arr(size) ;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	map< int,int > maped ;
	int k ;
	int flag = 0;
	for(int i=0;i<size;i++){
		k = x-arr[i] ;
		if(maped.find(arr[i]) == maped.end()){
			maped[k] = arr[i] ;	
		}	
		else{
			flag=1 ;
			break ;		
		}
	}
	if(flag)
		cout<<"Yes"<<endl ;
	else
		cout<<"No"<<endl ;
	

}

return 0 ;
}
