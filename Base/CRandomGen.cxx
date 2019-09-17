#ifndef __BASE_CRANDOMGEN_CXX__
#define __BASE_CRANDOMGEN_CXX__

#include "CRandomGen.h"
extern "C"
{
  #include "mt19937-3.C"

}

namespace Base{





CRandomGen::CRandomGen(unsigned long ul_seed)
{
    setSeed(ul_seed);
}
 
void CRandomGen::setSeed(unsigned long ul_seed)
{
    ::sgenrand(ul_seed);
}
 
CRandomGen::CRandomGen(std::vector<unsigned long>& ul_seed)
{
    for(int i=0;i<N;i++)
        mt[i] = ul_seed[i];
    mti=N;
}
 
CRandomGen::CRandomGen(std::istream& in)
{
    loadState(in);
}
 
 
CRandomGen::operator double() const
{
    return ::genrand();
}
 
void CRandomGen::loadState(std::istream& in)
{
    in>>mti;
    for(int i=0;i<N;++i)
        in>>mt[i];
}
 
void CRandomGen::saveState(std::ostream& out) const
{
    out<<mti<<std::endl;
    for(int i=0;i<N;++i)
        out<<mt[i]<<std::endl;
}


























}
#endif
