#include<iostream>
using namespace std;

//insert
//create
//delete

class TrieNode{
    public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val){
        this-> value = val;
        for(int i = 0; i<26;i++) {
            children[i]= NULL;
        }
        this->isTerminal= false;
    }
};

void insertWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        //present
        child = root-> children[index];
    }
    else{
        //absent
        child = new TrieNode(ch);
        root-> children[index] = child;
    }

    //reccursion
    insertWord(child, word.substr(1));

}

bool searchWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0){
       return root ->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //present or found
        child = root-> children[index];
    }
    //not found
    else{
        return false;
    }

    //reccursion
    bool reccursionKaAns = searchWord(child, word.substr(1));
    return reccursionKaAns;
}

void deleteWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

     char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //present or found
        child = root-> children[index];
    }
    else{
        return;
    }

    deleteWord(child, word.substr(1));

}



int main() {

    TrieNode* root = new TrieNode('-');

    insertWord(root, "gorgeous");
    insertWord(root, "arya");
    insertWord(root, "care");
    insertWord(root, "careful");
    insertWord(root, "happy");
    insertWord(root, "happiness");
    insertWord(root, "love");
    insertWord(root, "lovely");
    insertWord(root, "gupta");

    cout<<"Insertion done"<<endl;

    if(searchWord(root, "arya")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    deleteWord(root, "lovely");

    return 0;
}