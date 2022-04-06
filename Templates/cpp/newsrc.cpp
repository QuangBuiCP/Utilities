/**
 *    File:    $TM_FILENAME
 *    Author:  QaergzBit / QuangBuiCP
 *    Created: $CURRENT_HOUR:$CURRENT_MINUTE:$CURRENT_SECOND $CURRENT_DATE.$CURRENT_MONTH.$CURRENT_YEAR (GMT + 7)
**/
#include "bits/stdc++.h"
#ifdef LOCAL
	#include "local/debug.hpp"
#else 
	#define debug(...)
#endif
using namespace std;



void solve_problem() {
	;$0
}

signed main() {
	#ifndef LOCAL
		std::ios_base::sync_with_stdio(false);
		std::cin.exceptions(std::cin.failbit);
		std::cin.tie(0);
	#endif
	int T = 1;
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		// std::cout << "Case #" << tc + 1 << ": ";
		solve_problem();
	}
	#ifdef LOCAL
		std::clog << "\nTime elapsed: " << std::fixed << std::setprecision(4) << float(clock()) / CLOCKS_PER_SEC << " seconds.";
	#endif
}

/*
(*) Note: 
 - Use "(a + b - 1) / b" instead of "ceil(a / b)"

*/