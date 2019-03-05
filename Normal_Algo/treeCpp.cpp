#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std ;
static int flag ;
struct Node{
	int data;
	struct Node *left,*right;
};
struct Node* enterValue(struct Node* root,int data[],int n){
	for(int i=0;i<n;i++){
		struct Node* find = NULL;
		struct Node* temp = new Node;
		temp->data =  data[i];
		temp->left = temp->right = NULL;
		if(!root)
			root = temp;
		else{
			find = root ;
			while(1 && find){
				if(find->data <= temp->data ){
					if(find->right)
						find = find->right ;
					else{
						find->right=temp;
						break;
					}
				}
				else{
					if(find->left)
						find = find->left;
					else{
						find->left = temp;
						break;
					}
				}
			}
		}
	}
return root;
}
struct Node* findMax(struct Node* temp){
	if(!temp)
		return NULL;
	else{
		if(temp->right)
			return temp->right ;
		else
			return temp ;
	}
}
struct Node* findMin(struct Node* temp){
	if(!temp)
		return NULL;
	else{
		if(temp->left)
			return findMax(temp->left);
		else
			return temp;

	}
}
struct Node* deleteNode(struct Node* temp,int data){
	if(!temp)
		return NULL;
	else if(temp->data < data)
		temp->right = deleteNode(temp->right,data);

	else if(temp->data > data)
		temp->left = deleteNode(temp->left,data);
		
	else{
		if(!temp->right){
			return temp->left ;
		}
		else if(!temp->left){
			return temp->right ;
		}
		struct Node* tempNew ;
		int check = -1;
		if(temp->right){
			tempNew = findMin(temp->right);
			check = 1;
		}
		else if(temp->left){
			tempNew = findMax(temp->left);
			check = 0;
		}
		temp->data = tempNew->data;
		int key = temp->data ;
		if(check == 1){
			temp->right = deleteNode(temp->right,tempNew->data);
		}
		else if(check = 0){
			temp->left = deleteNode(temp->left,tempNew->data);
		}
		else
			return NULL ;
		cout<<"Key :"<<key<<endl ;
	}
}
void inOrder(struct Node * temp){
	if(!temp)
		return ;
	else{
		inOrder(temp->left) ;
		cout<<temp->data<<"-" ;
		inOrder(temp->right);
	}
}
void postOrder(struct Node *temp){
	if(!temp)
                return ;
        else{
                postOrder(temp->left) ;
                postOrder(temp->right);
		cout<<temp->data<<"-" ;
        }

}
void preOrder(struct Node *temp){
	if(!temp)
                return ;
        else{
		cout<<temp->data<<"-" ;
                preOrder(temp->left) ;
                preOrder(temp->right);
        }

}
void levelOrder(struct Node * temp){
	if(!temp)
                return;
	else{
		queue<struct Node*> tempNode ;
		tempNode.push(temp);
		struct Node * dummy = new Node ;
		dummy->data = -999 ;
		dummy->left = dummy->right = NULL ;
		tempNode.push(dummy);
		while(!tempNode.empty()){
			while(tempNode.front()->data != -999){
				cout<<tempNode.front()->data<<" ";
				if(tempNode.front()->left)
					tempNode.push(tempNode.front()->left);
				if(tempNode.front()->right)
					tempNode.push(tempNode.front()->right);
				tempNode.pop();
			}
			if(tempNode.front()->data == -999){
				cout<<"\n" ;
				tempNode.pop();
				if(!tempNode.empty())
					tempNode.push(dummy);			
			}
		}
	}
}
void spiralLevelOrder(struct Node* temp){
	int check = 1;
	if(!temp)
		return;
	else{
		queue<struct Node*> qNode;
		stack<int> sNode;
		struct Node* dummy = new Node ;
		dummy->data = -999 ;
		dummy->left = dummy->right = NULL;
		qNode.push(temp);
		qNode.push(dummy);
		while(!qNode.empty()){
			while(qNode.front()->data != -999){
				if(check==0)
					sNode.push(qNode.front()->data);
				else
					cout<<qNode.front()->data<<" " ;
				if(qNode.front()->left)
                                        qNode.push(qNode.front()->left);
                                if(qNode.front()->right)
                                        qNode.push(qNode.front()->right);
				qNode.pop();
			}
			if(qNode.front()->data == -999){
				qNode.pop();
                                if(!qNode.empty())
                                        qNode.push(dummy);
				if(!sNode.empty()){
					while(!sNode.empty()){
						cout<<sNode.top()<<" ";
						sNode.pop();
					}
				}
				cout<<endl ;
				if(check)
					check=0;
				else
					check=1;
			}
		}		
	}
}
void inorderSuccessor(struct Node* temp,int data){
	if(!temp)
		return;
	else{
		inorderSuccessor(temp->left,data);
		if(flag){
			cout<<"Inorder successor of "<<data<<" is : "<<temp->data<<endl ;
                	flag=0;
                	return;
		}
		if(temp->data == data)
                        flag =1;
		
		inorderSuccessor(temp->right,data);
	}
}
void reverseOrder(struct Node * temp){
	stack <int> stNode ;
	if(!temp)
		return ;
	else{
		queue<struct Node*> queueNode ;
		struct Node* dummy = new Node ;
		dummy->data = -999 ;
		dummy->left = dummy->right = NULL ;
		queueNode.push(temp);
		queueNode.push(dummy);
		while(!queueNode.empty()){
			while(queueNode.front()->data != -999){
				if(queueNode.front()->right)
					queueNode.push(queueNode.front()->left);
				if(queueNode.front()->left)
					queueNode.push(queueNode.front()->right);
				stNode.push(queueNode.front()->data);
				queueNode.pop();
			}
			if(queueNode.front()->data== -999){
				queueNode.pop();
				if(!queueNode.empty())
					queueNode.push(dummy);
			}
		}
	}
	while(!stNode.empty()){
		cout<<stNode.top()<<" " ;
		stNode.pop();
	}
}
void diagonalTraversal(struct Node* temp,map<int,vector<int> > &diaMap,int leftCount){
	if(!temp)
		return;
	else{
		diaMap.insert(pair<int, vector<int> >(leftCount,vector<int>()) );
		diaMap[leftCount++].push_back(temp->data);
		diagonalTraversal(temp->left,diaMap,leftCount);
		diagonalTraversal(temp->right,diaMap,--leftCount);
	}
}
void leftBoundaryTraversal(struct Node* temp){
	while(temp){
		if(temp->left || temp->right)
			cout<<temp->data<<" " ;
		temp=temp->left;	
	}
}
void rightBoundaryTraversal(struct Node* temp,int data){
	if(!temp)
		return ;
	else{
		rightBoundaryTraversal(temp->right,data);
		if(temp->data!=data && (temp->left || temp->right))
			cout<<temp->data<<" " ;
	}
}
void leafTraversal(struct Node* temp){
	if(!temp)
		return ;
	else{
		if(!temp->left && !temp->right)
			cout<<temp->data<<" " ;
		leafTraversal(temp->left);
		leafTraversal(temp->right);
	}
}
void boundaryTraversal(struct Node* temp){
	if(!temp)
		return;
	else{
		int data = temp->data ;
		cout<<temp->data<<" ";
		leftBoundaryTraversal(temp->left);
		leafTraversal(temp);
		rightBoundaryTraversal(temp,data);
	}
}
int countNoOfNodes(struct Node* temp){
	if(!temp)
		return 0 ;
	else{
		return (1+countNoOfNodes(temp->left)+countNoOfNodes(temp->right));
	}
}
int countNoOfLeafs(struct Node *temp){
	if(!temp)
		return 0;
	else if(!temp->right && !temp->left)
		return 1;
	else
		return (countNoOfLeafs(temp->left)+countNoOfLeafs(temp->right));
}
int countNoOfNonLeafs(struct Node* temp){
	if(!temp)
		return 0;
	else if(!temp->right && !temp->left)
		return 0;
	else
		return (1+countNoOfNonLeafs(temp->right)+countNoOfNonLeafs(temp->left));
}
int countNoOfFullNodes(struct Node* temp){
	if(!temp)
		return 0;
	else if(!temp->right && !temp->left)
		return 0;
	else if(!temp->right || !temp->left)
		return(countNoOfFullNodes(temp->left)+countNoOfFullNodes(temp->right));
	else
		return(1+countNoOfFullNodes(temp->left)+countNoOfFullNodes(temp->right));
} 
int findHeight(struct Node* temp){
	if(!temp)
		return 0;
	else{
		int left = findHeight(temp->left);
		int right = findHeight(temp->right);
		if(left>right)
			return (1+left);
		else
			return (1+right);
	}
}
int isCompleteTree(struct Node *temp){
	if(!temp)
		return 1 ;
	else if(!temp->left && !temp->right)
		return 1 ;
	else if(temp->left && temp->right)
		return (isCompleteTree(temp->left) && isCompleteTree(temp->right) ) ;
	else 
		return 0;
}
bool isBST(struct Node * root, struct Node* left, struct Node* right){
	if(!root)
		return true;
	else if(left && left->data > root->data)
		return false ;
	else if(right && right->data <root->data)
		return false ;
	else
		return(isBST(root->left,left,root) && isBST(root->right,root,right));
}
struct Node * findLowestCommonAncestor(struct Node* temp,int ch1, int ch2){
	if(!temp)
		return temp;
	else{
		if( ((temp->data == ch1) && (ch2 < temp->data || ch2 > temp->data)) || ((temp->data == ch2)&&(ch1<temp->data || ch2>temp->data)) )
			return temp ;
		else if( (ch1<temp->data && ch2>temp->data) || (ch1>temp->data && ch2<temp->data))
			return temp ;
		else if( ch1<temp->data && ch2<temp->data && temp->left)
			return findLowestCommonAncestor(temp->left,ch1,ch2);
		else if( ch1>temp->data && ch2>temp->data && temp->right)		
			return findLowestCommonAncestor(temp->right,ch1,ch2);
		else
			return temp ;			
	}
}
void tempInOrder(struct Node * temp,int n1,int n2){
	if(!temp)
		return;
	else{
		tempInOrder(temp->left,n1,n2);

		if(temp->data <= n2 && temp->data >= n1)
			cout<<temp->data<<" ";
		else 
			return;

		tempInOrder(temp->right,n1,n2);	
	}
}
void printBSTElementInGivenRange(struct Node *temp,int r1,int r2){
	if(!temp)
		return ;
	else{
		if(temp->data <= r2 && temp->data >=r1)
			tempInOrder(temp,r1,r2);
		else if(temp->data <= r1)
			printBSTElementInGivenRange(temp->right,r1,r2);
		else if(temp->data >= r2)
			printBSTElementInGivenRange(temp->left,r1,r2);
		else 
			return;
	}
}
void printElementInRange(struct Node *temp , int r1, int r2){
//same as above
	if(!temp)
		return ;
	else{
		if(r1 < temp->data)
			printElementInRange(temp->left,r1,r2);
		if(temp->data >= r1 && temp->data<=r2)
			cout<<temp->data<<" " ;
		if(temp->data<r2)
			printElementInRange(temp->right,r1,r2);
	}
	return ;
}
void deleteValAboveK(struct Node *temp,int val){
	static int check = 0;
	if(!temp)
		return ;
	else{
		if(temp->data<val){
			deleteValAboveK(temp->right,val);
			if(check){
				temp->right = temp->right->left ;
				check = 0;
				return ;
			}
		}
		else if(temp->data > val){
			deleteValAboveK(temp->left,val);
			if(check){
				temp->left = temp->left->left ;
                                check = 0;
                                return ;
			}
		}
			
		else{
			check = 1;
			return ;
		}
	}
}
int main(){
struct Node* root = NULL;
char ch ;
int data;
int treeData[100];
int choice = 999 ;
map<int,vector<int> > diaMap;
map<int,vector<int> >::iterator itr;
vector<int>::iterator it2 ;
do{
struct Node * temp = NULL ;
int ch1,ch2;
cout<<"Enter your choice : "<<endl<<"1. Enter value in tree."<<endl<<"2. Inorder traversing."<<endl<<"3. Postorder traversing."<<endl<<"4. Preorder traversing"<<endl;
cout<<"5. Level order traversal."<<endl<<"6. Level order traversal in spiral format."<<endl<<"7. Reverse order traversal."<<endl<<"8. Inorder successor."<<endl<<"9. Diagonal traversal of binary tree."<<endl<<"10. Boundary order traversal."<<endl<<"11. Count no. of nodes in tree."<<endl ;
cout<<"12. Count no. of leafs."<<endl<<"13. Count no. of non leafs."<<endl<<"14. Count no. of full nodes."<<endl<<"15. Find height of tree."<<endl<<"16. Delete a node."<<endl ;
cout<<"17. Find whether it is complete tree or not."<<endl<<"18. Find out whether it's bst or not."<<endl<<"19. Lowest common ancesto of two nodes."<<endl<<"20. Print no. between two value in ascending order."<<<<endl;
cout<<"21. Delete Node greater than k."<<endl<<"\nPress 0  for exit."<<endl;
cin>>choice ;
switch(choice){
	case 0 : cout<<"Tata"<<endl;
		break ;
	case 1 :cout<<"Enter the no. of value you want to enter :"<<endl ;
		cin>>data;
		cout<<"Enter value space seperated : " ;
		for(int i=0;i<data;i++)
			cin>>treeData[i];
		root = enterValue(root,treeData,data);
		break;
	case 2 :inOrder(root);
		cout<<endl ;
		break;
	case 3 :postOrder(root);
		cout<<endl ;
		break;
	case 4 :preOrder(root);
		cout<<endl ;
		break ;
	case 5 :levelOrder(root);
		cout<<endl ;
		break;
	case 6 :spiralLevelOrder(root);
		cout<<endl ;
                break;
	case 7 :reverseOrder(root);
                cout<<endl ;
                break ;
	case 8 :cout<<"Enter the key to find successor :" ;
                cin>>data;
                inorderSuccessor(root,data);
		cout<<"\n" ;
		break ;
	case 9 :diagonalTraversal(root,diaMap,0);
		itr = diaMap.begin();
		while(itr != diaMap.end()){
			for(it2 = (*itr).second.begin(); it2 != (*itr).second.end(); ++it2)
    				cout << *it2 << " ";
			itr++;
			cout<<"\n" ;
		}
		cout<<"\n" ;
                break ;
	case 10:boundaryTraversal(root);
		cout<<endl ;
		break ;
	case 11:cout<<"No. of nodes in tree : "<<countNoOfNodes(root)<<endl;
		break;
	case 12:cout<<"No. of leafs :"<<countNoOfLeafs(root)<<endl ;
		break;
	case 13:cout<<"No.of non leafs :"<<countNoOfNonLeafs(root)<<endl;
		break;
	case 14:cout<<"No. of full nodes :"<<countNoOfFullNodes(root)<<endl;
		break;
	case 15:cout<<"Height of the tree :"<<findHeight(root)<<endl ;
		break;
	case 16:cout<<"\nEnter the no. you want to delete :" ;
		cin>>data;
		deleteNode(root,data);
		break;
	case 17:cout<<"\nCompleteTree [1/0] : "<<isCompleteTree(root)<<endl ;
		break;
	case 18:cout<<"\nBST or NOT ? : "<<isBST(root,NULL,NULL)<<endl ;
		break;
	case 19:cout<<"Enter value [1:2] : " ;
		cin>>ch1>>ch2;
		temp = findLowestCommonAncestor(root,ch1,ch2);
		if(!temp)
			cout<<"Root is null."<<endl;
		else
			cout<<"Lowest common node : "<<temp->data<<endl;
		break;
	case 20:cout<<"Enter range [r1:r2] :";
		cin>>ch1>>ch2;
		printBSTElementInGivenRange(root,ch1,ch2);
		cout<<endl;
		break;
	case 21: cout<<"Enter value of k : "
		cin>>ch1;
		deleteValAboveK(root,ch1);
		break;
	default : cout<<"Invalid entry sucker."<<endl ;
}
}while(choice != 0);

return 0;
}
