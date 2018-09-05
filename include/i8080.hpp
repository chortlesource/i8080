/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

i8080 - i8080.hpp

Copyright (c) 2018 Christopher M. Short

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _I8080_HPP
#define _I8080_HPP

// ------- Includes

#include <cstdint>

#include <iostream>
#include <string>
#include <cctype>
#include <bitset>
#include <array>

// ------- Miscelaneous Variables / Functions

// Memory Constants
static const std::uint8_t MEM_SIZE = 0xFFFF; // 65535 bytes (64Kbytes)
static const std::uint8_t INSTR_SIZE = 0x100; // 256 bytes

// Flag Constants
static const std::uint8_t FLAG_SIGN = 0x80;
static const std::uint8_t FLAG_ZERO = 0x40;
static const std::uint8_t FLAG_PAD1 = 0x20;
static const std::uint8_t FLAG_AUX = 0x10;
static const std::uint8_t FLAG_PAD2 = 0x08;
static const std::uint8_t FLAG_PARITY = -0x04
static const std::uint8_t FLAG_CONST = 0x02;
static const std::uint8_t FLAG_CARRY = 0x01;

// Flag Functions
inline bool IF_SIGN(std::uint8_t value) { return value & FLAG_SIGN; }
inline bool IF_ZERO(std::uint8_t value) { return value & FLAG_ZERO; }
inline bool IF_AUX(std::uint8_t value) { return value & FLAG_AUX; }
inline bool IF_PARITY(std::uint8_t value) { return value & FLAG_PARITY; }
inline bool IF_CARRY(std::uint8_t value) { return value & FLAG_CARRY; }

inline bool SET_SIGN(bool value, std::uint8_t *flags) { value ? (*flags |= FLAG_SIGN) : (*flags &= (~FLAG_SIGN)); }
inline bool SET_ZERO(bool value, std::uint8_t *flags) { value ? (*flags |= FLAG_ZERO) : (*flags &= (~FLAG_ZERO)); }
inline bool SET_AUX(bool value, std::uint8_t *flags) { value ? (*flags |= FLAG_AUX) : (*flags &= (~FLAG_AUX)); }
inline bool SET_PARITY(bool value, std::uint8_t *flags) { value ? (*flags |= FLAG_PARITY) : (*flags &= (~FLAG_PARITY)); }
inline bool SET_CONST(bool value, std::uint8_t *flags) { value ? (*flags |= FLAG_CONST) : (*flags &= (~FLAG_CONST)); }
inline bool SET_CARRY(bool value, std::uint8_t *flags) { value ? (*flags |= FLAG_CARRY) : (*flags &= (~FLAG_CARRY)); }

// ------- i8080 Class

class i8080 {
private:
  // Emulation Variables
  bool initialized;
  bool none_opcode;
  std::uint32_t cycles;

  // General Purpose Registers
  std::uint8_t a;
  std::uint8_t b;
  std::uint8_t c;
  std::uint8_t d;
  std::uint8_t h;
  std::uint8_t l;

  // Stack Pointer
  std::uint16_t sp;

  // Program Counter
  std::uint16_t pc;

  // Flags / Status Register
  std::uint8_t flags;

  // Memory
  std::array<std::uint8_t, MEM_SIZE> MEMORY;

  // Opcode function table
  typedef void (i8080::*OPCODE)();
  std::array<OPCODE, INSTR_SIZE> instrtable

  // Opcode Functions
  void opcode_none(); // To catch unimplemented ops

  void opcode_nop();    // 0x00
  void opcode_lxib();   // 0x01
  void opcode_staxb();  // 0x02
  void opcode_inxb();   // 0x03
  void opcode_inrb();   // 0x04
  void opcode_dcrb();   // 0x05
  void opcode_mvib();   // 0x06
  void opcode_rlc();    // 0x07
  void opcode_dadb();   // 0x09
  void opcode_ldaxb();  // 0x0a
  void opcode_dcxb();   // 0x0b
  void opcode_inrc();   // 0x0c
  void opcode_dcrc();   // 0x0d
  void opcode_mvic();   // 0x0e
  void opcode_rrc();    // 0x0f

  void opcode_lxid();   // 0x11
  void opcode_staxd();  // 0x12
  void opcode_inxd();   // 0x13
  void opcode_inrd();   // 0x14
  void opcode_dcrd();   // 0x15
  void opcode_mvid();   // 0x16
  void opcode_ral();    // 0x17
  void opcode_dadd();   // 0x19
  void opcode_ldaxd();  // 0x1a
  void opcode_dcxd();   // 0x1b
  void opcode_inre();   // 0x1c
  void opcode_dcre();   // 0x1d
  void opcode_mvie();   // 0x1e
  void opcode_rar();    // 0x1f

  void opcode_rim();    // 0x20
  void opcode_lxih();   // 0x21
  void opcode_shld();   // 0x22
  void opcode_inxh();   // 0x23
  void opcode_inrh();   // 0x24
  void opcode_dcrh();   // 0x25
  void opcode_mvih();   // 0x26
  void opcode_daa();    // 0x27
  void opcode_dadh();   // 0x29
  void opcode_lhld();   // 0x2a
  void opcode_dclh();   // 0x2b
  void opcode_inrl();   // 0x2c
  void opcode_dcrl();   // 0x2d
  void opcode_mvil();   // 0x2e
  void opcode_cma();    // 0x2f

  void opcode_sim();    // 0x30
  void opcode_lxisp();  // 0x31
  void opcode_sta();    // 0x32
  void opcode_inxsp();  // 0x33
  void opcode_inrm();   // 0x34
  void opcode_dcrm();   // 0x35
  void opcode_mvim();   // 0x36
  void opcode_stc();    // 0x37
  void opcode_dadsp();  // 0x39
  void opcode_lda();    // 0x3a
  void opcode_dcxsp();  // 0x3b
  void opcode_inra();   // 0x3c
  void opcode_dcra();   // 0x3d
  void opcode_mvia();   // 0x3e
  void opcode_cmc();    // 0x3f

  void opcode_movbb();  // 0x40
  void opcode_movbc();  // 0x41
  void opcode_movbd();  // 0x42
  void opcode_movbe();  // 0x43
  void opcode_movbh();  // 0x44
  void opcode_movbl();  // 0x45
  void opcode_movbm();  // 0x46
  void opcode_movba();  // 0x47
  void opcode_movcb();  // 0x48
  void opcode_movcc();  // 0x49
  void opcode_movcd();  // 0x4a
  void opcode_movce();  // 0x4b
  void opcode_movch();  // 0x4c
  void opcode_movcl();  // 0x4d
  void opcode_movcm();  // 0x4e
  void opcode_movca();  // 0x4f

  void opcode_movdb();  // 0x50
  void opcode_movdc();  // 0x51
  void opcode_movdd();  // 0x52
  void opcode_movde();  // 0x53
  void opcode_movdh();  // 0x54
  void opcode_movdl();  // 0x55
  void opcode_movdm();  // 0x56
  void opcode_movda();  // 0x57
  void opcode_moveb();  // 0x58
  void opcode_movec();  // 0x59
  void opcode_moved();  // 0x5a
  void opcode_movee();  // 0x5b
  void opcode_moveh();  // 0x5c
  void opcode_movel();  // 0x5d
  void opcode_movem();  // 0x5e
  void opcode_movea();  // 0x5f

  void opcode_movhb();  // 0x60
  void opcode_movhc();  // 0x61
  void opcode_movhd();  // 0x62
  void opcode_movhe();  // 0x63
  void opcode_movhh();  // 0x64
  void opcode_movhl();  // 0x65
  void opcode_movhm();  // 0x66
  void opcode_movha();  // 0x67
  void opcode_movlb();  // 0x68
  void opcode_movlc();  // 0x69
  void opcode_movld();  // 0x6a
  void opcode_movle();  // 0x6b
  void opcode_movlh();  // 0x6c
  void opcode_movll();  // 0x6d
  void opcode_movlm();  // 0x6e
  void opcode_movla();  // 0x6f

  void opcode_movmb();  // 0x70
  void opcode_movmc();  // 0x71
  void opcode_movmd();  // 0x72
  void opcode_movme();  // 0x73
  void opcode_movmh();  // 0x74
  void opcode_movml();  // 0x75
  void opcode_hlt();    // 0x76
  void opcode_movma();  // 0x77
  void opcode_movab();  // 0x78
  void opcode_movac();  // 0x79
  void opcode_movad();  // 0x7a
  void opcode_movae();  // 0x7b
  void opcode_movah();  // 0x7c
  void opcode_moval();  // 0x7d
  void opcode_movam();  // 0x7e
  void opcode_movaa();  // 0x7f

  void opcode_();

  // CPU Functions
  void stack_push(std::uint16_t value);
  std::uint16_t stack_pop();

  void exec(OPCODE instr);

  std::uint8_t MEMORY_READ(std::uint16_t addr);
  void MEMORY_WRITE(std::uint16_t addr, std::uint8_t value);

public:
  // Constructor
  i8080();

  // User Functions
  void Open();
  void Run(std::uint32_t num_cycles);
  void Reset();
  void Debug();

};

#endif // _I8080_HPP
