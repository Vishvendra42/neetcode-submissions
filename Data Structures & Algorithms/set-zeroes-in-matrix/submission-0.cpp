class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n =matrix[0].size();

        vector<int>maskRow(m,0);
        vector<int>maskCol(n,0);

        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if( matrix[i][j]==0){
                    maskRow[i]=1;
                    maskCol[j]=1;
                }
            }
        }
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if( maskRow[i] || maskCol[j]){
                    matrix[i][j]=0;
                   
                }
            }
        }


    }
};
