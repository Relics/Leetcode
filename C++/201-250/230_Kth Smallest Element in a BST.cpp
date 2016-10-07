#include <iostream>
#include <bitset>
#include <ctime>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cctype> // For the isDigit
#include <stack>
#include <sstream> // For the change between int and string or any type
//int a=10;
//stringstream ss;
//ss<<a;
//return ss.str();

// typedef long long ll;

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int index;
    int ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        index = 0;
        ans = 0;
        solve(root, index, k);
        return ans;
    }
    void solve(TreeNode* root, int index, int k) {
        if (root == NULL) {
            return;
        } else if(index == k-1) {
            ans = root->val;
        } else {
            solve(root->left, ++index, k);
            if ()
        }
    }
    
};

int main(){
    Solution a;

    return 0;
}
