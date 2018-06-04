/*
 * makeSesus.hpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Percy
 */

#ifndef MAKESEUSS_HPP_
#define MAKESEUSS_HPP_

#include "hashMap.hpp"
#include <iostream>
using namespace std;

class makeSeuss{
	hashMap *ht;
	string fn;
	string newfile;
public:
	makeSeuss(string file, string newf, bool h1, bool c1);
	void readFile();
	void writeFile();
};



#endif /* MAKESEUSS_HPP_ */
