class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0, n = secret.length();
        unordered_map<char, int> sec, gue;
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                bull++;
            } else {
                sec[secret[i]]++;
                gue[guess[i]]++;
            }
        }
        for(auto it: sec) {
            if(gue.find(it.first) != gue.end()) {
                cow += min(gue[it.first], it.second);
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
