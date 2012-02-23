// task2_12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
const int N=30;
using namespace std;
struct Point
{
	int x,y;
	unsigned c;
};
void sortByColor(Point**p,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(p[j]->c<p[j+1]->c){
				Point tp=*p[j];
				*p[j]=*p[j+1];
				*p[j+1]=tp;
			}
};
void print(Point* p)
{
	printf("%3d  %3d   %u\n",p->x,p->y,p->c);
}
int isHas (int* m,int off,int value)
{
        for(int i=0;i<off;i++)
                if(*(m+i)==value)return 1;
        return 0;
};
void printMinDistance(Point**p,int n)
{
	int m[N];//colors;
	int pm[N][2];//coordinates of two nearest points
	double c[N];//min values
	int ij=0;
	int b,mini,minj;
	int mind[N];
	double min,m1,m2,l;
	for(int i=0;i<n-1;i++){
		Point bf;
		b=0;
		if(!isHas(m,i,p[i]->c)){
			//cout<<"(!isHas(m,i,p[i]->c))"<<endl;
			for(int j=i+1;j<n;j++)
			{
				if(p[i]->c==p[j]->c)
				{
					if(!b){
						m1=(p[i]->x-p[j]->x)*(p[i]->x-p[j]->x);
						m2=(p[i]->y-p[j]->y)*(p[i]->y-p[j]->y);
						min=sqrt(m1+m2);
						mini=i;
						minj=j;
					}
					b=1;
					m1=(p[i]->x-p[j]->x)*(p[i]->x-p[j]->x);
					m2=(p[i]->y-p[j]->y)*(p[i]->y-p[j]->y);
					l=sqrt(m1+m2);
					//cout<<min<<"if(min>l)"<<l<<endl;
					if(min>l){
						min=l;
						mini=i;
						minj=j;
						//cout<<mini<<"if(min>l)"<<minj<<endl;
						
					}

				}
			}

		}
	if(b){
			m[ij]=p[i]->c;
			pm[ij][0]=mini;
			pm[ij][1]=minj;
			ij++;
			//cout<<ij<<"if(b)"<<pm[ij][0]<<endl;
		}		
	}
	cout<<"ij==========="<<ij<<endl;
	for(int i1=0;i1<ij;i1++){
		cout<<"Two nearest points color "<<m[i1]<<endl;
		print(*(p+pm[i1][0]));
		print(*(p+pm[i1][1]));
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	Point*p[N];
	cout<<"Enter number of records->";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		p[i]=(Point*)malloc(sizeof(Point));
		cout<<"Enter x->";
		cin>>p[i]->x;
		cout<<"Enter y->";
		cin>>p[i]->y;
		cout<<"Enter color->";
		cin>>p[i]->c;
	}
	sortByColor(p,n);
		for(int i=0;i<n;i++)
			print(p[i]);
		cout<<"++++++++++++++++++++\n";
		printMinDistance(p,n);
		getchar();
		getchar();
}

