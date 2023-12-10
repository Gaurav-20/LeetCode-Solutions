class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        List<Integer> res = new ArrayList<>();
        for (int asteroid : asteroids) {
            if (res.size() == 0) {
                res.add(asteroid);
            } else if (asteroid < 0 && res.get(res.size() - 1) > 0) {
                int asteroid1 = res.get(res.size() - 1);
                int asteroid2 = Math.abs(asteroid);
                res.remove(res.size() - 1);
                if (asteroid1 == asteroid2) {
                    continue;
                } else if (asteroid1 > asteroid2) {
                    res.add(asteroid1);
                } else {
                    boolean destroyed = false;
                    while (res.size() > 0 && sign(res.get(res.size() - 1)) != sign(asteroid)) {
                        if (res.get(res.size() - 1) < asteroid2) {
                            res.remove(res.size() - 1);
                        } else if (res.get(res.size() - 1) > asteroid2) {
                            destroyed = true;
                            break;
                        } else {
                            res.remove(res.size() - 1);
                            destroyed = true;
                            break;
                        }
                    }
                    if (!destroyed) {
                        res.add(asteroid);
                    }
                }
            } else {
                res.add(asteroid);
            }
        }
        int[] result = new int[res.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = res.get(i);
        }
        return result;
    }
    
    public int sign(int number) {
        return (number < 0) ? -1 : 1;
    }
}