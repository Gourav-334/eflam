# TEST AREA



## 1. About


A generic test file used for testing various source files & large modules alike. This file is very dynamic, and changes depending on what was the most recent addition or modification made to the project. For instance, if a small program for loading filestream was written, it will be tested in this file (`test.c`). And even a large source engine will be tested in this same file. But usually, these will be tested separately, not together.



## 2. Implementation


```c
// test.c
/* Commonly used `_start` function alias, called `main`. */

int main(
    int argc,           // Number of arguments passed
    char *argv[]        // Array of string arguments
);
```

- Algorithm & implementation keeps changing as per what is being tested.

---