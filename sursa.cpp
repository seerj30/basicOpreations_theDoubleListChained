#include<iostream>
#include<fstream>
using namespace std;

int n;

struct nod
{
	int inf;
	nod *adr,*urm;
}*u;

void creare(nod *&p)
{
	ifstream f("in.txt");
	int x;
	nod *q;
	while(f>>x)
	{
		n++;
		if(p==NULL)
		{
			p=new nod;
			p->inf=x;
			p->urm=NULL;
			p->adr=NULL;
			u=p;
		}
		else
		{
			q=new nod;
			q->inf=x;
			u->urm=q;
			q->adr=u;
			u=q;
		}
	}
	u->urm=NULL;
}

void afisare(nod *p)
{
	nod *q;
	for(q=p;q;q=q->urm)
		cout<<q->inf<<" ";
	cout<<endl;
	/*for(q=u;q;q=q->adr)
		cout<<q->inf<<" ";
	cout<<endl;*/
}

void add_k(nod *&p)
{
	int k;
	do
	{
		cout<<"Pozitia de adaugat: ";
		cin>>k;
	}while(k<=0 || k>= n+1);
	nod *q=p,*r;
	int i;
	for(i=1;q && i<k;q=q->urm,i++);
	r=new nod;
	cout<<"Informatia de adaugat: ";
	cin>>r->inf;
	if(k==1)
	{
		r->urm=p;
		r->adr=NULL;
		p->adr=r;
		p=r;
	}
	else
		if(k==n+1)
		{
			u->urm=q;
			q->adr=u;
			q->urm=NULL;
			u=q;
		}
		else
		{
			r->adr=q->adr;
			q->adr->urm=r;
			r->urm=q;
			q->adr=r;
		}
		n++;
}

void delete_k(nod *&p)
{
	int k;
	do
	{
		cout<<"Pozitia de sters: ";
		cin>>k;
	}while(k<=0 || k>= n+1);
	nod *q=p,*r;
	int i;
	for(i=1;q && i<k;q=q->urm,i++);
	r=q;
	if(k==1)
	{
		p=p->urm;
		delete r;
	}
	else
		if(k==n)
		{
			u=r->adr;
			u->urm=NULL;
			delete r;
		}
		else
		{
			q->adr->urm=r->urm;
			r->urm->adr=q->adr;
			delete r;
		}
		n--;
}

int main()
{
	nod *p=NULL;
	creare(p);
	afisare(p);
	add_k(p);
	afisare(p);
	delete_k(p);
	afisare(p);
	return 0;
}
