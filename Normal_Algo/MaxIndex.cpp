#include<iostream>
#include<vector>
using namespace std;
/*
Complexity : O(n^2)
*/
int main(){
int t ;
cin>>t ;
while(t--){
	int size;
	cin>>size ;
	vector<int> v(size) ;
	for(int i=0;i<size;i++){
		cin>>v[i];	
	}
	int maxIndex = 0 ;
	for(int i=0;i<size;i++){
		for(int j=(i+maxIndex);j<size;j++){
			if(v[i]<=v[j] && (j-i)>maxIndex){
				maxIndex = j-i ;			
			}
		}	
	}
	cout<<maxIndex<<endl ;
}
return  0 ;
}


/*Complexity : O(n)
https://practice.geeksforgeeks.org/problems/maximum-index/0
A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

int findMaxIndex(vector<int> v1,int size){
	vector<int>vMin (size);
	vector<int>vMax (size);
	int min = 6000;
	for(int i=0;i<size;i++){
		if(min > v1[i])
			min = v1[i];
		vMin[i] = min ;		
	}
	int max = -1 ;
	for(int i =(size-1); i>=0 ; i--){
		if(max < v1[i])
			max = v1[i];
		vMax[i] = max ;		
	}

	int i=0,j=0;
	int maxIndex = -1;

	while(i<size && j< size){
		if(vMin[i] <= vMax[j] && (maxIndex < (j-i) )){
			maxIndex = j-i ;
			j++;		
		}
		else
			i++;	
	}
	cout<<maxIndex<<endl ;
}
int main(){
int t ;
cin>>t ;
while(t--){
	int s ;
	cin>>s;
	vector<int> v1(s) ;
	for(int i=0;i<s;i++)	
		cin>>v1[i] ;
	findMaxIndex(v1,s);
}
return 0;
}*/
