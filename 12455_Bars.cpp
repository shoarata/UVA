#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t, X, n, nums[1001], aSet, sum;
    bool found;
    scanf("%d", &t);
    while(t--){
        found  = false;
        scanf("%d %d", &X, &n);
        for(int i = 0; i < n ; i ++){
            scanf("%d", &nums[i]);
        }
        // this checks all sets possibles with the given numbers, using bitmask
        for(aSet = 0; aSet < (1<< n); aSet++){
            sum=0;
            // add all the numbers in the current set
            for(int i =0; i < n; i ++){
                // if ith bit is turned on add the ith element of nums to sum
                if(aSet & (1 << i)){
                    sum += nums[i];
                }
            }
            if(sum == X) {
              cout<< "YES" << endl;
              found = true;
              break;
            }
        }
        if(!found) cout<<"NO" << endl;
    }
    return 0;
}

