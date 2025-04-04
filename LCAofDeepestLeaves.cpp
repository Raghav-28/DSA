// PROBLEM LEETCODE 1123 && 865     SAME 

//APPROACH-1
class Solution {
    public:
        unordered_map<int,int>mp;
        int maxD =0;
    
        void depth(TreeNode* root, int d){
            if(root == NULL) return ;
    
            maxD = max(maxD,d);
            mp[root->val] = d;
            depth(root->left, d+1);
            depth(root->right, d+1);
        }
        TreeNode* LCA(TreeNode* root){
            if(root == NULL || mp[root->val]== maxD){
                return root;
            }
            TreeNode* l = LCA(root->left);
            TreeNode* r = LCA(root->right);
    
            if(l && r){
                return root;
            }
            return l != NULL ? l: r;
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            depth(root,0);
            return LCA(root);
        }
    };

// APPROACH-2
class Solution {
    public:
        
        pair<int , TreeNode*> solve(TreeNode* root){
            if(root ==NULL) return {0,NULL};
    
            auto l = solve(root->left);
            auto r = solve(root->right);
    
            if(l.first == r.first){
                return {l.first+1,root};
            }
            else if(l.first > r.first){
                return {l.first+1, l.second};
            }
            else{
                return {r.first+1, r.second};
            }
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return solve(root).second;
        }
    };