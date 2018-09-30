# Intel 8080 Emulator in C++
A Simple C++ implementation of the classic intel 8080 cpu with decimal arithmetic. At this point the cpu is complete (unimplemented codes below) and successfully passes the cpudiag test from Microcosm Associates found [here](http://www.emulator101.com/files/cpudiag.asm) and compiled using this [javascript assembler](http://sensi.org/~svo/i8080/).

## Dependencies
- C++11
- cmake >= 3.0

## Usage
Assuming you cloned and are inside the `i8080` folder with a terminal you should just
```
mkdir build && cd build
cmake ..
make
./i8080
```
The i8080 emulator will then produce `i8080.log` which records the output of the cpu.

## Unimplemented Opcodes
Some opcodes are not implemented given I had no means to test them. As such I have implemented all opcodes except illegal opcodes and the following:
* [0x20] - RIM
* [0x30] - SIM
* [0xD3] - OUTD
* [0xDB] - IND

## Testing
As aformentioned The CPU has been tested against the [cpudiag](http://www.emulator101.com/files/cpudiag.asm) assembly program which for completeness is also included pre-assembled, with source and results. For those interested there is a bug in cpudiag discussed [here](http://www.emulator101.com/full-8080-emulation.html). Which is accounted for in the main function implementation...after many many painful hours.

Presently I've implemented a debug class that produces `i8080.log` file in the `i8080` directory. It records everything. For memory this includes read, write, addresses and values. For the CPU it includes instructions, register states and flags (in binary).

To date the cpu completes all tests successfully. These are listed as:
* [SUCCESS] TEST JUMP INSTRUCTIONS AND FLAGS
* [SUCCESS] TEST ACCUMULATOR IMMEDIATE INSTRUCTIONS
* [SUCCESS] TEST CALLS AND RETURNS
* [SUCCESS] TEST "MOV","INR",AND "DCR" INSTRUCTIONS
* [SUCCESS] TEST ARITHMETIC AND LOGIC INSTRUCTIONS

## License
Copyright (c) 2018 Christopher M. Short

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
