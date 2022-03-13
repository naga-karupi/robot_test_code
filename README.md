# How to test this repository

まぁ堅苦しい英語っぽいやつはおいといて  
とりあえずコンパイルエラーでも実行時エラーでも変な挙動でも適当に伝えてくれ

まずはpc_connectionのやつをビルドしてくれ  

## pc_connection

### pyplot.cpp

ライブラリをクローンするからそのためののディレクトリに移動して

```bash
$ git clone https://github.com/lava/matplotlib-cpp.git
```

そこから`matplot.mk`を開いて

```makefile
# 前略
INC    = -I/usr/include/python3.8 -I ~/project/includes/
LIB    = -lpython3.8
#後略
```

を

```makefile
# 前略
INC    = -I/usr/include/python # pythonのバージョン \
        -I # クローンしたディレクトリ
LIB    = -lpython #pythonのバージョン
#後略
```

に書き換える  
これは環境によって変わるから見せてもらわないとなんとも言えない

```bash
$ make -f matplot.mk
```

これでコンパイルできたらおk

### serial.cpp

```bash
sudo apt install libserial-dev
```

これを叩いたら

```bash
make -f serial.mk
```

コンパイルが通ればおk

### main.cpp

`makefile` を開いて

```makefile
# 前略
INC    = -I ~/project/includes/ \
		 -I/usr/include/python3.8 \
		 -I ~/project/cpp/src/libserial/src/libserial/
LIB    = -lpython3.8 \
         -lserial
#後略
```

を

```makefile
# 前略        
INC    = -I # クローンしたディレクトリ \
		 -I/usr/include/python # pythonのバージョン \
		 -I ~/project/cpp/src/libserial/src/libserial/
LIB    = -lpython #pythonのバージョン \
         -lserial
#後略
```

コンパイルが通ればおk
