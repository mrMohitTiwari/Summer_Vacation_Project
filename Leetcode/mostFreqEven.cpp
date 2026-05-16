#include <iostream>
using namespace std;

int main() {
    class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
    int hash[100001]={0};
        for(const int x:nums) {
            if((x%2)==0 ) hash[x]++;
        }
        int fa = -1;
        for(int i = 0;i<100001;i += 2){
            if(hash[i]>fa && hash[i]!=0) fa = i;
        }
        return fa;
    }
// ,,,,,,,,÷
};
    return 0;
}