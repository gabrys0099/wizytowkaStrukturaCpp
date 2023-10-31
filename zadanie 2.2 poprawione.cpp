//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 2.2
//  Stworzenie struktury wizyt�wek z funkcjami dodawania, usuwania, ogl�dania
//
//  WCY21IY1S1  Go��biowski Gabriel
//============================================================================


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

//stworzenie struktury

struct wizytowka
{
	char nazwisko[30];
	char imie[15];
	int nrTel;
	struct wizytowka *next;
	struct wizytowka *prev;
};
typedef struct wizytowka node;

//funkcja dodawania wizytowki

node *dodajWizytowke(node *head)
{
node *newNode = (node *) malloc(sizeof(node));
cout<<"\nnazwisko: ";
cin>>newNode->nazwisko;
cout<<"imie: ";
cin>>newNode->imie;
cout<<"nrTel: ";
cin>>newNode->nrTel;
newNode->next=NULL;
newNode->prev=NULL;

if(head==NULL)
{
	
	head=newNode;
}
else
{
	node *tmp=head;
	while(tmp->next !=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->prev=tmp;
}

if(head==NULL)
{
	cout<<"\n\ntak\n\n";
}
return head;
} 

//funkcja wy�wietlania wizyt�wki

void wyswietlenieListy(node *head)
{
	if(head==NULL)
	{
		cout<<"\n\npusto\n\n";
	}
	node *tmp=head;
	if(tmp==NULL)
	{
		return;
	}
	do
	{
		cout<<"nazwisko: "<<tmp->nazwisko<<", imie: "<<tmp->imie<<", nrTel: "<<tmp->nrTel<<"\n";
		tmp=tmp->next;
	}
	while(tmp!=NULL);
	
}

// Funkcja wypisywania wizyt�wki wspak

void wypisanieWspak(node *head)
{
	if(head!=NULL)
	{
		while (head->next!=NULL)
		{
			head=head->next;

		}
		while(head!=NULL)
		{
			cout<<"nazwisko: "<<head->nazwisko<<", imie: "<<head->imie<<", nrTel: "<<head->nrTel<<"\n";
			head=head->prev;
		}
	}
}

//Funkcja usuwania wizyt�wki

void usun(node **head, int nrTel)
{
	if(head!=NULL)
	{
	node *obecny =*head;
	node *poprzedni = obecny;
	node *nastepny=*head;
	while(obecny->nrTel!=nrTel)
	{
		poprzedni=obecny;
		obecny=obecny->next;
		nastepny=obecny->next;
	}
	if(obecny==*head)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		poprzedni->next=nastepny;
		nastepny->prev=poprzedni;
	}
	
}
else
{
	cout<<"nie ma �adnej wizyt�wki";
}
}
//Funkcja szukania wizyt�wki po numerze

void szukanieElementu(node **head, int nrTel)
{
	node *tmp=*head;
do {
	if(tmp->nrTel==nrTel)
	{
		cout<<"Wizytowka:\nNazwisko: "<<tmp->nazwisko<<", imie: "<<tmp->imie<<", nrTel: "<<tmp->nrTel<<"\n\n";
		return;
	}
	else if(tmp->next==NULL)
	{
		cout<<"nie ma takiej wizytowki\n\n";
	}
	tmp=tmp->next;
} while(tmp != NULL);

}



int main()
{
	
	char c=1;
	node *head=NULL;
     
   while(c!='e') 
   {
	
	cout << "d - dodaj wizytowke" << endl;
	cout << "s - szukaj wizytowki" << endl;
	cout << "w - wypisz wizytowki (A... Z)" << endl;
	cout << "v - wypisz wizytowki (Z... A)" << endl;
	cout << "u - usun wizytowke" << endl;
	cout << "e - zakoncz dzialania" << endl;
	cin>>c;
	fflush(stdin);// to trzeba doda� dla czyszczenia bufora znak�w
	   
	   switch(c) 
	   {
		case 'e': printf("\nkoniec\n\n"); 
			break;
		case 'd': 
		    cout<<"\nDodaj wizytowke\npodaj dane : ";
		    head=dodajWizytowke(head);
		    break;
		case 's':
			cout<<"\npodaj nrTel do znalezienia: ";
			int nrTel;
			cin>>nrTel;
			szukanieElementu(&head, nrTel);
			break;
		case 'w': 
			wyswietlenieListy(head);
			break;
		case 'v': 
		    cout<<"\n\nlista elementow\n"; 
			wypisanieWspak(head);
			break;
		case 'u':
			cout<<"\npodaj nrTel z wizytowki do usuniecia: ";
			int nrTel2;
			cin>>nrTel2;
			usun(&head, nrTel2);
			break;
		
        default : cout<<"zly znak\n";
		};
	
}
return 0;
}
