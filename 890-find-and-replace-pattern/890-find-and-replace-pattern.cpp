class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer;
        for(string word : words) {
            if(word.size() != pattern.size()) continue;
            vector<int> v(26, -1);
            vector<bool> taken(26, false);
            bool good = true;
            for(int i=0; i<word.size(); i++) {
                int x = word[i] - 'a';
                int y = pattern[i] - 'a';
                if(v[x] == -1 && taken[y] == false) {
                    v[x] = y;
                    taken[y] = true;
                } else if(v[x] != y) {
                    good = false;
                    break;
                }
            }
            if(good) answer.push_back(word);
        }
        return answer;
    }
};