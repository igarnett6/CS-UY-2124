#include <iostream>
using namespace std;

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
	// Provide this code
		if (!root) {
			throw invalid_argument("Tree is empty.");
		}
		int left = INT_MIN;
		int right = INT_MIN;
		if(root->left){ left = max(root->left); }
		if(root->right){ right = max(root->right); }
		if (left < right) {
			if (root->data > right) { return root->data; }
			else return right;
		}
		else {
			if (root->data > left) {
				return root->data;
			}
			else return left;
		}
	
}

int main() {

  TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
  cout << max(&f) << endl;

  
  try {
	  cout << max(nullptr) << endl;
  }
  catch(invalid_argument e){
	  cerr << e.what() << endl;
  }

}

  
  
