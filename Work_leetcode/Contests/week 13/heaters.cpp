// By love_FDU_llp
class Solution {
public:
    int foobar(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int range = 0, ho = houses.size(), he = heaters.size();
        int temp = 0, j = 0;
        
        for (int i=0; i<ho; ++i) {
            while (j < he && houses[i] > heaters[j]) ++j;
            if (j == he) range = max(range, abs(houses[i]-heaters[j-1]));
            else {
                if (j >= 1)
                    range = max(range, min(abs(houses[i]-heaters[j]), abs(houses[i]-heaters[j-1])));
                else
                    range = max(range, abs(houses[i]-heaters[j]));
            }
        }
        return range;
    }
};