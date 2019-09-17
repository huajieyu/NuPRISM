/**
 * \file CRandomGen.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CRandomGen
 *
 * @author jiangl
 */

/** \addtogroup Base

    @{*/

#include <iostream>
#include <vector>
#include <time.h>

#ifndef __BASE_CRANDOMGEN_H__
#define __BASE_CRANDOMGEN_H__

namespace Base {

  /**
     \class CRandomGen
     User defined class CRandomGen ... these comments are used to generate
     doxygen documentation!
  */
  class CRandomGen{
    
  public:
    
    /// Default constructor
    //CRandomGen(){};
    CRandomGen(unsigned long ul_seed = time(0));
    CRandomGen(std::vector<unsigned long>& ul_seed);
    CRandomGen(std::istream& in);


    
    /// Default destructor
    ~CRandomGen(){};
   
    operator double() const;

    void setSeed(unsigned long ul_seed);
    void saveState(std::ostream& out)const;
    void loadState(std::istream& in);
   


 
  };
}

#endif
/** @} */ // end of doxygen group 

