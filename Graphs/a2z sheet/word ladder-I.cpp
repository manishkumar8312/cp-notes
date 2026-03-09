Problem Statement: 
Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest 
transformation sequence from startWord to targetWord..

In this problem statement, we need to keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.


Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Code:

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front();
                q.pop();
                if(endWord == word){
                    return level;
                }
                for(int i=0;i<word.length();i++){
                    char original = word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i] = ch;
                        if(st.find(word) != st.end()){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
        }
        return 0;
    }
};
