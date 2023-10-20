/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st; // Stack to hold the nested integers
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Push all elements of the input list onto the stack in reverse order
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int result = st.top().getInteger();
        st.pop();
        return result;
    }
    
    bool hasNext() {
        // Keep popping until we find an integer or the stack is empty
        while (!st.empty()) {
            if (st.top().isInteger()) {
                return true;
            }
            vector<NestedInteger> nestedList = st.top().getList();
            st.pop();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                st.push(nestedList[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */