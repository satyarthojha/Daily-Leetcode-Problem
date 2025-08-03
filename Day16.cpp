// pascal triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      
        vector<vector<int>> pascal(numRows, vector<int>(numRows, 0)); 
        for (  int i=0;  i < numRows; i++) {
            pascal[i][0] = pascal[i][i] = 1;  
            for (int j = 1; j < i; j++) {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) ; 
            }
        }
        int rowIndex;
        int index=1;
          for ( auto& row : pascal) {
            
              
                 row.erase((row.begin()+index) , row.begin()+numRows);
                 index++;
          }
         return pascal;

  
    }
};