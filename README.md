## GCC + Makefile example

The purposes of this example are to:
1. Illustrate the use of rules in Makefiles
2. Illustrate the use of specific flags in GCC
3. Capitalize on the ability to stop compilation at the
   assembly stage to compare the usage of libraries with
   their absence

### Structure:
    
- **lib_hello_world**: standard C hello world program developed
  using stdio.h
- **no_lib_hello_world**: non-standard C hello world programa
  developed using inline volatile x86-64 assembly

Both folders contain appropriate Makefiles. Considerations:
- The rule `all` generates all compilation stages, including assembly
  and object code (none are needed)
- The rule `debug` generates only the executable with debug symbols
- As per usual standards, `clean` is a phony rule that deletes anything 
  other than the original source code of the program

### Additional considerations
The implementation provided under **no_lib_hello_world** is, for all
intents and purposes, an excessive exercise in overengineering, not
anything students--or any sane person, for that matter--should be expected
to reproduce on their own. It is exceedingly complicated, hard to read, and
unportable to boot. Bear in mind it will only work in x86-64 UNIX, as it
directly depends on its specifics.

In short, this is an academic example meant exclusively to display the build
pipeline typically applied in C in full, and provide a brief, purely informative
look under the hood. Under no circumstances should it be taken as a reference
for good coding practices, industry standards, or indeed anything but a 
hazardous forey into the depths of what C is able to do as a language.

Also, I did promise students to show them an example of printing without relying
on the standard library. Let this be my way of making good on that promise, and
a proper deterrent on straying from the beautiful path marked by `<stdio.h>` and
its succesors.
