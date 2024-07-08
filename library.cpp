#include "library.h"
#include <cstring>
#include <string>
#include "Books.h"
#include "RFS.h"
Library::Library( char file[] ) :
    Rfs( sizeof(book), file ) {}
bool Library::add_book()
{
    book newbook ;
    cout<< "\t\t\t Adding new book \n\n" ;
    cout<< "\nBook Number : " ;
    cin >> newbook.number ;
    cout<< "\nBook Name : " ;
    cout.flush();
    cin.ignore() ;
    cin.getline( newbook.name, 200 ) ;
    cout<<"\nAuthor : " ;
    cout.flush();
    //cin.ignore() ;
    cin.getline ( newbook.author, 200 ) ;
    cout<<"\nPublisher : " ;
    cout.flush();
    //cin.ignore() ;
    cin.getline ( newbook.publisher, 200 ) ;
    cout<< "\nQuantity : " ;
    cin >> newbook.available_quantity ;
    cout<<"\nNumber of Pages : " ;
    cin >> newbook.number_page ;
    cout<<"\nCost : " ;
    cin >> newbook.cost ;
    return (Rfs.put(&newbook)) ;
}
bool Library ::chang_cost ()
{
    book modfy_book ;
    cout << "\t\t\tModify Book Cost \n\n" ;
    unsigned int num, location;
    cout << "\nEnter Book Number to be modified : " ;
    cin  >> num  ;
    location = 0 ;
    if ( !Rfs.get( &modfy_book, location++ ) )
        return false ;
    while ( (modfy_book.number != num) || (!modfy_book.is_active()) )
    {
        if (!Rfs.get(&modfy_book, location++))
            return false ;
    }
    --location ;
    cout << "\nOld cost  :  " << modfy_book.cost  ;
    cout << "\nNew Cost  :  " ;
    cin  >> modfy_book.cost   ;
    return (Rfs.put(&modfy_book, location )) ;
}
bool Library ::chang_quantity()
{
    book modfy_book ;
    cout << "\t\t\tModify Book Quantity \n\n" ;
    unsigned int num, location;
    cout << "\nEnter Book Number to be modified : " ;
    cin  >> num ;
    location = 0 ;
    if ( !Rfs.get( &modfy_book, location++ ) )
        return false ;
    while ( (modfy_book.number != num) || (!modfy_book.is_active()) )
    {
        if (!Rfs.get(&modfy_book, location++))
            return false ;
    }
    --location ;
    cout << "\nOld Quantity : " << modfy_book.available_quantity  ;
    cout << "\nNew Quantity : " ;
    cin  >> modfy_book.available_quantity ;
    return (Rfs.put(&modfy_book, location)) ;
}
bool Library ::delete_book ()
{
    book delete_book ;
    cout << "\t\t\tRemove Book \n\n" ;
    unsigned int num, location;
    cout << "\nEnter Book Nnumber to be removed : " ;
    cin  >> num ;
    location = 0 ;
    if ( !Rfs.get( &delete_book, location++ ) )
        return false ;
    while ( (delete_book.number != num) || (!delete_book.is_active()) )
    {
        if (!Rfs.get(&delete_book, location++))
            return false ;
    }
    --location ;
    delete_book.active = false ;
    return ( Rfs.put(&delete_book, location) ) ;
}
bool Library ::search_title()
{
    book books ;
    cout << "\t\t\t Search for a book (by book title) \n\n" ;
    char num[200] ;
    unsigned int location = Rfs.get_number_record() ;
    cout <<"\nEnter Name of Book : " ;
    //cin.ignore() ;
    cin.getline( num , 200 ) ;
    for (int i = 0 ; i < location ; i++)
    {
        if ( ! Rfs.get((&books), i ))
            return false ;
        if ( !books.is_active() ) continue ;
        bool test = 1 ;
        for ( int i = 0 ; i < 200 ; i++ )
        {
            if ( num[i] )
            {
                if ( num[i] != books.name[i] )
                {
                    test = 0 ;
                    break ;
                }
            }
            else break ;
        }
        if ( test &&(books.is_active()))
        {
            cout << endl << endl ;
            cout << "\nBook Number    :  " << books.number ;
            cout.flush();
            cout << "\nBook Name      :  " << books.name ;
            cout.flush();
            cout << "\nBook Author    :  " << books.author ;
            cout.flush();
            cout << "\nBook Publisher :  " << books.publisher ;
            cout << "\nBook Quantity  :  " << books.available_quantity;
            cout << "\nBook cost      :  " << books.cost ;
            cout << "\nNumber of Pages:  " <<books.number_page ;
        }
    }
    return true ;
}
bool Library ::search_number()
{
    book books ;
    cout << "\t\t\t Search for a book (by book number) \n\n" ;
    unsigned int numb ;
    int location = 0 ;
    cout <<"\nEnter Number of Book : " ;
    cin  >> numb ;
    if ( ! Rfs.get(&books, location++) )
        return false ;
    while ( (books.number != numb) || !(books.is_active()) )
    {
        if (! Rfs.get(&books, location++))
            return false ;
    }
    cout << endl << endl ;
            cout << "\nBook Number    :  " << books.number ;
            cout.flush();
            cout << "\nBook Name      :  " << books.name ;
            cout.flush();
            cout << "\nBook Author    :  " << books.author ;
            cout.flush();
            cout << "\nBook Publisher :  " << books.publisher ;
            cout << "\nBook Quantity  :  " << books.available_quantity;
            cout << "\nBook cost      :  " << books.cost ;
            cout << "\nNumber of Pages:  " <<books.number_page ;
    return true ;
}
bool Library ::find_book_auther ()
{
    book books ;
    cout << "\t\t\tFind all books by author \n\n" ;
    cout << "\nEnter Name of Author : " ;
    char num[200] ;
    unsigned int location = Rfs.get_number_record() ;
    //cin.ignore() ;
    cin.getline( num, 200 ) ;
    for (int i = 0 ; i < location ; i++)
    {
        if ( ! Rfs.get((&books), i ))
            return false ;
        if ( !books.is_active() ) continue ;
        if (( strcmp(num, books.author) == 0 ) &&(books.is_active()))
        {
            cout << endl << endl ;
            cout << "\nBook Number    :  " << books.number ;
            cout.flush();
            cout << "\nBook Name      :  " << books.name ;
            cout.flush();
            cout << "\nBook Author    :  " << books.author ;
            cout.flush();
            cout << "\nBook Publisher :  " << books.publisher ;
            cout << "\nBook Quantity  :  " << books.available_quantity;
            cout << "\nBook cost      :  " << books.cost ;
            cout << "\nNumber of Pages:  " <<books.number_page ;
        }
    }
    return true ;
}
bool Library ::find_bool_publisher()
{
    book books ;
    cout << "\t\t\tFind all books by publisher \n\n" ;
    cout << "\nEnter Name of publisher : " ;
    char num[200] ;
    unsigned int location = Rfs.get_number_record() ;
    //cin.ignore() ;
    cin.getline( num, 200 ) ;
    for (int i = 0 ; i < location ; i++)
    {
        if ( ! Rfs.get((&books), i ))
            return false ;
        if ( !books.is_active() ) continue ;
        if (( strcmp(num, books.publisher) == 0 ) &&(books.is_active()))
        {
            cout << endl << endl ;
            cout << "\nBook Number    :  " << books.number ;
            cout.flush();
            cout << "\nBook Name      :  " << books.name ;
            cout.flush();
            cout << "\nBook Author    :  " << books.author ;
            cout.flush();
            cout << "\nBook Publisher :  " << books.publisher ;
            cout << "\nBook Quantity  :  " << books.available_quantity;
            cout << "\nBook cost      :  " << books.cost ;
            cout << "\nNumber of Pages:  " <<books.number_page ;
        }
    }
    return true ;
}
bool Library ::find_book_zero_quantity ()
{
    book books ;
    cout << "\t\t\tFind all books with zero quantity \n\n" ;
    unsigned int location = Rfs.get_number_record() ;
    for (int i = 0 ; i < location ; i++)
    {
        if ( ! Rfs.get((&books), i ))
            return false ;
        if ( !books.is_active() ) continue ;
        if ( (books.available_quantity == 0) && (books.is_active()) )
        {
            cout << endl << endl ;
            cout << "\nBook Number    :  " << books.number ;
            cout << "\nBook Name      :  " << books.name ;
            cout << "\nBook Author    :  " << books.author ;
            cout << "\nBook Publisher :  " << books.publisher ;
            cout << "\nBook Quantity  :  " << books.available_quantity;
            cout << "\nBook cost      :  " << books.cost ;
            cout << "\nNumber of Pages:  " <<books.number_page ;
        }
    }
    return true ;
}
bool Library ::find_book_expensive ()
{
    book books ;
    cout << "\t\t\tFind all books with cost above a given value \n\n" ;
    unsigned int location = Rfs.get_number_record() ;
    double money ;
    cout << "\nEnter Number of cost : " ;
    cin  >> money ;
    for (int i = 0 ; i < location ; i++)
    {
        if ( ! Rfs.get((&books), i ))
            return false ;
        if ( !books.is_active() ) continue ;
        if ( (books.cost > money) && (books.is_active()) )
        {
            cout << endl << endl ;
            cout << "\nBook Number    :  " << books.number ;
            cout << "\nBook Name      :  " << books.name ;
            cout << "\nBook Author    :  " << books.author ;
            cout << "\nBook Publisher :  " << books.publisher ;
            cout << "\nBook Quantity  :  " << books.available_quantity;
            cout << "\nBook cost      :  " << books.cost ;
            cout << "\nNumber of Pages:  " <<books.number_page ;
        }
    }
    return true ;
}
bool Library ::sort_title()
{
    book book1, book2 ;
    unsigned int Loc1,Loc2;
    unsigned int NRecords;
    cout<<"\t\t\t\tSort books by title\n\n";
    NRecords= Rfs.get_number_record() ;
    cout<<"Sorting ...\n";
    for(Loc1=0; Loc1<NRecords-1; Loc1++)
    {
        for(Loc2=Loc1+1; Loc2<NRecords; Loc2++)
        {
            if(! Rfs.get(&book1,Loc1) )
                return false;
            if(! Rfs.get(&book2,Loc2) )
                return false;
            if(!book2.is_active())
                continue;
            if((book1.is_active()) && ( strcmp((book1.name), (book2.name)) > -1 ))
            {
                Rfs.put(&book2,Loc1);
                Rfs.put(&book1,Loc2);
            }
        }
    }
    cout<<"Sorting completed.\n";
    for ( Loc1 = 0 ; Loc1 < NRecords ; Loc1++ )
    {
        if ( (Rfs.get(&book1, Loc1)) && (book1.is_active()) )
        {
            cout << endl << endl ;
            cout << "\nBook Number    :  " << book1.number ;
            cout << "\nBook Name      :  " << book1.name ;
            cout << "\nBook Author    :  " << book1.author ;
            cout << "\nBook Publisher :  " << book1.publisher ;
            cout << "\nBook Quantity  :  " << book1.available_quantity;
            cout << "\nBook cost      :  " << book1.cost ;
            cout << "\nNumber of Pages:  " << book1.number_page ;
        }
    }
    return true;
}
