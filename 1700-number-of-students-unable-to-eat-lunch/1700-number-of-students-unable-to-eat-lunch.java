class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int studentsWhoAte = 0;
        Queue<Integer> queue = new LinkedList<>();
        for (int student : students) {
            queue.offer(student);
        }
        int sandwichPtr = 0;
        while (!queue.isEmpty()) {
            boolean isTakenInThisRound = false;
            int size = queue.size();
            while (size-- > 0) {
                Integer curr = queue.poll();
                if (curr == sandwiches[sandwichPtr]) {
                    studentsWhoAte += 1;
                    sandwichPtr += 1;
                    isTakenInThisRound = true;
                } else {
                    queue.offer(curr);
                }
            }
            if (!isTakenInThisRound) {
                break;
            }
        }
        return students.length - studentsWhoAte;
    }
}