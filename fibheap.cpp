//
// Created by jayesh on 13-11-2018.
//

#include <iostream>
#include <unordered_map>
#include "fibheap.h"
#include <list>

using namespace std;


//PRINT A LIST
void pdata(node* a){
    node *b=a;
    std::cout<<"\n Printing DATA \n";
    do{
        std::cout<<"{"<<*(b->keyword)<<","<<b->count<<"}"<<b->degree<<"\t";
        b=b->right;
    }while(b!=a);
    std::cout<<"\n";
}

void fibheap::insert(node *x) {
    if(max == nullptr){
        max = x;//set max to new node
    }else{//insert after max node
        node *next = max->right;
        max->right=x;
        x->left=max;
        x->right=next;
        next->left=x;
    }

    if(max->count < x->count)//update max heap pointer
    max=x;
}


void fibheap::increasekey(node *x, int c) {
    x->count=(x->count)+c; //increase the count
    if(x->parent != nullptr && x->count >= x->parent->count){ //check if count greater than parent if yes cascade cut
        cascadecut(x);
    }
    if(x->count > max->count) //update the heap pointer if necessary
        max=x;
}

node* fibheap::extractmax() {
    if(max== nullptr)
        return nullptr;
    else{
        node *m = max; //get max node to return

        //remove max node from list
        if(max->right==max)
            max = nullptr;
        else{
            max->left->right=max->right;
            max->right->left=max->left;
            max=max->right;
        }

        //set child parent pointer as null
        if(m->child!=nullptr){
            node *c = m->child;
            do{
                c->parent = nullptr;
                c=c->right;
            }while(c!=m->child);
        }

        //merge children with root list
        max=combinelist(max,m->child);
        if(debug){
            cout<<"\n CHILD COMBINE \n";
            pdata(max);
            cout<<"CHILD COMBINE END\n";
        }

        //remove pointers of max
        m->right=m->left=m;
        m->child= nullptr;
        m->degree=0;

        //only one node
        if(max== nullptr)
            return m;

        //combine pair
        unordered_map<int, node*> deg_table; //map to keep track of degrees

        //create a list to iterate through root nodes
        list<node*> clist;
        node *st = max;
        node *end = max;
        do{
            st=st->left;
            clist.push_front(st);
        }while (st!=end);

        //iterate through root list to combine pairs with equal degree
        for(node* cur:clist){
            while (true){

                if(deg_table.find(cur->degree) == deg_table.end()){
                    deg_table[cur->degree]=cur;//insert in degree table
                    break;
                }
                else{   //merge two trees with same degree
                    node *sdt = deg_table[cur->degree];
                    deg_table.erase(cur->degree);

                    //find the max and min node in a pair
                    node *nmax,*nmin;
                    if(sdt->count>cur->count) {
                        nmax = sdt;
                        nmin = cur;
                    } else{
                        nmax=cur;
                        nmin=sdt;
                    }

                    if(debug){
                        cout<<"NMAX,NMIN = {"<<*(nmax->keyword)<<","<<*(nmin->keyword)<<"}\n";
                    }

                    //remove smaller from list
                    nmin->left->right=nmin->right;
                    nmin->right->left=nmin->left;
                    //reset left right pointer
                    nmin->left=nmin->right=nmin;
                    //set parent
                    nmin->parent=nmax;
                    //insert into child list
                    nmax->child = combinelist(nmax->child,nmin);
                    //increase degree
                    nmax->degree++;
                    //set cc to false
                    nmin->cc = false;
                    cur=nmax;
                }
            }
            if(cur->count >= max->count)
                max=cur;
            if(debug){
                cout<<"step\t";
                pdata(max);
            }

        }
        return m;
    }
}

node* fibheap::getmax() {
    return max;
}

node* fibheap::combinelist(node *a, node *b) {
    if(a == nullptr && b == nullptr)//check if both list are empty
        return nullptr;
    else if(a== nullptr)
        return b;
    else if(b== nullptr)
        return a;
    else{//if both the list are not empty insert list b after start of list a
        node *anext = a->right;
        node *bpre = b->left;
        a->right=b;
        b->left=a;
        bpre->right=anext;
        anext->left=bpre;
        return b->count > a->count ? b:a;
    }
}

void fibheap::cascadecut(node *a) {
    a->cc=false;//set cc to false as it will be added to root list
    if(a->parent== nullptr)//if parent is null stop
        return;

    //remove the node
    if(a->right != a){
        a->left->right=a->right;
        a->right->left=a->left;
    }

    //reset child pointer
    if(a->parent->child==a){
        if(a->right != a)
            a->parent->child=a->right;
        else
            a->parent->child= nullptr;
    }

    //decrease degree of parent
    a->parent->degree--;
    //reset left right pointer
    a->left=a->right=a;

    if(debug){
        cout<<" FIB MAX "<<*(max->keyword)<<"\n";
    }

    //insert into root  list
    insert(a);

    //if cc is true cascade cut the parent
    if(a->parent->cc){
        cascadecut(a->parent);
    } else // else set it true
        a->parent->cc=true;
    //set parent to null as it is added to root list
    a->parent=nullptr;
}





