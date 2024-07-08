#ifndef LIBRARY
#define LIBRARY
#include "RFS.h"
class Library
{
protected :
     rfs Rfs ;
public:
    Library ( char file[]) ;
    bool add_book () ;
    bool search_title  () ;
    bool search_number () ;
    bool find_book_auther() ;
    bool find_bool_publisher() ;
    bool chang_cost () ;
    bool chang_quantity () ;
    bool delete_book () ;
    bool sort_title () ;
    bool find_book_zero_quantity () ;
    bool find_book_expensive() ;
};
#endif // LIBRARY
