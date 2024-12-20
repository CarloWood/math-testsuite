#include "sys.h"
#include "IEEE754.h"
#include <cmath>
#include "debug.h"

constexpr mp_prec_t precision_in_bits = 256;
constexpr double log10_of_two = 0.30102999566;
constexpr int mpprecision = precision_in_bits * log10_of_two;

int main()
{
  Debug(NAMESPACE_DEBUG::init());

  // Set the default floating-point precision.
  mpfr_set_default_prec(precision_in_bits);

  // By default, print everything with mpprecision digits precision.
  std::streamsize const old_precision = std::cout.precision(mpprecision);
  std::ios::fmtflags const old_flags = std::cout.setf(std::ios::fixed);

  IEEE754 val1 = 0.000012345;
  IEEE754 val2 = 1.0 / 3.0;

  Dout(dc::notice, std::fixed << (val1 / val2));
}
