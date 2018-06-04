/*
 * hashMap.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Percy
 */

#include "hashMap.hpp"
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {

	map = new hashNode*[3457];
	for (int i = 0; i < 3457; i++) {
		map[i] = new hashNode();
	}
	numKeys = 0;
	mapSize = 3457;
	h1 = hash1;
	c1 = coll1;
	first = "";
	coll =0;
}

void hashMap::addKeyValue(string k, string v) {

	int place = getIndex(k);
	int i = 1;
	for (;;) {
		if (map[place]->keyword == k) {
			map[place]->addValue(v);
			break;
		}
		if (map[place]->keyword == "") {
			delete map[place];
			map[place] = new hashNode(k, v);
			if (numKeys == 0)
				first = k;
			numKeys++;
			break;
		}
		if (c1){
			place = collHash1(place, i);
			i++;
		}
		else place = collHash2(place);
		coll++;
	}

	if (numKeys >= mapSize * 0.7) {
		reHash();
	}
}

int hashMap::getIndex(string k) {
	if (h1)
		return calcHash(k);
	else
		return calcHash2(k);
}

int hashMap::calcHash(string k) {  //Hash index = (k[0] + k[1] + ...) % mapSize
	int h = 0;
	int L = k.length();
	for (int j = 0; j < L; j++) {
		h += ((int) k[j]);
	}
	h = (int) (h % mapSize);
	return h;
}

int hashMap::calcHash2(string k) { //Hash index = (int)k[0]
	int h = 0;
	h = (int)k[0];
	return h;
}

void hashMap::getClosestPrime() {
	int primeNum[353] = { 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067,
			3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181,
			3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259,
			3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347,
			3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457,
			3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533,
			3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613,
			3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697,
			3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793,
			3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881,
			3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967,
			3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057,
			4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153,
			4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243,
			4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339,
			4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447,
			4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523,
			4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639,
			4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723,
			4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813,
			4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933,
			4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003,
			5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099,
			5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197,
			5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303,
			5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413,
			5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483,
			5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573,
			5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669,
			5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779,
			5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851,
			5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939,
			5953, 5981, 5987 };

	int size = 353, mid = size / 2, low = 0, high = size - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (primeNum[mid] == mapSize) {
			mapSize = primeNum[mid * 2];
			return;
		} else if (primeNum[mid] > mapSize) {
			high = mid - 1;
		} else if (primeNum[mid] < mapSize) {
			low = mid + 1;
		}
	}
}

void hashMap::reHash() {
	int oldSize = mapSize;
	getClosestPrime();
	hashNode ** nMap = new hashNode*[mapSize];

	for (int i = 0; i < mapSize; i++) {
		nMap[i] = new hashNode();
	}

	for (int i = 0; i < oldSize; i++) {
		if (map[i]->values != NULL) {
			int nindex = getIndex(map[i]->keyword);
			for (;;) {
				if (nMap[nindex]->keyword == "") {
					nMap[nindex]->keyword = map[i]->keyword;
					nMap[nindex]->values = map[i]->values;
					nMap[nindex]->currSize = map[i]->currSize;
					nMap[nindex]->valuesSize = map[i]->valuesSize;
					break;
				}
				if (c1) {
					nindex = collHash1(nindex, i);
					i++;
				} else
					nindex = collHash2(nindex);
			}
		}
	}
	delete[] map;
	map = nMap;
}

int hashMap::collHash1(int h, int i) { //Double Hashing
	if (h >= mapSize)
		return 0;
	h = (h + i * i) % mapSize;
	return h;
}

int hashMap::collHash2(int h) { // Linear probing
	if (h >= mapSize)
		return 0;
	return h + 1;
}

int hashMap::findKey(string k) {
	for (int i = 0; i < mapSize; i++) {
		if (map[i]->keyword == k)
			return i;
	}
	return -1;
}

void hashMap::printMap() {
	for (int i = 0; i < mapSize; i++) {
		cout << i << " " << map[i]->keyword << " : ";
		for (int j = 0; j < map[i]->valuesSize; j++) {
			cout << map[i]->values[j] << " ";
		}
		cout << endl;
	}
}
