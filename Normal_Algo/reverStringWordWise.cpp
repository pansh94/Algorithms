#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/
int main(){
int t;
cin>>t;
string test;
getline(cin,test);
while(t--){
	
	string str1 , strTra="" ;
	getline(cin,str1);

	int len = str1.length();

	string::iterator start = str1.begin() ;
	stack<string>s ;

	for(;start!=str1.end();start++){
		if(*start == '.'){
			s.push(strTra);
			strTra = "" ;
		}
		else{
			strTra += *start ;
		}
	}
	s.push(strTra) ;
	while(!s.empty()){
		cout<<s.top();
		s.pop();
		if(!s.empty())
			cout<<"." ;
	}
	cout<<endl ;
}
return 0;
}
