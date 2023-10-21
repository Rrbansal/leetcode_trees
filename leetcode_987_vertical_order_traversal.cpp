class Solution {
public:
queue<pair<TreeNode*,pair<int,int>>>q;
map<int,map<int,multiset<int>>>m; // multiset stores value in oinc order
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto cell=q.front();
            q.pop();
            TreeNode* node=cell.first;
            int col=cell.second.first;
            int row=cell.second.second;
            m[col][row].insert(node->val);
            if(node->left) q.push({node->left,{col-1,row+1}});
            if(node->right) q.push({node->right,{col+1,row+1}});

        }
        vector<vector<int>>final;
        for(auto x:m)
        {
            vector<int>temp;
            for(auto t:x.second)
            {
                temp.insert(temp.end(),t.second.begin(),t.second.end());
            }
            final.push_back(temp);
        }
        return final;
        
    }
};
