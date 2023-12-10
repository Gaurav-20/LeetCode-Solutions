class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        List<Integer> flowerBed = new ArrayList<>();
        flowerBed.add(0);
        for (int i = 0; i < flowerbed.length; i++) {
            flowerBed.add(flowerbed[i]);
        }
        flowerBed.add(0);
        int len = flowerBed.size();
        for (int i = 1; i < len - 1; i++) {
            if (flowerBed.get(i - 1) + flowerBed.get(i) + flowerBed.get(i + 1) == 0) {
                n--;
                i++;
            }
        }
        return n <= 0;
    }
}