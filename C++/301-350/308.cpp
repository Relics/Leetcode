class Node {
public:
    int start, end, sum;
    Node* left;
    Node* right;
    Node(int start, int end) {
        this->start = start;
        this->end = end;
        sum = 0;
        left = right = NULL;
    }
};

class NumMatrix {
private:
    vector<Node*> roots;
    int m, n;
public:
    Node* build(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        Node* root = new Node(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        } else {
            int mid = start + (end-start)/2;
            root->left = build(nums, start, mid);
            root->right = build(nums, mid+1, end);
            root->sum = root->left->sum + root->right->sum;
            return root;
        }
    }
    NumMatrix(vector<vector<int>> &matrix) {
        m = (int)matrix.size();
        n = m ? (int)matrix[0].size() : 0;
        if (n == 0) return;
        for (int i=0; i<m; ++i) {
            Node* root = build(matrix[i], 0, n-1);
            roots.push_back(root);
        }
    }

    void update(int row, int col, int val) {
        update(col, val, roots[row]);
    }
    int update(int i, int val, Node* root) {
        if (!root) return 0;
        int diff = 0;
        if (root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (i > mid) {
                diff = update(i, val, root->right);
            } else if (i <= mid) {
                diff = update(i, val, root->left);
            }
            root->sum = root->sum + diff;
            return diff;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i=row1; i<=row2; ++i) {
            ans += sumRange(col1, col2, roots[i]);
        }
        return ans;
    }
    int sumRange(int i, int j, Node* root) {
        if (!root) return 0;
        if (root->start == i && root->end == j) {
            return root->sum;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (i > mid) {
                return sumRange(i, j, root->right);
            } else if (j <= mid) {
                return sumRange(i, j, root->left);
            } else {
                return sumRange(i, mid, root->left) + sumRange(mid+1, j, root->right);
            }
        }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);