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
            _print(_root->left);
            cout << _root->val <<  " ";
            _print(_root->right);
        }
    }
    node * _add(node * _root, int x){
        if(_root == NULL){
            _root = new node(x);
        }else if(x > _root->val){
            if(_root->left == NULL){
                _root->left = new node(x);
            }else{
                _add(_root->left, x);
            }
        }else if(x < _root->val){
            if(_root->right == NULL){
                _root->right = new node(x);
            }else{
                _add(_root->right, x);
            }
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

    void find(int x){

    }
    void del(int x){

    }
    void print(){
       _print(this->root);
    }
};

int main()
{
    bst * tree = new bst();

    int a[] = {5, 6, 3, 4, 2, 1};

    //     5
    //   3   6
    //  2 4    7
    // 1         9
    //          8
    //     
    int n = sizeof(a) / sizeof(int);

    for(int i = 0; i < n; ++i)
    {
        tree->add(a[i]);
    }

    tree->print();

    return 0;
}