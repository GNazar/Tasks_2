// task2_13.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
const int N=30;
using namespace std;
struct Stud{
        char name[20];
        int age;
        char s;
        double stature;
        double weight;
};
void print(Stud*p)
{
        printf("%20s %4d %2c %.2f %.2f\n",p->name,p->age,p->s,p->stature,p->weight);
};
 // function sort list by name
void sort(Stud** p,int n)
{
        for(int i=0;i<n;i++)
                for (int j=0;j<n-i-1;j++)
                        if(strcmp(p[j]->name,p[j+1]->name)>0)
                        {
                                Stud buf=*p[j];
                                *p[j]=*p[j+1];
                                *p[j+1]=buf;
                        }

};
//function print middle weight and stature by each sex
void printWeightStature(Stud**p,int n)
{
        int mc=0,wc=0;
        double sm=0,sw=0,wm=0,ww=0;
        for(int i=0;i<n;i++)
        {
                if(p[i]->s=='m')
                {
                        sm+=p[i]->stature;
                        wm+=p[i]->weight;
                        mc++;
                } else if(p[i]->s=='w')
                {
                        sw+=p[i]->stature;
                        ww+=p[i]->weight;
                        wc++;
                }
        }
        if(mc!=0){
                cout<<"Middle male weight - "<<wm/mc<<endl;
                cout<<"Middle male stature - "<<sm/mc<<endl;
        }
        if(wc!=0){
                cout<<"Middle female weight - "<<ww/wc<<endl;
                cout<<"Middle female stature - "<<sw/wc<<endl;
        }
};
void del(Stud** p,int n)
{       // free memory
        for(int i=0;i<n;i++)
                free(p[i]);
};
void main (void)
{
        Stud*p[N];
        int n;
        char bf[20];
        cout<<"Enter number of records->";
        cin>>n;
        for(int i=0;i<n;i++)
        {       //input data
                p[i]=(Stud*)malloc(sizeof(Stud));
                getchar();
                cout<<"Enter name->";
                gets(bf);
                strcpy(p[i]->name,bf);
                cout<<"Enter age->";
                cin>>p[i]->age;
                cout<<"Enter sex->";
                cin>>p[i]->s;
                cout<<"Enter stature->";
                cin>>p[i]->stature;
                cout<<"Enter weight->";
                cin>>p[i]->weight;
        }
        cout<<"Sorted list by name\n";
        sort(p,n);
        for(int i=0;i<n;i++)
        {
                print(p[i]);
        }
        printWeightStature(p,n);
		del(p,n);
        getchar();getchar();

}

