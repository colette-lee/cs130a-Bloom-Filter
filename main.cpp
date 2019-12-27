#include "BloomFilter.h"
#include "HashSet.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  PearsonHash p;
  JenkinsHash j;
  SquareRootHash sr(6,1000);
  DivisionHash d(6,1000);
  cout<<sr.hash(p.hash("fuck this assignment"))<<endl;
  cout<<d.hash(p.hash("fuck this assignment"))<<endl;
  cout<<p.hash("1fuck this assignment")<<endl;
  cout<<p.hash("2fuck this assignment")<<endl;
  cout <<"-------\n";

  cout << d.hash(p.hash("BLDM.SW00001A1,1991.02,1525,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,"))<<endl;
  cout << d.hash(p.hash("BLDM.SW00001A1,1991.03,1749,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,"))<<endl;
  cout << d.hash(p.hash("BLDM.SW00001A1,1991.04,1681,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,"))<<endl;
  cout << d.hash(p.hash("BLDM.SW00001A1,1991.05,1918,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,"))<<endl;


  /*
  BLDM.SW00001A1,1991.02,1525,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.03,1749,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.04,1681,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.05,1918,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.06,1589,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.07,1821,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.08,1657,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.09,1948,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.10,1934,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
  BLDM.SW00001A1,1991.11,1862,n,F,Number,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New,Number,
*/
  string s1 = "BLDM.SW00001C2,1972.03,48400000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,";
  string s2 = "BLDM.SW00001C2,1972.04,42600000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,";
  string s3 = "BLDM.SW00001C2,1972.05,54000000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,";
  string s4 = "BLDM.SW00001C2,1972.06,62400000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,";

  cout << p.hash(s1)<<endl;
  cout << p.hash(s2)<<endl;
  cout << p.hash(s3)<<endl;
  cout << p.hash(s4)<<endl;
  cout << p.hash("adfadsfad")<<endl;
  cout << p.hash("iue973hb")<<endl;
  cout << p.hash("kjeuh32bh \n")<<endl;
  cout << p.hash("kjadf dsfhuewhuiewbh io3738673b iuaewbhj,")<<endl;
  cout << "------\n";

/*
  BLDM.SW00001C2,1972.07,62600000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
  BLDM.SW00001C2,1972.08,58800000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
  BLDM.SW00001C2,1972.09,59100000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
  BLDM.SW00001C2,1972.10,74800000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
  BLDM.SW00001C2,1972.11,68000000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
  BLDM.SW00001C2,1972.12,54300000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
  BLDM.SW00001C2,1973.01,58300000,n,F,Dollars,0,Building Consents - BLD,Building consents by institutional control,Total all controls,All construction,New plus altered,Value,
*/

  ReciprocalHash r(3,1000);
  for (int i=1; i<=100; i++){
    cout << r.hash(i)<<endl;
  }
  cout << r.hash(23487438)<<endl;



  /*
    cout << "Jenkins squareroot"<<endl;
    for(int i=10; i<=100; i++){
      string command = "./bloom -s jenkins -i squareroot -k 10 -n 10 -m "+to_string(i)+" -t data.csv data.csv";
      system(command.c_str());

    }
    cout << "--------\n";
    cout << "Jenkins division"<<endl;
    for(int i=10; i<=100; i++){
      string command = "./bloom -s jenkins -i division -k 10 -n 10 -m "+to_string(i)+" -t data.csv data.csv";
      system(command.c_str());

    }
    cout << "--------\n";
    cout << "Jenkins reciprocal"<<endl;
    for(int i=10; i<=100; i++){
      string command = "./bloom -s jenkins -i reciprocal -k 10 -n 10 -m "+to_string(i)+" -t data.csv data.csv";
      system(command.c_str());

    }
    cout << "--------\n";
    cout << "Pearson squareroot"<<endl;
    for(int i=10; i<=100; i++){
      string command = "./bloom -s pearson -i squareroot -k 10 -n 10 -m "+to_string(i)+" -t data.csv data.csv";
      system(command.c_str());

    }
    cout << "--------\n";
    cout << "Pearson division"<<endl;
    for(int i=10; i<=100; i++){
      string command = "./bloom -s pearson -i division -k 10 -n 10 -m "+to_string(i)+" -t data.csv data.csv";
      system(command.c_str());

    }
    cout << "--------\n";
    cout << "pearson reciprocal"<<endl;
    for(int i=10; i<=100; i++){
      string command = "./bloom -s pearson -i reciprocal -k 10 -n 10 -m "+to_string(i)+" -t data.csv data.csv";
      system(command.c_str());

    }
    cout << "--------\n";
*/
}
