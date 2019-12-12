#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int frequency = 0; //Global variable to store the frequency.

struct node {
  string data; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(string item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do traversal of the BST 
void searchForWord(struct node *root, string word) 
{ 
  //use recurrsive strategy if current node is null, return.
    if (root != NULL) 
    { 
    
   	if (root->data.compare(word) == 0) {
       //if current nodes data matches the user input increase frequency by 1.
   		frequency++;
		}
        searchForWord(root->left, word);  //search left node
        searchForWord(root->right, word);  //search right node
    } 
       
} 
   
/* A utility function to insert a new node with given data in BST */
struct node* insert(struct node* node, string data) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data); 
  
    /* Otherwise, recur down the tree */
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else 
        node->right = insert(node->right, data);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
   
// Driver Program to test above functions 
int main() 
{ 
       
  struct node *root = NULL; 
  //inserting words into the tree
  root = insert(root, "test"); 
  insert(root, "test"); 
  insert(root, "test"); 
  insert(root, "two Occurences");
  insert(root, "two Occurences");
  insert(root, "one"); 
  insert(root, "any string"); 
  insert(root, "Software Engineering"); 
   
	string word;
	
	cout << "What word would you like to search for?" << endl;
	
  //get user input
	getline(cin, word);
   	
  //search if a node in the tree matches user input   
  searchForWord(root, word);

  //print out results
  cout << word << " appeared " << frequency << " time(s)!";
	
  return 0; 
}