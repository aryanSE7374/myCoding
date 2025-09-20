#include<bits/stdc++.h>
using namespace std;

/*

class FoodRatings {
public:

    unordered_map<string , int> foodsMap;
    unordered_map<string , int> cuisinesMap;
    unordered_map<int , int> ratingsMap;
    // unordered_set<int > max_ratings; //indices
    set< string > max_ratings; //indices
    int maxRating = 0;


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0 ; i<foods.size() ; i++){
            foodsMap[foods[i]] = i;
        }
        for(int i=0 ; i<cuisines.size() ; i++){
            cuisinesMap[cuisines[i]] = i;
        }
        for(int i=0 ; i<ratings.size() ; i++){
            ratingsMap[ratings[i]] = i;
            maxRating = max(maxRating , ratings[i]);
        }
        for(auto it : ratingsMap){
            if(it.first == maxRating){
                max_ratings.insert(foods[it.second]);
            }
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = foodsMap[food];
        ratingsMap[idx] = newRating;
        if(newRating>maxRating){
            maxRating = newRating;
            max_ratings.clear();
            max_ratings.insert(food);
        }
        else if(newRating==maxRating){
            max_ratings.insert(food);
        }
    }
    
    string highestRated(string cuisine) {
        return *max_ratings.begin();
    }
};

*/

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


class FoodRatings {
public:
    // Store cuisine and rating for each food
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;

    // For each cuisine, keep an ordered set of (rating, food)
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];

        // Remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        // Update rating
        foodRating[food] = newRating;
        // Insert new entry
        cuisineFoods[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // The set is ordered by (-rating, foodName), so begin() gives the best
        return cuisineFoods[cuisine].begin()->second;
    }
};