class Robot {
    public int index;
    public int position;
    public int health;
    public char direction;
    
    Robot(int index, int position, int health, char direction) {
        this.index = index;
        this.position = position;
        this.health = health;
        this.direction = direction;
    }
}

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        List<Robot> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new Robot(i, positions[i], healths[i], directions.charAt(i)));
        }
        Collections.sort(list, (r1, r2) -> r1.position - r2.position);
        Stack<Robot> stack = new Stack<>();
        for (Robot r2 : list) {
            while (!stack.isEmpty() && stack.peek().direction == 'R' && r2.direction == 'L') {
                Robot r1 = stack.pop();
                if (r1.health > r2.health) {
                    r2.direction = 'X';
                    r1.health -= 1;
                    stack.push(r1);
                } else if (r1.health < r2.health) {
                    r2.health -= 1;
                } else {
                    r2.direction = 'X';
                    break;
                }
            }
            if (r2.direction != 'X') {
                stack.push(r2);
            }
        }
        int[] res = new int[n];
        while (!stack.isEmpty()) {
            Robot robot = stack.pop();
            res[robot.index] = robot.health;
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (res[i] > 0) {
                result.add(res[i]);
            }
        }
        return result;
    }
}