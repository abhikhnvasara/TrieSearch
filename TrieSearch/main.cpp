//
//  main.cpp
//  TrieSearch
//
//  Created by Vinod Gupta on 1/29/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class TrieNode
{
public:
    TrieNode(char k,int v):_key(k),_val(v),_next(NULL),_children(NULL)
    {}
    virtual ~TrieNode()
    {
        if(_next)
            delete _next;
        if(_children)
            delete _children;
    }
    
    char key() {return _key;}
    int val() {return _val;}
    
    TrieNode *next() {return _next;}
    TrieNode *child() {return _children;}
    
    void AddNext(TrieNode *next) {_next = next;}
    void AddChild(TrieNode *child) {_children = child;}
    
private:
    char _key;
    int _val;
    TrieNode *_next;
    TrieNode *_children;
};

class Trie
{
public:
    Trie()
    {
        _root = new TrieNode('.',0);
    }
    virtual ~Trie()
    {
        if(_root)
            delete _root;
    }
    
    bool insertString(std::string word)
    {
        TrieNode *parent = _root;
        TrieNode *me = NULL;
        TrieNode *my_sibling = NULL;
        
        for(std::string::const_iterator itr = word.begin(); itr != word.end(); ++itr)
        {
            const char c = *itr;
            me = parent->child();
            
            while(me)
            {
                if(me->key() == c) break;
                my_sibling = me;
                me=me->next();
            }
            
            if (!me)
            {
                me = new TrieNode(c,0);
                
                if(!me) return false;
                
                if (!parent->child())
                    parent->AddChild(me);
                else
                    if (my_sibling)
                        my_sibling->AddNext(me);
            }
            
            parent = me;
        }
        
        return true;
    }
    
    bool searchString(std::string word)
    {
        TrieNode *parent = _root;
        
        for(std::string::const_iterator itr = word.begin(); itr != word.end(); ++itr)
        {
            const char c = *itr;
            TrieNode *me = parent->child();
            
            while(me && me->key() != c) me=me->next();
            
            if (!me) return false;
            
            parent = me;
        }
        
        return true;
    }
    
private:
    TrieNode *_root;
};

int main(int argc, const char * argv[]) {
    
    Trie trie_dictionary;
    
    string myString1("apple");
    string myString2("orange");
    string myString3("pineaplle");
    string myString4("apricot");
    string myString5("plum");
    
    trie_dictionary.insertString(myString1);
    trie_dictionary.insertString(myString2);
    trie_dictionary.insertString(myString3);
    trie_dictionary.insertString(myString4);

    bool found = false;
    
    found = trie_dictionary.searchString(myString1);
    cout << myString1 << " found => " << found << endl;
    
    found = trie_dictionary.searchString(myString2);
    cout << myString2 << " found => " << found << endl;
    
    found = trie_dictionary.searchString(myString3);
    cout << myString3 << " found => " << found << endl;
    
    found = trie_dictionary.searchString(myString4);
    cout << myString4 << " found => " << found << endl;

    found = trie_dictionary.searchString(myString5);
    cout << myString5 << " found => " << found << endl;
    
    return 0;
}
