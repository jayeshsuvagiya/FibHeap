//
// Created by jayesh on 13-11-2018.
//
#include "string"
#ifndef FIBHEAP_FIBHEAP_H
#define FIBHEAP_FIBHEAP_H
const bool debug=false; //set debug true to print steps
typedef struct node{    // node structure
    int degree=0;
    bool cc= false;
    node *child= nullptr;
    node *parent=nullptr;
    node *left;
    node *right;
    std::string* keyword;
    int count=0;
    node(int c,std::string* k){
        left=this;
        right=this;
        count=c;
        keyword=k;
    }
}node;

class fibheap { //Fibonacci Heap Class
    node *max;
    public:
        void insert(node*); //insert a node in MAX FibHeap
        void increasekey(node*,int c); //increase count of a node in MAX FibHeap
        node* extractmax();//remove a node with maximum count in MAX FibHeap
        node* getmax();//fetch a node with maximum count in MAX FibHeap
        node* combinelist(node* a,node* b);//combine two circular list
        void cascadecut(node* a);//Cascade cut a node of MAX FibHeap
};


#endif //FIBHEAP_FIBHEAP_H
