// task2_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int N=30;
struct Book{
        char author[20];
        char title[20];
        char publish[20];
        int year;
};
void sortBooks(Book *p,int n)// sort books by field "year"
{
        for (int i=0;i<n;i++)
                for(int j=0;j<n-i-1;j++)
                        if((p+j)->year<(p+j+1)->year){
                                Book buf=*(p+j);
                                *(p+j)=*(p+j+1);
                                *(p+j+1)=buf;
                        }
};
void printBook(Book* p)
{
        printf(" %-20s   %-20s   %-20s   %-d\n",p->author,p->title,p->publish,p->year);
};
void filterBooks(Book *p,int n)
{
        for (int i=0;i<n;i++){
                int l=strlen((p+i)->title);
                //check if title contains strings: C/C++,C++, C ,C., C at the begining and at the and;
                if(strstr((p+i)->title,"C/C++")||strstr((p+i)->title,"C++")||strstr((p+i)->title," C ")
                                ||strstr((p+i)->title,"C.")||(((p+i)->title[l-1]=='C')&&((p+i)->title[l-2]==' '))
                                ||(((p+i)->title[0]=='C')&&((p+i)->title[1]==' ')))
                        printBook((p+i));


        }
};
int main(int argc, char* argv[])
{
        Book *b;
        int n;
        cout<<"Enter number of records-> ";
        cin>>n;
		b=(Book*)malloc(sizeof(Book)*n);
        for(int i=0;i<n;i++) //inputing
        {
                //b[i]=(Book*)malloc(sizeof(Book));
                cout<<"Book: "<<i+1<<"."<<endl;
                getchar();
                cout<<"Authors name->";
				
                gets((b+i)->author);
                cout<<"Title->";
                gets((b+i)->title);
                cout<<"Name of publishing->";
                gets((b+i)->publish);
                cout<<"Year of publishing->";
                cin>>((b+i)->year);

        }
        sortBooks(b,n);
        cout<<"++++++Sorted library by year of publishing++++++"<<endl;
        for(int i=0;i<n;i++) //print all list of Books;
        {
                printBook(b+i);
        }
        puts("C/C++ books");
        filterBooks(b,n); // print C/C++ books;
		free(b);
        cout<<endl;
        getchar();
        getchar();
}
