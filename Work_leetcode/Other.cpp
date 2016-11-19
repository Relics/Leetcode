class Solution {
public:
    int minTransfers(vector<vector<int>>& trans) {
        N = 0; ans = 0;
        set<int> id;
        for (auto tran: trans) id.insert(tran[0]), id.insert(tran[1]);
        N = max((int)id.size(), *id.rbegin() + 1);
        
        vector<vector<int>> graph(N, vector<int>(N, 0));
        for (auto tran: trans) {
            
            graph[tran[0]][tran[1]] += tran[2];
            //graph[tran[1]] += graph[tran[2]];
        }
        minCashFlow(graph);
        return ans;
    }
    
    
int getMin(vector<int> arr)
{
    int minInd = 0;
    for (int i=1; i<arr.size(); i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
 
int getMax(vector<int> arr)
{
    int maxInd = 0;
    for (int i=1; i<arr.size(); i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
 
int minOf2(int x, int y)
{
    return (x<y)? x: y;
}
 
void minCashFlowRec(vector<int> amount)
{
    int mxCredit = getMax(amount), mxDebit = getMin(amount);
 
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;
 
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
 
    ++ ans;
    minCashFlowRec(amount);
}
 
void minCashFlow(vector<vector<int>> graph)
{
    vector<int> amount(N, 0);
 
    for (int p=0; p<N; p++)
       for (int i=0; i<N; i++)
          amount[p] += (graph[i][p] -  graph[p][i]);
 
    minCashFlowRec(amount);
}

private:
    int N;
    int ans;
};