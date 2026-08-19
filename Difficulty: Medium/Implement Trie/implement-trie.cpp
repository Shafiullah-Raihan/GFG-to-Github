class Trie {
  public:
    
    Trie* children[26];
    bool end ;
    
    Trie() {
        // implement Trie
        end = false;
        for(int i=0;i<26;i++)
        {
            children[i] = nullptr;
            
        }
    
        
    }

    void insert(string &word) {
        // insert word into Trie
        Trie* curr  =this;
        for(auto u:word)
        {
            if(curr->children[u-'a'] == nullptr)
            {
                curr->children[u-'a'] = new Trie();
                
                
            }
            curr = curr->children[u-'a'];
        }
        curr->end = true;
    }

    bool search(string &word) {
        // search word in the Trie
        Trie* curr = this;
        for(auto u:word)
        {
            if(curr->children[u-'a'] == nullptr ) return false;
            curr = curr->children[u-'a'];
            
        }
        return curr->end;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Trie* node = this;
        for(auto u: word)
        {
            if(node->children[u-'a'] == nullptr)
            {
                return false;
            }
            node = node ->children[u-'a'];
        }
        return true;
        
    }
};
