
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
const int N=30;
struct Test
{
		char q[50];
		char a1[10];
		char a2[10];
		char a3[10];
		char a4[10];
		int ra;
};
//check if array 'p' include 'value';
//if include return '1' otherwise - '0';
int isHas(int* p,int off,int value)
{
		for(int i=0;i<off;i++)
				if(*(p+i)==value) return 1;
		return 0;
};
void test(Test*p,int n,int nq)
{
	int m[N];
	int b;
	double ra=0;
	for(int i=0;i<nq;i++)
	{
		do{ //generate unique number;
			m[i]=rand()%n;
			b=isHas(m,i,m[i]); //check if number unique;
		}while(b);
		//output question and answers;
		cout<<i+1<<". "<<(p+m[i])->q<<endl;
		cout<<"1. "<<(p+m[i])->a1<<endl;
		cout<<"2. "<<(p+m[i])->a2<<endl;
		cout<<"3. "<<(p+m[i])->a3<<endl;
		cout<<"4. "<<(p+m[i])->a4<<endl;
		cout<<"Answer->";
		cin>>b;
		if(b==(p+m[i])->ra){//check if answer is right;
			cout<<"You are right!\n";
			ra++;
		} else {
			cout<<"You are wrong!\n";
			cout<<"The number of right answer - "<<(p+m[i])->ra<<endl;
		}
	}
	cout<<"Percentage of right answers: "<<ra/nq*100<<"%"<<endl;

};
int main(int argc, _TCHAR* argv[])
{
	Test*p;
	int n;
	int nq;
	cout<<"Enter number of questions->";
	cin>>n;
	p=(Test*)malloc(sizeof(Test)*n);
	for (int i=0;i<n;i++)
	{   //input questions and variants;
		getchar();
		cout<<"Enter question->";
		gets((p+i)->q);
		cout<<"Enter 1-st variant->";
		gets((p+i)->a1);
		cout<<"Enter 2-nd variant->";
		gets((p+i)->a2);
		cout<<"Enter 3-rd variant->";
		gets((p+i)->a3);
		cout<<"Enter 4-th variant->";
		gets((p+i)->a4);
		cout<<"Enter number of right variant->";
		cin>>(p+i)->ra;
	}
	cout<<"Enter number of questions->";
	cin>>nq;
	system("cls");
	test(p,n,nq);
	free(p);
	getchar();	getchar();

	return 0;
}
