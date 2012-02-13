// task2_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
const int N=30;
struct MPoint{
        int x;
        int y;
        int z;
};
void sortByZ(MPoint **p,int n)// sort points by Z;
{
        for (int i=0;i<n;i++)
                for(int j=0;j<n-i-1;j++)
                        if(p[j]->z>p[j+1]->z){
                                MPoint buf=*p[j];
                                *p[j]=*p[j+1];
                                *p[j+1]=buf;
                        }
};
void printPoint(MPoint* p)
{
        printf("%6d%6d%6d\n",p->x,p->y,p->z);
};
void deletePoints(MPoint** p,int n)
{       // free memory
        for(int i=0;i<n;i++)
                free(p[i]);
};
void printNearestPoints(MPoint** p,int n)//  function prints nearest 2 points;
{
        double min=0;
        MPoint p1,p2;
        for (int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++){
                        double dx=(p[i]->x-p[j]->x)*(p[i]->x-p[j]->x);
                        double dy=(p[i]->y-p[j]->y)*(p[i]->y-p[j]->y);;
                        double dz=(p[i]->z-p[j]->z)*(p[i]->z-p[j]->z);
                        double d=sqrt(dx+dy+dz);
						//cout<<d<<endl;
						//cout<<dx<<endl;
						//cout<<dy<<endl;
                       // DOMAIN Error (LOOK FOR IN INTERNET!!!!)
                        if(d>=min){
                                p1=*p[i];
                                p2=*p[j];
								min=d;
                        }
                }
        printPoint(&p1);
        printPoint(&p2);
}
int main(int argc, char* argv[])
{
        MPoint* b[N];
        int n;
        cout<<"Enter number of records-> ";
        cin>>n;
        for(int i=0;i<n;i++) //inputing
        {
                b[i]=(MPoint*)malloc(sizeof(MPoint));
                cout<<"X->";
                cin>>b[i]->x;
                cout<<"Y->";
                cin>>b[i]->y;
                cout<<"Z->";
                cin>>b[i]->z;
        }
        sortByZ(b,n);
        cout<<"++++++Sorted points by Z++++++"<<endl;
        for(int i=0;i<n;i++) //print all list of Points;
        {
                printPoint(b[i]);
        }
        cout<<"++++++Two nearest points+++++++"<<endl;
        printNearestPoints(b,n);
        deletePoints(b,n);
        getchar();
        getchar();
}

