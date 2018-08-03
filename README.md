# JinksDraw 0.0
Ken Jinks 2018

## Intro

JinksDraw is a utility for creating 2D procedural art. It is based on GTK 3.0 and Cairo.
## History
### Aug 3 2018
First week of programming and development.  

Files created:

  * primitives.h
  * primitives.cpp
  * prime_test.cpp
  * jinks_math.h
  * jinks_math.cpp
  * main.cpp
  * Makefile

The primitives have classes created, Point, Line, Circle and Rectangle but not completed. The test file prime_test.cpp tests the current methods.
These primitives when complete will have the methods that will calculate intersections between them producing vectors of points. Other methods include subpoint which converts the primitive into a vector of points and subline which converts the primitive into a vector of lines.
The Makefile currently makes the test file, prime_test by running make prime_test the running ./prime_test. 
