一、Bakery算法如果没有choosing
假设有两个进程T0,T1，初始时刻num[0],num[1]均为0，
首先num[1]=1，然后num[0]=1，这两个进程都进入了临界区。

二、了解race condition. 进入race-condition代码目录。
执行 ./x86.py -p loop.s -t 1 -i 100 -R dx， 请问dx的值是什么？
-1
执行 ./x86.py -p loop.s -t 2 -i 100 -a dx=3,dx=3 -R dx ， 请问dx的值是什么？
对于这两个线程而言都是-1
执行 ./x86.py -p loop.s -t 2 -i 3 -r -a dx=3,dx=3 -R dx， 请问dx的值是什么？
-1
变量x的内存地址为2000, ./x86.py -p looping-race-nolock.s -t 1 -M 2000, 请问变量x的值是什么？
1
变量x的内存地址为2000, ./x86.py -p looping-race-nolock.s -t 2 -a bx=3 -M 2000, 请问变量x的值是什么？为何每个线程要循环3次？
6  bx初值为3

变量x的内存地址为2000, ./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 0， 请问变量x的值是什么？
1或2

变量x的内存地址为2000, ./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 1， 请问变量x的值是什么？
1或2

变量x的内存地址为2000, ./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 2， 请问变量x的值是什么？
1或2

变量x的内存地址为2000, ./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 1， 请问变量x的值是什么？
1