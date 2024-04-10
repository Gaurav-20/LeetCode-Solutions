class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int[] result = new int[deck.length];
        Arrays.sort(deck);
        Arrays.fill(result, 0);
        int diffBetweenCurrentAndNextIndex = 2;
        int resultIndex = 0;
        int deckIndex = 0;

        for (deckIndex = 0; deckIndex < deck.length; deckIndex++) {
            if (result[resultIndex] == 0) {
                result[resultIndex] = deck[deckIndex];
            }

            if (resultIndex + diffBetweenCurrentAndNextIndex > deck.length - 1) {
                diffBetweenCurrentAndNextIndex *= 2;
                resultIndex += diffBetweenCurrentAndNextIndex - (deck.length - 1 - resultIndex);
            } else {
                resultIndex += diffBetweenCurrentAndNextIndex;
            }
            resultIndex %= deck.length;
        }

        for (int i = 0; i < result.length; i++) {
            if (result[i] == 0) {
                result[i] = deck[deckIndex - 1];
            }
        }
        return result;
    }
}