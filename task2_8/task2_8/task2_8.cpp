// task2_8.cpp : Defines the entry point for the console application.
/*
8.	З клавіатури ввести послідовність даних, які є координатами (x,y,z) проcторових точок.  
Роздрукувати введені дані у вигляді таблиці, відсортувавши їх за зростанням координати z. 
Визначити дві проcторові точки, віддаль між якими найменша.
*/
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
void sortByZ(MPoint *p,int n)// sort points by Z;
{
        for (int i=0;i<n;i++)
                for(int j=0;j<n-i-1;j++)
                        if((p+j)->z>(p+j+1)->z){
                                MPoint buf=*(p+j);
                                *(p+j)=*(p+j+1);
                                *(p+j+1)=buf;
                        }
};
void printPoint(MPoint* p)
{
        printf("%6d%6d%6d\n",p->x,p->y,p->z);
};
void printNearestPoints(MPoint* p,int n)//  function prints nearest 2 points;
{
        double dx=(p->x-(p+1)->x)*(p->x-(p+1)->x);
        double dy=(p->y-(p+1)->y)*(p->y-(p+1)->y);;
        double dz=(p->z-(p+1)->z)*(p->z-(p+1)->z);
        double d;
		double min=sqrt(dx+dy+dz);;
        MPoint p1=*p,p2=*(p+1);
        for (int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++){
                        dx=((p+i)->x-(p+j)->x)*((p+i)->x-(p+j)->x);
                        dy=((p+i)->y-(p+j)->y)*((p+i)->y-(p+j)->y);;
                        dz=((p+i)->z-(p+j)->z)*((p+i)->z-(p+j)->z);
                        d=sqrt(dx+dy+dz);
                        if(d<min){
                                p1=*(p+i);
                                p2=*(p+j);
								min=d;
                        }
                }
        printPoint(&p1);
        printPoint(&p2);
}
int main(int argc, char* argv[])
{
        MPoint* b;
        int n;
        cout<<"Enter number of records-> ";
        cin>>n;
		b=(MPoint*)malloc(sizeof(MPoint)*n);
        for(int i=0;i<n;i++) //inputing
        {
                
                cout<<"X->";
                cin>>(b+i)->x;
                cout<<"Y->";
                cin>>(b+i)->y;
                cout<<"Z->";
                cin>>(b+i)->z;
        }
        sortByZ(b,n);
        cout<<"++++++Sorted points by Z++++++"<<endl;
        for(int i=0;i<n;i++) //print all list of Points;
        {
                printPoint(b+i);
        }
        cout<<"++++++Two nearest points+++++++"<<endl;
        printNearestPoints(b,n);
        free(b);
        getchar();
        getchar();
}

