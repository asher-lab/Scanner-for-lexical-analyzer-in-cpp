# Scanner-for-lexical-analyzer-in-cpp
A simple c++ program that takes a file as input and after tokenizing the file it finds what each token name is(identifier, keyword, separator, operator, literal or comment).


To see what a compiler's lexical analyzer is click [here](https://en.wikipedia.org/wiki/Lexical_analysis)
### Prerequisites

You need c++11 or higher to run the code.
To compile the code do:
```
sudo apt-get install g++
```

### Using

To use it, first you just need to clone it:

```
git@github.com:amirhakimnejad/Scanner-for-lexical-analyzer-in-cpp.git
```

Change the testfile (program.txt) as your desire:
```
// This is the c test file

int x ;
x = x + 5 ;
/*
    Multi line Comment
*/

// Single line Comment
for(int i = 0, i <= 4; i++){
    x += i;
}
    x++;

54dsa
_sda = "gdsdg";

```
Compile with c++11:

```
g++ main.cpp scanner.cpp -std=c++11
```

Run it:
```
./a.out
```

This will be your output:
```
Which file for it to open?: test.por
Comments:                     //
Comments:                     /*
Keywords:                 double
Identifiers:                   y
Operators - Assignment:         =
Literals:                     90
Delimeters:                    ;
Keywords:                 double
Identifiers:                   x
Operators - Assignment:         =
Literals:                   1000
Delimeters:                    ;
Keywords:                  float
Identifiers:                   y
Operators - Assignment:         =
Literals:                   9999
Delimeters:                    ;
Comments:                     //
Keywords:                   char
Identifiers:                   x
Delimeters:                    [
Literals:                    100
Delimeters:                    ]
Operators - Assignment:         =
Literals:               "AfricanNative"
Delimeters:                    ;
Keywords:                   char
Identifiers:                   x
Delimeters:                    [
Literals:                    100
Delimeters:                    ]
Operators - Assignment:         =
Literals:               'AfricanNative'
Delimeters:                    ;
Keywords:                    out
Delimeters:                    (
Identifiers:                   e
Delimeters:                    )
Delimeters:                    ;
Keywords:                  until
Delimeters:                    (
Identifiers:                   x
Operators - Relational:        ==
Literals:                      6
Delimeters:                    )
Delimeters:                    ;
NoiseWords Keywords:              output
Delimeters:                    (
Literals:                 'Test'
Delimeters:                    )
Delimeters:                    ;
NoiseWords Keywords:              output
Delimeters:                    (
Literals:                 "Test"
Delimeters:                    )
Delimeters:                    ;
Keywords:                  until
Delimeters:                    (
Keywords:                    int
Identifiers:                   i
Operators - Assignment:         =
Literals:                      0
Delimeters:                    ,
Identifiers:                   i
Operators - Relational:        <=
Literals:                      4
Delimeters:                    ;
Identifiers:                   i
Operators - Arithmetic:        ++
Delimeters:                    )
Delimeters:                    {
Identifiers:                   x
Operators - Arithmetic:         +
Operators - Assignment:         =
Identifiers:                   i
Delimeters:                    ;
Identifiers:                   r
Operators - Arithmetic:         +
Operators - Assignment:         =
Literals:                    999
Delimeters:                    ;
Delimeters:                    }
NoiseWords Keywords:             integer
Identifiers:             bitcoin
Operators - Assignment:         =
Literals:                  43000
Delimeters:                    ;
NoiseWords Keywords:              output
Delimeters:                    (
Identifiers:             bitcoin
Delimeters:                    )
Delimeters:                    ;
Keywords:                    int
Reserved Keywords:                  body
Delimeters:                    (
Delimeters:                    )
Delimeters:                    {
Identifiers:             slpMoon
Operators - Assignment:         =
Reserved Keywords:               invalid
Delimeters:                    ;
Reserved Keywords:                  next
Delimeters:                    ;
Keywords:                  float
Operators - Assignment:         =
Identifiers:                   x
Operators - Arithmetic:         +
Identifiers:                   y
Delimeters:                    ;
Keywords:                  float
Identifiers:                   x
Operators - Assignment:         =
Identifiers:                   a
Operators - Arithmetic:         +
terminate called after throwing an instance of 'std::runtime_error'
  what():  Invalid token: 1b
Aborted (core dumped)
```

As you can see there are few keywords or statements in my program. You can manually add any other values to their vector.
```c++
const vector<std::string> keywords{"int", "float", "auto", "double", "do", "switch", "return"};
const vector<std::string> statements{"for", "while"};
const vector<std::string> operators{"*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};
const vector<std::string> Separators{"{", "}", ",", "(", ")", ";"};
```



### How each function works
```c++
bool isID(const std::string &str);
bool isComment(const std::string &str);
bool isDigit(const std::string &str);
bool isString(const std::string &str);
bool isBool(const std::string &str);
bool isLiteral(const std::string &str);
bool isKeyword(const std::string &str);
bool isStatement(const std::string &str);
bool isOperator(const std::string &str);
bool isSeparator(const std::string &str);
bool isNotLegal(const std::string &str);
void printRoleOfToken(const vector<std::string>& tokens);
void lexicalAnalyze(const std::string &nameOfFile);
```
Most of the functions above don't need any explanation. Generally lexicalAnalyze() function tokenizes the given file to
a vector of strings with ignoring whitespaces, newlines and the contents of comments with using the help of isOperator()
isNotLegal() and isComment() because these are the only things that comes between main things of our program. 
```
for(i=5;     i<= 10; i++){}
```
After making tokens vector lexicalAnalyze() passes it to printRoleOfToken() function then the functions simply uses all 
other functions to print the name of each token.
[Known tokens](https://en.wikipedia.org/wiki/Lexical_analysis#Token):
```
identifier: names the programmer chooses;
keyword: names already in the programming language;
separator (also known as punctuators): punctuation characters and paired-delimiters;
operator: symbols that operate on arguments and produce results;
literal: numeric, logical, textual, reference literals;
comment: line, block.
```

Feel free to ask questions, find bugs(:D) or anything else.

## Authors

* **Amirhossein Hakimnejad** - *Initial work* - [amirhakimnejad](https://github.com/amirhakimnejad)
* **Henry** - *Contributor* - [henry-bugfree](https://github.com/henry-bugfree)
* *Asher Manangan** - *Forker* - I just modified this lexical analyzer because of interests, but not really used on project in school.

## License

This project is licensed under the MIT License
