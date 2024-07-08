#ifndef STOR
#define STOR
class rfs ;
class st
{
protected :
    int record ;
    bool active ;
    friend class rfs ;
public:
    st()  ;
    bool is_active() ;
};
#endif
