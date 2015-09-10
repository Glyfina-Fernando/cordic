//=========================================================================
// cordic.cpp
//=========================================================================
// @brief : A CORDIC implementation of sine and cosine functions.

#include "cordic.h"
#include <math.h>

#include <iostream>
#include  <fstream>

using namespace std;
//-----------------------------------
// cordic function
//-----------------------------------
// @param[in]  : theta - input angle
// @param[out] : s - sine output
// @param[out] : c - cosine output
void cordic(theta_type theta, cos_sin_type *s, cos_sin_type *c)
{
    // -----------------------------
    // YOUR CODE GOES HERE
    // -----------------------------
    
    
    // Output file stream
    std::ofstream fp;
    fp.open ("out_unsigned.dat");
    
    #ifdef FIXED_TYPE // fixed-point design
    
    
    #define K_CONST 0.6072529351031 // value of k remains constant for all iterations
    
    
    static const theta_type angles[] = {
   0.785398163, 0.463647608,0.244978663,0.124354992,
   0.062418807,0.03123983,0.015623726,0.00781234,
   0.003906228,0.001953121,0.000976559,0.000488278,
   0.000244137,0.000122067,0.000061031, 0.000030514,
   0.000015255,0.000007626, 0.000003815, 0.000001904};
    
    
    
  
   
   theta_type X,Y,T,current;
  unsigned step;
  
  X=K_CONST;
  Y=0;
  current=0;
  for (step=0;step<NUM_ITER;step++){
    if(theta > current){
    T   = X - (Y >> step);
    fp<<"t>"<<T<<"\n";
    Y   = (X >> step) + Y;
    fp<<"y>"<<Y<<"\n";
    X   = T;
    fp<<"x>"<<X<<"\n";
    current+= angles[step];

    } else{
    T   = X + (Y >> step);
    fp<<"t<"<<T<<"\n";
    Y		= -(X >> step) + Y;
    fp<<"y<"<<Y<<"\n";		
    X   = T;
    fp<<"x<"<<X<<"\n";
    current -=angles[step];
    }
   }
   *c = X;
   *s = Y; 
   
   
 
    #else // floating-point design

    #define K_CONST 0.6072529351031 // value of k remains constant for all iterations
    
    
    static const float angles[] = {
   0.785398163, 0.463647608,0.244978663,0.124354992,
   0.062418807,0.03123983,0.015623726,0.00781234,
   0.003906228,0.001953121,0.000976559,0.000488278,
   0.000244137,0.000122067,0.000061031, 0.000030514,
   0.000015255,0.000007626, 0.000003815, 0.000001904};
    
    
  
  theta_type X,Y,T,current;
  unsigned step;
  X=K_CONST;
  Y=0;
  current=0;
  for (step=0;step<NUM_ITER;step++){
    if(theta > current){
    T   = X - (Y/(float)(1UL<<step)); 
    Y   = (X/(float)(1UL<< step) + Y;
    X   =  T;
    current+= cordic_ctab[step];

    } else{
    T   = X + (Y/(float)(1UL<<step));
    Y		= -(X/(float)(1UL<<step)) + Y;		
    X   = T;
    current -=cordic_ctab[step];
    }
   }
   *c = X;
   *s = Y; 
  #endif
  
  fp.close();

}


