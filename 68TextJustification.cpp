/*问题：对给定字符串的一种格式化处理，要求每行有L个字符，空格均匀（不均匀的话就前多后少）
 *解决：正常流程格式化处理
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        for(int i(0), k, l; i < words.size();i += k){ //i is the index of words, k is the nums of every line, l is the all words lenth.
            for(k = l = 0; i+k < words.size() && l+words[i+k].size() <= maxWidth-k; ++k){
                l += words[i+k].size();
            }
            string tmp = words[i];
            for(int j=0; j<k-1; ++j){ // handle the k words choosed.why is k-1, cause the last words no space followed.
                if(i+k >= words.size()) tmp += " "; //the last line, every word have one space.
                else tmp += string( (maxWidth-l)/(k-1) + (j < (maxWidth-l)%(k-1)) , ' '); // (maxWidth-l)/(k-1) means the average space behind a word, % means the left most have but right not.
                tmp += words[i+(j+1)]; //add the next word;
            }
            tmp += string(maxWidth-tmp.size(), ' '); //add the space to fill to maxWidth;
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main(){
    //AC
    cout << string(5, 'a') << endl;
}
