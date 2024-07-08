#include "RFS.h"
rfs ::~rfs ()
{
    OUT.close() ;
}
rfs :: rfs ( int sizes , char file[] )
{
    records=0;
	size_of_record=sizes;
    OUT.open(file,ios::app|ios::out|ios::in|ios::binary);
	OUT.close();
	OUT.open(file,ios::out|ios::in|ios::binary);
	if(good()){
		cout<< file <<" is Open"<<endl;
		OUT.seekg(0,ios::end);
		records=OUT.tellg()/size_of_record;
		}
	else{
		cout<< "could not open"<<file<<endl;
	}
}
bool rfs ::get(st* r ,unsigned int i)
{
    if (!good())
	{
		cout<< "error reading from file"<<endl;
		return false;
	}
	if (i<records)
	{
		OUT.seekg(position(i),ios::beg);
		OUT.read((char *)r,size_of_record);
		return true;
	}
	else
		return false;
}
bool rfs ::put(st* r , int i)
{
    if (!good())
	{
		cout<< "error writting to file"<<endl;
        return false;
	}
	if (i==-1)
	{
		r->active=true;
		r->record=records;
        OUT.seekp(position(records),ios::beg);
		OUT.write((char *)r,size_of_record );
		records++;
		return true;
	}
	else
		if (i<records)
		{
			r->record=i;
			OUT.seekp(position(i),ios::beg);
			OUT.write((char *)r,size_of_record );
			return true;
		}
		else
			return false;
}

bool rfs :: good ()
{
    return OUT.good() ;
}
unsigned int rfs ::get_number_record ()
{
    return records ;
}
