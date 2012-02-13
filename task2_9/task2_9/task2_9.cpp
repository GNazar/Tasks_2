// task2_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
const int N=30;
using namespace std;
struct Dictionary
{
        char word[20];
        char tran[20];
};
int isHas(int* p,int off,int value)
{
        for(int i=0;i<off;i++)
                if(*(p+i)==value) return 1;
        return 0;
}
void test(Dictionary**p,int pn1,int pn2)
{
        int *m=(int*)malloc(pn2*sizeof(int));
        char s[20];
        double c=0;
		srand((unsigned)time( NULL ));
        for (int i=0;i<pn2;i++){
                int b;
                do{
                        m[i]=rand()%pn1;
                        b=isHas(m,i,m[i]);
               }while(b);
               cout<<p[m[i]]->word<<"->";
               gets(s);
               if (strcmp(p[m[i]]->tran,s)==0) c++;
        }
        cout<<"Number of rights answers-"<<c<<" "<<c/pn2*100<<"%"<<endl;
};
void del(Dictionary** p,int n)
{       // free memory
        for(int i=0;i<n;i++)
                free(p[i]);
};
int main (void)
{
        Dictionary *p[N];
        int n,n1;
        char buf[30];
        cout<<"Enter number of words->";
        cin>>n;
        getchar();
        for (int i=0;i<n;i++)
        {       //inputting
                p[i]=(Dictionary*)malloc(sizeof(Dictionary));
                cout<<"Word->";
                gets(buf);
                strcpy(p[i]->word,buf);
                cout<<"Translation->";
                gets(buf);
                strcpy(p[i]->tran,buf);
        }
        cout<<"Enter number of words you want to check->";
        cin>>n1;
        getchar();
        system("cls");
        test(p,n,n1);
		del(p,n);
        getchar();
        //getchar();

        return 0;
}

