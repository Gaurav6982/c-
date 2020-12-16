/*
    HACKER RANK BIT MANIPULATION -Medium

    https://www.hackerrank.com/challenges/winning-lottery-ticket/problem

    INPUT
    
        5
        129300455 
        5559948277
        012334556 
        56789
        123456879
        
    OUTPUT 
        
        5
*/

/*
    WHAT I GOT

    CONVERT EACH NUMBER IN BIT WHICH SIGNIFIES THE PRESENSE OF A DIGIT BETWEEN 0-9
    AND ADD IT TO MAP WITH ITS OCCURRENCE.
    LATER CHECK IF ANY TWO ENTRIES OF MAP MAKING THE ALL ONES WHICH WE HAVE PRE COMPUTED IN VARIABLE WIN
    IF IT IS SO THEN MULTIPLY THE OCCERENCES OF BOTH NUMBERS
    ALSO CONSIDER THAT THERE MIGHT BE SOME NUMBERS WHICH ALREADY CONTAINS DIIGT FROM 0-9 SO TAKE CARE OF THEM AT END.
    BY APPLYING THE SUMMATION FORMULA.
*/

#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
using value_t=long long;
// Complete the winningLotteryTicket function below.
value_t winningLotteryTicket(vector<string> tickets) {

    map<int,value_t> table;
    const int win=(1<<10)-1;
    for (auto ticket : tickets) {
        int numbers(0);
        for (auto c : ticket)
            numbers |= 1 << (c - '0');
        table[numbers]++;
    }
    value_t res=0;
    
    for (auto ticket1 = table.begin(); ticket1 != prev(table.end()); ++ticket1)
        for (auto ticket2 = next(ticket1); ticket2 != table.end(); ++ticket2)
            if ((ticket1->first | ticket2->first) == win)
                res += ticket1->second * ticket2->second;
    return res+table[win] * (table[win] - 1) / 2;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> tickets(n);
    for(int tickets_i = 0; tickets_i < n; tickets_i++){
       cin >> tickets[tickets_i];
    }
    value_t result = winningLotteryTicket(tickets);
    cout << result << endl;
    return 0;
}