#include <iostream>
using namespace std;

struct Node {
    //PROPERTIES
    int data;
    struct Node *left, *right;
    //CONSTRUCTOR
    Node(int data){
      this->data = data;
      left = NULL;
      right = NULL;
    }
};
//PREORDER TRAVERSAL
void preorderTraversal(struct Node* node){
  if(node == NULL) return;

  cout << node->data << " "; //menampilkan data pertama masuk
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

//POSTORDER TRAVErSAL
void postorderTraversal(struct Node* node){
  if(node == NULL) return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->data << " ";
}

//INORDER TRAVERSAL
void inorderTraversal(struct Node* node){
  if(node == NULL) return;

  inorderTraversal(node->left);
  cout  << node->data << " ";
  inorderTraversal(node->right);
}

int main(){
  struct Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);

  cout << "\nInorder traversal output\n";
  inorderTraversal(root);
  
  cout << "\npreorder traversal output\n";
  preorderTraversal(root);

  cout << "\npostorder traversal output\n";
  postorderTraversal(root);
}
