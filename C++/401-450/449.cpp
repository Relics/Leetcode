/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "!";
        string res = to_string(root->val) + "!";
        if (root->left) res += serialize(root->left);
        if (root->right) res += serialize(root->right);
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = split(data, '!');
        return recoverPreorder(q, INT_MAX, INT_MIN);
    }
    
    // recover
    TreeNode* recoverPreorder(queue<string>& q, int maxVal, int minVal) {
        if (q.empty()) return NULL;
        string f = q.front();
        if (f == "") return NULL;
        int temp = stoi(f);
        if (temp > maxVal || temp < minVal) return NULL;
        q.pop();
        TreeNode* root = new TreeNode(temp); 
        root->left = recoverPreorder(q, temp, minVal);
        root->right = recoverPreorder(q, maxVal, temp);
        return root;
    }
    
    // Split
    queue<string> split(string a, char delimiter) {
        string temp;
        queue<string> res;
        stringstream ss(a);
        while (getline(ss, temp, delimiter)) res.push(temp);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));