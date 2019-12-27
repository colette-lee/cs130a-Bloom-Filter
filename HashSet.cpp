#include "HashSet.h"
#include <iostream>
using namespace std;


HashSet::HashSet(){
  //construcotr
  nslots = 331;
  nitems = 0;
  this->intfn = new SquareRootHash(1, nslots);
  this->strfn = new JenkinsHash();
  this->strfn2 = nullptr;
  slots = new std::string*[nslots];
  for(int i=0; i<nslots; i++){
    slots[i]=nullptr;
  }

}

HashSet::~HashSet(){
  delete intfn;
  delete strfn;
  for(int i=0; i<nslots; i++){
    delete slots[i];
  }
  delete[]slots;
}
void HashSet::rehash(){
  std::string** temp = new std::string*[nslots];
  for(int i=0; i<nslots; i++){
    temp[i]=nullptr;
    if(slots[i]!=nullptr)
      temp[i]=slots[i];
  }
  nslots*=2;
  nitems=0;
  slots = new std::string*[nslots];
  delete intfn;
  intfn = new SquareRootHash(1, nslots);
  for(int i=0; i<nslots; i++){
    slots[i]=nullptr;
  }
  for(int i=0; i<nslots/2; i++){
    //cout << "i= "<<i<<endl;
    if(temp[i]!=nullptr)
      this->insert(*(temp[i]));
  }
  for(int i=0; i<nslots/2; i++){
    delete temp[i];
  }
  //cout << "done rehashing\n";
}

void HashSet::insert(const std::string& value){

  uint64_t index = intfn->hash(strfn->hash(value));
  while(slots[index]!=nullptr){
    //cout << "collision at "<<index<<endl;
    //if(*(slots[index])==value) cout << "repeat\n";
    index++;
    if(index==(uint64_t)nslots)
      index=0;
  }
  slots[index] = new std::string(value);
  //cout << "inserted "<<value<<" at index "<<index<<endl;
  nitems++;

  if((double)nitems/nslots > 0.6)
    this->rehash();

}
bool HashSet::lookup(const std::string& value) const{
  uint64_t index = intfn->hash(strfn->hash(value));
  uint64_t temp = index-1;
  while (true){
    if(slots[index]==nullptr){
      return false;
    } else if(value==*(slots[index])){
    //  cout << slots[index]<<" "<< *(slots[index])<<endl;
      //cout << "index = "<<index<<endl;
      return true;
    }
    if(index==temp)
      break;
    index++;
    if(index==(uint64_t)nslots)
      index=0;
  }
  return false;
}
