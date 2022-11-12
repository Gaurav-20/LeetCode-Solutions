class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    bool even = true;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (even) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if (even) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */