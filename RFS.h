#ifndef RFS
#define RFS
#include <fstream>
#include <iostream>
#include "stor.h"
using namespace std ;
class rfs
{
protected:
    unsigned int records ;
    unsigned int size_of_record ;
    fstream OUT ;
    unsigned int position ( unsigned int i )
    {return (size_of_record * i );}
public:
    rfs ( int sizes  , char file[] ) ;
    bool put ( st * r , int i = -1 ) ;
    bool get ( st * r , unsigned int i ) ;
    bool good () ;
    unsigned int get_number_record () ;
    virtual ~rfs () ;
};
#endif // RFS
