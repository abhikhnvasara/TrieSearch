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
        bool found = false;
        
        for(std::string::const_iterator itr = word.begin(); itr != word.end(); ++itr)
        {
            const char c = *itr;
            me           = parent->child();
            
            while(!found && me)
            {
                if(me->val() == c)
                {
                    found=true;
                    break;
                }
                
                my_sibling = me;
                if(me)
                    me=me->next();
            }
            
            if (found)
            {
                parent = me;
                found  = false;
            }
            else
            {
                me = new TrieNode(c,0);
                
                if (!parent->child())
                    parent->AddChild(me);
                else
                    if (my_sibling)
                        my_sibling->AddNext(me);
                
                parent = me;
            }
        }
        
        return false;
    }
    
    
private:
    TrieNode *_root;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
