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
        if (!root) return "#!";
        string res = to_string(root->val) + "!";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = split(data, '!');
        return recoverPreorder(q);
    }
    // Recover
    TreeNode* recoverPreorder(queue<string>& q) {
        if (q.empty()) return NULL;
        string f = q.front(); q.pop();
        if (f == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(f));
        root->left = recoverPreorder(q);
        root->right = recoverPreorder(q);
        return root;
    }
    // Split
    queue<string> split(string data, char delimiter) {
        string temp;
        stringstream ss(data);
        queue<string> res;
        while (getline(ss, temp, delimiter)) res.push(temp);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));