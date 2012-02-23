// task2_9.cpp : Defines the entry point for the console application.
/*
9.	З клавіатури ввести послідовність записів, які складаються зі слів-термінів і їх перекладів на іноземну мову. 
Очистити екран. Випадковим чином вибрати з масиву-словника задану кількість термінів (серед них не повинно бути повторень), 
до кожного з яких користувач повинен ввести переклад. Визначити відсоток правильних відповідей.   
*/
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
void test(Dictionary*p,int pn1,int pn2)
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
               cout<<(p+m[i])->word<<"->";
               gets(s);
               if (strcmp((p+m[i])->tran,s)==0) c++;
        }
        cout<<"Number of right answers-"<<c<<" "<<c/pn2*100<<"%"<<endl;
};
int main (void)
{
        Dictionary *p;
        int n,n1;
        char buf[30];
        cout<<"Enter number of words->";
        cin>>n;
        getchar();
		p=(Dictionary*)malloc(sizeof(Dictionary)*n);
        for (int i=0;i<n;i++)
        {       //inputting
                cout<<"Word->";
                gets((p+i)->word);
                cout<<"Translation->";
				gets((p+i)->tran);
                //strcpy(p[i]->tran,buf);
        }
        cout<<"Enter number of words you want to check->";
        cin>>n1;
        getchar();
        system("cls");
        test(p,n,n1);
		free(p);
        getchar();
        //getchar();

        return 0;
}

