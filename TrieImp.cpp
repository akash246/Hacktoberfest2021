#include <iostream>
#include <unordered_map>
#define N 26

using namespace std;

struct TrieNode1 {
    TrieNode1* children[N];
    
    // you might need some extra values according to different cases
    // fast access of children since array used
    // space complexity maybe unnecessarily high due to unused space
};

/** Usage:
 *  Initialization: TrieNode root = new TrieNode();
 *  Return a specific child node with char c: (root->children)[c - 'a']
 */

struct TrieNode2 {
    unordered_map<char, TrieNode2*> children;
    
    // you might need some extra values according to different cases
    // pretty fast access to children but not as fast as array
    // space complecity in check since only reqd space allotted at a time
};

/** Usage:
 *  Initialization: TrieNode root = new TrieNode();
 *  Return a specific child node with char c: (root->children)[c]
 */


struct TrieNode{
    unordered_map<char,TrieNode*> children; 
    bool end=0;                                 // bool to keep track of the end of each word, reqd for word search
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode;
    }
    
    // INSERTION---------------------------------------------------------------------------------------
    void insert(string word) {                      // inserts the string provided in params
        TrieNode* ptr=root;
        for(char &c: word){
            if((ptr->children).find(c)==(ptr->children).end()){
                (ptr->children)[c]=new TrieNode;
            }
            ptr=(ptr->children)[c];
        }
        
        ptr->end=1;
    }
    // Time Complexity - O(m), m -> length of word
    // Space Complexity - O(m) 
    

    // WORD SEARCH-------------------------------------------------------------------------------------
    bool search(string word) {                      // checks if word is present in the Trie
        TrieNode* ptr=root;
        for(char &c: word){
            if((ptr->children).find(c)==(ptr->children).end()){
                return false;
            }
            ptr=(ptr->children)[c];
        }
        
        if((ptr->end))return true;
        return false;
    }
    // Time Complexity - O(m), m -> length of word
    // Space Complexity - O(1)

    
    // PREFIX SEARCH-----------------------------------------------------------------------------------
    bool startsWith(string prefix) {                // checks if prefix is present in the Trie
        TrieNode* ptr=root;
        for(char &c: prefix){
            if((ptr->children).find(c)==(ptr->children).end()){
                return false;
            }
            ptr=(ptr->children)[c];
        }
        
        return true;
    }
    // Time Complexity - O(m), m -> length of word
    // Space Complexity - O(1)
};

int main(){

}