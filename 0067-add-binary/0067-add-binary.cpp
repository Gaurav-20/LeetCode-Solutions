class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) {
            return addBinary(b, a);
        }
    
        int diff = b.size() - a.size();
        string padding;
        for (int i = 0; i < diff; i++) {
            padding.push_back('0');
        }
        a = padding + a;

        string res;
        char carry = '0';    
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == '1' && b[i] == '1') {
                if (carry == '1') {
                    res.push_back('1');
                } else {
                    res.push_back('0');
                }
                carry = '1';
            } else if (a[i] == '0' && b[i] == '0') {
                if (carry == '1') {
                    res.push_back('1');
                } else {
                    res.push_back('0');
                }
                carry = '0';
            } else if (a[i] != b[i]) {
                if (carry == '1') {
                    res.push_back('0');
                    carry = '1';
                } else {
                    res.push_back('1');
                    carry = '0';   
                }       
            }
        }
        if (carry == '1') {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        int index = 0;
        while (index + 1 < res.size() && res[index] == '0') {
            index++;
        }
        return res.substr(index);
    }
};