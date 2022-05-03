#include<bits/stdc++.h>
#define MAXLEN 5
#define MAXNODE 15
#define TOL 2
using namespace std;

struct node{
    string word;
    int next[MAXLEN];
    
    node(string w){
        word = w;
        memset(next,-1,sizeof(next));
    }
};

int ptr;
node *Tree[MAXNODE];

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int getDistance(string& a,string& b)
{
	int m = a.length(), n = b.length();
	int dp[m+1][n+1];

	// filling base cases
	for (int i=0; i<=m; i++)
		dp[i][0] = i;
	for (int j=0; j<=n; j++)
		dp[0][j] = j;

	// populating matrix using dp-approach
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (a[i-1] != b[j-1])
			{
				dp[i][j] = min( 1 + dp[i-1][j], // deletion
								1 + dp[i][j-1], // insertion
								1 + dp[i-1][j-1] // replacement
							);
			}
			else
				dp[i][j] = dp[i-1][j-1];
		}
	}
	return dp[m][n];
}
void insert(node **root,node *newNode){
    if(!(*root)){
        (*root) = newNode;
        return;
    }
    
    int dist = getDistance((*root)->word,newNode->word);
    if((*root)->next[dist] == -1){
        (*root)->next[dist] = ptr;
        Tree[ptr++] = newNode;
    }
    else{
        insert(&Tree[(*root)->next[dist]],newNode);
    }
}

void getSimWord(node *root,string currWord,vector<string> &result){
    if(!root) return;
    
    int dist = getDistance(root->word,currWord);
    
    if(dist<=TOL) result.push_back(root->word);
    
    int start = (dist-TOL>=0)?(dist-TOL):(0);
    int end = (dist+TOL<MAXLEN)?(dist+TOL):(MAXLEN-1);
    
    while(start<=end){
        getSimWord(Tree[root->next[start]],currWord,result);
        start++;
    }
}
int main(){
    
    vector<string> words = {"hope","rope","dope","eat","ate","rat"
        ,"pat","sat","mat","cat","cut","tat","sad","mate","fat"
    };
    
    int n = words.size();
    
    node *root = 0;
    
    for(int i=0;i<n;i++){
        node *newNode = new node(words[i]);
        insert(&root,newNode);
    }
    vector<string> result;
    getSimWord(root,"kate",result);
    
    cout<<"All words similar to \"kate\":";
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    return 0;
}