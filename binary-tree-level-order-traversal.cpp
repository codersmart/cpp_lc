/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        order(root, vv, 0);
        return vv;
    }
    void order(TreeNode* n, vector<vector<int>> &vv, int depth)
    {
        if(n != NULL) {
            if(vv.size() < depth + 1){
                vector<int> x;
                vv.push_back(x);
            }
            vv[depth].push_back(n->val);
            
            if(n->left != NULL){
                order(n->left, vv, depth + 1);
            }
            if(n->right != NULL);
            {
                order(n->right, vv, depth + 1);
            }
            
        }
    }
};
