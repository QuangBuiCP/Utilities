/**
 *    File:    $TM_FILENAME
 *    Author:  QaergzBit / QuangBuiCP
 *    Created: $CURRENT_HOUR:$CURRENT_MINUTE:$CURRENT_SECOND $CURRENT_DATE.$CURRENT_MONTH.$CURRENT_YEAR (GMT + 7)
**/
#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <string>
#include <tuple>
#include <ctime>
#ifdef LOCAL
  #include "local/debug.hpp"
#else
  #define debug(...)
#endif
using namespace std;



void MAIN() {
  ;$0
}

signed main() {
  #ifndef LOCAL
    std::ios_base::sync_with_stdio(false);
    std::cin.exceptions(std::cin.failbit);
    std::cin.tie(0);
  #endif
  MAIN();
  #ifdef LOCAL
    std::clog << "\nTime elapsed: " << std::fixed << std::setprecision(4) << float(clock()) / CLOCKS_PER_SEC << " seconds.";
  #endif
}

/*
(*) Note: 
 - Use "(a + b - 1) / b" instead of "ceil(a / b)"

*/