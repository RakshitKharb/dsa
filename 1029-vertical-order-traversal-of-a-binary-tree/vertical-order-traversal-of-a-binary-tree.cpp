class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes grouped by vertical lines, sorted by level and value
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // Queue stores {node, {vertical line, level}}

        // Initialize the queue with the root node
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second.first;  // Vertical line
            int level = it.second.second;  // Depth level

            // Insert the node into the map
            nodes[line][level].insert(node->val);

            // Add left and right children to the queue with updated line and level
            if (node->left != NULL) {
                q.push({node->left, {line - 1, level + 1}});
            }
            if (node->right != NULL) {
                q.push({node->right, {line + 1, level + 1}});
            }
        }

        // Compile the result from the map
        vector<vector<int>> ans;
        for (auto line : nodes) {
            vector<int> col;
            for (auto level : line.second) {
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
