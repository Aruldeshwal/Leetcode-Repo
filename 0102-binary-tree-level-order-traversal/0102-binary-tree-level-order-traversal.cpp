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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push({root, 1});
        while(!q.empty()) {
            TreeNode* ele = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            if(ele -> left) q.push({ele -> left, currLevel + 1});
            if(ele -> right) q.push({ele -> right, currLevel + 1});
            vector<int> res;
            res.push_back(ele -> val);
            while(q.front().second == currLevel) {
                TreeNode* newEle = q.front().first;
                int level = q.front().second;
                q.pop();
                if(newEle -> left) q.push({newEle -> left, level + 1});
                if(newEle -> right) q.push({newEle -> right, level + 1});
                res.push_back(newEle -> val);
            }
            ans.push_back(res);
        }
        return ans;

    }
};