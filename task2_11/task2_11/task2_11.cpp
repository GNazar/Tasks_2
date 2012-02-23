// task2_11.cpp : Defines the entry point for the console application.
/*
11.	З клавіатури ввести послідовність записів, які містять дані про результати сесії студентів групи: 
<Прізвище>, <Ім’я>, <Список рейтингових оцінок>. Роздрукувати введені дані у вигляді таблиці, 
відсортувавши їх за прізвищами студентів в абетковому порядку. 
Визначити двох студентів з найвищим середнім рейтинговим балом.
*/
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
void sort(Student* p,int n)
{
        for(int i=0;i<n;i++)
                for (int j=0;j<n-i-1;j++)
                        if(strcmp((p+j)->sname,(p+j+1)->sname)>0)
                        {
                                Student buf=*(p+j);
                                *(p+j)=*(p+j+1);
                                *(p+j+1)=buf;
                        }

}
//function print best 2 students
void printBest2Students(Student* p,int n)
{
        Student p1,p2; //p1 save record with higher raiting; 
						//p2 save record with 2nd raiting;
        if(p->point>(p+1)->point){ //set begining values
                p1=*p;
                p2=*(p+1);
        }else{
                p1=*(p+1);
                p2=*p;
        }

        for (int i=2;i<n;i++)
        {
                if(p2.point<(p+i)->point){
                        if(p1.point<(p+i)->point){
                                p2=p1;
                                p1=*(p+i);
                        }else
                                p2=*(p+i);
                }
        }
        cout<<"Two best students:\n";
        print(&p1);
        print(&p2);
};
void main (void)
{
        Student* p;
        int n;
        cout<<"Emter number of records->";
        cin>>n;
		p=(Student*)malloc(sizeof(Student)*n);
        for(int i=0;i<n;i++)
        {		//input data
                getchar();
                cout<<"Enter students first name->";
                gets((p+i)->fname);
                cout<<"Enter students second name->";
                gets((p+i)->sname);
                cout<<"Enter students rating->";
                cin>>(p+i)->point;

        }
		cout<<"Sorted list by second name\n";
        sort(p,n);
        for(int i=0;i<n;i++)
                print(p+i);
        printBest2Students(p,n);
		free(p);
        getchar();
        getchar();
}
