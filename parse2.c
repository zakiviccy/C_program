#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse2.h"

#define MAX_NUM 32         // 1行に記述される最大要素数
#define TOKLEN  64         // 要素の最大文字長

/* 文字列を分解し、構造体に格納する */
void str2infection(char str[], struct infection *inf) {
  int i, j;
  char *token[MAX_NUM];

  /* strtok()の第2引数で順に区切って要素に分割し、char *token[] に格納 */
  for (i=0; i < MAX_NUM; i++) {
    if ((token[i] = strtok(str, ",")) == NULL) {
      break;
    }
    str = NULL;  /* 2回目以降は第1引数にヌルポインタを指定する; strtok()の仕様 */
  }
  
  /* 各tokenに何が入ったかを確認! */
  /*
    for (j=0; j < i; j++) {
      printf("%02d: %s\n", j, token[j]);
    }
  */
  
  /* 分割した要素から、各データを取り出して格納 */
  inf->year   = atoi(token[0]);                // 0: 年
  inf->month  = atoi(token[1]);                // 1: 月
  inf->day    = atoi(token[2]);                // 2: 日
  strcpy(inf->prefecture,token[3]);//県名
  inf->infected = atoi(token[4]);                 // 4: 感染者数
  inf->hospital = atoi(token[5]);                 // 5: 入院者数
  inf->discharge = atoi(token[6]);                 // 6: 退院者数
  inf->death = atoi(token[7]);                 // 7: 死亡者数 

}

/* データを出力する */
void print_infection(struct infection *inf) {
  printf("%04d\t%02d\t%02d\t%s\t%03d\t%03d\t%03d\t%03d\n", 
	 inf->year, inf->month, inf->day, 
	 inf->prefecture,
	 inf->infected,inf->hospital,inf->discharge,inf->death);
}

void print_save_infection(struct infection *inf, FILE *fp) {
  fprintf(fp, "%04d\t%02d\t%02d\t%s\t%03d\t%03d\t%03d\t%03d\n", 
	 inf->year, inf->month, inf->day, 
	 inf->prefecture,
	 inf->infected,inf->hospital,inf->discharge,inf->death);
}
