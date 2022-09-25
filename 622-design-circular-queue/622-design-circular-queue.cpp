class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    // reset is the mark when the queue is empty
    // to differentiate from queue is full
    // because in both conditions (tail == head) stands
    bool reset;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        reset = true;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (head == tail && reset) {
            reset = false;
        }
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % data.size();
        if (head == tail && !reset) {
            reset = true;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(tail + data.size() - 1) % data.size()];
    }
    
    bool isEmpty() {
        return (tail == head && reset);
    }
    
    bool isFull() {
        return (tail == head && !reset);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */