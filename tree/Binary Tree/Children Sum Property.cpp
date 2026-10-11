// Children Sum Property

// Problem statement
// Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

// A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

// Note :
//  1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
//  2. You can not change the structure of the original binary tree.
//  3. A binary tree is a tree in which each node has at most two children.      
//  4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.

void changeTree(BinaryTreeNode < int > * root) {
    if(root == nullptr) return;

    int sum = 0;
    if(root->left){
        sum += root->left->data;
    }

    if(root->right){
        sum += root->right->data;
    }

    // after left and right node sum we are checking if sum is bigger than root value then update it
    if(sum >= root->data){
        root->data = sum;
    }
    // if not then change there child value to root value.
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    // move left and right
    changeTree(root->left);
    changeTree(root->right);


    // afther came back from updating child element now its time to udpate the root again. agian sum left and right child then update the root value if
    // it has left or right node
    int temp = 0;

    if(root->left) temp += root->left->data;
    if(root->right) temp += root->right->data;

    if(root->left || root->right) root->data = temp;
}  