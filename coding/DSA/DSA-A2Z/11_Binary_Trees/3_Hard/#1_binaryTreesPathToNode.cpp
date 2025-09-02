#include<bits/stdc++.h>
using namespace std;


// path from root to a given node
// https://www.naukri.com/code360/problems/path-in-a-tree_3843990

template <typename T = int>
class TreeNode
{
	public:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~TreeNode()
	{
		if (left != NULL)
		{
			delete left;
		}
		if (right != NULL)
		{
			delete right;
		}
	}
};


// inorder traversal
bool getPath(TreeNode<int> *root ,  int x , vector<int> &res ){
    
    if(root==NULL){
        return false;
    }
    
    res.push_back(root->data);

    if(root->data == x){
        return true;
    }

    if( getPath(root->left , x , res) || getPath(root->right , x , res)){
        return true;
    }

    res.pop_back();

    return false;

}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> res;
    getPath(root , x , res );
	return res;
}
