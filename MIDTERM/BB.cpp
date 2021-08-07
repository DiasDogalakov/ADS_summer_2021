#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
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

    void * _find(node * _root, int x, int & res) {
        if (res - x > _root->val - x && _root->val - x >= 0) {
            res = _root->val;
        }
        if (_root->val < x && _root->right != NULL) {
            _find(_root->right, x, res);
        }else if (_root->val > x && _root->left != NULL) {
            _find(_root->left, x, res);
        }
    }


public:
    bst(){
        root = NULL;
    }

    void add(int x){
        root = _add(this->root, x);
    }

    void find(int x, int & res){
        _find(this->root, x, res);
    }

    void print(){
       _print(this->root);
    }
};

int main()
{
    bst * tree = new bst();

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        tree->add(x);
    }

    for (int i = 0; i < m; ++i) {
        int x, res = 1e9; cin >> x;
        tree->find(x, res);
        cout << res << endl;
    }

    return 0;
}