// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
const int N=30;
struct Point
{
	int x,y;
};
struct Triangle
{
	Point A,B,C;
	double p;
};
void print(Triangle *p)
{
	printf("%3d %3d %3d %3d %3d %3d %3.1f\n",p->A.x,p->A.y,p->B.x,p->B.y,p->C.x,p->C.y,p->p);
};
//function sort reords by perimetr
void sort(Triangle** p,int n)
{		
        for(int i=0;i<n;i++)
                for (int j=0;j<n-i-1;j++)
					if(p[j]->p<p[j+1]->p)
                        {
                                Triangle buf=*p[j];
                                *p[j]=*p[j+1];
                                *p[j+1]=buf;
                        }

};
//function print all elemets which over min more than twise;
void printBigTriangles(Triangle** p,int n)
{
	int min=0;
	for(int i=1;i<n;i++)//find element with min perimetr
			if(p[i]->p<p[min]->p) min=i;
	cout<<"Elemets that over min element more than twice\n";
	//print(p[min]);
	for(int i=0;i<n;i++)//print all elemets which over min more than twise; 
		if(p[i]->p>2*p[min]->p)
			print(p[i]);
};
void del(Triangle** p,int n)
{       // free memory
        for(int i=0;i<n;i++)
                free(p[i]);
};
int _tmain(int argc, _TCHAR* argv[])
{
	
	Triangle *p[N];
	int n;
	cout<<"Enter number of records->";
	cin>>n;
	double a1,a2,a3;
	double x,y;
	for(int i=0;i<n;i++)
	{	//input coordinate
		p[i]=(Triangle*)malloc(sizeof(Triangle));
		cout<<"1st point\n";
		cout<<"X->";
		cin>>p[i]->A.x;
		cout<<"Y->";
		cin>>p[i]->A.y;
		//=============
		cout<<"2nd point\n";
		cout<<"X->";
		cin>>p[i]->B.x;
		cout<<"Y->";
		cin>>p[i]->B.y;
		//=============
		cout<<"3rd point\n";
		cout<<"X->";
		cin>>p[i]->C.x;
		cout<<"Y->";
		cin>>p[i]->C.y;
		//calculate distance between each point
		x=(double)(p[i]->B.x-p[i]->A.x)*(p[i]->B.x-p[i]->A.x);
		y=(double)(p[i]->B.y-p[i]->A.y)*(p[i]->B.y-p[i]->A.y);
		a1=sqrt(x+y);
		x=(double)(p[i]->C.x-p[i]->A.x)*(p[i]->C.x-p[i]->A.x);
		y=(double)(p[i]->C.y-p[i]->A.y)*(p[i]->C.y-p[i]->A.y);
		a2=sqrt(x+y);
		x=(double)(p[i]->C.x-p[i]->B.x)*(p[i]->C.x-p[i]->B.x);
		y=(double)(p[i]->C.y-p[i]->B.y)*(p[i]->C.y-p[i]->B.y);
		a3=sqrt(x+y);
		p[i]->p=a1+a2+a3;
	}
	sort(p,n);
	cout<<"Sorted list by perimeter\n";
	for(int i=0;i<n;i++){
		print(p[i]);
	}
	printBigTriangles(p,n);
	getchar();getchar();
	return 0;
}

