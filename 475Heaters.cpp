#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int house_size = houses.size();
        int heat_size = heaters.size();
        int i = 0; //pointer of house
        int j = 0; //pointer of heater
        int ret = 0; //save the result
        int tmp = 0; //save the tmp result of every house.
        for(; i < house_size; ++i){
            while(j < heat_size && heaters[j] < houses[i]) ++j;//then heaters[j] >= houses[i] or j==heat_size;
            if(j == heat_size){
                tmp = abs(houses[i] - heaters[j-1]);
            } else if(j == 0){
                tmp = heaters[0] - houses[i]; //the first heater must ware the left-most house.
            } else if(heaters[j] > houses[i]){
                tmp = min(heaters[j] - houses[i], houses[i] - heaters[j-1]);
            }
            if(tmp > ret) ret = tmp;
        }
        return ret;
    }

    int findRadius_(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int house_size = houses.size();
        int heat_size = heaters.size();
        int i = 0; //pointer of house
        int j = 0; //pointer of heater
        int ret = 0; //save the result
        int tmp = 0; //save the tmp result of every house.
        for(; i < house_size; ++i){
            while(j < heat_size && heaters[j] < houses[i]) ++j;//then heaters[j] >= houses[i] or j==heat_size;
            if(j == heat_size){
                tmp = abs(houses[i] - heaters[j-1]);
            } else {
                tmp = min(heaters[j] - houses[i], houses[i] - heaters[j-1]);
            }
            if(tmp > ret) ret = tmp;
        }
        tmp = heaters[0] - houses[0];
        return max(ret, tmp);
    }

};

int main(){
    freopen("475test.txt", "r", stdin);
    int total;
    int house_size, heat_size;
    cin >> total;
    for(int i=0; i<total; ++i){
        cin >> house_size;
        cin >> heat_size;
        int ele;
        vector<int> houses;
        vector<int> heaters;
        for(int j=0; j<house_size; ++j) {
            cin >> ele;
            houses.push_back(ele);
        }
        for(int j=0; j<heat_size; ++j){
            cin >> ele;
            heaters.push_back(ele);
        }
        Solution Sol;
        cout << Sol.findRadius_(houses, heaters) << endl;
    }
}
