class Solution {
    public int minOperations(String[] logs) {
        int folderDepth = 0;
        for (String log : logs) {
            if (log.equals("./")) {
                continue;
            } else if (log.equals("../")) {
                folderDepth = Math.max(folderDepth - 1, 0);
            } else {
                folderDepth += 1;
            }
        }
        return folderDepth;
    }
}