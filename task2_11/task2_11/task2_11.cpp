// task2_11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
const int N=30;
using namespace std;
struct Student
{
        char sname[15];
        char fname[15];
        double point;
};
void print(Student *p)
{
         printf("%15s  %15s %f\n",p->sname,p->fname,p->point);
}
//function that sort list by name;
void sort(Student** p,int n)
{
        for(int i=0;i<n;i++)
                for (int j=0;j<n-i-1;j++)
                        if(strcmp(p[j]->sname,p[j+1]->sname)>0)
                        {
                                Student buf=*p[j];
                                *p[j]=*p[j+1];
                                *p[j+1]=buf;
                        }

}
//function print best 2 students
void printBest2Students(Student** p,int n)
{
        Student p1,p2; //p1 save record with higher raiting; 
						//p2 save record with 2nd raiting;
        if(p[0]->point>p[1]->point){ //set beginng values
                p1=*p[0];
                p2=*p[1];
        }else{
                p1=*p[1];
                p2=*p[0];
        }

        for (int i=2;i<n;i++)
        {
                if(p2.point<p[i]->point){
                        if(p1.point<p[i]->point){
                                p2=p1;
                                p1=*p[i];
                        }else
                                p2=*p[i];
                }
        }
        cout<<"Two best students:\n";
        print(&p1);
        print(&p2);
};
void del(Student** p,int n)
{       // free memory
        for(int i=0;i<n;i++)
                free(p[i]);
};
void main (void)
{
        Student* p[N];
        int n;
        char bf[15];
        cout<<"Emter number of records->";
        cin>>n;
        for(int i=0;i<n;i++)
        {		//input data
                getchar();
                p[i]=(Student*)malloc(sizeof(Student));
                cout<<"Enter students first name->";
                gets(bf);
                strcpy(p[i]->fname,bf);
                cout<<"Enter students second name->";
                gets(bf);
                strcpy(p[i]->sname,bf);
                cout<<"Enter students rating->";
                cin>>p[i]->point;

        }
		cout<<"Sorted list\n";
        sort(p,n);
        for(int i=0;i<n;i++)
                print(p[i]);
        printBest2Students(p,n);
		del(p,n);
        getchar();
        getchar();
}
