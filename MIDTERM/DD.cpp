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

    void _count_full_parents(node * _root, int & cnt){
        if(_root != NULL){
            _count_full_parents(_root->left, cnt);
            _count_full_parents(_root->right, cnt);
            if (_root->left != NULL && _root->right != NULL) {
                cnt++;
            }
        }
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

    void count_full_parents(int & cnt) {
        _count_full_parents(this->root, cnt);
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

    int cnt = 0;
    tree->count_full_parents(cnt);
    cout << cnt << endl;

    return 0;
}