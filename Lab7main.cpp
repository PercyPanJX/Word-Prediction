/*
 * Lab7main.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Percy
 */

#include "hashNode.hpp"
#include "hashMap.hpp"
#include "makeSeuss.hpp"

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	srand(time(NULL));
	makeSeuss *nHash = new makeSeuss("DrSeuss.txt","NewDrSeuss.txt", false, true);

	return 0;

}


