class FoodRatings {

	private Map<String, String> foodToCuisine;
	private Map<String, Integer> foodToRating;
	private Map<String, TreeSet<RatingAndFood>> cuisineToRatingAndFoodSet;

	public FoodRatings(final String[] foods, final String[] cuisines, final int[] ratings) {
		this.foodToCuisine = new HashMap<>();
		this.foodToRating = new HashMap<>();
		this.cuisineToRatingAndFoodSet = new HashMap<>();

		for (int i = 0; i < foods.length; i++) {
			this.foodToCuisine.put(foods[i], cuisines[i]);
			this.foodToRating.put(foods[i], ratings[i]);
			if (this.cuisineToRatingAndFoodSet.get(cuisines[i]) == null) {
				this.cuisineToRatingAndFoodSet.put( cuisines[i], new TreeSet<>() );
			}
			this.cuisineToRatingAndFoodSet.get(cuisines[i]).add(new RatingAndFood(ratings[i], foods[i]));
		}
	}

	public void changeRating(final String food, final int newRating) {
		final String cuisine = this.foodToCuisine.get(food);
		final TreeSet<RatingAndFood> ratingAndFoodSet = this.cuisineToRatingAndFoodSet.get(cuisine);
		ratingAndFoodSet.remove(new RatingAndFood(this.foodToRating.get(food), food));
		ratingAndFoodSet.add(new RatingAndFood(newRating, food));
		this.foodToRating.put(food, newRating);
	}

	public String highestRated(final String cuisine) {
		final RatingAndFood ratingAndFood = this.cuisineToRatingAndFoodSet.get(cuisine).first();
		return ratingAndFood.getFood();
	}

	static class RatingAndFood implements Comparable<RatingAndFood> {
		private int rating;
		private String food;

		public RatingAndFood(final int rating, final String food) {
			this.rating = rating;
			this.food = food;
		}

		public String getFood() {
			return this.food;
		}

		public int compareTo(final RatingAndFood base) {
			return (this.rating != base.rating)? -(this.rating - base.rating) : this.food.compareTo(base.food);
		}
	}
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */