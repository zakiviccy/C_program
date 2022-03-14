#include "parse3.h"

class infection_list : public infection{
public:
  class infection data;  /*データの中身*/

  class infection_list *nextptr; /*次のデータ*/
};

int DayAscend(class infection *p, class infection *q);

int DayDescend(class infection *p, class infection *q);

int HospitalizationAscend(class infection *p, class infection *q);

int HospitalizationDescend(class infection *p, class infection *q);

void insert_infection_list(class infection_list** ptr, class infection newdata, int (*comp)(class infection*, class infection*));

void print_infection_list(class infection_list* ptr, char* prefecturename);

void save_infection_list(class infection_list* ptr, FILE *fp, char* prefecturename);

