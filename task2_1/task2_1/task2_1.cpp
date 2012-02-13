// task2_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
const int N=30;
struct Book {
        char author[30];
        char title[30];
        unsigned year;
        char note[50];
} ;
void printBook(Book* b)
{       //out data about 1 book;
      cout<<"Authors name->";
      cout<<b->author<<endl;
      cout<<"Title->";
      cout<<b->title<<endl;
      cout<<"Year of publishing->";
      cout<<b->year<<endl;
      cout<<"Note->";
      cout<<b->note<<endl;
}
void filterList(Book* p,int n)
{        // function prints books published before 1970;
        for (int i=0;i<n;i++)
        {
                if((p+i)->year<1970){
                        cout<<"Book "<<i+1<<":"<<endl;
                        printBook(p+i);
                }

        }
};
int main(int argc, char* argv[])
{
        Book b[N];
        int n,buf;
        puts("Enter number of records");
        cin>>n;
        for(int i=0;i<n;i++) //inputing
        {
                cout<<"Book: "<<i+1<<"."<<endl;
                cout<<"Authors name->";
                cin>>b[i].author;
                cout<<"Title->";
                cin>>b[i].title;
                cout<<"Year of publishing->";
                cin>>b[i].year;
                cout<<"Note->";
                cin>>b[i].note;
        }
        cout<<"+++++++++++Library+++++++++"<<endl;
        for(int i=0;i<n;i++) //print all list of Books;
        {
                cout<<"Book: "<<i+1<<"."<<endl;
                printBook(b+i);
        }
        cout<<endl;
        cout<<"Books published before 1970\n";
        filterList(b,n);
        getchar();
        getchar();
        return 0;
}