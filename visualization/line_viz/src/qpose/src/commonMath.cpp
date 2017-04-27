/**
 * commonMath.cpp
 * \author Joshua Vasquez
 * \date June 14, 2014
 */
#include "commonMath.hpp"

//FIXME: change std::numeric_limits<float>::infinity to a constexpr

bool CommonMath::parallel(float slopeA, float slopeB)
{
    // TODO: rounding here is probably redundant at this point.
    // round huge and tiny numbers to inf and zero respectively:
    float roundedA = round(slopeA);
    float roundedB = round(slopeB);

    // Handle special case where parallel vertical lines could round to 
    // opposite slopes.
    if((roundedA == std::numeric_limits<float>::infinity() ||
       (roundedA == -std::numeric_limits<float>::infinity())) &&
       (roundedB == std::numeric_limits<float>::infinity() ||
       (roundedB == -std::numeric_limits<float>::infinity())))
        return true;

    // check if both lines are equal to within 1% 
    if (almostEqual(roundedA, roundedB, ulp_))
        return true;

    return false;
}

float CommonMath::tuneAngle(float angleInDeg)
{
    float newAngle  = angleInDeg;
    // Map to circle range:
    while (newAngle > 2*M_PI)
        newAngle -= 2*M_PI;    
    while (newAngle < -2*M_PI)
        newAngle += 2*M_PI;    

    // Convert to -Pi to Pi range. FIXME: should this be pi/2 to pi/2 range??
    if (newAngle > M_PI)
        newAngle -= 2*M_PI;
    if (newAngle < -M_PI)
        newAngle += 2*M_PI;

    return newAngle;

}


float CommonMath::round(float input)                                                    
{                                                                               
    if (input > largeVal_)                                                          
        return std::numeric_limits<float>::infinity(); 
    if (input < -largeVal_)                                                          
        return -std::numeric_limits<float>::infinity();                          
    if (std::abs(input) < smallVal_) 
        return 0.;                                                                 
    return input;                                                               
} 


bool CommonMath::almostEqual(float x, float y, int ulp)
{
    // Compare all subnormal values (like infinity) exactly.
/// OLD METHOD: slow!
    assert((isnan(x) == false) && (isnan(x) == false));

    if (!std::isnormal(x) || !std::isnormal(y))                                 
        return x == y;                                                          

/// NEW METHOD: avoid calls to isnormal
/*
    if (x == y)
            return true;
*/
    return std::abs(x - y) <=                                                   
        std::numeric_limits<float>::epsilon() * std::abs(x + y) * ulp;
}

float CommonMath::pdf(float x, float mu, float sigma)
{

    /// Apparently: inf - inf = nan. Fix that here
    if ( ((x == std::numeric_limits<float>::infinity()) &&
          (mu == std::numeric_limits<float>::infinity())) ||  
         ((x == -std::numeric_limits<float>::infinity()) &&
          (mu == -std::numeric_limits<float>::infinity())) )
    return 1.0;

    /// note: weird constant is sqrt(2*pi) precomputed
/*
    return (1/(sigma * (2.5066282746310002))) * 
            exp(- (pow((x - mu), 2))/(2*sigma*sigma) );
*/
    
    return  exp(- (pow((x - mu), 2)) / (2*sigma*sigma) );
}
