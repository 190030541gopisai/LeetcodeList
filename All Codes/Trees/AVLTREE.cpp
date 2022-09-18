// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


 // } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{

	int getHeight(Node *p){
		if(p == NULL){
			return 0;
		}
		int lh = 0, rh = 0;
		if(p->left){
			lh = p->left->height;
		}
		if(p->right){
			rh = p->right->height;
		}
		return 1 + max(lh, rh);
	}

	int balanceFactor(Node *p){
		if(p == NULL){
			return 0;
		}
		int lh = 0, rh = 0;
		if(p->left){
			lh = p->left->height;
		}
		if(p->right){
			rh = p->right->height;
		}
		return lh-rh;
	}
	Node * LLRotation(Node *p){
		if(p == NULL){
			return NULL;
		}
		Node *pl = p->left;
		Node *plr = pl->right;

		pl->right = p;
		p->left = plr;

		p->height = getHeight(p);
		pl->height = getHeight(pl);

		return pl;
	}

	Node *RRRotation(Node *p){
		if(p == NULL){
			return NULL;
		}
		Node *pr = p->right;
		Node *prl = pr->left;

		pr->left = p;
		p->right = prl;

		p->height = getHeight(p);
		pr->height = getHeight(pr);

		return pr;
	}
	Node * LRRotation(Node *p){
		p->left = RRRotation(p->left);
		return LLRotation(p);
	}
	Node* RLRotation(Node *p){
		p->right = LLRotation(p->right);
		return RRRotation(p);
	}
  public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* root, int data)
    {
        //Your code here
        if(root == NULL){
        	return new Node(data);
        }
        if(data < root->data){
        	root->left = insertToAVL(root->left, data);
        }
        if(data >= root->data){
        	root->right = insertToAVL(root->right, data);
        }

        root->height = getHeight(root);

        if(balanceFactor(root) == 2 and balanceFactor(root->left) == 1){
        	return LLRotation(root);
        }
        if(balanceFactor(root) == 2 and balanceFactor(root->left) == -1){
        	return LRRotation(root);
        } 
        if(balanceFactor(root) == -2 and balanceFactor(root->right) == -1){
        	return RRRotation(root);
        }
        if(balanceFactor(root) == -2 and balanceFactor(root->right) == 1){
        	return RLRotation(root);
        }
        return root;
    }
};

// { Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        // cout << n << endl;
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}  // } Driver Code Ends