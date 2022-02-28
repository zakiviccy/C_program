/* 
   ファイルから1行ずつ読み込み、文字列配列に格納する 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse2.h"
#include <unistd.h>
#include "infection_list2.h"

#define FILEBUFSIZE  1024                // 1行の最大文字長
#define DEFAULT_R_FILE "prefectures_1.csv"
#define DEFAULT_W_FILE "out.txt"



int sampleNum = 0;                       // 実際に読み込んだ行数
struct infection_list* root;

void saveList(char filename[], char* prefecturename){
  FILE *fp;
  fp=fopen(filename,"w");
  if(fp==NULL){
    printf("file open error\n");
    return;
  }
  save_infection_list(root, fp, prefecturename);        //指定されたファイルポインタ、県名に対してsave_infection_listを呼ぶ
  fclose(fp);
  printf("File saved to %s\n",filename);
}

void readFile(char filename[]) {
    FILE *fp;
    char buf[FILEBUFSIZE];              // 読み込んだデータを一時的に格納する文字配列
    struct infection inf;               // 読み込んだデータを一時的に格納する構造体

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Cannot open file: %s\n", filename);
        exit(1);
    }

    /*入力されたアルファベットによってソートの仕方を変える*/

    printf("まずはソートの順番を選んでください\na:日付昇順\tb:日付降順\tc:入院患者数昇順\td:入院患者数降順\t:");

    char c;
    scanf("%c", &c);

    while (! feof(fp)) {             // ファイルの終わりまで
      if (fgets(buf, FILEBUFSIZE, fp) != NULL) {    // まずはbufに読み込んでから

	  /*読み込んだ内容を構造体に入れる*/
	  str2infection(buf, &inf);

	  /*構造体をリストに入れる*/
      if(c=='a'){        //aが入力された場合、日付昇順にソート
	  insert_infection_list(&root, inf, DayAscend);
      }
      else if(c=='b'){   //bが入力された場合、日付降順にソート
	  insert_infection_list(&root, inf, DayDescend);
      }
      else if(c=='c'){   //cが入力された場合、入院患者数昇順にソート
	  insert_infection_list(&root, inf, HospitalizationAscend);
      }
      else if(c=='d'){   //dが入力された場合、入院患者数降順にソート
	  insert_infection_list(&root, inf, HospitalizationDescend);
      }
      
      else{
          printf("error\n");
          exit(0);
      }
	  ++sampleNum;
      }
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int i;
    char buffer[256];

    /*ファイル名が指定されない場合は初期設定のファイルに作動する*/
    if(argc < 2){
        readFile(DEFAULT_R_FILE);
        printf("次にデータを閲覧したい県を漢字で入力してください（すべてのデータが見たい場合は all と入力）:");
        scanf("%s",buffer);
        print_infection_list(root, buffer);
        saveList(DEFAULT_W_FILE, buffer);
        exit(1);
    }

    int opt = 0;          
    char *filename1;
    char *filename2;

    

    while((opt = getopt(argc, argv, "f:w:v::")) != -1){
        switch(opt){
            case 'f':                   //fの後ろに読み込むファイル名を入力
                filename1 = optarg;
                readFile(filename1); 
                break;
            case 'w':                   //wの後ろに書き込むファイル名を入力
                printf("次にデータを見たい県を漢字で入力してください（すべてのデータが見たい場合は all と入力）:");
                scanf("%s",buffer);
                filename2 = optarg;
                saveList(filename2, buffer);  
                break;
            case 'v':                   //vが入力されたらリストを表示する
                printf("次にデータを閲覧したい県を漢字で入力してください（すべてのデータが見たい場合は all と入力）:");
                scanf("%s",buffer);
                print_infection_list(root, buffer);
                break;
            default:
                printf("error, try again\n");       
                return 1;

        }
    }
    return 0;
}
