class Solution {
    public int numberOfBeams(String[] bank) {
        int n = bank.length;
        int[] deviceCount = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < bank[i].length(); j++) {
                char ch = bank[i].charAt(j);
                if (ch == '1') {
                    deviceCount[i]++;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (deviceCount[i] == 0) {
                continue;
            }
            int currentRowDevices = deviceCount[i];
            while (i + 1 < n && deviceCount[i + 1] == 0) {
                i++;
            }
            if (i + 1 < n) {
                result += currentRowDevices * deviceCount[i + 1];
            }
        }
        return result;
    }
}