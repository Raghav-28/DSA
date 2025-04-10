//LEETCODE PROBLEM 199
//APPROACH -1 BFS{LEVEL ORDER TRAVERSAL}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            if(root== NULL) return {};
            queue<TreeNode*> que;
    
            vector<int> result;
            que.push(root);
    
            while(!que.empty()){
                int n = que.size();
                TreeNode* node = NULL;
    
                while(n--){
                    node = que.front();
                    que.pop();
    
                    if(node->left != NULL){
                        que.push(node->left);
                    }
                    if(node->right != NULL){
                        que.push(node->right);
                    }
                }
                result.push_back(node->val);
    
            }
            return result;
        }
    };
//APPROACH-2 DFS{RECURSION}
class Solution {
    public:
    
        void preOrder(TreeNode* root, int level, vector<int>& result){
            if(root == NULL){
                return ;
            }
            if(result.size() < level){
                result.push_back(root->val);
            }
            preOrder(root->right , level+1, result);
            preOrder(root->left , level+1, result);
        }
    
        vector<int> rightSideView(TreeNode* root) {
            
            vector<int> result ;
            preOrder(root,1,result);
    
            return result;
    
    
        }
    };