//
// Created by ÂÞÈðµÑ on 2024/3/19.
//

#ifndef OFFER_HOT_208_H
#define OFFER_HOT_208_H

class Trie {
public:

    vector<string> res;
    Trie() : res() {

    }

    void insert(string word) {
        res.push_back(word);
    }

    bool search(string word) {
        auto it = std::find(res.begin(), res.end(),word);
        if( it != res.end()) return true;
        else return false;
    }

    bool startsWith(string prefix) {

        bool is_prefix = false;
        for( const string& str : res){

            if(prefix.size() >  str.size()) continue;
            ///
            int count = 0;
            for( int i = count ; i < prefix.size() ; ++i)
            {
                if( str[i] != prefix[i])
                    break;
                else count++;
            }
            if(count == prefix.size()) return true;
        }
        return is_prefix;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //OFFER_HOT_208_H
