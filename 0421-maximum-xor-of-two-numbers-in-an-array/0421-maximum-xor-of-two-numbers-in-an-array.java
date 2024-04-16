class Trie {
    public Trie[] child;
    
    public Trie() {
        child = new Trie[2];
        child[0] = null;
        child[1] = null;
    }
};

class Solution {
    public Trie root;
    
    public int findMaximumXOR(int[] nums) {
        root = new Trie();
        for (int num : nums) {
            insert(num);
        }
        int result = 0;
        for (int num : nums) {
            result = Math.max(result, findMaxXor(num));
        }
        return result;
    }
    
    public int[] getBits(int num) {
        int[] bits = new int[32];
        for (int i = 0; i < 32; i++) {
            bits[i] = num % 2;
            num /= 2;
        }
        return bits;
    }
    
    public void insert(int num) {
        int[] bits = getBits(num);
        Trie ptr = root;
        for (int i = 31; i >= 0; i--) {
            if (ptr.child[bits[i]] == null) {
                ptr.child[bits[i]] = new Trie();
            }
            ptr = ptr.child[bits[i]];
        }
    }
    
    public int findMaxXor(int num) {
        int result = 0;
        int[] bits = getBits(num);
        Trie ptr = root;
        for (int i = 31; i >= 0; i--) {
            if (ptr.child[1 - bits[i]] != null) {
                result += (1 << i);
                ptr = ptr.child[1 - bits[i]];
            } else {
                ptr = ptr.child[bits[i]];
            }
        }
        return result;
    }
}