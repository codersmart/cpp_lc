#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:

    struct CNT{
        int count; // leave nodes
        int height;
        CNT(int c, int h):count(c), height(h){}
    };
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        auto leftmost = root;
        int lmh = 0;
        int rmh = 0;
        auto rightmost = root; 
        while(leftmost->left != NULL){leftmost = leftmost->left; lmh ++;}
        while(rightmost->right != NULL){rightmost = rightmost->right; rmh ++;}        
        if(lmh == rmh) return pow(2, (rmh+1)) - 1;
        
        CNT cnt(0, rmh);
        if(root != NULL){
            count(root, cnt, 0);
        }
        return cnt.count + (pow(2, (cnt.height + 1)) - 1);
    }
    // Count leave nodes
    void count(TreeNode* node, CNT & cnt, int currHeight)
    {
        if(node == NULL) return;
        if(currHeight == cnt.height){
            if(node->right != NULL){
                cnt.count += 2;
            }else if(node->left != NULL){
                cnt.count ++;
            }
            return;
        }else{
            if(node->left != NULL) count(node->left, cnt, currHeight + 1);
            if(node->right!= NULL) count(node->right, cnt, currHeight + 1);
        }
        
    }
};
int mainx()
{
    TreeNode * p = new TreeNode(1);
    class Solution s;
    cout << s.countNodes(p);
    return 0;
}
