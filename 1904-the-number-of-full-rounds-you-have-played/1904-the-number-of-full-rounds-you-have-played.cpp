class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int login = 60 * stoi(loginTime.substr(0, 2)) + stoi(loginTime.substr(3));
        int logout = 60 * stoi(logoutTime.substr(0, 2)) + stoi(logoutTime.substr(3));
        if (login > logout) {
             // If logoutTime is earlier than loginTime, add 24 hours to logoutTime
            logout += 60 * 24;
        }
        return max(0, logout / 15 - (login + 14) / 15);
    }
};