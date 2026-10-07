class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first take image respect to horizontal line through the mid of matrix
        // then image from the diagnol 0,0 to n,n

        int n =matrix.size();
         int half = n/2 -1;
        for( int row =0;row<= half;row++){
            // row from top = row
            //row from bottom = n-row-1
            int from_bottom = n-1-row;
            for( int col =0;col<n;col++){
                swap( matrix[row][col] , matrix[from_bottom][col]);
            }
        }

        //image by diagonal
        // return matrix;

        for( int row=0 ;row<n;row++){
            for( int col=row+1;col<n;col++){
               
                 // swap btw row,col value and (col,  row)
                 swap(matrix[row][col] , matrix[col][row] );

            }
        }
    }
};
