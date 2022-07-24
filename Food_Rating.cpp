/*
    problem : Design a Food Rating System
    url : https://leetcode.com/contest/weekly-contest-303/problems/design-a-food-rating-system/
    discuss : https://leetcode.com/problems/design-a-food-rating-system/discuss/2324669/Three-Maps
*/

// Input
// ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
// [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
// Output
// [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_ratings;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            cuisine_ratings[cuisines[i]].insert({ -ratings[i], foods[i] });
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    void changeRating(string food, int newRating) {
        auto &cuisine = food_cuisine.find(food)->second;
        cuisine_ratings[cuisine].erase({ -food_rating[food], food });
        cuisine_ratings[cuisine].insert({ -newRating, food });
        food_rating[food] = newRating;
    }
    string highestRated(string cuisine) {
        //return begin(cuisine_ratings[cuisine])->second;
        set<pair<int, string>>> cr = cuisine_ratings[cuisine];
        return begin(cr)->second;
    }
};
int main(){
    vector<string> foods { "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi" };
    vector<string> cusines { "korean", "japanese", "japanese", "greek", "japanese", "korean" };
    vector<int> rating { 9, 12, 8, 15, 14, 7 };
    FoodRatings* foodRatings = new FoodRatings(foods, cusines, rating);
    cout << foodRatings->highestRated("korean") << endl; // return "kimchi"
    // "kimchi" is the highest rated korean food with a rating of 9.
    // korean -> kimchi(9) bulgogi(7)
    cout << foodRatings->highestRated("japanese") << endl; // return "ramen"
    // "ramen" is the highest rated japanese food with a rating of 14.
    // japanese -> miso(12) sushi(8) ramen(14)
    foodRatings->changeRating("sushi", 16); // "sushi" now has a rating of 16.
    cout << foodRatings->highestRated("japanese") << endl; // return "sushi"
    // "sushi" is the highest rated japanese food with a rating of 16.
    // japanese -> miso(12) sushi(16) ramen(14)
    foodRatings->changeRating("ramen", 16); // "ramen" now has a rating of 16.
    cout << foodRatings->highestRated("japanese") << endl; // return "ramen"
    // Both "sushi" and "ramen" have a rating of 16.
    // However, "ramen" is lexicographically smaller than "sushi".
    // japanese -> miso(12) sushi(16) ramen(16)
    return 0;
}