// gcc -g -rdynamic ./execinfo.c -o execinfo

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

void baz() {
 int *foo = (int*)-1; // make a bad pointer
  printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }

#define BT_DEPTH 4
void print_bt() {
  void *array[BT_DEPTH];
  size_t size;
  size = backtrace(array, BT_DEPTH);
  fprintf(stderr, "Current backtrace:\n");
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  fprintf(stderr, "\n\n");
}
void stack1() { print_bt(); }
void stack2() { stack1(); }
void stack3() { stack2(); }
void stack4() { stack3(); }
void stack5() { stack4(); }

int main(int argc, char **argv) {
  signal(SIGSEGV, handler);   // install our handler
  stack5(); // Will call all the way up the stack until print_bt()
  foo(); // this will call foo, bar, and baz.  baz segfaults.
}
