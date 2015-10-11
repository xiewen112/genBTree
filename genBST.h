#include <queue>
#include <stack>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <class T>
class Stack: public stack<T>{
public:
    T pop(){
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }

};

template <class T>
class Queue: public queue<T>{
public:
    T dequeue(){
        T tmp = queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el){
        queue<T>::push(el);
    }
};

template <class T>
class BSTNode{
public:
    BSTNode(){
        left = right = 0;
    }
    BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0){
        el = e;
        left = l;
        right = r;
    }
    T el;
    BSTNode<T> *left, *right;
};

template <class T>
class BST{
public:
    BST(){
        root = 0;
    }
    ~BST(){
        clear();
    }
    void clear(){ //
        clear(root);
        root = 0;
    }
    bool isEmpty() const {
        return root == 0;
    }
    void preorder(){
        preorder(root);
    }
    void inorder(){
        inorder(root);
    }
    void postorder(){
        postorder(root);
    }
    T* search(const T& el) const{
        return search(root, el);
    }


    void breadthFirst(){ //from top to bottom, left to tight
        Queue<BSTNode<T>*> queue;
        BSTNode<T>* p = root;
        if(p != 0){
            queue.enqueue(p); // add node of root
            while(!queue.empty()){
                p = queue.dequeue();
                visit(p);
                if(p->left != 0)
                    queue.enqueue(p->left);
                if(p->right != 0)
                    queue.enqueue(p->right);
            }
        }
    }
    void iterativePreorder(){
        BSTNode<T>* p = root;
        Stack<BSTNode<T>*> travStack;
        if(p != 0){
            travStack.push(p);
            while(!travStack.empty()){
                p = travStack.pop();
                visit(p);
                if(p->right != 0){
                    travStack.push(p->right);
                }
                if(p->left != 0){
                    travStack.push(p->left);
                }
            }
        }

    }

    void iterativePostorder(){
        BSTNode<T>* p = root;
        BSTNode<T>* q = root;
        Stack<BSTNode<T>*> travStack;

        while(p != 0){
            for(;p->left != 0; p = p->left){
                travStack.push(p);
            }
            while(p->right == 0 || p->right == q){
                visit(p);
                q = p; // mark the previous entry access of right node
                if(travStack.empty()){
                    return;
                }
                p = travStack.pop();
            }
            travStack.push(p);
            p = p->right;
        }
    }
    void iterativeInorder(){

    }

    void balance(T data[], int first, int last){
        if(first <= last){
            int middle = (first + last)/2;
            insert(data[middle]);
            balance(data, first, middle - 1);
            balance(data, middle + 1, last);
        }
    }


    void insert(const T& el){
        BSTNode<T> *p = root;
        BSTNode<T> *prev = 0;
        // find a new node
        while(p != 0){
            prev = p;
            if(el < p->el){
                p = p->left;
            }else{
                p = p->right;
            }
        }
        //insert an element into new node
        if(root == 0){
            root = new BSTNode<T>(el);
        }
        else if (el < prev->el){
            prev->left = new BSTNode<T>(el);
        }
        else{
            prev->right = new BSTNode<T>(el);
        }
    }
protected:
    BSTNode<T>* root;
    void clear(BSTNode<T>* r){

    }
    void inorder(BSTNode<T>* p){
        if(p != 0){
            inorder(p->left);
            visit(p);
            inorder(p->right);
        }
    }
    void preorder(BSTNode<T>* p){
        if(p != 0){
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }
    void postorder(BSTNode<T>* p){
        if(p != 0){
            postorder(p->left);
            postorder(p->right);
            visit(p);
        }
    }
    T* search(BSTNode<T>* p, const T& el) const{
        while(p != 0){
            if(el == p->el)
                return &p->el;
            else if (el < p->el)
                p = p->left;
            else
                p = p->right;
        }
        return 0;
    }
    virtual void visit(BSTNode<T>* p){
        cout << p->el << ' ';
    }
};


#endif





