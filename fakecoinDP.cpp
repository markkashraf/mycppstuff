#include <bits/stdc++.h>

using namespace std;



struct coin
{
    int weight;
    int id;
};

//convert the array to coins
vector<coin> toCoin(vector<int> coins)
{
    vector<coin> ans;
    for(int i = 0; i<coins.size(); i++)
    {
        ans.push_back({coins[i],i});
    }
    return ans;
}

//calculate the weight of a coin stack
int weigh(vector<coin> coins)
{
    int sum = 0;
    for(coin c : coins) sum += c.weight;
    return sum;
}

//map for memoization of weights
map<vector<coin>*,int> memo; 
vector<coin> w1,w2,w3;
bool isHeavy; //flag that the counterfiet coin is heavy or light
int group = 0; //group id of the counterfiet coin
int weighings = 0;// total number of weighings

coin ans ={-1,-1}; // the coin that will cointain the answer


//Split the coins and mark the group that contains the counterfiet coin
void splitCoins(vector<coin> coins)
{
    
    // split the coins into N/3 groups
    for(int i = 0; i<4; i++)
    {
        w1.push_back(coins[i]);
        w2.push_back(coins[i+4]);
        w3.push_back(coins[i+8]);
    }
    
    memo[&w1] = weigh(w1);
    memo[&w2] = weigh(w2);
    memo[&w3] = weigh(w3);



    //get the heaviest group and mark its info
    if(memo[&w1]==memo[&w2] && memo[&w3]!=memo[&w1])
    {
        group = 3;
        isHeavy = memo[&w3]>memo[&w1];
    }
    else if(memo[&w1]==memo[&w3] &&memo[&w2]!=memo[&w1])
    {
        group = 2;
        isHeavy = memo[&w2]>memo[&w1];
    }
    else if(memo[&w2]==memo[&w3] &&memo[&w2]!=memo[&w1])
    {
        group = 1;
        isHeavy = memo[&w1]>memo[&w2];
    }
    else 
    {
        group = 0;
    }
    weighings+=2;
}

//get the fake coin from the group
void find_fake(vector<coin> coins){
    // base case (2 coins on the scale)
    if(coins.size()==2)
    {
        // mark the counterfiet and return
        if(isHeavy) ans = (coins[0].weight>coins[1].weight)? coins[0] : coins[1];
        else ans = (coins[0].weight<coins[1].weight)? coins[0] : coins[1];
        weighings++;
        return;
    }
    else
    {
    // create 2 placeholder arrays
    vector<coin> h1,h2;

    // fill placeholder arrays with the coins and memoize them
    for(int i = 0; i<coins.size()/2; i++) h1.push_back(coins[i]);
    memo[&h1] = weigh(h1); 
    for(int i = coins.size()/2; i<coins.size(); i++) h2.push_back(coins[i]);
    memo[&h2] = weigh(h2);

    //if both arrays are equal, just return
    if(memo[&h1]==memo[&h2]) {return; weighings++;}
    //else find the counterfiet group and do the process again
    else
    {   
        if(isHeavy && memo[&h1]>memo[&h2] ||!isHeavy && memo[&h1]<memo[&h2] )
        
            {weighings++; find_fake(h1);}
        
        else if(isHeavy && memo[&h1]<memo[&h2] ||!isHeavy && memo[&h1]>memo[&h2])
        
            {weighings++; find_fake(h2);}
    }
    }
}


void getFakeCoin(vector<int> coins)
{
    splitCoins(toCoin(coins));
    if(group==1) find_fake(w1);
    if(group==2) find_fake(w2);
    if(group==3) find_fake(w3);
    
}
    

int main()
{   
   vector<int> coins = {2,2,2,2, 1,2,2,2, 2,2,2,2};
   getFakeCoin(coins);
   
   if(group==0) cout << "All coins are real" <<endl;
   
   else cout << "Counterfiet coin is coin number: " << ans.id+1 << " and is " << ((isHeavy)? "heavier":"lighter") << " than other coins"<<  endl;
   

   cout<< "Number of weighings: " << weighings << endl;

    return 0;
}
