#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
// Alphabet string, plus whitespace.
string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
// Generation counter.
int counter = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // The string 'goal' is the sentence we want to reach.
    string initial = "", goal = "THIS IS A GOAL";
    // Here, 'initial', being S from README, is the mutated string. It will change throughhout the execution of the programme.
    // It is initially set to a random string (of random characters from 'alp').
    for(int i = 0; i < goal.size(); i++){
        initial += alp[rand()%(alp.size())];
    }
    // For future uses. Ignore.
    char c;
    // While S is not equal to G. While our initial string, that is supposed to change, is not yet equal to our goal. When our mutations didn't meet their objective.
    while(initial != goal){
        // Display the generation and the current string S.
        printf("%d: %s\n", counter, initial.c_str());
        // Temporaty string.
        string mostLikely = initial;
        int maxsim = 0;
        // Here, X from README, namely, the number of replications (with intentional errors) is set to 5,000,000 by default, but could be changed.
        // That means that the string S will be copied 5,000,000 times, each copy being slightly changed.
        for(int i = 0; i < 5000000; i++){
            // The vector 'proposition' stores all positions in the string S where the character needs to change.
            // This is to avoid changing letters that are already correctly placed (i.e., preserving advantageous traits).
            // For instance, if G = "ABCD" and S = "AHCJ", then propositions = {1, 3} (it is 0-indexed) because only H and J in S need to change.
            vector<int> propositions;
            for(int j = 0; j < goal.size(); j++){
                // If letters at the position j do not match, save j (the position).
                if(goal[j] != initial[j]) propositions.push_back(j);
            }
            // Temporary helper string.
            string duplicate = initial;
            int a, b, c, d, sim = 0;
            // a, b, c, and d are four random positions that will change.
            // Here, each picks one random value from the vector 'proposition'.
            a = propositions[rand()%(propositions.size())];
            b = propositions[rand()%(propositions.size())];
            c = propositions[rand()%(propositions.size())];
            d = propositions[rand()%(propositions.size())];
            // The temporary helper string (the current mutation out of X) is updated with random characters at each position (ath, bth, cth and dth).
            duplicate[a] = alp[rand()%(alp.size())];
            duplicate[b] = alp[rand()%(alp.size())];
            duplicate[c] = alp[rand()%(alp.size())];
            duplicate[d] = alp[rand()%(alp.size())];
            // Here, we verify how close to the goal the new mutation is.
            // 'sim' denotes the number of matching characters.
            for(int j = 0; j < duplicate.size(); j++){
                if(duplicate[j] == goal[j]) sim++;
            }
            // If 'sim' had the highest counter in the current duplication process, then this specific S should be selected for the next mutation.
            // 'mostLikely' is the closest result in the current loop.
            if(sim > maxsim){
                maxsim = sim;
                mostLikely = duplicate;
            }
        }
        // S is set to the best result out of the previous loop.
        initial = mostLikely;
        // A generation has occured.
        counter++;
    }
    // We display S.
    printf("%d: %s\n", counter, goal.c_str());
    return 0;
}
