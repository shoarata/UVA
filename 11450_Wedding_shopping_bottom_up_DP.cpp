    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    int prices[25][20];
    bool paths[25][210]; //[garment][money left]
    int main(){
        int t, M ,C;
        scanf("%d", &t);
        while(t--){
            scanf("%d %d", &M, &C);
            for(int i =0 ; i < C ; i ++){
              scanf("%d",&prices[i][0]);
              for(int j =1; j <= prices[i][0]; j++) scanf("%d", & prices[i][j]);
            }
            memset(paths,false,sizeof(paths));
            //initial row
            for(int model = 1; model <= prices[0][0]; model++){
                if(M-prices[0][model] >=0)
                    paths[0][M-prices[0][model]] = true;
            }
            for(int g = 1; g < C; g++){
                for(int money = 0; money < M ; money++){
                    if(paths[g-1][money]){
                        for(int model = 1; model <= prices[g][0] ; model++){
                            if(money - prices[g][model] >=0){
                                paths[g][money - prices[g][model]] =  true;
                            }
                        }
                    }
                }
            }
            int money_left;
            for( money_left = 0; money_left <= M && !paths[C-1][money_left]; money_left++ ){
            }
            if(money_left == M + 1) printf("no solution\n");
            else printf("%d\n",M-money_left);
        }
        return 0;
    }

