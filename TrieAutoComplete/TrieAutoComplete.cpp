#include<iostream>

using namespace std;
#define SIZE 26

typedef struct trie{
  trie *child[SIZE];
  bool end_of_word;
}Trie;

Trie *GetNode() {
  Trie *root = new Trie();
  for(int i = 0; i < SIZE;i++) {
    root->child[i] = NULL;
  }
  root->end_of_word = false;
  return root;
}


void insert(trie *root, string key) {
  Trie *temp = root;
  for(int i = 0; i < (int)key.size(); i++) {
    int k = (int)(key[i] - 'a');
    if(temp->child[k] == NULL) {
      temp->child[k] = GetNode();
    } 
    temp = temp->child[k];
  }
  temp->end_of_word = true;
}

bool search(Trie *root, string key) {
  Trie *temp = root;
  for(int i = 0; i < (int)key.size(); i++) {
    int k = key[i] - 'a';
    if(temp->child[k] == NULL) {
      return false;
    }
    temp = temp->child[k];
  }
  return(temp != NULL && temp->end_of_word == true);
}

bool IsLastNode(Trie *root) {
  Trie *temp = root;
  for(int i = 0; i < SIZE; i++) {
    if(temp->child[i] == NULL) {
      return false;
    }
  }
  return true;
}

void AutoSuggestUtil(Trie *root, string query) {
  if(root->end_of_word == true) {
    cout<<" "<<query<<" "<<endl;
  }
  if(IsLastNode(root)) {
    return;
  }
  Trie *temp = root;
  for(int i = 0; i < SIZE; i++) {
    if(temp->child[i]) {
      query.push_back(i + 'a');
      AutoSuggestUtil(temp->child[i], query);
      query.pop_back();
    }
  }
}


int AutoSuggest(Trie *root, string query) {
  Trie *temp = root;
  
  for(int i = 0; i < (int)query.size(); i++) {
    int k = query[i] - 'a';
    if(temp->child[k] == NULL) {
      cout<<"dbg :NULL case"<<endl;
      cout<<"dbg : k, i "<<k<<" "<<i<<endl; 
      return 0;
    }
    temp = temp->child[k];
  }
  
  if(IsLastNode(temp) && temp->end_of_word) {
    cout<<" "<<query<<" "<<endl;
    return -1;
  }
  
  if(!IsLastNode(temp)) {
    AutoSuggestUtil(temp, query);
    return 1;
  }
  // Fall through to non-existing use-case - prefix exists and is last node 
  // But not end of the word
  return  0;
  
}

int main() {
  Trie *root = GetNode();
  insert(root, "cat");
  insert(root, "hello");
  insert(root, "dog");
  insert(root, "hell");
  insert(root, "cat");
  insert(root, "a");
  insert(root, "hel");
  insert(root, "help");
  insert(root, "helps");
  insert(root, "helping");
  
  string query = "hel";
 
 
  cout<<boolalpha<<search(root, "dog")<<endl;
  cout<<boolalpha<<search(root, "cat")<<endl;
  
  int result = AutoSuggest(root, query);
  if(result == 0) {
    cout<<"No results for search query!"<<endl;
  } else if(result == -1) {
    cout<<endl<<"No other results for search query"<<endl;
  }
  
  return 0;
}
