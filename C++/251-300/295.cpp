class MedianFinder {
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxheap.empty() || (maxheap.top() > num)) maxheap.push(num);
        else minheap.push(num);
        // rebalance
        if ((int)maxheap.size() > (int)minheap.size()+1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if ((int)maxheap.size()+1 < (int)minheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if ((int)maxheap.size() == (int)minheap.size()) return maxheap.empty() ? 0 : (maxheap.top() + minheap.top()) / 2.0;
        else return (int)maxheap.size() > (int)minheap.size() ? maxheap.top() : minheap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();