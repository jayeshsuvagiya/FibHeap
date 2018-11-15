#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <list>
#include "fibheap.h"

using namespace std;

void printdata(node* a){
    node *b=a;
    std::cout<<"\n Printing DATA MAIN\n";
    do{
        std::cout<<"{"<<*(b->keyword)<<","<<b->count<<"}"<<"\t";
        b=b->right;
    }while(b!=a);
    std::cout<<"\n";
}
int main(int argc, char** argv) {
    fibheap fibh{};
    unordered_map<string, node*> keys;
    ifstream  input;
    input.open(argv[1]);
    fstream output;
    string out;
    output.open("output_file.txt", ios::in | ios::out | ios::trunc );
    if(input.good()){
        string line;
        while ( getline (input,line) )
        {
            if(line[0]=='$'){
                unsigned int p = line.find(' ');
                string *keyword=new string(line.substr(1,p-1));
               // keyword= ;
                std::istringstream ss(line.substr(p));
                int count;
                ss>>count;
                if(debug)
                cout<<" Keyword - "<<*keyword<<" length = "<<(*keyword).length()<<" count - "<<count<<"\n";
                if(keys.find(*keyword) == keys.end()){
                    node *n=new node(count, keyword);
                    keys[*keyword]=n;//insert in degree table
                    fibh.insert(n);
                } else {
                    fibh.increasekey(keys[*keyword],count);
                }
            }else if(line=="stop"){
                //cout<<"STOP RECIEVED - "<<line<<"\n";
                input.close();
                out.pop_back();
                output<<out;
                output.close();
                return 0;
            } else{
                std::istringstream ss(line);
                int c;
                ss>>c;
                list<node*> toplist;
                if(debug){
                    cout<<"QUERY - "<<c<<"\n";
                    printdata(fibh.getmax());
                }
               // output<<"\n";
                while(c--){
                    if(debug){
                        cout<<"BEFORE EXTRACT MAX - "<<c<<"\n";
                        printdata(fibh.getmax());
                    }
                    node *n = fibh.extractmax();
                    if(n != nullptr){
                       // output<<*(n->keyword);
                        out.append(*(n->keyword));
                        if(c!=0)
                            out.append(",");
                       // output<<",";
                    }

                    if(debug){
                        cout<<"After EXTRACT MAX - "<<c<<"\n";
                        printdata(fibh.getmax());
                    }
                    toplist.push_back(n);
                }
                out.append("\n");
                //cout<<"\n";
                for(node* n:toplist){
                  //  cout<<"\t"<<*(n->keyword)<<" - "<<(n->count)<<",";
                   // output<<*(n->keyword)<<",";
                    fibh.insert(n);
                }

                //cout<<"\n";
                if(debug){
                    cout<<"\n";
                    printdata(fibh.getmax());
                }
            }
        }
        input.close();
        output.close();
    } else
        cout<<"Cannot locate file "<<argv[1]<<"\n";

    return 0;
}
