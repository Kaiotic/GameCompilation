GameCompilation
===============

BS Projekt


## Style Guidelines ##

"_" - prefix for function parameters
  int add(int _iX, int _iY) { ... }

string parameters as const char*
  void print(const char* _String) { ... }

"ext_" - prefix for external variables
  external int ext_iAge

structs as typedef and "_t" - suffix
  typedef struct Person { ... } Person_t
  Person_t* person = (Person_t*)malloc(...)

pre-increment instead of post-increment as often as possible

Pointer declaration
  int* x = &myInt
instead of
  int *x = &myInt

as the pointer is part of the data type
