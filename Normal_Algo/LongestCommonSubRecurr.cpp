#include<iostream>
#include<vector>
#include<string>

using namespace std;

int findLCS(string str1,string str2,int size1, int size2){

	if(size1==0 || size2==0)
		return 0 ;
	else if(str1[size1-1] == str2[size2-1])
		return 1+findLCS(str1,str2,size1-1,size2-1) ;
	else 
		return (findLCS(str1,str2,size1-1,size2) > findLCS(str1,str2,size1,size2-1))?findLCS(str1,str2,size1-1,size2):findLCS(str1,str2,size1,size2-1) ;

}


int main(){

int t;
cin>>t;
string str_space ;
getline(cin,str_space);
while(t--){
	int size1,size2;
	string str1,str2;
	cin>>size1>>size2 ;
	getline(cin,str_space) ;

	getline(cin,str1);
	getline(cin,str2);
	
	cout<<findLCS(str1,str2,size1,size2)<<endl;	
}
return 0;
}
