/**
 Time = O(4^n) or O(n*Cn) where Cn is a catalan number
 Space = O(4^n)
 **/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> allTrees;
        
        if(start>end){
            allTrees.push_back(NULL);
            return allTrees;
        }
        
        for(int i = start; i<=end; i++){
            vector<TreeNode*> leftTrees = helper(start, i-1);
            vector<TreeNode*> rightTrees = helper(i+1, end);
            
            for(auto leftNode:leftTrees){
                for(auto rightNode: rightTrees){
                    TreeNode* curTree = new TreeNode(i);
                    curTree->left = leftNode;
                    curTree->right = rightNode;
                    allTrees.push_back(curTree);
                }
            }
            
        }
        return allTrees;
    }
};
