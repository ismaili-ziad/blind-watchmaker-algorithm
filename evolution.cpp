#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
int counter = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string initial = "", goal = "THIS IS A GOAL";
    for(int i = 0; i < goal.size(); i++){
        initial += alp[rand()%(alp.size())];
    }
    char c;
    while(initial != goal){
        printf("%d: %s\n", counter, initial.c_str());
        string mostLikely = initial;
        int maxsim = 0;
        for(int i = 0; i < 5000000; i++){
            vector<int> propositions;
            for(int j = 0; j < goal.size(); j++){
                if(goal[j] != initial[j]) propositions.push_back(j);
            }
            string duplicate = initial;
            int a, b, c, d, sim = 0;
            a = propositions[rand()%(propositions.size())];
            b = propositions[rand()%(propositions.size())];
            c = propositions[rand()%(propositions.size())];
            d = propositions[rand()%(propositions.size())];
            duplicate[a] = alp[rand()%(alp.size())];
            duplicate[b] = alp[rand()%(alp.size())];
            duplicate[c] = alp[rand()%(alp.size())];
            duplicate[d] = alp[rand()%(alp.size())];
            for(int j = 0; j < duplicate.size(); j++){
                if(duplicate[j] == goal[j]) sim++;
            }
            if(sim > maxsim){
                maxsim = sim;
                mostLikely = duplicate;
            }
        }
        initial = mostLikely;
        counter++;
    }
    printf("%d: %s\n", counter, goal.c_str());
    return 0;
}
