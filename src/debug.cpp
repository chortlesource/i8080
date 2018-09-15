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

#include <i8080>

void i8080_DEBUG::init(std::string filename) {
  file = filename;
  illegal = false;
}

void i8080_DEBUG::start() {
    OUT.open(filename, std::ofstream::out | std::ofstream::app);
    OUT << std::endl << "################################## DEBUGGING ##################################" << std::endl
}

void i8080_DEBUG::append(std::uint8_t opcode, std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d, std::uint8_t e, std::uint8_t h, std::uint8_t l, std::uint8_t flags, std::uint16_t pc, std::uint16_t sp) {
  if(illegal)
    return;

  std::string instr = DEBUG_OPSTRING[opcode];
  if(OUT.is_open()) {
    OUT << "| " << instr << " | A: 0x" << std::hex << std::setw(2) << unsigned(a) <<
    " | B: 0x" << std::hex << std::setw(2) << unsigned(b) << " | C: 0x" << std::hex << std::setw(2) << unsigned(c) <<
    " | D: 0x" << std::hex << std::setw(2) << unsigned(d) << " | E: 0x" << std::hex << std::setw(2) << unsigned(e) <<
    " | H: 0x" << std::hex << std::setw(2) << unsigned(h) << " | L: 0x" << std::hex << std::setw(2) << unsigned(l) <<
    " | PC: 0x" << std::hex << std::setw(4) << unsigned(pc) << " | SP: 0x" << std::hex << std::setw(4) << unsigned(sp) <<
    " | " << std::bitset<8>(flags) << std::endl;
  }

  if(!instr.compare("####"))
    illegal = true;
}

void i8080_DEBUG::stop() {
  OUT << "\n###############################################################################" << std::endl << std::endl;
  OUT.close();
}