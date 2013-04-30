GameCompilation
===============

- <a href="http://de.wikipedia.org/wiki/Dame_%28Spiel%29#Checkers">Checkers</a>
- <a href="http://de.wikipedia.org/wiki/Reversi">Reversi</a>
- <a href="http://de.wikipedia.org/wiki/4_gewinnt">Connect Four</a>
- <a>Bridges</a>


## Style Guidelines ##

- <b>Function parameters are prefixed with an underscore</b>
  
  <pre>int add(int _iX, int _iY) { ... }</pre>

- <b>Strings are passed to functions as a const char*</b>
  
    <pre>void print(const char* _String) { ... }</pre>

- <b>External variables are prefixed with "ext_"</b>
  
    <pre>external int ext_iAge</pre>

- <b>Structs are declared as typedef and suffixed with "_t"</b>
  
    <pre>
    typedef struct Person { ... } Person_t
    Person_t* person = (Person_t*)malloc(...)
    </pre>

- <b>Pointers are declared as follows</b>
    
    <pre>int* x = &myInt</pre>

- <b>Initialize variables in the declaration</b>

    <pre>
    int i = 0;
    char c = '\0';
    float f = 0.0;
    double d = 0.0;
    </pre>
