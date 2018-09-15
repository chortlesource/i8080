/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

debug - debug.hpp

Copyright (c) 2018 Christopher M. Short

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _DEBUG_HPP
#define _DEBUG_HPP

// ------- Debug Constants

static const char *DEBUG_OPSTRING[256] {
  "NOP", "LXIB", "STAXB", "INXB", "INRB", "DCRB", "MVIB", "RLC", "####", "DADB", "LDAXB", "DCXB", "INRC", "DCRC", "MVIC", "RRC",
  "####", "LXID", "STAXD", "INXD", "INRD", "DCRD", "MVID", "RAL", "####", "DADD", "LDAXD", "DCXD", "INRE", "DCRE", "MVIE", "RAR",
  "RIM", "LXIH", "SHLD", "INXH", "INRH", "DCRH", "MVIH", "DAA", "####", "DADH", "LHLD", "DCXH", "INRL", "DCRL", "MVIL", "CMA",
  "SIM", "LXISP", "STA", "INXSP", "INRM", "DCRM", "MVIM", "STC", "####", "DADSP", "LDA", "DCXSP", "INRA", "DCRA", "MVIA", "CMC",
  "MOVBB", "MOVBC", "MOVBD", "MOVBE", "MOVBH", "MOVBL", "MOVBM", "MOVBA", "MOVCB", "MOVCC", "MOVCD", "MOVCE", "MOVCH", "MOVCL", "MOVCM", "MOVCA",
  "MOVDB", "MOVDC", "MOVDD", "MOVDE", "MOVDH", "MOVDL", "MOVDM", "MOVDA", "MOVEB", "MOVEC", "MOVED", "MOVEE", "MOVEH", "MOVEL", "MOVEM", "MOVEA",
  "MOVHB", "MOVHC", "MOVHD", "MOVHE", "MOVHH", "MOVHL", "MOVHM", "MOVHA", "MOVLB", "MOVLC", "MOVLD", "MOVLE", "MOVLH", "MOVLL", "MOVLM", "MOVLA",
  "MOVMB", "MOVMC", "MOVMD", "MOVME", "MOVMH", "MOVML", "HLT", "MOVMA", "MOVAB", "MOVAC", "MOVAD", "MOVAE", "MOVAH", "MOVAL", "MOVAM", "MOVAA",
  "ADDB", "ADDC", "ADDD", "ADDE", "ADDH", "ADDL", "ADDM", "ADDA", "ADCB", "ADCC", "ADCD", "ADCE", "ADCH", "ADCL", "ADCM", "ADCA",
  "SUBB", "SUBC", "SUBD", "SUBE", "SUBH", "SUBL", "SUBM", "SUBA", "SBBB", "SBBC", "SBBD", "SBBE", "SBBH", "SBBL", "SBBM", "SBBA",
  "ANAB", "ANAC", "ANAD", "ANAE", "ANAH", "ANAL", "ANAM", "ANAA", "XRAB", "XRAC", "XRAD", "ARAE", "XRAH", "XRAL", "XRAM", "XRAA",
  "ORAB", "ORAC", "ORAD", "ORAE", "ORAH", "ORAL", "ORAM", "ORAA", "CMPB", "CMPC", "CMPD", "CMPE", "CMPH", "CMPL", "CMPM", "CMPA",
  "RNX", "POPB", "JNZ", "JMP", "CNZ", "PUSHB", "ADID", "RST0", "RZ", "RET", "JZ", "####", "CZ", "CALL", "ACID", "RST1",
  "RNC", "POPD", "JNC", "OUTD", "CNC", "PUSHD", "SUID", "RST2", "RC", "####", "JC", "IND", "CC", "####", "SBID", "RST3",
  "RPO", "POPH", "JPO", "XTHL", "CPO", "PUSHH", "ANID", "RST4", "RPE", "PCHL", "JPE", "XCHG", "CPE", "####", "XRID", "RST5",
  "RP", "POPP", "JP", "DI", "CP", "PUSHP", "ORID", "RST6", "RM", "SPHL", "JM", "EL", "CM", "####", "CPID", "RST7"
};

// ------- DEBUG class

class i8080_DEBUG {
private:
  std::string file;
  bool illegal;
  std::ofstream OUT;

public:
  void init(std::string filename);
  void start();
  void append(std::uint8_t opcode, std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d, std::uint8_t e, std::uint8_t h, std::uint8_t l, std::uint8_t flags, std::uint16_t pc, std::uint16_t sp);
  void stop();
};

#endif // _DEBUG_HPP
