class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> validIPAddresses;
        // each of a b c d determine the length of each ip address partition
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == s.size()) {
                            // extract each partition value
                            int first = stoi(s.substr(0, a));
                            int second = stoi(s.substr(a, b));
                            int third = stoi(s.substr(a + b, c));
                            int fourth = stoi(s.substr(a + b + c, d));
                            if (first <= 255 && second <= 255 && third <= 255 && fourth <= 255) {
                                string ipAddress;
                                ipAddress += to_string(first) + ".";
                                ipAddress += to_string(second) + ".";
                                ipAddress += to_string(third) + ".";
                                ipAddress += to_string(fourth);
                                if (ipAddress.size() == s.size() + 3) {
                                    validIPAddresses.push_back(ipAddress);
                                }
                            }
                        }
                    }
                }
            }
        }
        return validIPAddresses;
    }
};