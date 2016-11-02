 #include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int prices[25][25], paths[205][25];
int t, M, C, score;
int backTrack(int money, int g){
    if(money < 0) return -9999999999999999;
    if(g == C) return M- money;
    //checking if we have traversed this path before
    if(paths[money][g] != -1) return paths[money][g];
    int ans = -1;
    for(int model = 1; model <= prices[g][0] ; model++){
        ans = max(ans, backTrack(money - prices[g][model],g+1));
    }
    return paths[money][g] = ans;
}
int main(){

    scanf("%d", &t);
    while(t--){
        memset(paths,-1, sizeof(paths));
        scanf("%d %d", &M, &C);
        for(int i =0 ; i < C ; i ++){
          scanf("%d",&prices[i][0]);
          for(int j =1; j <= prices[i][0]; j++) scanf("%d", & prices[i][j]);
        }
        score = backTrack(M,0);// backtrack with initial money and first garment(0 indexed)
        if(score<0){
            printf("no solution\n");
        }
        else{
            printf("%d\n",score);
        }
    }
    return 0;
}

