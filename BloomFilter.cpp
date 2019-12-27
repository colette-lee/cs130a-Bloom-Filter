#include "BloomFilter.h"
#include <math.h>
#include <iostream>
using namespace std;

BloomFilter::BloomFilter(int k, int m, std::string strfn, std::string intfn){

  this->k = k;
  this->m = m;
  int arraySize = m/64;
  if(m%64>0)
    arraySize += 1;
  bits = new uint64_t[arraySize];
  for(int i=0; i<arraySize; i++){
    bits[i]=0;
  }

  if(strfn == "pearson"){
    this->strfn = new PearsonHash();
  } else {
    this->strfn = new JenkinsHash();
  }

  intfns = new IntegerHash*[k];
  for(int i=0; i<k; i++){
    if(intfn=="division"){
      intfns[i] = new DivisionHash(i,m);
    } else if (intfn=="reciprocal"){
      intfns[i] = new ReciprocalHash(i, m);
    } else {
      intfns[i] = new SquareRootHash(i, m);
    }
  }


}
BloomFilter::~BloomFilter(){
  delete[] bits;
  delete strfn;
  for(int i=0; i<k; i++){
    delete intfns[i];
  }
  delete[] intfns;

}

void BloomFilter::insert(const std::string& value){
  for(int i=0; i<k; i++){
    uint64_t bitIndex = intfns[i]->hash(strfn->hash(value));
    uint64_t bitInt = pow(2, bitIndex%64);
    bits[bitIndex/64] =  bits[bitIndex/64]|bitInt;
  }
}

bool BloomFilter::lookup(const std::string& value) const{
  for(int i=0; i<k; i++){
    uint64_t bitIndex = intfns[i]->hash(strfn->hash(value));

    uint64_t newInt = bits[bitIndex/64] >> bitIndex%64;
    if(newInt%2==0)
      return false;
  }
  return true;
}
