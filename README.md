# ComplierLabA
# C++ Lexical Analyzer 🔍

A simple **C++ Lexical Analyzer** developed for a Compiler Design project.
The program reads a C++ source file, analyzes it line by line, identifies different types of tokens, and detects several basic lexical and syntax-related errors.

---

## 📌 Project Overview

This project demonstrates the basic working principles of a **Lexical Analyzer**.

The analyzer reads a C++ source file named:

```text
program.cpp
```

It processes the source code line by line and identifies:

* Libraries
* Variables / identifiers
* Operators
* Integers
* Real numbers
* Invalid variables
* Comments
* Missing semicolons
* Invalid expressions

The extracted information is displayed in the terminal after processing the complete source file.

---

## 🎯 Objectives

The main objectives of this project are:

1. Read a C++ source program from a file.
2. Break the source code into tokens.
3. Identify valid identifiers.
4. Identify C++ keywords.
5. Identify operators.
6. Identify integer and real-number constants.
7. Identify included libraries.
8. Detect invalid variable names.
9. Detect missing semicolons.
10. Detect invalid expressions.
11. Display the analyzed information to the user.

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concept:** Compiler Design / Lexical Analysis
* **Standard Libraries:** C++ Standard Library
* **Input:** `program.cpp`
* **Output:** Console / Terminal

### Main Header Files

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
```

---

## ⚙️ How the Program Works

The program follows these basic steps:

```text
             C++ Source File
                    │
                    ▼
             Read Line by Line
                    │
                    ▼
              Parse the Line
                    │
          ┌─────────┼─────────┐
          ▼         ▼         ▼
       Keywords  Operators  Identifiers
          │         │         │
          └─────────┼─────────┘
                    ▼
             Numbers / Libraries
                    │
                    ▼
             Error Detection
                    │
                    ▼
             Display Results
```

---

## 🔎 Token Identification

### 1. Keywords

The function:

```cpp
bool isKeyword(char* str)
```

checks whether a token is a predefined C++ keyword.

Examples include:

```text
int
float
double
char
return
for
while
if
else
using
namespace
include
main
cout
cin
endl
std
```

---

### 2. Identifiers / Variables

The function:

```cpp
bool validIdentifier(char* str)
```

checks whether a token can be considered a valid identifier.

A valid identifier cannot start with:

* A number
* A delimiter

The program stores unique variables using:

```cpp
addUniqueVariable()
```

---

### 3. Operators

The function:

```cpp
bool isOperator(char ch)
```

checks for operators such as:

```text
+
-
*
/
=
>
<
%
!
```

Unique operators are stored using:

```cpp
addUniqueOperator()
```

---

### 4. Integers

The function:

```cpp
bool isInteger(char* str)
```

checks whether a token contains an integer value.

Examples:

```text
10
9
100
25
```

---

### 5. Real Numbers

The function:

```cpp
bool isRealNumber(char* str)
```

checks whether a token contains a decimal number.

Examples:

```text
10.5
3.14
25.75
```

---

### 6. Libraries

The program detects libraries included using the preprocessor directive:

```cpp
#include <iostream>
```

The library name is extracted and stored using:

```cpp
addUniqueLibrary()
```

For example:

```text
iostream
string
```

---

### 7. Invalid Variables

The program also maintains an array for invalid variables:

```cpp
char* invalidVarArray[100];
```

If a token does not satisfy the expected identifier or number conditions, it can be stored as an invalid variable.

---

## 🧠 Expression Validation

The function:

```cpp
bool checkValidExpression(char* tokens[], int tokenCount)
```

performs a basic validation of assignment expressions.

For example:

```cpp
a = b + c;
```

is treated as a valid expression structure.

The function checks that:

* The left side is a valid identifier.
* The assignment operator `=` is present.
* Operands are variables or integers.
* Operators appear in the expected positions.

An expression such as:

```cpp
a = b -;
```

can therefore be detected as an invalid expression.

---

## 📝 Sample Input

The following sample C++ program can be saved as:

```text
program.cpp
```

```cpp
#include<iostream>
#include<string>

using namespace std;

int main(){

    int a=10, b=9, _c;

    cout<<"Hello"<<endl

    _c = a + b;

    a = b -;

    int d, e, 1f;

    d = a * b;

    e = d @ _c;

    int arr[] = {a,b,_c,d,e};

    //this is a comment

    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;
}
```

---

## ⚠️ Errors in the Sample Program

The sample input intentionally contains several errors that can be detected by the analyzer.

### 1. Missing Semicolon

```cpp
cout<<"Hello"<<endl
```

The statement does not end with:

```cpp
;
```

Therefore, the analyzer can report a missing semicolon for that line.

---

### 2. Invalid Expression

```cpp
a = b -;
```

The `-` operator does not have a right-side operand.

Expected form:

```text
operand operator operand
```

Therefore, this is an invalid expression.

---

### 3. Invalid Variable Name

```cpp
int d, e, 1f;
```

The variable:

```text
1f
```

is invalid because an identifier cannot begin with a number.

---

### 4. Invalid Operator

```cpp
e = d @ _c;
```

The `@` symbol is not recognized as a valid C++ operator by the analyzer.

Therefore, this expression can be identified as invalid.

---

### 5. Comment

```cpp
//this is a comment
```

The analyzer recognizes a line containing `//` as a comment and reports it.

---

## 📤 Expected Type of Output

After processing the source file, the program displays information such as:

```text
";" missing in line - ...

Comment in line - ...

Invalid expression in line - ...

Library- 1: iostream
Library- 2: string

Variable- 1: a
Variable- 2: b
Variable- 3: _c
...

Total number of the variables: ...

Operator- 1: =
Operator- 2: +
Operator- 3: -
...

Total number of the operators: ...

Invalid variable - 1f
```

The exact output depends on how each line is tokenized by the current implementation.

---

## 📂 Project Structure

```text
Lexical-Analyzer/
│
├── main.cpp
├── program.cpp
└── README.md
```

### `main.cpp`

Contains the complete lexical analyzer implementation.

### `program.cpp`

Contains the C++ source code that is analyzed.

### `README.md`

Contains the project documentation.

---

## ▶️ How to Run

### Step 1 — Create the Input File

Create a file named:

```text
program.cpp
```

and place the C++ source code you want to analyze inside it.

---

### Step 2 — Compile the Analyzer

Compile `main.cpp` using a C++ compiler.

For example:

```bash
g++ main.cpp -o lexer
```

---

### Step 3 — Run the Program

```bash
./lexer
```

On Windows, depending on the compiler:

```bash
lexer.exe
```

---

## 🔄 Main Functions

| Function                 | Purpose                                           |
| ------------------------ | ------------------------------------------------- |
| `isDelimiter()`          | Checks whether a character is a delimiter         |
| `isOperator()`           | Checks whether a character represents an operator |
| `validIdentifier()`      | Checks whether an identifier is valid             |
| `isKeyword()`            | Checks whether a token is a keyword               |
| `isInteger()`            | Detects integer values                            |
| `isRealNumber()`         | Detects real numbers                              |
| `subString()`            | Extracts a substring                              |
| `addUniqueVariable()`    | Stores unique variables                           |
| `addUniqueOperator()`    | Stores unique operators                           |
| `addUniqueLibrary()`     | Stores unique libraries                           |
| `addInvalidVariable()`   | Stores invalid variables                          |
| `checkValidExpression()` | Performs basic expression validation              |
| `parse()`                | Processes and analyzes each source-code line      |
| `main()`                 | Reads `program.cpp` and starts the analysis       |

---

## 📊 Data Storage

The program uses arrays to store detected information.

### Variables

```cpp
char* idArray[100];
int idCount;
```

### Operators

```cpp
char* opArray[100];
int opCount;
```

### Libraries

```cpp
char* libArray[100];
int libCount;
```

### Invalid Variables

```cpp
char* invalidVarArray[100];
int invalidVarCount;
```

These arrays allow the program to keep track of unique items found during lexical analysis.

---

## 💡 Key Compiler Design Concepts Demonstrated

This project demonstrates several fundamental compiler concepts:

* Lexical analysis
* Tokenization
* Keywords
* Identifiers
* Operators
* Constants
* Delimiters
* Preprocessor directives
* Comments
* Basic expression validation
* Error detection
* Source-code parsing

---

## 🚀 Possible Future Improvements

The analyzer can be further improved by adding:

* Better multi-character operator detection
* Floating-point number validation
* String literal handling
* Character literal handling
* More accurate identifier validation
* Better syntax-error detection
* Parentheses and bracket matching
* More C++ keywords
* Support for multiple input files
* A graphical user interface
* Token tables with token type and value

---

## 🎓 Academic Purpose

This project was developed as an **educational Compiler Design project** to demonstrate how a basic lexical analyzer can process C++ source code and identify different types of tokens and common errors.

---

## 👨‍💻 Author

**Compiler Design Project**

**Project:** C++ Lexical Analyzer

**Language:** C++

**Purpose:** Academic / Educational
