# Error Logging #

If there are unstable passages in the code, or you just need more help to debug, use the ErrorHandler's log(...) method. <br/>
It will create an error.txt file (in the directory, where the *.exe is located) with timestamp and a given error message. <br/>
Don't log everything as constant file access will be a huge performance issue at some point.

# Miscellaneous #
### Utility.h ###

Utility.h has an <a href="https://github.com/Tehlyria/GameCompilation/wiki/%5BEnum%5D-boolean">boolean</a>-enum that defines TRUE and FALSE. <br/>
If you need a boolean somewhere, include Utility.h and use TRUE / FALSE. <br/>
Utility also contains a method to initialize a game board (init(...)) and a method to cleanUp a game board (cleanUp(...)). <br/>
init() initializes all X/Y coordinates and its value.
cleanUp() frees the memory.

### nansi_Utility.h ###

nansi_Utility.h contains utility methods that are not covered by the ANSI C standard. <br/>

### Field.h ###

Field.h has a typedef <a href="https://github.com/Tehlyria/GameCompilation/wiki/%5BTypedef%5D-Field_t">Field_t</a>. <br/>
This holds X/Y coordinates and a character value. <br/>
This will be used to represent the game board. <br/>


# GameCompilation #

- <a href="http://de.wikipedia.org/wiki/Dame_%28Spiel%29#Checkers">Checkers</a>
    - Kai (+ Jens ASAP)  
- <a href="http://de.wikipedia.org/wiki/Reversi">Reversi</a>
    - Niels (+ Daniel ASAP)
- <a href="http://de.wikipedia.org/wiki/4_gewinnt">Connect Four</a>
    - Florian
- Bridges
    - Thomas + Genter


# Style Guidelines #

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
    
- <b>Header Guard (for <em>every</em> header file, replace HEADERNAME with actual name)</b>

    <pre>
    #ifndef HEADERNAME_H_INCLUDED
    #define HEADERNAME_H_INCLUDED
      ... code ...
    #endif //HEADERNAME_H_INCLUDED
    </pre>
    
- <b>Global variables are prefixed with "g_"</b>

    <pre>Field_t* g_Board;</pre>
