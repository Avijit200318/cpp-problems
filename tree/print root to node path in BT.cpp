// // print root to node path in BT

// Problem statement
// You are given a binary tree with ‘N’ number of nodes and a node ‘X’. Your task is to print the path from the root node to the given node ‘X’.

// A binary tree is a hierarchical data structure in which each node has at most two children.

bool getPath(TreeNode<int> *root, vector<int> &ans, int x){
	if(root == nullptr) return false;

	ans.push_back(root->data);
	if(root->data == x){
		return true;
	}

	if(getPath(root->left, ans, x)){
		return true;
	}

	if(getPath(root->right, ans, x)){
		return true;
	}

	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	if(root == nullptr) return ans;

	getPath(root, ans, x);
	return ans;
}
