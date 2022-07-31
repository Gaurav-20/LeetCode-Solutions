#define MAXN 30005
int tree[MAXN * 4];
int n;

void buildTree(vector<int>& nums, int i, int start, int end) {
    if (start == end) {
        tree[i] = nums[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(nums, 2 * i + 1, start, mid);
    buildTree(nums, 2 * i + 2, mid + 1, end);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void updateTree(int i, int start, int end, int index, int val) {
    if (start == end) {
        tree[i] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (index <= mid) {
        updateTree(2 * i + 1, start, mid, index, val);
    } else {
        updateTree(2 * i + 2, mid + 1, end, index, val);
    }
    tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
}

int findSumTree(int i, int start, int end, int left, int right) {
    if (left <= start and right >= end) {
        return tree[i];
    }
    if (left > end or right < start) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    return findSumTree(2 * i + 1, start, mid, left, right) 
        + findSumTree(2 * i + 2, mid + 1, end, left, right);
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        buildTree(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return findSumTree(0, 0, n - 1, left, right);    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */