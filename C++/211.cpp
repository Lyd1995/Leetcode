#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

struct TreeNode2 {
    string word;
    int len;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2(string s) : word(s), len(s.size()), left(NULL), right(NULL) {}
};



class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(list.count(word.size()) == 0){
            vector<string> temp;
            temp.push_back(word);
            list.insert(map<int, vector<string>>::value_type(word.size(), temp));
        }
        else
            list[word.size()].push_back(word);
    }

    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        vector<string> temp = list[word.size()];
        sort(temp.begin(), temp.end());
        int j=0;
        while(word[j] == '.')
            j++;
        string word1 = word.substr(j);
        for(int i=0; i < temp.size(); i++){
            string s1 = temp[i].substr(j);
            if(s1[0] > word1[0])
                break;
            if(compareWord(s1, word1))
                return true;
        }
        return false;
    }

    bool compareWord(string& s1, string& word){
        for(int i=0; i < word.size(); i++){
            if(s1[i] != word[i] && word[i] != '.')
                return false;
        }
        return true;
    }
private:
    map<int, vector<string>> list;
};

int main(){
    WordDictionary a;
    a.addWord("at");
    a.addWord("and");
    a.addWord("an");
    a.addWord("add");
    bool a1 = a.search("a");
    bool a2 = a.search(".at");
    a.addWord("bat");
    bool a3 = a.search(".at");
    bool a4 = a.search("an.");
    bool a5 = a.search("a.d.");
    bool a6 = a.search("b.");
    bool a7 = a.search("a.d");
    bool a8 = a.search(".");
    return 0;
}