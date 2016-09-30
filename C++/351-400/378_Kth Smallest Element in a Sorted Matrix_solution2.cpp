class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int size = (int) matrix.size();
        int pushNum=0;
        priority_queue<int> pq;
        for (int i=0; i < size; ++i){
            for (int j=0; j < size; ++j){
                if (pushNum < k){
                    pq.push(matrix[i][j]);
                    ++ pushNum;
                }else{
                    if (matrix[i][j] < pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    } else {
                        break;
                    }
                }
            }
        }
        return pq.top();
    }
};