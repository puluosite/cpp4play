// include class headfile
#include "cpp11test.h"
// include C/C++ lib
#include <iostream>
// include other lib
// include other local headfiles


void Cpp11test::runAuto() {
	for (auto x:{1,2,4,8,16}) {
		std::cout<<x<<std::endl;
	}

}