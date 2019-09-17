/**
 * \file CGaussianDistrib.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CGaussianDistrib
 *
 * @author jiangl
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CGAUSSIANDISTRIB_H__
#define __BASE_CGAUSSIANDISTRIB_H__
#include <cmath>
#include "CRandomGen.h"



namespace Base {

  /**
     \class CGaussianDistrib
     User defined class CGaussianDistrib ... these comments are used to generate
     doxygen documentation!
  */
  class CGaussianDistrib{
    
  public:
    
    /// Default constructor
    //CGaussianDistrib(){};
    CGaussianDistrib(CRandomGen& io_randomNumber)
                :m_rnd( io_randomNumber ),
                vx(0.0),
                vy(0.0),
                rSq(0.0),
                coef(0.0)
    {
    };


    
    /// Default destructor
    ~CGaussianDistrib(){};

    double generateStandard() const
    {
        static bool switchIsStored(false);
        static double number(0.0);

        while ( not switchIsStored )
        {
            vx = 2*m_rnd - 1.0;
            vy = 2*m_rnd - 1.0;

            rSq = vx*vx + vy*vy;

            if ( rSq > 0.0 and rSq <= 1.0 )
            {
                switchIsStored = true;
                coef = sqrt( -2*log(rSq)/rSq );
                number = coef*vy;

                return coef*vx;
            }
        }

        switchIsStored = false;
        return number;
    }


    inline double generate(const double average, const double sigma) const
    {
                return (sigma <= 0.0) ? average : average + sigma*generateStandard();
    }


private:
        CRandomGen m_rnd;
        mutable double vx;
        mutable double vy;
        mutable double rSq;
        mutable double coef;




    
  };
}

#endif
/** @} */ // end of doxygen group 

