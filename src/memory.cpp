/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

memory - memory.hpp

Copyright (c) 2018 Christopher M. Short

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <i8080.hpp>

// ------- MEMORY Implementation

unsigned int i8080_MEMORY::hextoint(std::string line) {
  int rvalue = 0;

  // Loop through the length of line
  for(int i = 0; i < line.length(); i++) {
    int ch = tolower(line.at(i)); // obtain first digit as int

    unsigned int value = 0;
    if(isdigit(ch))
      value = ch - '0'; // Subtract ascii 48 to obtain numerical value from ascii char
    else if(isxdigit(ch))
      value = ch - 'a' + 10; // Do some magic ?

    rvalue = rvalue * 16 + value; // WTF does this do?

  }
  return rvalue;
}


bool i8080_MEMORY::checksum(std::string line) {
  int sum = 0;
  int pairs = (line.length() - 1) / 2 - 1; // Avoid the ':' and the 2's compliment

  for(int i = 0; i < pairs; i++) {
    unsigned int byte = hextoint(line.substr(1 + (i * 2), 2)); // Cycle through pairs
    sum += byte;
    sum &= 0xFF;
  }

  sum ^= 0xFF;  // XOR to obtain the 2's compliment
  sum++;

  long value = hextoint(line.substr(line.length() - 2));
  return (value == sum);
}


bool i8080_MEMORY::loadLine(std::string line) {

  if(line.length() == 0)
    return false;

  // Ascertain the record length is correct
  if(line.length() < 10) {
    std::cout << "[ERROR]: Record too short." << std::endl;
    return false;
  }

  // Clarify the start character is correct
  if(line.at(0) != ':') {
    std::cout << "[ERROR]: Invalid start character." << std::endl;
    return false;
  }

  // Verify the checksum
  if(!checksum(line)) {
    std::cout << "[ERROR]: Invalid checksum" << std::endl;
    return false;
  }

  std::uint8_t bytecount = hextoint(line.substr(1, 2)); // Obtain bytecount
  std::uint16_t addr = hextoint(line.substr(3, 4)); // Obtain the address
  std::uint8_t recordtype = hextoint(line.substr(7, 2)); // Obtain the record type

  switch(recordtype) {
    case 00: // Data
      for(uint8_t i = 0; i < bytecount; i++)
      {
          // Write the data to memory at the address specified
          unsigned int data = hextoint(line.substr(i*2+9,2));
          WRITE(addr, data & 0xFF);   // & 0xFF to handle overflow
          addr++;
      }
      break;
    case 01: // EOF
      break;
    case 02: // Extended Segment
    case 03: // Start Segment
    case 04: // Extended Liner
    case 05: // Start Liner
    default:
      break;
  }

  return true;
}


void i8080_MEMORY::WRITE(uint16_t addr, uint8_t data) {
  MEMORY[addr] = data;
}


uint8_t i8080_MEMORY::READ(uint16_t addr) {
  return MEMORY[addr];
}


void i8080_MEMORY::loadFile(const char *path) {
  std::ifstream input(path, std::ios::binary);
  if(input) {
    input.seekg (0, input.end);
    auto fsize = input.tellg();
    input.seekg (0, input.beg);

    char *buffer = new char[fsize];
    input.read(buffer, fsize);

    for (unsigned int i = 0; i < fsize; i++) {
      MEMORY[0x600 + i] = static_cast<uint8_t>(buffer[i]);
    }
    delete [] buffer;
  }
  std::cout << "[CPU] FILE LOADED" << std::endl;
}


void i8080_MEMORY::loadHexFile(const char *path) {
  std::ifstream input;
  input.open(path);
  if(!input) {
    std::cout << "[ERROR]: File not open" << std::endl;
    return;
  }

  std::string line;

  while(!input.eof()) {
    char ch[256];
    input.getline(ch, 254);

    line = std::string(ch);
    if(!loadLine(line))
      return;
  }
}


void i8080_MEMORY::reset() {
  MEMORY.fill(0);
}
