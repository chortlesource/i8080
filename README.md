## i8080 Emulator in C++

A Simple C++ implementation of the classic intel 8080 cpu. At this point completed but pending further testing with the cpudiag test from Microcosm Associates available [here](http://www.emulator101.com/files/cpudiag.asm) and compiled using this [javascript assembler](http://sensi.org/~svo/i8080/).

### Usage
Assuming your in the i8080 folder you should just

* mkdir build/ && cd build
* Compile a copy of the cpudiag.asm and dump in this folder
* cmake ..
* make
* ./i8080

It will then produce a debug.log file which shows the output of the cpu.

### Completed tasks

* Implement cpu Class
* Implement Ops 00 - 0f
* Implement Ops 10 - 1f
* Implement Ops 20 - 2f
* Implement Ops 30 - 3f
* Implement Ops 40 - 4f
* Implement Ops 50 - 5f
* Implement Ops 60 - 6f
* Implement Ops 70 - 7f
* Implement Ops 80 - 8f
* Implement Ops 90 - 9f
* Implement Ops a0 - af
* Implement Ops b0 - bf
* Implement Ops c0 - cf
* Implement Ops d0 - df
* Implement Ops e0 - ef
* Implement Ops f0 - ff
* Implement Debug Class

### Test's Completed
* TEST JUMP INSTRUCTIONS AND FLAGS
* TEST ACCUMULATOR IMMEDIATE INSTRUCTIONS
* TEST CALLS AND RETURNS

### Pending Tests
* TEST "MOV","INR",AND "DCR" INSTRUCTIONS
* TEST ARITHMETIC AND LOGIC INSTRUCTIONS

### Known Bugs
* The cpudiag test fails at STAXB. (I'm working on it!)
