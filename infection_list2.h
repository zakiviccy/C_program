#include "parse2.h"

struct infection_list{
  struct infection data;  /*データの中身*/

  struct infection_list *nextptr; /*次のデータ*/
};

void insert_infection_list(struct infection_list** ptr, struct infection newdata, int (*comp)(struct infection*, struct infection*));

void print_infection_list(struct infection_list* ptr, char* prefecturename);

void save_infection_list(struct infection_list* ptr, FILE *fp, char* prefecturename);

int DayAscend(struct infection *p, struct infection *q);

int DayDescend(struct infection *p, struct infection *q);

int HospitalizationAscend(struct infection *p, struct infection *q);

int HospitalizationDescend(struct infection *p, struct infection *q);


