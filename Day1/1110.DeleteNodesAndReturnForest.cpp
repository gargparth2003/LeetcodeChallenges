
class Solution {
    vector<TreeNode*>res;
    unordered_set<int>st;
    void deleteNode(TreeNode* &root){
        if(root){
            deleteNode(root->left);
            deleteNode(root->right);
            if(st.find(root->val)!=st.end()){
                if(root->left) res.push_back(root->left);
                if(root->right) res.push_back(root->right);
                root=NULL;
                delete root;
            }
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        deleteNode(root);
        if(root)res.push_back(root);
        return res;
    }
};



//Questions

// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.

 

// Example 1:


// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
// Example 2:

// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]