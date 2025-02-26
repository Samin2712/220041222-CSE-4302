#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<fstream>
#include<sstream>
using namespace std;
class Book
{
    private:
       string title;
       string author;
       string ISBN;
    public:
       Book(string t,string a,string i):title(t),author(a),ISBN(i){}
       string getTitle() const{return title;}
       string getAuthor() const{return author;}
       string getISBN() const{return ISBN;}
       void display() const
       {
          cout<< "Title: "<<title<<endl;
          cout<< "Author: "<<author<<endl;
          cout<< "Title: "<<ISBN<<endl;
          cout<<endl;
       }
};
class Library
{
    private:
        vector<Book>inventory;
        deque<Book>borrowed;
        list<Book>archived;
    public:
        void addBook()
        {
            string title,author,isbn;
            cout<< "Enter Title: ";
            getline(cin,title);
            cout<< "Enter Author: ";
            getline(cin,author);
            cout<< "Enter ISBN: ";
            getline(cin,isbn);
            inventory.push_back(Book(title,author,isbn));
        }
        void BorrowBook(string isbn)
        {
            for(auto it=inventory.begin();it!=inventory.end();it++)
            {
                if(it->getISBN()==isbn)
                {
                    borrowed.push_back(*it);
                    inventory.erase(it);
                    cout<< "Book borrowed successfully"<<endl;
                    return;
                }
            }
            cout<< "Book is not found in inventory book resource"<<endl;
        }
        void ReturnBook(string isbn)
        {
            for(auto it=borrowed.begin();it!=borrowed.end();it++)
            {
                if(it->getISBN()==isbn)
                {
                    inventory.push_back(*it);
                    borrowed.erase(it);
                    cout<< "Book returned successfully"<<endl;
                    return;
                }
            }
            cout<< "Book is not found in borrowed book resource"<<endl;
        }
        void ArchivedBook(string isbn)
        {
            for(auto it=inventory.begin();it!=inventory.end();it++)
            {
                if(it->getISBN()==isbn)
                {
                    archived.push_back(*it);
                    inventory.erase(it);
                    cout<< "Book archived successfully"<<endl;
                    return;
                }
            }
            cout<< "Book is not found in inventory book resource"<<endl;
        }
        void disPlayAllBook()
        {
            cout<< "--Inventory Books:--"<<endl;
            for(const auto bk:inventory) bk.display();
            cout<< "--Borrowed Books:--"<<endl;
            for(const auto bk:borrowed) bk.display();
            cout<< "--Archived Books:--"<<endl;
            for(const auto bk:archived) bk.display();
        }
        void SaveData() const
        {
            ofstream inv_b("inventory.txt");
            ofstream bor_b("borrowed.txt");
            ofstream arc_b("archived.txt");
            for(auto bk:inventory) inv_b<< bk.getTitle()<< ","<<bk.getAuthor()<< ","<<bk.getISBN()<<endl;
            inv_b.close();
            for(auto bk:borrowed) bor_b<< bk.getTitle()<< ","<<bk.getAuthor()<< ","<<bk.getISBN()<<endl;
            bor_b.close();
            for(auto bk:archived) arc_b<< bk.getTitle()<< ","<<bk.getAuthor()<< ","<<bk.getISBN()<<endl;
            arc_b.close();
            cout<< "Saved data successfully"<<endl;
        }
        void LoadData()
        {
            ifstream inv_b("inventory.txt");
            ifstream bor_b("borrowed.txt");
            ifstream arc_b("archived.txt");
            string line;
            int inv_count=0,bor_count=0,arc_count=0;
            if (!inv_b||!bor_b||!arc_b)
            {
                cout<<"Error: One or more files not found or unable to open."<<endl;
                return;
            }
            while(getline(inv_b,line))
            {
                stringstream ss(line);
                string tl,at,isb;
                if(getline(ss,tl,',')&&getline(ss,at,',')&&getline(ss,isb,','))
                {
                    inventory.push_back(Book(tl,at,isb));
                    inv_count++;
                }
                else cout<< "Warning: There is an error in loading input format"<<endl;
            }
            while(getline(bor_b,line))
            {
                int c=0;
                stringstream ss(line);
                string tl,at,isb;
                if(getline(ss,tl,',')&&getline(ss,at,',')&&getline(ss,isb,','))
                {
                    borrowed.push_back(Book(tl,at,isb));
                    bor_count++;
                }
                else cout<< "Warning: There is an error in loading input format"<<endl;
            }
            while(getline(arc_b,line))
            {
                stringstream ss(line);
                string tl,at,isb;
                if(getline(ss,tl,',')&&getline(ss,at,',')&&getline(ss,isb,','))
                {
                    archived.push_back(Book(tl,at,isb));
                    arc_count++;
                }
                else cout<< "Warning: There is an error in loading input format"<<endl;
            }
            if(inv_count!=inventory.size()) cout<<"Warning: All data is not read successfully from inventory list"<<endl;
            if(bor_count!=borrowed.size()) cout<< "Warning: All data is not read successfully from borrowed list"<<endl;
            if(arc_count!=archived.size()) cout<< "Warning: All data is not read successfully from archived list"<<endl;
            cout<< "Load Data successfully"<<endl;
            inv_b.close();
            bor_b.close();
            arc_b.close();
        }
};
int main()
{
    Library lb;
    int choice;
    string title,author,isbn;
    do
    {
        cout<<"1. Add Book\n2. Borrow Book\n3. Return Book\n4. Archive Book\n5. Display All Books\n6. Save Data\n7. Load Data\n8. Exit\n";
        cout<< "Enter your choice: ";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                lb.addBook();
                break;
            case 2:
                cout<< "Enter ISBN of the borrwed book: ";
                getline(cin,isbn);
                lb.BorrowBook(isbn);
                break;
            case 3:
                cout<< "Enter ISBN of the returned book: ";
                getline(cin,isbn);
                lb.ReturnBook(isbn);
                break;
            case 4:
                cout<< "Enter ISBN of the archived book: ";
                getline(cin,isbn);
                lb.ArchivedBook(isbn);
                break;
            case 5:
                lb.disPlayAllBook();
                break;
            case 6:
                lb.SaveData();
                break;
            case 7:
                lb.LoadData();
                break;
            case 8:
                cout<< "Programme Finished.....";
                break;
        }
    }while (choice!=8);
    
}