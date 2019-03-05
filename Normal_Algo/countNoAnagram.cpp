#include<iostream>
#include<map>
#include<string>
using namespace std;
//link :: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams/0
int main(){
int t;
cin>>t;
string temp;
getline(cin,temp);
while(t--){
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	int len1 = str1.length();
	int len2 = str2.length();
	int w1 = 0,w2 = 0, count = 0;
	for(int j=0;j<len2;j++){
		w1 += (int)str2[j];
	}

	for(int i=0;i<len1;i++){
		if(i<len2)
			w2 += (int)str1[i];
		else
			w2 = w2 + (int)str1[i] - (int)str1[i-len2];
		if(w2==w1){
			int k = 0;
			int flag =1;
			map<int,int> m1,m2 ;
        		map<int,int>::iterator itr1,itr2;

			for(int j=(i-len2+1);j<=i;j++){
				itr1 = m1.find((int)str1[j]);
				itr2 = m2.find((int)str2[k]);
				
				if(itr1 == m1.end()){
					m1.insert(pair<int,int>((int)str1[j],1));
				}
				else{
					(itr1->second)++ ;
				}
				if(itr2 == m2.end()){
					m2.insert(pair<int,int>((int)str2[k],1));
				}
				else{
					(itr2->second)++ ;
				}
				k++;
				
			}
			itr1 = m1.begin();
			itr2 = m2.end();
			/*for(;itr1 != m1.end();itr1++)
				cout<<" <++> "<<itr1->first<<" = "<<itr1->second ;
			cout<<"\nitr1 ended"<<endl ;
			for(;itr2 != m2.end();itr2++)
                                cout<<" <++> "<<itr2->first<<" = "<<itr2->second ;
                        cout<<"\nitr2 ended"<<endl ;
			itr1 = m1.begin();
                        itr2 = m2.end();
			*/
			for(;itr1 != m1.end();itr1++){
				itr2 = m2.find(itr1->first);
				if(itr1->second != itr2->second){
					//cout<<itr1->first<<" = "<<itr1->second<<" -- "<<itr2->second<<endl ;
					flag=0;
					break ;
				}
				else
					flag=2;
			}
			if(flag==2)
				count++;
		}			
	}
	cout<<count<<endl;
}
return 0;
}
