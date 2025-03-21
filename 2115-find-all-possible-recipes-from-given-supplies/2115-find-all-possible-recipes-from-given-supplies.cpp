class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_set<string> foundRecipes;
        bool addedNewRecipe = true;

        while(addedNewRecipe) {
            addedNewRecipe = false;
            for(int i = 0; i < recipes.size(); i++) {
                if (foundRecipes.count(recipes[i])) continue; // Skip if already made

                bool canMake = true;
                for(string& ing : ingredients[i]) {
                    if(!available.count(ing)) { // If an ingredient is missing
                        canMake = false;
                        break;
                    }
                }

                if(canMake) {
                    available.insert(recipes[i]); // Mark the recipe as available
                    
                    addedNewRecipe = true;
                }
            }
        }
        return vector<string>(foundRecipes.begin(), foundRecipes.end());
    }
};