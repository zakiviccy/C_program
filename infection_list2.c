#include"parse2.h"
#include"infection_list2.h"

/*日付の前後を判定する関数(昇順)*/
int DayAscend(struct infection *p, struct infection *q){
  return(p->year>q->year||
  (p->year == q->year && p->month > q->month)||
  (p->year == q->year && p->month == q->month && p->day > q->day));
}

/*日付の前後を判定する関数(降順)*/
int DayDescend(struct infection *p, struct infection *q){
  return(p->year<q->year||
  (p->year == q->year && p->month < q->month)||
  (p->year == q->year && p->month == q->month && p->day < q->day));
}

/*入院患者数の前後を判定する関数(昇順)*/
int HospitalizationAscend(struct infection *p, struct infection *q){
  return (p->hospital > q->hospital);
}

/*入院患者数の前後を判定する関数(降順)*/
int HospitalizationDescend(struct infection *p, struct infection *q){
  return (q->hospital > p->hospital);
}

/*リストの途中にcompの順番に従ってデータを挿入する*/
void insert_infection_list(struct infection_list** ptr, struct infection newdata,int (*comp)(struct infection*, struct infection*)){
  if(*ptr==NULL || (*comp)(&((*ptr)->data), &newdata)>0){
    // (1) セルを動的に作成 
    struct infection_list *newcell;
    newcell=(struct infection_list *)malloc(sizeof(struct infection_list));
    if(newcell==NULL){
      printf("No memory!\n"); exit(0);
    }
    // (2) 作成したセルにデータを格納
    newcell->data=newdata;
    newcell->nextptr=*ptr;  // 新しいセルが末尾；以下でもよい！ newcell->nextpt=NULL;
    // (3) 元の末尾から新しいセルにポインタを張る
    *ptr=newcell;
  }
  else {  // 末尾以外ならば、ポインタを辿って、次のセルを調べる
    insert_infection_list(&(*ptr)->nextptr, newdata, comp);
  }
}

/*リストのうち入力された県のデータを先頭から最後までを表示する関数*/
void print_infection_list(struct infection_list* ptr, char* prefecturename){  
  /*表示にはparse2.cのprint_infectionを利用*/
  /*mylist.cのtraverseListを参考にする*/ 

  char str[] = "all" ;      

  while (ptr!=NULL) {
    if(strcmp(str , prefecturename)==0){            //allと入力された場合すべて表示
      print_infection(&(ptr->data)); 
      ptr=ptr->nextptr;
    }
    else
    {
    if(strcmp(((ptr->data).prefecture), prefecturename)==0){           //入力された県のデータを表示
    print_infection(&(ptr->data)); 
    } 
    ptr=ptr->nextptr;
    }
  }
}  
 

/*リストのうち入力された県のデータを先頭から最後までファイルに書き出す関数*/
void save_infection_list(struct infection_list* ptr, FILE *fp, char* prefecturename){  
  
  /*表示にはparse2.cのprint_infectionを利用*/
  while (ptr!=NULL) {
    if(strcmp(((ptr->data).prefecture), prefecturename)==0){
    print_save_infection(&(ptr->data), fp);
    }
    ptr=ptr->nextptr;
  }
}




