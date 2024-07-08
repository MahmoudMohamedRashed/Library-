#include <conio.h>
#include <sstream>
#include "RFS.h"
#include "library.h"
#include "Books.h"
char againYON()
{
    char again=0;
    while((again!='Y')&&(again!='N'))
    {
        again=cin.get();
        again=toupper(again);
    }
    return again;
}
void CleanScreen()
{
    cin.ignore();
    cout.flush();
    for(int i=0; i<25; i++)
        cout<<endl;
}
int ShowMenu(void)
{
    int choice;
    cout<<"\t\t\t\t MainMenu\n\n";
    cout<<"\t\t\t (1) Add New Book.\n";
    cout<<"\t\t\t (2) Search for a book (by book title) (press double enter).\n";
    cout<<"\t\t\t (3) Search for a book (by book number).\n";
    cout<<"\t\t\t (4) Find all books by author.\n";
    cout<<"\t\t\t (5) Find all books by publisher.\n";
    cout<<"\t\t\t (6) Modify book cost (provide book number).\n";
    cout<<"\t\t\t (7) Modify book quantity (provide book number).\n";
    cout<<"\t\t\t (8) Remove book (provide book number).\n";
    cout<<"\t\t\t (9) Sort books by title.\n";
    cout<<"\t\t\t (10) Find all books with zero quantity.\n";
    cout<<"\t\t\t (11) Find all books with cost above a given value (provide reference cost).\n";
    cout<<"\t\t\t (12) Exit.\n";
    cout<<"\t\t Enter your choice (1...12) : ";
    cin>>choice;
    cin.ignore();
    return choice;
}

int main()
{
    Library library ("Library.txt") ;
    char again;
    int choice;
    bool exit=false;
    while(true)
    {
        CleanScreen();
        choice=ShowMenu();
        switch(choice)
        {
        case 1:
            again='Y';
            while(again=='Y')
            {
                if( library.add_book() )
                {
                    cout <<"\n\na New book has been"
                         <<" successfully added\n";
                    cout <<"Do you want to add another"
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't add a New book\n";
                    cin.get();
                }
            }
            break ;
        case 2:
            again='Y';
            while(again=='Y')
            {
                cin.ignore() ;
                if( library.search_title() )
                {
                    cout <<"\n\nsuccessfully search" ;
                    cout <<"Do you want to search again"
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be search\n";
                    cout<<"Press any key to continue";
                    cin.get();
                }
            }
            break ;
        case 3:
            again='Y';
            while(again=='Y')
            {
                if( library.search_number() )
                {
                    cout <<"\n\nsuccessfully search \n" ;
                    cout <<"Do you want to search again"
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be search\n";
                    cout<<"Press any key to continue";
                    cin.get();
                }
            }
            break ;
        case 4:
            again='Y';
            while(again=='Y')
            {
                cin.ignore() ;
                if( library.find_book_auther() )
                {
                    cout <<"\n\nprocess is successfully \n " ;
                    cout <<"Do you want to do that again "
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be found book \n";
                    cin.get();
                }
            }
            break ;
        case 5:
            again='Y';
            while(again=='Y')
            {
                cin.ignore() ;
                if( library.find_bool_publisher() )
                {
                    cout <<"\n\nprocess is successfully \n " ;
                    cout <<"Do you want to do that again "
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be found book \n";
                    cin.get();
                }
            }
            break ;
        case 6:
            again='Y';
            while(again=='Y')
            {
                if( library.chang_cost() )
                {
                    cout <<"\n\ncost is successfully change \n" ;
                    cout <<"Do you want to change another"
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be change the cost\n";
                    cin.get();
                }
            }
            break ;
        case 7:
            again='Y';
            while(again=='Y')
            {
                if( library.chang_quantity())
                {
                    cout <<"\n\nquantity is successfully change \n" ;
                    cout <<"Do you want to change another"
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be change the quantity\n";
                    cin.get();
                }
            }
            break ;
        case 8:
            again='Y';
            while(again=='Y')
            {
                if( library.delete_book() )
                {
                    cout<<"a book has been"
						<<" successfully removed\n";
					cout<<"Do you want to remove another"
						<< "(y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't remove a Student\n";
					cout<<"Press any key to continue";
                    cin.get();
                }
            }
            break ;
        case 9:
            again='Y';
                if( library.sort_title() )
                    cout << "\nsorted \n" ;
                else
                {
                    cout<<"couldn't do Sort\n";
					cout<<"Press any key to continue";
                }
            break ;
        case 10:
                if( library.find_book_zero_quantity() )
                {
                    cout <<"if successfully found \n" ;
                }
                else
                {
                    cout<<"couldn't be found\n";
                }
            break ;
        case 11:
            again='Y';
            while(again=='Y')
            {
                if( library.find_book_expensive() )
                {
                    cout <<"\n\nif successfully found\n";
                    cout <<"Do you want to found another"
                         <<" (y/n)?";
                    again=againYON();
                }
                else
                {
                    again='N';
                    cout<<"couldn't be found \n";
                    cin.get();
                }
            }
            break ;
        case 12 :
            exit=true;
            break;
        }
        if(exit)
			break;
    }
    return 0;
}
