class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int maxLen = Math.max(v1.length, v2.length);
        for (int i = 0; i < maxLen; i++) {
            int revisionV1 = 0, revisionV2 = 0;
            if (i < v1.length) {
                revisionV1 = Integer.valueOf(v1[i]);
            }
            if (i < v2.length) {
                revisionV2 = Integer.valueOf(v2[i]);
            }
            if (revisionV1 < revisionV2) {
                return -1;
            }
            if (revisionV1 > revisionV2) {
                return 1;
            }
        }
        return 0;
    }
}