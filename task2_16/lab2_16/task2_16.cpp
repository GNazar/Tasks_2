// lab2_16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
const int N=30;
struct Participant
{
	char fname[20];
	char sname[20];
	int school,form;
};
void sort(Participant** p,int n)
{
        for(int i=0;i<n;i++)
                for (int j=0;j<n-i-1;j++)
					if(p[j]->school>p[j+1]->school)
                    {
						Participant buf=*p[j];
                        *p[j]=*p[j+1];
                        *p[j+1]=buf;
                        } else if (p[j]->school==p[j+1]->school)
							if(p[j]->form>p[j+1]->form){
								Participant buf=*p[j];
								*p[j]=*p[j+1];
								*p[j+1]=buf;							
							}
};
void print(Participant* p)
{
	printf("%-20s %-20s %4d %3d\n",p->fname,p->sname,p->school,p->form);
};
int isHas (int* m,int off,int value)
{
        for(int i=0;i<off;i++)
                if(*(m+i)==value)return 1;
        return 0;
};
void printPupilFromNineForm(Participant**p,int n)
{
        int maxn;
		int maxnc;
		int ij=0;
		const int form=9;
        int nc[N]={0};//number of pupils 9 form
        int m[N]; // schools
        for(int i=0;i<n;i++){
			if(!isHas(m,ij,p[i]->school)){ //are in a list school which have not been counted yet;
				if(p[i]->form==form){	//are participant study at 9 form;
						nc[ij]=1;
                        m[ij]=p[i]->school;
                        for(int j=i+1;j<n;j++){ //count quantity pupils from 9 form
							if(p[i]->school==p[j]->school)
								if(p[j]->form==form) nc[ij]++;
                        }
                        ij++;
				}
             }
        }
        for(int i=0;i<ij;i++)
                printf("School number %d, number of pupil from 9 form - %d\n",m[i],nc[i]);
		maxn=m[0];
		maxnc=nc[0];
		for(int i=1;i<ij;i++)
		{
			if(nc[i]>maxnc){
				maxn=m[i];
				maxnc=nc[i];
			}
		}
		if(ij==0)
			printf("There are no studets 9 forms\n");
		else
			printf("Most of the pupils 9 form from school number %d\n",maxn);
};
void del(Participant**p,int n)
{	//free memory;
	for(int i=0;i<n;i++){
		free(*(p+i));
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	Participant*p[N];
	int n;
	char bf[20];
	cout<<"Enter number of records->";
	cin>>n;
	for(int i=0;i<n;i++){
		//inputing data
		p[i]=(Participant*)malloc(sizeof(Participant));
		getchar();
		cout<<"Enter first name->";
		gets(bf);
		strcpy(p[i]->fname,bf);
		cout<<"Enter second name->";
		gets(bf);
		strcpy(p[i]->sname,bf);
		cout<<"Enter number of school->";
		cin>>p[i]->school;
		cout<<"Enter form->";
		cin>>p[i]->form;
	}
	sort(p,n);
	cout<<"++++Sorted list++++\n";
	for(int i=0;i<n;i++){
		print(p[i]);
	}
	printPupilFromNineForm(p,n);
	del(p,n);
	getchar();
	getchar();
	return 0;
}

