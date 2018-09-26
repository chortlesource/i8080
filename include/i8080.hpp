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
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <array>

#include <debug.hpp>

// Local Includes
#include <memory.hpp>
#include <debug.hpp>

// ------- Miscelaneous Variables / Functions

// Flag Constants
static const std::uint8_t FLAG_SIGN = 0x80;
static const std::uint8_t FLAG_ZERO = 0x40;
static const std::uint8_t FLAG_PAD1 = 0x20;
static const std::uint8_t FLAG_AUX = 0x10;
static const std::uint8_t FLAG_PAD2 = 0x08;
static const std::uint8_t FLAG_PARITY = 0x04;
static const std::uint8_t FLAG_CONST = 0x02;
static const std::uint8_t FLAG_CARRY = 0x01;

// Flag Functions
inline bool IS_SIGN(std::uint8_t value) { return value & FLAG_SIGN; }
inline bool IS_ZERO(std::uint8_t value) { return value & FLAG_ZERO; }
inline bool IS_AUX(std::uint8_t value) { return value & FLAG_AUX; }
inline bool IS_PARITY(std::uint8_t value) { return value & FLAG_PARITY; }
inline bool IS_CARRY(std::uint8_t value) { return value & FLAG_CARRY; }

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
  bool halt;
  bool interuptEnabled;

  i8080_DEBUG DEBUG;
  i8080_MEMORY MEMORY;

  std::uint8_t interuptPending;
  std::uint32_t cycles;

  // General Purpose Registers
  std::uint8_t a;
  std::uint8_t b;
  std::uint8_t c;
  std::uint8_t d;
  std::uint8_t e;
  std::uint8_t h;
  std::uint8_t l;

  // Stack Pointer
  std::uint16_t sp;

  // Program Counter
  std::uint16_t pc;

  // Flags / Status Register
  std::uint8_t flags;

  // Opcode function table
  typedef void (i8080::*OPCODE)();
  std::array<OPCODE, INSTR_SIZE> instrtable;

  // Opcode Functions
  void opcode_none();   // To catch unimplemented ops

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

  void opcode_addb();   // 0x80
  void opcode_addc();   // 0x81
  void opcode_addd();   // 0x82
  void opcode_adde();   // 0x83
  void opcode_addh();   // 0x84
  void opcode_addl();   // 0x85
  void opcode_addm();   // 0x86
  void opcode_adda();   // 0x87
  void opcode_adcb();   // 0x88
  void opcode_adcc();   // 0x89
  void opcode_adcd();   // 0x8a
  void opcode_adce();   // 0x8b
  void opcode_adch();   // 0x8c
  void opcode_adcl();   // 0x8d
  void opcode_adcm();   // 0x8e
  void opcode_adca();   // 0x8f

  void opcode_subb();   // 0x90
  void opcode_subc();   // 0x91
  void opcode_subd();   // 0x92
  void opcode_sube();   // 0x93
  void opcode_subh();   // 0x94
  void opcode_subl();   // 0x95
  void opcode_subm();   // 0x96
  void opcode_suba();   // 0x97
  void opcode_sbbb();   // 0x98
  void opcode_sbbc();   // 0x99
  void opcode_sbbd();   // 0x9a
  void opcode_sbbe();   // 0x9b
  void opcode_sbbh();   // 0x9c
  void opcode_sbbl();   // 0x9d
  void opcode_sbbm();   // 0x9e
  void opcode_sbba();   // 0x9f

  void opcode_anab();   // 0xa0
  void opcode_anac();   // 0xa1
  void opcode_anad();   // 0xa2
  void opcode_anae();   // 0xa3
  void opcode_anah();   // 0xa4
  void opcode_anal();   // 0xa5
  void opcode_anam();   // 0xa6
  void opcode_anaa();   // 0xa7
  void opcode_xrab();   // 0xa8
  void opcode_xrac();   // 0xa9
  void opcode_xrad();   // 0xaa
  void opcode_xrae();   // 0xab
  void opcode_xrah();   // 0xac
  void opcode_xral();   // 0xad
  void opcode_xram();   // 0xae
  void opcode_xraa();   // 0xaf

  void opcode_orab();   // 0xb0
  void opcode_orac();   // 0xb1
  void opcode_orad();   // 0xb2
  void opcode_orae();   // 0xb3
  void opcode_orah();   // 0xb4
  void opcode_oral();   // 0xb5
  void opcode_oram();   // 0xb6
  void opcode_oraa();   // 0xb7
  void opcode_cmpb();   // 0xb8
  void opcode_cmpc();   // 0xb9
  void opcode_cmpd();   // 0xba
  void opcode_cmpe();   // 0xbb
  void opcode_cmph();   // 0xbc
  void opcode_cmpl();   // 0xbd
  void opcode_cmpm();   // 0xbe
  void opcode_cmpa();   // 0xbf

  void opcode_rnz();    // 0xc0
  void opcode_popb();   // 0xc1
  void opcode_jnz();    // 0xc2
  void opcode_jmp();    // 0xc3
  void opcode_cnz();    // 0xc4
  void opcode_pushb();  // 0xc5
  void opcode_adid();   // 0xc6
  void opcode_rst();    // 0xc7
  void opcode_rz();     // 0xc8
  void opcode_ret();    // 0xc9
  void opcode_jz();     // 0xca
  void opcode_cz();     // 0xcc
  void opcode_call();   // 0xcd
  void opcode_acid();   // 0xce
  void opcode_rst1();   // 0xcf

  void opcode_rnc();    // 0xd0
  void opcode_popd();   // 0xd1
  void opcode_jnc();    // 0xd2
  void opcode_outd();   // 0xd3
  void opcode_cnc();    // 0xd4
  void opcode_pushd();  // 0xd5
  void opcode_suid();   // 0xd6
  void opcode_rst2();   // 0xd7
  void opcode_rc();     // 0xd8
  void opcode_jc();     // 0xda
  void opcode_ind();    // 0xdb
  void opcode_cc();     // 0xdc
  void opcode_sbid();   // 0xde
  void opcode_rst3();   // 0xdf

  void opcode_rpo();    // 0xe0
  void opcode_poph();   // 0xe1
  void opcode_jpo();    // 0xe2
  void opcode_xthl();   // 0xe3
  void opcode_cpo();    // 0xe4
  void opcode_pushh();  // 0xe5
  void opcode_anid();   // 0xe6
  void opcode_rst4();   // 0xe7
  void opcode_rpe();    // 0xe8
  void opcode_pchl();   // 0xe9
  void opcode_jpe();    // 0xea
  void opcode_xchg();   // 0xeb
  void opcode_cpe();    // 0xec
  void opcode_xrid();   // 0xee
  void opcode_rst5();   // 0xef

  void opcode_rp();     // 0xf0
  void opcode_poppsw(); // 0xf1
  void opcode_jp();     // 0xf2
  void opcode_di();     // 0xf3
  void opcode_cp();     // 0xf4
  void opcode_pushpsw();// 0xf5
  void opcode_orid();   // 0xf6
  void opcode_rst6();   // 0xf7
  void opcode_rm();     // 0xf8
  void opcode_sphl();   // 0xf9
  void opcode_jm();     // 0xfa
  void opcode_ei();     // 0xfb
  void opcode_cm();     // 0xfc
  void opcode_cpid();   // 0xfe
  void opcode_rst7();   // 0xff

  // CPU Functions
  bool getParity(std::uint16_t value);
  void stack_push(std::uint16_t value);
  std::uint16_t stack_pop();

  void exec(OPCODE instr);

  std::uint8_t MEMORY_READ(std::uint16_t addr);
  void MEMORY_WRITE(std::uint16_t addr, std::uint8_t value);

public:
  // Constructor
  i8080();

  // User Functions
  void Open(const char *path);
  void OpenIH(const char *path);
  void Run(std::uint32_t num_cycles);
  void Reset();
  void Debug(const bool& value, const char *path);

};

#endif // _I8080_HPP
