#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;


struct node{
    int val;
    node * left;
    node * right;
    node(int x):left(NULL),right(NULL),val(x){}
};

struct bst{
private:
    node * root;
    void _print(node * _root){
        if(_root != NULL){
            cout << _root->val <<  " ";
            _print(_root->left);
            _print(_root->right);
        }
    }

    node * _add(node * _root, int x){
        if(_root == NULL){
            _root = new node(x);
        }else if(x < _root->val){
            if(_root->left == NULL){
                _root->left = new node(x);
            }else{
                _add(_root->left, x);
            }
        }else if(x > _root->val){
            if(_root->right == NULL){
                _root->right = new node(x);
            }else{
                _add(_root->right, x);
            }
        }
        return _root;
    }

    node *  _find(node * _root, int x) {
        if (_root->val < x) {
            return _find(_root->right, x);
        } else if (_root->val > x) {
            return _find(_root->left, x);
        }
        return _root;
    }


public:
    bst(){
        root = NULL;
    }

    void add(int x){
        root = _add(this->root, x);
    }

    node * find(int x){
        return _find(this->root, x);
    }

    void print(node * r){
       _print(r);
    }
};

int main()
{
    bst * tree = new bst();

    int n; cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        tree->add(x);
    }
    int target; cin >> target;
    node * root = tree->find(target);

    tree->print(root);

    return 0;
}
