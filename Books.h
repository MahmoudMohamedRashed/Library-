#ifndef BOOKS
#define BOOKS
#include "RFS.h"
#include <string>
typedef unsigned int uint  ;
class Library ;
class book : public st
{
protected:
        uint number ;
        uint available_quantity ;
        uint number_page ;
        double cost ;
        char author[200] ;
        char publisher[200] ;
        char name[200] ;
        friend class Library ;
public:
        book() ;
};
#endif // BOOKS
