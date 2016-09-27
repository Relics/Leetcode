// The first algorithm is straight-forward. 
// Let's think about the simplest case: 
// how to remove 1 digit from the number so that the new number is the smallest possible？ 
// Well, one can simply scan from left to right, and remove the first "peak" digit; 
// the peak digit is larger than its right neighbor. 
// One can repeat this procedure k times, and obtain the first algorithm:
class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k>0){
            int i=0;
            int size=(int)num.size();
            while(i+1<=size-1 && num[i]<=num[i+1]) ++i;
            num.erase(i, 1);
            --k;
        }
        int i=0;
        while(i<(int)num.size()-1 && num[i]=='0') ++i;
        num.erase(0, i);
        return num=="" ? "0" : num;
    }
};