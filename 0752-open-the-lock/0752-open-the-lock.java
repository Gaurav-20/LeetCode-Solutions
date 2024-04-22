class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        String start = "0000";
        for (String end : deadends) {
            if (end.equals(start)) {
                return -1;
            }
            visited.add(end);
        }
        queue.offer(start);
        visited.add(start);
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                String str = queue.poll();
                if (str.equals(target)) {
                    return steps;
                }
                StringBuilder curr = new StringBuilder(str);
                for (int i = 0; i < 4; i++) {
                    char ch = curr.charAt(i);
                    char dec = (ch == '0') ? '9' : (char) (ch - 1);
                    curr.setCharAt(i, dec);
                    String decStr = curr.toString();
                    if (!visited.contains(decStr)) {
                        visited.add(decStr);
                        queue.offer(decStr);
                    }
                    char inc = (ch == '9') ? '0' : (char) (ch + 1);
                    curr.setCharAt(i, inc);
                    String incStr = curr.toString();
                    if (!visited.contains(incStr)) {
                        visited.add(incStr);
                        queue.offer(incStr);
                    }
                    curr.setCharAt(i, ch);
                }
            }
            steps += 1;
        }
        return -1;
    }
}