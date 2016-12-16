// Reference 1: http://www.cnblogs.com/boring09/p/4231906.html
// Reference 2: https://ask.julyedu.com/question/7291
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int size = (int)heights.size();
        stack<int> indexs;
        int ans = 0;
        for (int i=0; i<size; ++i) {
            if (indexs.empty()) {
                indexs.push(i);
            } else {
                if (heights[i] >= heights[indexs.top()]) {
                    indexs.push(i);
                } else {
                    while (!indexs.empty() && heights[i] < heights[indexs.top()]) {
                        int tempIndex = indexs.top();
                        indexs.pop(); 
                        int width = indexs.empty() ? i : i - (indexs.top() + 1);
                        ans = max(ans, heights[tempIndex] * width);
                    }
                    indexs.push(i);
                }
            }
        }
        return ans;
    }
};