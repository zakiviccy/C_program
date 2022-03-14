#ifndef __PARSE_H__
#define __PARSE_H__

#include <string.h>
#include <iostream>
#include <fstream>
#include <ios>     
#include <iomanip> 

using namespace std;

/* 感染データを格納する構造体の定義 */
class infection{
public:
  int year;
  int month; 
  int day; 
  char prefecture[20];
  int infected;
  int hospital;
  int discharge;
  int death;
  void str2infection(char str[], class infection *inf);
  void print_infection(class infection *inf);
  void print_save_infection(class infection *inf, FILE *fp);
};


#endif
