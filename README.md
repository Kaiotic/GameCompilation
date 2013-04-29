GameCompilation
===============

BS Projekt


## Style Guidelines ##

- <b>Function parameters are prefixed with an underscore</b>
  
  <pre>int add(int _iX, int _iY) { ... }</pre>

- <b>Strings are passed to functions as a const char*</b>
  
    <pre>void print(const char* _String) { ... }</pre>

- <b>External variables are prefixed with "ext_"</b>
  
    <pre>external int ext_iAge</pre>

- <b>Structs are declared as typedef and suffixed with "_t"</b>
  
    <pre>typedef struct Person { ... } Person_t
    Person_t* person = (Person_t*)malloc(...)</pre>

- <b>Pointers are declared as follows</b>
    
    <pre>int* x = &myInt</pre>
