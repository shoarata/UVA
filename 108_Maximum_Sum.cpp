    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    #define MAX 110
    using namespace std;

    int main(){
        int N, ans, currentSum;

        int sumMatrix[MAX][MAX];
        while(scanf("%d",&N) == 1){
            // every cell (i,j) of this matrix will contain the sum of the sub-matrix (0,0):(i,j)
            for(int i = 0; i < N ; i ++){
                for(int j = 0; j < N ; j++){
                    scanf("%d", &sumMatrix[i][j]);
                    if(i > 0) sumMatrix[i][j] += sumMatrix[i-1][j];
                    if(j > 0) sumMatrix[i][j] += sumMatrix[i][j-1];
                    if(i > 0 && j >0) sumMatrix[i][j] -= sumMatrix[i-1][j-1];
                }
            }
            ans = -127 * N * N; // set ans to the lowest possible number

            for(int i = 0; i < N ; i ++)
                for(int j = 0; j < N ; j++)    // checking every possible origin
                    for(int k = i; k < N ; k ++)
                for(int l = j; l < N ; l++){     // checking every possible last cell
                    //calculating sum of sub-matrix origin:last cell
                    currentSum = sumMatrix[k][l];
                    if(i>0) currentSum -= sumMatrix[i-1][l];
                    if(j>0) currentSum -= sumMatrix[k][j-1];
                    if(i>0 && j > 0) currentSum += sumMatrix[i-1][j-1];
                    // holding the higher sum
                    ans = max(currentSum, ans);
                }

            printf("%d\n",ans);
        }
        return 0;
    }

