#include<iostream>
#include<string>
#include<vector>
//link : https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
using namespace std;
int findLCS(string str1,string str2,int size1,int size2){
	vector< vector<int> > matrix(size1+1, vector<int>(size2+1) ) ;

	for(int i=0;i<size1;i++)
		matrix[i][0] = 0;
	for(int i=0;i<size2;i++)
		matrix[0][i] = 0;
	
	for(int i=1;i<=size1;i++){
		for(int j=1;j<=size2;j++){ 
			if(str1[i-1] == str2[j-1]){
				matrix[i][j] = matrix[i-1][j-1] + 1 ;
			}		
			else{
				matrix[i][j] = (matrix[i-1][j] >= matrix[i][j-1])?matrix[i-1][j]:matrix[i][j-1] ;			
			}
		}
	}
	/*for(int i=0;i<=size1;i++){
		for(int j=0;j<=size2;j++){
			cout<<matrix[i][j]<<" " ;		
		}
		cout<<endl ;
	}*/
		
	return (matrix[size1][size2]) ;		

}

int main(){
int t;
string str_space ;
cin>>t ;
getline(cin,str_space) ;

while(t--){
	int size1,size2;
	cin>>size1>>size2 ;
	getline(cin,str_space) ;
	string str1,str2 ;
	
	getline(cin,str1);
	getline(cin,str2);

	cout<<findLCS(str1,str2,size1,size2)<<endl ;
}
return 0;
}
