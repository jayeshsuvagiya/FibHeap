//
// Created by jayesh on 13-11-2018.
//

#include <iostream>
#include <unordered_map>
#include "fibheap.h"
#include <list>

using namespace std;



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
        max = x;
    }else{
        node *next = max->right;
        max->right=x;
        x->left=max;
        x->right=next;
        next->left=x;
    }

    if(max->count < x->count)
    max=x;
}

void fibheap::query(int count) {

}

void fibheap::increasekey(node *x, int c) {
    x->count=(x->count)+c;
    if(x->parent != nullptr && x->count >= x->parent->count){
        cascadecut(x);
    }
    if(x->count > max->count) //update the heap pointer if necessary
        max=x;
}

node* fibheap::extractmax() {

    //std::cout<<"m and max "<<m<<"\n"<<max<<"\n";
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
        node *cur = max;
        node *end = max;
        unordered_map<int, node*> deg_table;
        list<node*> clist;
       // pdata(cur);
        do{
            cur=cur->left;
            clist.push_front(cur);
        }while (cur!=end);
       // pdata(clist.front());
        for(node* cur:clist){
            while (true){
                 //preserve the next node to iterate properly
                if(deg_table.find(cur->degree) == deg_table.end()){
                    deg_table[cur->degree]=cur;//insert in degree table
                    break;
                }
                else{   //merge two trees with same degree
                    node *sdt = deg_table[cur->degree];
                    deg_table.erase(cur->degree);

                    node *nmax,*nmin;
                    if(sdt->count>cur->count) {
                        nmax = sdt;
                        nmin = cur;
                    } else{
                        nmax=cur;
                        nmin=sdt;
                    }
                    if(debug)
                    cout<<"NMAX,NMIN = {"<<*(nmax->keyword)<<","<<*(nmin->keyword)<<"}\n";
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
      /*  do{
            node *nextnode = cur->right; //preserve the next node to iterate properly
            if(deg_table.find(cur->degree) == deg_table.end()) 
                deg_table[cur->degree]=cur;//insert in degree table
            else{   //merge two trees with same degree
                node *sdt = deg_table[cur->degree];

                node *nmax,*nmin;
                if(sdt->count>cur->count) {
                    nmax = sdt;
                    nmin = cur;
                } else{
                    nmax=cur;
                    nmin=sdt;
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
            }
            if(cur->count > max->count)
                max=cur;

            cur=nextnode;
        }while(cur!=end);*/
        return m;
    }
}

node* fibheap::getmax() {
    return max;
}

node* fibheap::combinelist(node *a, node *b) {
    if(a == nullptr && b == nullptr)
        return nullptr;
    else if(a== nullptr)
        return b;
    else if(b== nullptr)
        return a;
    else{
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
    a->cc=false;
    if(a->parent== nullptr)
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

    a->left=a->right=a;
    if(debug)
    cout<<" FIB MAX "<<*(max->keyword)<<"\n";
    insert(a);

    if(a->parent->cc){
        cascadecut(a->parent);
    } else
        a->parent->cc=true;
    a->parent=nullptr;
}





