all:
	$(error ---------------Specify between "proc" or "thread"---------------)

proc: searchtest.c multitest_proc.o
	gcc -o searchproc searchtest.c multitest_proc.o

thread: searchtest.c multitest_thread.o
	gcc -o searchthread searchtest.c multitest_thread.o

proclib: multitest_proc.c
	gcc -c multitest_proc.c

threadlib: multitest_thread.c
	gcc -c multitest_thread.c

clean:
	rm searchproc
	rm searchthread
