#include <iostream>
using namespace std;

int main() {
    class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int row = mat.size(); //row
        int col = mat[0].size(); //col

        int dir = 0;
        int top =0;
        int down = row-1;
        int left = 0;
        int right = col-1;
        // if dir = 0 print left to right
        // dir = 1 top to bottom 
        // dir =2 right to left
        // dir 3 = down to top
        vector<int> result;
        while(top<=down && left<=right){
            if(dir==0){
                // print left to right : row is fixed and col veries
                for(int i = left;i<=right;i++){
                    result.push_back(mat[top][i]);
                }
                top++;
            }
            dir++;
            if(dir==1){
                // top to bottom 
                for(int i = top;i<=down;i++){
                    result.push_back(mat[i][right]);
                }
                right--;
                dir++;
                if(dir==2){
                            // right to left
                            for(int i =right;i>=left;i--){
                    result.push_back(mat[down][i]);
                            }
                            down--;

                }
                dir++;
                if(dir==3){
                    // down to top
                    for(int i = down ; i>=top;i--){
                        result.push_back(mat[i][left]);
                    }
                    left++;
                }

                dir++;
                if(dir==4){
                    dir = 0;
                }
            }
        }
        return result;

    }
};
    return 0;
}