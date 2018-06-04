/*
 * hashNode.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: Percy
 */

#include "hashNode.hpp"
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

hashNode::hashNode(){
	keyword = "";
	values = NULL;
	valuesSize = 0;
	currSize = 0;
}

hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
}

hashNode::hashNode(string s, string v){
	keyword = s;
	values = new string[100];
	values[0]= v;
	valuesSize = 100;
	currSize = 1;
}

void hashNode::addValue(string v){
	if(currSize >= valuesSize) dblArray();
	values[currSize] = v;
	currSize += 1;
}

void hashNode::dblArray(){
	string * narray = new string[valuesSize * 2];
	for(int i =0; i < valuesSize; i++){
		narray[i] = values[i];
	}
	valuesSize = valuesSize * 2;
	delete [] values;
	values = narray;
}

string hashNode::getRandValue(){
	if(currSize==0) return "";
	int randNum = rand() % currSize;
	return values[randNum];
}
