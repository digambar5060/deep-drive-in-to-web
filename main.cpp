#include<iostream>
#include<string>
#include<vector>
#include<fstream>


#include<sstream>

#include<cstdio>


#include<stdio.h>
#include<fstream>
using namespace std; 
class Bank{
    public:
        int Balance  =10000;
        void show_all_lenders(){
                
            fstream fin; 
            vector<string> row;
            string line, word;
            
            fin.open("lenderdb.txt", ios::in);
  
            while (!fin.eof()) {
                row.clear();
                getline(fin, line);
                stringstream s(line);
      
                while (getline(s, word, ',')) {
                    row.push_back(word);
                }
                cout<<"Lender "<<row[0]<<"\nAmount: "<<row[1]<<endl<<endl;
            }
            cout<<"task finished\n";
            fin.close();
            }
        

        void show_all_borrower(){
            fstream fin; 
            vector<string> row;
            string line, word;
            
            fin.open("borrowerdb.txt", ios::in);
  
            while (!fin.eof()) {
                row.clear();
                getline(fin, line);
                stringstream s(line);
      
                while (getline(s, word, ',')) {
                    row.push_back(word);
                }
                cout<<"Borrower "<<row[0]<<"\nAmount: "<<row[1]<<endl<<endl;
            }
            cout<<"task finished\n";
            fin.close();
        }

        void Find_balance(){
        cout<<Balance<<endl;
    }
        void lend_money(){
            string s;
            int n;
            cout<<"Enter name of lender:"<<endl;
            cin>>s;
            cout<<"Enter amount to lend:"<<endl;
            cin>>n;
            Lender len(s,n);
            Balance += n;
        }
        void borrow_money(){
            string s;
            int n;
            cout<<"Enter name of borrower:"<<endl;
            cin>>s;
            cout<<"Enter amount to borrow:"<<endl;
            cin>>n;
            Lender len(s,n);
            Balance -= n;   
        }

};

class Borrower{
    public:
    string name;
    int amt;
    Borrower(string s, int amount){
        name = s;
        amt = amount;
        
        fstream borrowerdb;
        string filename="borrowerdb.txt";
        borrowerdb.open(filename.c_str(),ios::app);
        borrowerdb<<endl<<name<<","<<amt;
    };
};

class Lender{
    public:
    string name;
    int amt;
    Lender(string s, int amount){
        name = s;
        amt = amount;
        
        fstream lenderdb;
        string filename="lenderdb.txt";
        lenderdb.open(filename.c_str(),ios::app);
        lenderdb<<endl<<name<<","<<amt;
    }
    };

int main(){
    Bank b;
    int choice1;
    cout<<"Welcome to lending and Borowing soft: choose one option\n1.lend_money\n2.borrow_money\n3.show_balance\n4.show_list_of_lenders\n5.show_list_of_borowers"<<endl;
    while(1){
        cin>>choice1;
        switch(choice1){
            case 1:
                b.lend_money();
                break;
            case 2:
                b.borrow_money();
                break;
            case 3: 
                b.Find_balance();
                break;
            case 4:
                b.show_all_lenders();
                break;
            case 5:
                b.show_all_borrower();
                break;
            default:
                break;
        }
        cout<<"Enter 0 to exit or any other key to continue:"<<endl;
        string k;
        cin>>k;
        if(k=="0") break;
        cout<<"choose one option\n1.lend_money\n2.borrow_money\n3.show_balance\n4.show_list_of_lenders\n5.show_list_of_borowers"<<endl;
    }
}
//finish
