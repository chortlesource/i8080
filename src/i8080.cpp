/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

i8080 - i8080.cpp

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

const bool& i8080::getParity(uint16_t value) {
  // Iterate through the bit to establish if it has an even or odd parity of 1's
  uint8_t count = 0;
  for(int i = 0; i < 16; i++) {
    if(value & 0x01)
      count++
    value >>= 1;
  }

  // Parity is the most significant bit of count; 0 for odd 1 for even parity.
  return !(count & 0x01);
}

void i8080::stack_push(std::uint16_t value) {
    // Do nothing
}

std::uint16_t i8080::stack_pop() {
    // Do nothing
}

void i8080::exec(OPCODE instr) {
  // Execute the relevant opcode function
  (this->*instr)();
}

std::uint8_t i8080::MEMORY_READ(std::uint16_t addr) {
  // Read memory address 'addr'
  return MEMORY[addr];
}

void i8080::MEMORY_WRITE(std::uint16_t addr, std::uint8_t value) {
  // Store 'value' in memory address 'addr'
  MEMORY[addr] = value;
}

i8080::i8080() {
  // Provisionally fill all instructions with nones
  OPCODE instr = &i8080::opcode_none;
  for(unsigned int i = 0; i < 0xFF; i++)
    instrtable[i] = instr;

  // Manually populate the function table
  instrtable[0x00] = &i8080::opcode_nop();    // 0x00
  instrtable[0x01] = &i8080::opcode_lxib();   // 0x01
  instrtable[0x02] = &i8080::opcode_staxb();  // 0x02
  instrtable[0x03] = &i8080::opcode_inxb();   // 0x03
  instrtable[0x04] = &i8080::opcode_inrb();   // 0x04
  instrtable[0x05] = &i8080::opcode_dcrb();   // 0x05
  instrtable[0x06] = &i8080::opcode_mvib();   // 0x06
  instrtable[0x07] = &i8080::opcode_rlc();    // 0x07
  instrtable[0x09] = &i8080::opcode_dadb();   // 0x09
  instrtable[0x0a] = &i8080::opcode_ldaxb();  // 0x0a
  instrtable[0x0b] = &i8080::opcode_dcxb();   // 0x0b
  instrtable[0x0c] = &i8080::opcode_inrc();   // 0x0c
  instrtable[0x0d] = &i8080::opcode_dcrc();   // 0x0d
  instrtable[0x0e] = &i8080::opcode_mvic();   // 0x0e
  instrtable[0x0f] = &i8080::opcode_rrc();    // 0x0f

  instrtable[0x11] = &i8080::opcode_lxid();   // 0x11
  instrtable[0x12] = &i8080::opcode_staxd();  // 0x12
  instrtable[0x13] = &i8080::opcode_inxd();   // 0x13
  instrtable[0x14] = &i8080::opcode_inrd();   // 0x14
  instrtable[0x15] = &i8080::opcode_dcrd();   // 0x15
  instrtable[0x16] = &i8080::opcode_mvid();   // 0x16
  instrtable[0x17] = &i8080::opcode_ral();    // 0x17
  instrtable[0x19] = &i8080::opcode_dadd();   // 0x19
  instrtable[0x1a] = &i8080::opcode_ldaxd();  // 0x1a
  instrtable[0x1b] = &i8080::opcode_dcxd();   // 0x1b
  instrtable[0x1c] = &i8080::opcode_inre();   // 0x1c
  instrtable[0x1d] = &i8080::opcode_dcre();   // 0x1d
  instrtable[0x1e] = &i8080::opcode_mvie();   // 0x1e
  instrtable[0x1f] = &i8080::opcode_rar();    // 0x1f

  instrtable[0x20] = &i8080::opcode_rim();    // 0x20
  instrtable[0x21] = &i8080::opcode_lxih();   // 0x21
  instrtable[0x22] = &i8080::opcode_shld();   // 0x22
  instrtable[0x23] = &i8080::opcode_inxh();   // 0x23
  instrtable[0x24] = &i8080::opcode_inrh();   // 0x24
  instrtable[0x25] = &i8080::opcode_dcrh();   // 0x25
  instrtable[0x26] = &i8080::opcode_mvih();   // 0x26
  instrtable[0x27] = &i8080::opcode_daa();    // 0x27
  instrtable[0x29] = &i8080::opcode_dadh();   // 0x29
  instrtable[0x2a] = &i8080::opcode_lhld();   // 0x2a
  instrtable[0x2b] = &i8080::opcode_dclh();   // 0x2b
  instrtable[0x2c] = &i8080::opcode_inrl();   // 0x2c
  instrtable[0x2d] = &i8080::opcode_dcrl();   // 0x2d
  instrtable[0x2e] = &i8080::opcode_mvil();   // 0x2e
  instrtable[0x2f] = &i8080::opcode_cma();    // 0x2f

  instrtable[0x30] = &i8080::opcode_sim();    // 0x30
  instrtable[0x31] = &i8080::opcode_lxisp();  // 0x31
  instrtable[0x32] = &i8080::opcode_sta();    // 0x32
  instrtable[0x33] = &i8080::opcode_inxsp();  // 0x33
  instrtable[0x34] = &i8080::opcode_inrm();   // 0x34
  instrtable[0x35] = &i8080::opcode_dcrm();   // 0x35
  instrtable[0x36] = &i8080::opcode_mvim();   // 0x36
  instrtable[0x37] = &i8080::opcode_stc();    // 0x37
  instrtable[0x39] = &i8080::opcode_dadsp();  // 0x39
  instrtable[0x3a] = &i8080::opcode_lda();    // 0x3a
  instrtable[0x3b] = &i8080::opcode_dcxsp();  // 0x3b
  instrtable[0x3c] = &i8080::opcode_inra();   // 0x3c
  instrtable[0x3d] = &i8080::opcode_dcra();   // 0x3d
  instrtable[0x3e] = &i8080::opcode_mvia();   // 0x3e
  instrtable[0x3f] = &i8080::opcode_cmc();    // 0x3f

  instrtable[0x40] = &i8080::opcode_movbb();  // 0x40
  instrtable[0x41] = &i8080::opcode_movbc();  // 0x41
  instrtable[0x42] = &i8080::opcode_movbd();  // 0x42
  instrtable[0x43] = &i8080::opcode_movbe();  // 0x43
  instrtable[0x44] = &i8080::opcode_movbh();  // 0x44
  instrtable[0x45] = &i8080::opcode_movbl();  // 0x45
  instrtable[0x46] = &i8080::opcode_movbm();  // 0x46
  instrtable[0x47] = &i8080::opcode_movba();  // 0x47
  instrtable[0x48] = &i8080::opcode_movcb();  // 0x48
  instrtable[0x49] = &i8080::opcode_movcc();  // 0x49
  instrtable[0x4a] = &i8080::opcode_movcd();  // 0x4a
  instrtable[0x4b] = &i8080::opcode_movce();  // 0x4b
  instrtable[0x4c] = &i8080::opcode_movch();  // 0x4c
  instrtable[0x4d] = &i8080::opcode_movcl();  // 0x4d
  instrtable[0x4e] = &i8080::opcode_movcm();  // 0x4e
  instrtable[0x4f] = &i8080::opcode_movca();  // 0x4f

  instrtable[0x50] = &i8080::opcode_movdb();  // 0x50
  instrtable[0x51] = &i8080::opcode_movdc();  // 0x51
  instrtable[0x52] = &i8080::opcode_movdd();  // 0x52
  instrtable[0x53] = &i8080::opcode_movde();  // 0x53
  instrtable[0x54] = &i8080::opcode_movdh();  // 0x54
  instrtable[0x55] = &i8080::opcode_movdl();  // 0x55
  instrtable[0x56] = &i8080::opcode_movdm();  // 0x56
  instrtable[0x57] = &i8080::opcode_movda();  // 0x57
  instrtable[0x58] = &i8080::opcode_moveb();  // 0x58
  instrtable[0x59] = &i8080::opcode_movec();  // 0x59
  instrtable[0x5a] = &i8080::opcode_moved();  // 0x5a
  instrtable[0x5b] = &i8080::opcode_movee();  // 0x5b
  instrtable[0x5c] = &i8080::opcode_moveh();  // 0x5c
  instrtable[0x5d] = &i8080::opcode_movel();  // 0x5d
  instrtable[0x5e] = &i8080::opcode_movem();  // 0x5e
  instrtable[0x5f] = &i8080::opcode_movea();  // 0x5f

  instrtable[0x60] = &i8080::opcode_movhb();  // 0x60
  instrtable[0x61] = &i8080::opcode_movhc();  // 0x61
  instrtable[0x62] = &i8080::opcode_movhd();  // 0x62
  instrtable[0x63] = &i8080::opcode_movhe();  // 0x63
  instrtable[0x64] = &i8080::opcode_movhh();  // 0x64
  instrtable[0x65] = &i8080::opcode_movhl();  // 0x65
  instrtable[0x66] = &i8080::opcode_movhm();  // 0x66
  instrtable[0x67] = &i8080::opcode_movha();  // 0x67
  instrtable[0x68] = &i8080::opcode_movlb();  // 0x68
  instrtable[0x69] = &i8080::opcode_movlc();  // 0x69
  instrtable[0x6a] = &i8080::opcode_movld();  // 0x6a
  instrtable[0x6b] = &i8080::opcode_movle();  // 0x6b
  instrtable[0x6c] = &i8080::opcode_movlh();  // 0x6c
  instrtable[0x6d] = &i8080::opcode_movll();  // 0x6d
  instrtable[0x6e] = &i8080::opcode_movlm();  // 0x6e
  instrtable[0x6f] = &i8080::opcode_movla();  // 0x6f

  instrtable[0x70] = &i8080::opcode_movmb();  // 0x70
  instrtable[0x71] = &i8080::opcode_movmc();  // 0x71
  instrtable[0x72] = &i8080::opcode_movmd();  // 0x72
  instrtable[0x73] = &i8080::opcode_movme();  // 0x73
  instrtable[0x74] = &i8080::opcode_movmh();  // 0x74
  instrtable[0x75] = &i8080::opcode_movml();  // 0x75
  instrtable[0x76] = &i8080::opcode_hlt();    // 0x76
  instrtable[0x77] = &i8080::opcode_movma();  // 0x77
  instrtable[0x78] = &i8080::opcode_movab();  // 0x78
  instrtable[0x79] = &i8080::opcode_movac();  // 0x79
  instrtable[0x7a] = &i8080::opcode_movad();  // 0x7a
  instrtable[0x7b] = &i8080::opcode_movae();  // 0x7b
  instrtable[0x7c] = &i8080::opcode_movah();  // 0x7c
  instrtable[0x7d] = &i8080::opcode_moval();  // 0x7d
  instrtable[0x7e] = &i8080::opcode_movam();  // 0x7e
  instrtable[0x7f] = &i8080::opcode_movaa();  // 0x7f

  instrtable[0x80] = &i8080::opcode_addb();   // 0x80
  instrtable[0x81] = &i8080::opcode_addc();   // 0x81
  instrtable[0x82] = &i8080::opcode_addd();   // 0x82
  instrtable[0x83] = &i8080::opcode_adde();   // 0x83
  instrtable[0x84] = &i8080::opcode_addh();   // 0x84
  instrtable[0x85] = &i8080::opcode_addl();   // 0x85
  instrtable[0x86] = &i8080::opcode_addm();   // 0x86
  instrtable[0x87] = &i8080::opcode_adda();   // 0x87
  instrtable[0x88] = &i8080::opcode_adcb();   // 0x88
  instrtable[0x89] = &i8080::opcode_adcc();   // 0x89
  instrtable[0x8a] = &i8080::opcode_adcd();   // 0x8a
  instrtable[0x8b] = &i8080::opcode_adce();   // 0x8b
  instrtable[0x8c] = &i8080::opcode_adch();   // 0x8c
  instrtable[0x8d] = &i8080::opcode_adcl();   // 0x8d
  instrtable[0x8e] = &i8080::opcode_adcm();   // 0x8e
  instrtable[0x8f] = &i8080::opcode_adca();   // 0x8f

  instrtable[0x90] = &i8080::opcode_subb();   // 0x90
  instrtable[0x91] = &i8080::opcode_subc();   // 0x91
  instrtable[0x92] = &i8080::opcode_subd();   // 0x92
  instrtable[0x93] = &i8080::opcode_sube();   // 0x93
  instrtable[0x94] = &i8080::opcode_subh();   // 0x94
  instrtable[0x95] = &i8080::opcode_subl();   // 0x95
  instrtable[0x96] = &i8080::opcode_subm();   // 0x96
  instrtable[0x97] = &i8080::opcode_suba();   // 0x97
  instrtable[0x98] = &i8080::opcode_sbbb();   // 0x98
  instrtable[0x99] = &i8080::opcode_sbbc();   // 0x99
  instrtable[0x9a] = &i8080::opcode_sbbd();   // 0x9a
  instrtable[0x9b] = &i8080::opcode_sbbe();   // 0x9b
  instrtable[0x9c] = &i8080::opcode_sbbh();   // 0x9c
  instrtable[0x9d] = &i8080::opcode_sbbl();   // 0x9d
  instrtable[0x9e] = &i8080::opcode_sbbm();   // 0x9e
  instrtable[0x9f] = &i8080::opcode_sbba();   // 0x9f

  instrtable[0xa0] = &i8080::opcode_anab();   // 0xa0
  instrtable[0xa1] = &i8080::opcode_anac();   // 0xa1
  instrtable[0xa2] = &i8080::opcode_anad();   // 0xa2
  instrtable[0xa3] = &i8080::opcode_anae();   // 0xa3
  instrtable[0xa4] = &i8080::opcode_anah();   // 0xa4
  instrtable[0xa5] = &i8080::opcode_anal();   // 0xa5
  instrtable[0xa6] = &i8080::opcode_anam();   // 0xa6
  instrtable[0xa7] = &i8080::opcode_anaa();   // 0xa7
  instrtable[0xa8] = &i8080::opcode_xrab();   // 0xa8
  instrtable[0xa9] = &i8080::opcode_xrac();   // 0xa9
  instrtable[0xaa] = &i8080::opcode_xrad();   // 0xaa
  instrtable[0xab] = &i8080::opcode_xrae();   // 0xab
  instrtable[0xac] = &i8080::opcode_xrah();   // 0xac
  instrtable[0xad] = &i8080::opcode_xral();   // 0xad
  instrtable[0xae] = &i8080::opcode_xram();   // 0xae
  instrtable[0xaf] = &i8080::opcode_xraa();   // 0xaf

  instrtable[0xb0] = &i8080::opcode_orab();   // 0xb0
  instrtable[0xb1] = &i8080::opcode_orac();   // 0xb1
  instrtable[0xb2] = &i8080::opcode_orad();   // 0xb2
  instrtable[0xb3] = &i8080::opcode_orae();   // 0xb3
  instrtable[0xb4] = &i8080::opcode_orah();   // 0xb4
  instrtable[0xb5] = &i8080::opcode_oral();   // 0xb5
  instrtable[0xb6] = &i8080::opcode_oram();   // 0xb6
  instrtable[0xb7] = &i8080::opcode_oraa();   // 0xb7
  instrtable[0xb8] = &i8080::opcode_cmpb();   // 0xb8
  instrtable[0xb9] = &i8080::opcode_cmpc();   // 0xb9
  instrtable[0xba] = &i8080::opcode_cmpd();   // 0xba
  instrtable[0xbb] = &i8080::opcode_cmpe();   // 0xbb
  instrtable[0xbc] = &i8080::opcode_cmph();   // 0xbc
  instrtable[0xbd] = &i8080::opcode_cmpl();   // 0xbd
  instrtable[0xbe] = &i8080::opcode_cmpm();   // 0xbe
  instrtable[0xbf] = &i8080::opcode_cmpa();   // 0xbf

  instrtable[0xc0] = &i8080::opcode_rnz();    // 0xc0
  instrtable[0xc1] = &i8080::opcode_popb();   // 0xc1
  instrtable[0xc2] = &i8080::opcode_jnz();    // 0xc2
  instrtable[0xc3] = &i8080::opcode_jmp();    // 0xc3
  instrtable[0xc4] = &i8080::opcode_cnz();    // 0xc4
  instrtable[0xc5] = &i8080::opcode_pushb();  // 0xc5
  instrtable[0xc6] = &i8080::opcode_adid();   // 0xc6
  instrtable[0xc7] = &i8080::opcode_rst0();   // 0xc7
  instrtable[0xc8] = &i8080::opcode_rz();     // 0xc8
  instrtable[0xc9] = &i8080::opcode_ret();    // 0xc9
  instrtable[0xca] = &i8080::opcode_jz();     // 0xca
  instrtable[0xcb] = &i8080::opcode_cz();     // 0xcc
  instrtable[0xcd] = &i8080::opcode_call();   // 0xcd
  instrtable[0xce] = &i8080::opcode_acid();   // 0xce
  instrtable[0xcf] = &i8080::opcode_rst1();   // 0xcf

  instrtable[0xd0] = &i8080::opcode_rnc();    // 0xd0
  instrtable[0xd1] = &i8080::opcode_popd();   // 0xd1
  instrtable[0xd2] = &i8080::opcode_jnc();    // 0xd2
  instrtable[0xd3] = &i8080::opcode_outd();   // 0xd3
  instrtable[0xd4] = &i8080::opcode_cnc();    // 0xd4
  instrtable[0xd5] = &i8080::opcode_pushd();  // 0xd5
  instrtable[0xd6] = &i8080::opcode_suid();   // 0xd6
  instrtable[0xd7] = &i8080::opcode_rst2();   // 0xd7
  instrtable[0xd8] = &i8080::opcode_rc();     // 0xd8
  instrtable[0xda] = &i8080::opcode_jc();     // 0xda
  instrtable[0xdb] = &i8080::opcode_ind();    // 0xdb
  instrtable[0xdc] = &i8080::opcode_cc();     // 0xdc
  instrtable[0xde] = &i8080::opcode_sbid();   // 0xde
  instrtable[0xdf] = &i8080::opcode_rst3();   // 0xdf

  instrtable[0xe0] = &i8080::opcode_rpo();    // 0xe0
  instrtable[0xe1] = &i8080::opcode_poph();   // 0xe1
  instrtable[0xe2] = &i8080::opcode_jpo();    // 0xe2
  instrtable[0xe3] = &i8080::opcode_xthl();   // 0xe3
  instrtable[0xe4] = &i8080::opcode_cpo();    // 0xe4
  instrtable[0xe5] = &i8080::opcode_pushh();  // 0xe5
  instrtable[0xe6] = &i8080::opcode_anid();   // 0xe6
  instrtable[0xe7] = &i8080::opcode_rst4();   // 0xe7
  instrtable[0xe8] = &i8080::opcode_rpe();    // 0xe8
  instrtable[0xe9] = &i8080::opcode_pchl();   // 0xe9
  instrtable[0xea] = &i8080::opcode_jpe();    // 0xea
  instrtable[0xeb] = &i8080::opcode_xchg();   // 0xeb
  instrtable[0xec] = &i8080::opcode_cpe();    // 0xec
  instrtable[0xee] = &i8080::opcode_xrid();   // 0xee
  instrtable[0xef] = &i8080::opcode_rst5();   // 0xef

  instrtable[0xf0] = &i8080::opcode_rp();     // 0xf0
  instrtable[0xf1] = &i8080::opcode_poppsw(); // 0xf1
  instrtable[0xf2] = &i8080::opcode_jp();     // 0xf2
  instrtable[0xf3] = &i8080::opcode_di();     // 0xf3
  instrtable[0xf4] = &i8080::opcode_cp();     // 0xf4
  instrtable[0xf5] = &i8080::opcode_pushpsw();// 0xf5
  instrtable[0xf6] = &i8080::opcode_orid();   // 0xf6
  instrtable[0xf7] = &i8080::opcode_rst6();   // 0xf7
  instrtable[0xf8] = &i8080::opcode_rm();     // 0xf8
  instrtable[0xf9] = &i8080::opcode_sphl();   // 0xf9
  instrtable[0xfa] = &i8080::opcode_jm();     // 0xfa
  instrtable[0xfb] = &i8080::opcode_ei();     // 0xfb
  instrtable[0xfc] = &i8080::opcode_cm();     // 0xfc
  instrtable[0xfd] = &i8080::opcode_cpid();   // 0xfe
  instrtable[0xff] = &i8080::opcode_rst7();   // 0xff

  Reset();

  return;
}

void i8080::Open(const char *path) {
  if(!initialized)
    return;
  // Do nothing
}

void i8080::Run(std::uint32_t num_cycles) {
  if(!initialized || halt)
    return;

  // Do nothing
}

void i8080::Reset() {
  // Reset Registers
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  h = 0;
  l = 0;

  // Reset program counter, stack pointer and status register
  pc = 0;
  sp = 0xFFFF;
  flags = 0x02;

  // Fill the memory
  MEMORY.fill(0);

  // Reset emulation variables
  none_opcode = false;
  halt = false;
  interuptEnabled = false;
  interuptPending = 0;
  cycles = 0;

  // Set the CPU as initialized
  initialized = true;
}

void i8080::Debug() {
  if(!initialized)
    return;

  // Do nothing
}
