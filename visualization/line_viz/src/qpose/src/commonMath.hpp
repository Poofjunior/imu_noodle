/** 
 * commonMath.hpp
 * \author Joshua Vasquez
 * \date June 12, 2014
 */

#ifndef COMMONMATH_HPP
#define COMMONMATH_HPP
#include <limits>
#include <ctgmath>
#include <cassert>
namespace CommonMath {

const float largeVal_ = 1000; 
const float smallVal_ = 0.001;
const int ulp_ = 10000;

/**
 * \fn parallel(float slopeA, slopeB)
 * \brief true if both lines are parallel within rounding error
 * \details handles special case of slopeA: +inf and slopeB: -inf
 */
bool parallel( float slopeA, float slopeB);

/**
 * \fn float round(float input)
 * \brief rounds input to infinities or to zero for extreme values to prevent
 *        rounding error
 */
float round(float input);


/**
 * bool almostEqual( float val1, float val2, int ulp)
 * \brief true if two numbers are close enough (for this algorithm) to be 
 *        considered equal
 * \param ulp is the number of units in the last place 
 * \details href='http://en.cppreference.com/w/cpp/types/numeric_limits/epsilon'>algorithm reference</a>
 *
 */
bool almostEqual( float val1, float val2, int ulp);

/**
 * \fn tuneAngle(float angle)
 * \brief converts input float (in radians) to the correct range of -Pi to Pi.
 */
float tuneAngle(float angle);

/**
 * \fn float pdf(float x, float mu, float sigma)
 * \brief return the probability of getting x from a Gaussian distribution
 *        centered at mu with std deviation sigma.
 */
float pdf(float x, float mu, float sigma);

};

#endif // COMMONMATH_HPP
