/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

debug - debug.cpp

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

// ------- i8080_DEBUG Implementation

void i8080_DEBUG::initialize(const char *path) {
  file = path;  // Configure our log file
  illegal = false;  // Reset our illegal catch
}


void i8080_DEBUG::start() {
  // Open our log file and print a header
  OUT.open(file, std::ofstream::out | std::ofstream::app);

  for(int i = 0; i < 50; i++) OUT << "#";
  OUT << " DEBUGGING ";
  for(int i = 0; i < 51; i++) OUT << "#";   // Inequality makes me unhappy
  OUT << std::endl;
}


void i8080_DEBUG::append(std::uint8_t opcode, std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d, std::uint8_t e, std::uint8_t h, std::uint8_t l, std::uint8_t flags, std::uint16_t pc, std::uint16_t sp) {
  if(illegal || !enabled)
    return;

  // Ascertain what instruction was called
  std::string instr = DEBUG_OPSTRING[opcode];

  if(OUT.is_open()) {
    // Print output from the CPU to the log file
    OUT << "| " << instr << " | A: 0x" << std::hex << std::setw(2) << unsigned(a) <<
    " | B: 0x" << std::hex << std::setw(2) << unsigned(b) << " | C: 0x" << std::hex << std::setw(2) << unsigned(c) <<
    " | D: 0x" << std::hex << std::setw(2) << unsigned(d) << " | E: 0x" << std::hex << std::setw(2) << unsigned(e) <<
    " | H: 0x" << std::hex << std::setw(2) << unsigned(h) << " | L: 0x" << std::hex << std::setw(2) << unsigned(l) <<
    " | PC: 0x" << std::hex << std::setw(4) << unsigned(pc) << " | SP: 0x" << std::hex << std::setw(4) << unsigned(sp) <<
    " | " << std::bitset<8>(flags) << std::endl;
  }

  // If it's an illegal instruction stop debugging something went wrong.
  if(!instr.compare("####"))
    illegal = true;
}


void i8080_DEBUG::appendMemory(std::uint16_t addr, uint8_t value) {
  if(illegal || !enabled)
    return;

  if(OUT.is_open()) {
    // Print output from the memor read instruction
    OUT << "| MEMORY READ: 0x" << std::hex << std::setw(4) << unsigned(addr) <<
    " | FOUND: 0x" << std::hex << std::setw(2) << unsigned(value) << std::endl;
  }
}


void i8080_DEBUG::appendMemoryW(std::uint16_t addr, uint8_t value) {
  if(illegal || !enabled)
    return;

  if(OUT.is_open()) {
    // Print output from the memor read instruction
    OUT << "| MEMORY WRITE: 0x" << std::hex << std::setw(4) << unsigned(addr) <<
    " | WROTE: 0x" << std::hex << std::setw(2) << unsigned(value) << std::endl;
  }
}


void i8080_DEBUG::stop() {
  // Print out our footer and close the log file
  for(int i = 0; i < 112; i++)
    OUT << "#";
  OUT << std::endl << std::endl;
  OUT.close();
}
