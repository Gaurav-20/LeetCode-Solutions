class Solution {
    public int numSteps(String s) {
        int steps = 0;
        char[] array = s.toCharArray();
        for (int i = array.length - 1; i > 0; i--) {
            steps++;
            if (array[i] == '1') {
                boolean isFound = false;
                for (int j = i; j > 0; j--) {
                    if (array[j] == '1') {
                        array[j] = '0';
                    } else {
                        array[j] = '1';
                        isFound = true;
                        break;
                    }
                }
                if (!isFound) {
                    steps++;
                }
                i++; 
            }
        }
        return steps;
    }
}