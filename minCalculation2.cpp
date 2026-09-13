#include<iostream>
#include<vector>
using namespace std;

vector<int> min_multiplications(int n) {
    vector<int> powers;

    //TODO : complete min multiplication
    if(n<=1){
          powers.push_back(1);
          return powers;        
    }
    vector<int> upperChain;
    upperChain.push_back(1);

    int highestBit= 0;
    int temp = n;
    while(temp>1){
         temp/=2;
         highestBit++;

    }
    int currentPower = 1;
    for(int bit= highestBit-1; bit>=0;bit--){
        currentPower*=2;
        upperChain.push_back(currentPower);
        if((n>>bit)&1){
             currentPower+=1;
             upperChain.push_back(currentPower);
        }
    }
    int upperBound= static_cast<int>(upperChain.size())-1;
    int lowerBound= 0;
    long long value =1;
    while(value<n){
        value *=2;
        lowerBound++;

    }

    for(int limit = lowerBound;limit<upperBound;limit++){
        vector<int> chain(limit+1);
        chain[0]=1;
        auto dfs=[&](auto&& self, int depth)->bool{
         int last = chain[depth];
         if(depth==limit){
             return last == n;

         }
         long long maxReach = last;
         for(int i=depth;i<limit;i++)maxReach*=2;
         if(maxReach<n)return false;

         vector <int> candidates;
         for(int i=depth;i>=0;i--){
             for(int j=i;j>=0;j--){
                 long long sum = static_cast<long long> (chain[i])+chain[j];
                 if(sum<=last||sum>n)continue;
                 bool duplicate = false;

                 for(int candidate:candidates){
                     if(candidate==sum){
                         duplicate=true;
                         break;
                     }
                 }
                 if(duplicate) continue;

                 int pos = 0;
                 while(pos<static_cast<int> (candidates.size())&&candidates[pos]>sum)pos++;

                 candidates.insert(candidates.begin()+pos, static_cast<int>(sum));
             }
         }
         for(int nextPower:candidates){
             long long possible =nextPower;
             int remaining = limit - (depth+1);
             for(int i =0;i<remaining;i++){
                  possible*=2;
                
             }
             if(possible<n) continue;
             chain[depth+1]=nextPower;
             if(self(self,depth+1)) return true;

         }
         return false;
        };
        if(dfs(dfs, 0)) return chain;
    }


    return upperChain;
}

int main(){

    int n;
    cin >> n;

    
    vector<int> steps = min_multiplications(n);
    cout << steps.size() - 1 << " ";
    for (int step : steps) {
        cout << step << " ";
    }

    return 0;
}