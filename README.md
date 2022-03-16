# C_sort_program

prefectures_1.csvには2020/3/18~2020/4/27までの都道府県別のcovid-19の感染者数、入院者数、退院者数、死亡者数のデータが入っています。

parse3.hでは感染データを格納するクラス"infection"を定義しています。infectionはメンバ関数として、文字列を構造体に格納する関数とinfectionに格納されたデータを出力する関数を持ちます。


infection_list3.hではクラス"infection"を継承したクラス"infection_list"を定義してリスト構造を形成しました。またデータの大小を比較する関数、リストにデータを挿入する関数、リストを表示する関数をプロトタイプ宣言しました。

load_infection_list3.cppでは新たにファイルにリストを書き込む関数、ファイルを読み込んでソートする関数を定義しました。

コンパイル方法
g++ -c parse3.cpp
g++ -c infection_list3.cpp
g++ -p load load_infection_list3.cpp parse3.o infection_list3.o

実行方法
./load -f ○○.csv -w ○○.txt -v
○○.csvには読み込みたいファイル名を指定してください。○○.txtには書き込みたいファイル名を指定してください。
