// duplicate sub tree in a binary tree
class Solution {
  public:
    unordered_map <string,int> subtree;
    string checkDup(Node* head){
        if(head == NULL)
        {
            return "";
        }
        string left = checkDup(head->left);
        string right = checkDup(head->right);
        string s = to_string(head->data)+left+right;
        if(left != "" || right != "")
        {
            if(subtree.find(s) != subtree.end())
            {
               subtree[s]++; 
            }
            else{
                subtree[s]=1;
            }
        }
        return s;
    }
    int dupSub(Node *root) {
         checkDup(root);
         for(const auto it : subtree)
         {
             if(it.second >= 2 && it.first != "")
             {
                 return 1;
             }
         }
         return 0;
    
             
         
    }
};
