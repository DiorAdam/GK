#include "rational.h"
#include "gcd.h"

#include <stdexcept>
#include <ostream>
#include <iostream>


const Rational Rational::inverse() const {
  return Rational(_den, _num);
}


Rational::sign_type Rational::sign() const {
  return (_num < 0)? sign_type::NEGATIVE : sign_type::POSITIVE;
}

/* Print the value num/den to the supplied output stream, or 0 if 
 * the Rational happens to be identically zero.
 */
std::ostream& operator<<( std::ostream &os, const Rational &ratio ) {
  if( ratio == 0 ) {
    os << "0";
  } else {
    if( ratio.sign() == Rational::NEGATIVE ) {
      os << "-";
    }
    os << std::abs( ratio.num() ) << "/" << std::abs( ratio.den() );
  }
  return os;
}

/* This function will be called whenever the 
 * Rational is constructed from integers that
 * are supplied as numerator and denominator.
 * It should reduce the fraction to lowest terms;
 * for example, when we try to construct a
 * Rational{ 4, -8 }, this is the function that
 * will cause the number to be exactly the same
 * as Rational{ -1, 2 }. Numerators should be
 * the only value potentially negative after
 * the call to ::normalize().
 * Throw bad_rational if there is an attempt
 * to set one with a zero denominator.
 */
void Rational::normalize() {
  // sign
  if (_num*_den < 0){
    _num = -abs(_num);
    _den = abs(_den);
  }
  else{
    _num = abs(_num);
    _den = abs(_den);
  }
  // factorization
  int a{abs(_num)}, b{abs(_den)};
  int _gcd = gcd(a, b);
  _num /= _gcd;
  _den /= _gcd;
}

// Return the float precision number corresponding to the Rational
float Rational::to_float() const {
  return (float) _num / (float) _den;
}

// Return the double precision number corresponding to the Rational
double Rational::to_double() const {
  return (double) _num / (double) _den;
}
