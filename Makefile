all:
	$(error ---------------Specify between "proc" or "thread"---------------)

proc: searchtest.c multitest_proc.o
	gcc -o search searchtest.c multitest_proc.o -lm

thread: searchtest.c multitest_thread.o
	gcc -o search searchtest.c multitest_thread.o -pthread -lm

proclib: multitest_proc.c
	gcc -c multitest_proc.c

threadlib: multitest_thread.c
	gcc -c multitest_thread.c -pthread

clean:
	rm search
