    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #define MAX_N 1010
    #define MAX_W 40
    #include <algorithm>
    using namespace std;
    int t,N, aux, g, capacity, score;
    int V[MAX_N],weights[MAX_N], memo[MAX_N][MAX_W];
    int maxValue(int n, int leftw){
        if(n == N || leftw ==0) return 0;
        if(memo[n][leftw] != -1) return memo[n][leftw];
        if(weights[n] > leftw) return memo[n][leftw] = maxValue(n+1, leftw);
        return memo[n][leftw] = max(maxValue(n+1,leftw), V[n] + maxValue(n+1, leftw - weights[n]));
    }
    int main(){

        scanf("%d", &t);
        while(t--){
            scanf("%d",&N);
            memset(memo, -1, sizeof(memo));
            // storing weights
            for(int i = 0; i < N; i ++) {
                scanf("%d %d",&V[i],&weights[i]);
            }
            scanf("%d",&g);
            score = 0;
            while(g--){
                scanf("%d",&capacity);
                score+= maxValue(0,capacity);
            }
            printf("%d\n",score);
        }
        return 0;
    }

