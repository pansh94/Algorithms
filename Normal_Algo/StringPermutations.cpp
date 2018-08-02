#include<iostream>
#include<string>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std ;
/*
Input:
2
ABC
ABSG
Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA 
Link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
*/
void permutate(string str,string out){
	if(str.length() == 0)
		cout<<out<<" " ;
	else{
		for(int i=0;i<str.size();i++){
			string str1 = str.substr(1) ;
			sort(str1.begin(),str1.end()) ;
			permutate(str1,out+str[0]);
			rotate(str.begin(),str.begin()+1,str.end());
		}	
	}
	
}
int main(){
int t;
string temp ;
cin>>t ;
getline(cin,temp);
while(t--){
	string str1 ;
	getline(cin,str1);
	sort(str1.begin(),str1.end());
	permutate(str1,"");
	cout<<endl ;
}
return 0 ;
}


