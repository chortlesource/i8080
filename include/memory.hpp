/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

memory - memory.hpp

Copyright (c) 2018 Christopher M. Short

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _MEMORY_HPP
#define _MEMORY_HPP


// ------- Memory Variables

// Memory Constants
static const std::uint16_t MEM_SIZE = 0xFFFF; // 65535 bytes (64Kbytes)
static const std::uint8_t INSTR_SIZE = 0xFF; // 256 bytes

// Record Type Enumeration
enum RECTYPE {
  hRecDataRecord=0,
	hRecEOFRecord,
	hRecExtSegment,
	hRecStartSegment,
	hRecExtendedLinear,
  hRecStartLinear
};


// ------- i8080_MEMORY Class

class i8080_MEMORY {
private:
  // CPU Memory
  std::array<std::uint8_t, MEM_SIZE> MEMORY;

  // Intel Hex Functions
  unsigned int hextoint(std::string line);
  bool checksum(std::string line);
  bool loadLine(std::string line);

public:
  // Memory Read / Write public Functions
  void WRITE(std::uint16_t addr, std::uint8_t value);
  std::uint8_t READ(std::uint16_t addr);

  // File handling functions
  void loadFile(const char *path, const uint16_t& offset);
  void loadHexFile(const char *path);

  void set(const int& addr, const int& value) { MEMORY[addr] = value; }
  void reset();


};


#endif // _MEMORY_HPP
