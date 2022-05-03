#include<bits/stdc++.h>
using namespace std;

struct node{
  
  char data;
  bool isEndNode;
  node *left,*right,*eq;
  
  node(char d){
      isEndNode=false;
      data=d;
      left=right=eq=0;
  }
};

void insert(node **root,string word,int i){
    
    //tree is empty
    if(!(*root)) 
        (*root) = new node(word[i]);
    
    if(word[i] < (*root)->data){           //char is less than current node
        insert(&((*root)->left),word,i);
    }
    else if(word[i] > (*root)->data){    //char is greater than current node
        insert(&((*root)->right),word,i);
    }
    else{                                  // both are equal
        if(i+1<word.length()){
            insert(&((*root)->eq),word,i+1);
        }
        else (*root)->isEndNode = true;
    }
}

void printAllWords(node *root,string currWord){
    if(root){
        
        printAllWords(root->left,currWord);
        
        currWord+=root->data;
        
        if(root->isEndNode){
            cout<<currWord<<"\n";
        }
        
        printAllWords(root->eq,currWord);
        currWord.pop_back();
        printAllWords(root->right,currWord);
        
    }
}

void search(node *root,string word,int i,bool *isPresent){
    if(root){
        search(root->left,word,i,isPresent);
        if(root->data == word[i]){
            if(i+1<word.length() && root->isEndNode){
                return;
            } 
            else if(i+1==word.length() && root->isEndNode){
                *isPresent=true;
                return;
            }
        }
        search(root->eq,word,i+1,isPresent);
        search(root->right,word,i,isPresent);
    }
    
}

int main()
{
    node *root = 0;
    vector<string> words = {"Azure","baby","cabs","cars","cafe","Cavil","Edify","Mien",
    "Angst","Adagio","Agita","Agog","Aloof","Blob","Bozo","Bond","Bed","Bat","Eat","East","Eager","Eagle"};
    
    int n = words.size();
    
    srand(time(0));
    for(int i=0;i<4;i++) {
        string x = words[rand()%n];
        
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        
        cout<<"Inserting: "<<x<<endl;
        insert(&root,x,0);
    }
    
    cout<<"\n\nPrinting all the words store in tree: \n";
    printAllWords(root,"");
    cout<<"\n\n";
    
    for(int i=0;i<4;i++) {
        string x = words[rand()%n]; //randomly selecting one string from collection of string
        
        transform(x.begin(), x.end(), x.begin(), ::tolower); //lowercasing all the letters
        
        cout<<"Search \""<<x<<"\": ";  
        
        bool isPresent=false;             //flag 
        search(root,x,0,&isPresent);     
        
        if(isPresent) cout<<"Present";
        else cout<<"Not Present";
        cout<<endl;
    }
    
    return 0;
}
