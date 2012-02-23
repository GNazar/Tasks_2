// task2_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
const int N=30;
using namespace std;
struct Car
{
        char model[15];
        char number[10];
        int year;
        long run;
};
void printCar(Car* p)
{
        printf("%15s  %10s  %4d  %7d\n",p->model,p->number,p->year,p->run);
};
int isHas (char** m,int off,char* s)
{
        for(int i=0;i<off;i++)
                if(strcmp(*(m+i),s)==0)return 1;
        return 0;
};
void sort(Car*p,int n) //by year;
{
        for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                {
                        if((p+j)->year<(p+j+1)->year)
                        {
                                Car buf=*(p+j);
                                *(p+j)=*(p+j+1);
                                *(p+j+1)=buf;
                        }
                }
}
void printMiddleRun(Car*p,int n)
{
        int ij=0;
        long r[N]={0};//run
        int nc[N]={0};//number of cars
        char* m[N]; // model array
        for(int i=0;i<n;i++){
                if(!isHas(m,ij,(p+i)->model)){ //are in a list cars which have not been counted yet
                        m[ij]=(char*)malloc(sizeof(p->model));
                        strcpy(m[ij],(p+i)->model);
                        r[ij]=(p+i)->run;
                        nc[ij]=1;
                        for(int j=i+1;j<n;j++){ //count run and quantity car the same model
                                if(strcmp((p+i)->model,(p+j)->model)==0){
                                        r[ij]+=(p+j)->run;
                                        nc[ij]++;
                                }
                        }
                        ij++;
                }
        }
        for(int i=0;i<ij;i++)
                printf("%15s  %f\n",m[i],r[i]/(double)nc[i]);
};
void main (void)
{
        Car *p;
        int n;
        char buf[15];
        cout<<"Enter number of cars-> ";
        cin>>n;
		p=(Car*)malloc(sizeof(Car)*n);
        for (int i=0;i<n;i++)
        {       //input data
                getchar();
                cout<<"Name->";
                gets((p+i)->model);
                cout<<"Number->";
                gets((p+i)->number);
                cout<<"Year->";
                cin>>(p+i)->year;
                cout<<"Run->";
                cin>>(p+i)->run;
        }
        sort(p,n);
        cout<<"Sorted list by year:\n";
        for(int i=0;i<n;i++)
                printCar(p+i);
        cout<<"Middle run:\n";
        printMiddleRun(p,n);
		free(p);
        getchar();
        getchar();

}
