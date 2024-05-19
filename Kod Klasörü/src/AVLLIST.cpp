
#include "AVLLIST.hpp"
#include "AVL.hpp"
#include "Stack.hpp"
#include <iomanip>
#include <iostream>

using namespace std;


Control::Control()
{
	cfirst = 0;
}

void Control::addtree(AVL* avl)
{

	Cnode* nevv = new Cnode(avl);
	if (cfirst == 0)
		cfirst = nevv;
	else
	{
		Cnode* tmp = cfirst;
		while (tmp->cnext != 0)
		{
			tmp = tmp->cnext;
		}
		tmp->cnext = nevv;

	}
	avlsayi++;
	
}

Control::~Control()
{
	Cnode* tmp = cfirst;
	while (tmp != 0)
	{
		tmp = tmp->cnext;
		delete cfirst;
		cfirst = tmp;
	}
}

void Control::pushstacks()
{
	Cnode* tmp =cfirst;

	while(tmp!=nullptr)
	{
		tmp->avl->pushstack(*(tmp->stack));
		tmp=tmp->cnext;
	}

}

void Control::deletestacks()
{
	Cnode* tmp= cfirst;

	while(tmp!=nullptr)
	{
		tmp->stack->~Stack();
		tmp=tmp->cnext;
	}
}

void Control::lastfunc()
{
		Cnode* currentv2=cfirst;
		pushstacks();

		Cnode* current=cfirst;
		while(current!=0)
		{
			int ascii = current->avl->AVLToplamDugumDeger()%(90-65 + 1) + 65;
			cout<<(char)ascii;
			current=current->cnext;
		}
		
		while(currentv2->cnext)
		{		
			int max, min;
			max=min=currentv2->stack->topof();
			while(currentv2!=nullptr)
			{
				if(currentv2->stack->topof()>max)
				{
					max=currentv2->stack->topof();
				}
			
				if(currentv2->stack->topof()<min)
				{
					min=currentv2->stack->topof();
				}
				currentv2=currentv2->cnext;
			
			}			

			int oldavlsayi=avlsayi;

			currentv2=cfirst;
			while(!(min==currentv2->stack->topof()))
			{
				currentv2=currentv2->cnext;
			}
			currentv2->stack->pop();
			
			currentv2=cfirst;
			Cnode* currentbefore=currentv2;
			while(currentv2!=nullptr)
			{
				
				if(!currentv2->stack->topof())
				{
					Cnode* delnode=cfirst;
					if(currentv2==cfirst)
					{
						cfirst=cfirst->cnext;
					}
					else
					{
						delnode=currentv2;
						currentbefore->cnext=currentv2->cnext;
						currentv2=currentbefore;
						
					}
					delete delnode;
					Cnode* current=cfirst;
					avlsayi--;
					system("cls");
					deletestacks();
					while(current!=0)
					{
						int ascii = current->avl->AVLToplamDugumDeger()%(90-65 + 1) + 65;
						cout<<(char)ascii;
						current=current->cnext;
					}
					pushstacks();
					
				}
				currentbefore=currentv2;
				currentv2=currentv2->cnext;
			}	


			if(oldavlsayi==avlsayi)
			{

				currentv2=cfirst;
				while(!(max==currentv2->stack->topof()))
				{
					currentv2=currentv2->cnext;
				}
				currentv2->stack->pop();


				currentv2=cfirst;
				Cnode* currentbefore=currentv2;
				while(currentv2!=nullptr)
				{
					
					if(!currentv2->stack->topof())
					{
						Cnode* delnode=cfirst;
						if(currentv2==cfirst)
						{
						cfirst=cfirst->cnext;
						}
						else
						{
							delnode=currentv2;
							currentbefore->cnext=currentv2->cnext;
							currentv2=currentbefore;
						}
						delete delnode;
						Cnode* current=cfirst;
						avlsayi--;
						system("cls");
						deletestacks();
						while(current!=0)
						{
							int ascii = current->avl->AVLToplamDugumDeger()%(90-65 + 1) + 65;
							cout<<(char)ascii;
							current=current->cnext;
							
						}
						pushstacks();
						
					}
					currentbefore=currentv2;
					currentv2=currentv2->cnext;
				}	
			}
			currentv2 = cfirst;
		}
		system("cls");
		cout<<"=============================="<<endl;
		cout<<"|"<<setw(28)<<" "<<"|"<<endl;
		cout<<"|"<<setw(28)<<" "<<"|"<<endl;
			
		cout<<"|"<<setw(4)<<" "<<"Son Karakter: ";
		int ascii=currentv2->avl->AVLToplamDugumDeger()%(90-65 + 1) + 65;
		cout<<(char)ascii;
		cout<<setw(9)<<" "<<"|"<<endl;
				
		cout<<"|"<<setw(4)<<" "<<setw(12)<<left<<"AVL No"<<": "
		<<setw(10)<<left<<currentv2->avl->gettreenum()<<"|"<<endl;;
				
		cout<<"|"<<setw(28)<<" "<<"|"<<endl;
		cout<<"|"<<setw(28)<<" "<<"|"<<endl;
		cout<<"=============================="<<endl;
	}
	
	
	


