# Word-auto-completion-suggestion 

Here we have implemented two different data structure for word suggestion and auto completion. The data structure that we have implemented here are ***Burkhad-Keller Tree*** and ***Ternary Search Tree***.

To run code:
1. Run the cpp code and keep the input file in the same folder.

Breif Description:

# 1. Burkhad Keller Tree<br/><br/>
## Description:<br />
- For near-matches to a String Query, Spell Check, Auto-Complete.<br />
- BK-Tree rests its concepts on the Levenshtein distance which can be understood as the value that is returned after two strings are passed and the minimum number      of insertion, deletion and replacements are returned which are required to translate one string into the other.<br />
- more efficient compared to the TRIE and Ternary Search tree.<br />

## Representation:<br />
- Node storing word and array of all children nodes.<br />
## Example:<br />
<img src="https://github.com/khushij12/Word-auto-completion-suggestion/blob/main/resource/BKtree.png" alt="drawing" width="400"/>

# 2. Ternary Search Tree<br />
## Description:<br />
- A ternary search tree is a special trie data structure useful for efficient search of strings. 
- A well balanced BST will need time proportional to M * log N, where M is maximum string length and N is the number of keys in the tree to search a string. Using Trie, we can search the key in O(M) time. 
- But the penalty is on Trie storage requirements as each node can point to 26 different nodes. So we instead use a ternary search tree for that.
- Ternary search trees are efficient to use(in terms of space) when the strings to be stored share a common prefix

## Representation:<br />
1. There are 3 types of pointers pointing to adjacent nodes:
  A. The left pointer points to the node whose value is less than the value in the current node.
  B. The equal pointer points to the node whose value is equal to the value in the current node.
  C. The right pointer points to the node whose value is greater than the value in the current node.
2. To store char
3. Another field to mark the end of a string.
## Example:<br />
<img src="https://github.com/khushij12/Word-auto-completion-suggestion/blob/main/resource/TST.png" alt="drawing" width="400"/>

