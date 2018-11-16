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
    //initialize variables
    fibheap fibh{};
    unordered_map<string, node*> keys;
    ifstream  input;
    input.open(argv[1]);
    fstream output;
    string out;
    output.open("output_file.txt", ios::in | ios::out | ios::trunc );

    if(input.good()){
        string line;
        while ( getline (input,line) ) //read input lines
        {
            if(line[0]=='$'){ //check for $ and process

                //split keyword and count
                unsigned int p = line.find(' ');
                string *keyword=new string(line.substr(1,p-1));
                std::istringstream ss(line.substr(p));
                int count;
                ss>>count;

                if(debug){
                    cout<<" Keyword - "<<*keyword<<" length = "<<(*keyword).length()<<" count - "<<count<<"\n";
                }

                if(keys.find(*keyword) == keys.end()){ //if keyword doesnt exist insert
                    node *n=new node(count, keyword);
                    keys[*keyword]=n;//insert in degree table
                    fibh.insert(n);
                } else { //else increase count
                    fibh.increasekey(keys[*keyword],count);
                }
            }else if(line=="stop"){ //check for stop and exit
                input.close();
                out.pop_back(); //remove extra line at the end of file
                output<<out;
                output.close();
                return 0;
            } else{ //else query

                std::istringstream ss(line);
                int c;
                ss>>c;
                list<node*> toplist;

                if(debug){
                    cout<<"QUERY - "<<c<<"\n";
                    printdata(fibh.getmax());
                }

                while(c--){ //loop till query count

                    if(debug){
                        cout<<"BEFORE EXTRACT MAX - "<<c<<"\n";
                        printdata(fibh.getmax());
                    }

                    //remove max
                    node *n = fibh.extractmax();

                    //append it to ouput
                    if(n != nullptr){
                        out.append(*(n->keyword));
                        if(c!=0)
                            out.append(",");
                    }

                    if(debug){
                        cout<<"After EXTRACT MAX - "<<c<<"\n";
                        printdata(fibh.getmax());
                    }

                    toplist.push_back(n);
                }
                out.append("\n");

                for(node* n:toplist){
                    //insert all the max nodes again in to the heap
                    fibh.insert(n);
                }

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
