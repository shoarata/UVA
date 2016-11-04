    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    int r, s, first, last, firstaux, lastaux, sum, ans, value, counter;
    int main(){
        counter = 0;
        scanf("%d", &r);
        while(r--){
            counter ++;
            scanf("%d",&s);
            first = last = sum = ans = firstaux= lastaux = 0;
            for(int i =0; i < s-1; i ++)
            {
                scanf("%d", &value);
                sum+= value;
                lastaux ++;
                if(sum > ans || (sum == ans && (last- first < lastaux- firstaux))){
                    ans = sum;
                    first = firstaux;
                    last = lastaux;
                }
                if(sum < 0) {
                    firstaux = lastaux = i + 1;
                    sum = 0;
                }
            }
            if(last == 0){
                printf("Route %d has no nice parts\n", counter);
            }
            else{
                printf("The nicest part of route %d is between stops %d and %d\n", counter, first+1, last +1);
            }

        }
        return 0;
    }

