//
// Created by jayesh on 13-11-2018.
//
#include "string"
#ifndef FIBHEAP_FIBHEAP_H
#define FIBHEAP_FIBHEAP_H
const bool debug=false;
typedef struct node{
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

class fibheap {
    node *max;
    public:
        void insert(node*);
        void query(int n);
        void increasekey(node*,int count);
        node* extractmax();
        node* getmax();
        node* combinelist(node* a,node* b);
        void cascadecut(node* a);
};


#endif //FIBHEAP_FIBHEAP_H
