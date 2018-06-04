/*
 * hashNode.hpp
 *
 *  Created on: Nov 25, 2017
 *      Author: Percy
 */

#include <string>
using namespace std;

#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_

class hashNode{
	friend class hashMap;
	string keyword;
	string *values;

	int valuesSize;
	int currSize;
public:
	hashNode();
	hashNode(string s);
	hashNode(string s, string v);
	void addValue(string v);
	void dblArray();
	string getRandValue();
};



#endif /* HASHNODE_HPP_ */
