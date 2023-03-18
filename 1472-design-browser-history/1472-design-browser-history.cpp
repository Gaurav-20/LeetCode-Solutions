class BrowserHistory {
    vector<string> history;
    int currIndex;
public:
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currIndex = 0;
    }
    
    void visit(string url) {
        while (history.size() > currIndex + 1) {
            history.pop_back();
        }
        history.push_back(url);
        currIndex++;
    }
    
    string back(int steps) {
        currIndex = max(0, currIndex - steps);
        return history[currIndex];
    }
    
    string forward(int steps) {
        currIndex = min((int) history.size() - 1, currIndex + steps);
        return history[currIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */