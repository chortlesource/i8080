/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

opcodes - opcodes.cpp

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

void i8080::opcode_none(){
    none_opcode = true;
}   // To catch unimplemented ops


void i8080::opcode_nop(){
    return;
}    // 0x00

void i8080::opcode_lxib(){
    // Do Nothing
}   // 0x01

void i8080::opcode_staxb(){
    // Do Nothing
}  // 0x02

void i8080::opcode_inxb(){
  c++;
  if(!c) b++;
}   // 0x03

void i8080::opcode_inrb(){
  // Use uint16_t to capture the carry
  std::uint16_t value = b + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  b = value;
}   // 0x04

void i8080::opcode_dcrb(){
  // Use uint16_t to capture the carry
  std::uint16_t value = b - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  b = value;
}   // 0x05

void i8080::opcode_mvib(){
    // Do Nothing
}   // 0x06

void i8080::opcode_rlc(){
    // Do Nothing
}    // 0x07

void i8080::opcode_dadb(){
    // Do Nothing
}   // 0x09

void i8080::opcode_ldaxb(){
    // Do Nothing
}  // 0x0a

void i8080::opcode_dcxb(){
  c--;
  if(!c) b--;
}   // 0x0b

void i8080::opcode_inrc(){
  // Use uint16_t to capture the carry
  std::uint16_t value = c + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  c = value;
}   // 0x0c

void i8080::opcode_dcrc(){
  // Use uint16_t to capture the carry
  std::uint16_t value = c - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  c = value;
}   // 0x0d

void i8080::opcode_mvic(){
    // Do Nothing
}   // 0x0e

void i8080::opcode_rrc(){
    // Do Nothing
}    // 0x0f


void i8080::opcode_lxid(){
    // Do Nothing
}   // 0x11

void i8080::opcode_staxd(){
    // Do Nothing
}  // 0x12

void i8080::opcode_inxd(){
  e++;
  if(!e) d++;
}   // 0x13

void i8080::opcode_inrd(){
  // Use uint16_t to capture the carry
  std::uint16_t value = d + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  d = value;
}   // 0x14

void i8080::opcode_dcrd(){
  // Use uint16_t to capture the carry
  std::uint16_t value = d - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  d = value;
}   // 0x15

void i8080::opcode_mvid(){
    // Do Nothing
}   // 0x16

void i8080::opcode_ral(){
    // Do Nothing
}    // 0x17

void i8080::opcode_dadd(){
    // Do Nothing
}   // 0x19

void i8080::opcode_ldaxd(){
    // Do Nothing
}  // 0x1a

void i8080::opcode_dcxd(){
  e--;
  if(!e) d--;
}   // 0x1b

void i8080::opcode_inre(){
  // Use uint16_t to capture the carry
  std::uint16_t value = e + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  e = value;
}   // 0x1c

void i8080::opcode_dcre(){
  // Use uint16_t to capture the carry
  std::uint16_t value = e - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  e = value;
}   // 0x1d

void i8080::opcode_mvie(){
    // Do Nothing
}   // 0x1e

void i8080::opcode_rar(){
    // Do Nothing
}    // 0x1f


void i8080::opcode_rim(){
    // Do Nothing
}    // 0x20

void i8080::opcode_lxih(){
    // Do Nothing
}   // 0x21

void i8080::opcode_shld(){
    // Do Nothing
}   // 0x22

void i8080::opcode_inxh(){
  l++;
  if(!l) h++;
}   // 0x23

void i8080::opcode_inrh(){
  // Use uint16_t to capture the carry
  std::uint16_t value = h + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  h = value;
}   // 0x24

void i8080::opcode_dcrh(){
  // Use uint16_t to capture the carry
  std::uint16_t value = h - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  h = value;
}   // 0x25

void i8080::opcode_mvih(){
    // Do Nothing
}   // 0x26

void i8080::opcode_daa(){
    // Do Nothing
}    // 0x27

void i8080::opcode_dadh(){
    // Do Nothing
}   // 0x29

void i8080::opcode_lhld(){
    // Do Nothing
}   // 0x2a

void i8080::opcode_dclh(){
    // Do Nothing
}   // 0x2b

void i8080::opcode_inrl(){
  // Use uint16_t to capture the carry
  std::uint16_t value = l + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  l = value;
}   // 0x2c

void i8080::opcode_dcrl(){
  // Use uint16_t to capture the carry
  std::uint16_t value = l - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  l = value;
}   // 0x2d

void i8080::opcode_mvil(){
    // Do Nothing
}   // 0x2e

void i8080::opcode_cma(){
    // Do Nothing
}    // 0x2f


void i8080::opcode_sim(){
    // Do Nothing
}    // 0x30

void i8080::opcode_lxisp(){
    // Do Nothing
}  // 0x31

void i8080::opcode_sta(){
    // Do Nothing
}    // 0x32

void i8080::opcode_inxsp(){
    // Do Nothing
}  // 0x33

void i8080::opcode_inrm(){
  // Obtain the value from memory address hl
  uint8_t mem = MEMORY_READ((h << 8) + l);

  // Use uint16_t to capture the carry
  std::uint16_t value = mem + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);

  // Write memory back to address
  MEMORY_WRITE((h << 8) + l, value & 0xFF);
}   // 0x34

void i8080::opcode_dcrm(){
  // Obtain the value from memory address hl
  uint8_t mem = MEMORY_READ((h << 8) + l);

  // Use uint16_t to capture the carry
  std::uint16_t value = mem - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);

  // Write memory back to address
  MEMORY_WRITE((h << 8) + l, value & 0xFF);
}   // 0x35

void i8080::opcode_mvim(){
    // Do Nothing
}   // 0x36

void i8080::opcode_stc(){
    // Do Nothing
}    // 0x37

void i8080::opcode_dadsp(){
    // Do Nothing
}  // 0x39

void i8080::opcode_lda(){
    // Do Nothing
}    // 0x3a

void i8080::opcode_dcxsp(){
  sp--;
}  // 0x3b

void i8080::opcode_inra(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x3c

void i8080::opcode_dcra(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - 1;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x3d

void i8080::opcode_mvia(){
    // Do Nothing
}   // 0x3e

void i8080::opcode_cmc(){
    // Do Nothing
}    // 0x3f


void i8080::opcode_movbb(){
  return;
}  // 0x40

void i8080::opcode_movbc(){
  b = c;
}  // 0x41

void i8080::opcode_movbd(){
  b = d;
}  // 0x42

void i8080::opcode_movbe(){
  b = e;
}  // 0x43

void i8080::opcode_movbh(){
  b = h;
}  // 0x44

void i8080::opcode_movbl(){
  b = l;
}  // 0x45

void i8080::opcode_movbm(){
  b = MEMORY_READ((h << 8) + l);
}  // 0x46

void i8080::opcode_movba(){
  b = a;
}  // 0x47

void i8080::opcode_movcb(){
  c = b;
}  // 0x48

void i8080::opcode_movcc(){
  return;
}  // 0x49

void i8080::opcode_movcd(){
  c = d;
}  // 0x4a

void i8080::opcode_movce(){
  c = e;
}  // 0x4b

void i8080::opcode_movch(){
  c = h;
}  // 0x4c

void i8080::opcode_movcl(){
  c = l;
}  // 0x4d

void i8080::opcode_movcm(){
  c = MEMORY_READ((h << 8) + l);
}  // 0x4e

void i8080::opcode_movca(){
  c = a;
}  // 0x4f


void i8080::opcode_movdb(){
  d = b;
}  // 0x50

void i8080::opcode_movdc(){
  d = c;
}  // 0x51

void i8080::opcode_movdd(){
  return;
}  // 0x52

void i8080::opcode_movde(){
  d = e;
}  // 0x53

void i8080::opcode_movdh(){
  d = h;
}  // 0x54

void i8080::opcode_movdl(){
  d = l;
}  // 0x55

void i8080::opcode_movdm(){
  d = MEMORY_READ((h << 8) + l);
}  // 0x56

void i8080::opcode_movda(){
  d = a;
}  // 0x57

void i8080::opcode_moveb(){
  e = b;
}  // 0x58

void i8080::opcode_movec(){
  e = c;
}  // 0x59

void i8080::opcode_moved(){
  e = d;
}  // 0x5a

void i8080::opcode_movee(){
  return;
}  // 0x5b

void i8080::opcode_moveh(){
  e = h;
}  // 0x5c

void i8080::opcode_movel(){
  e = l;
}  // 0x5d

void i8080::opcode_movem(){
  e = MEMORY_READ((h << 8) + l);
}  // 0x5e

void i8080::opcode_movea(){
  e = a;
}  // 0x5f


void i8080::opcode_movhb(){
  h = b;
}  // 0x60

void i8080::opcode_movhc(){
  h = c;
}  // 0x61

void i8080::opcode_movhd(){
  h = d;
}  // 0x62

void i8080::opcode_movhe(){
  h = e;
}  // 0x63

void i8080::opcode_movhh(){
  return;
}  // 0x64

void i8080::opcode_movhl(){
  h = l;
}  // 0x65

void i8080::opcode_movhm(){
  h = MEMORY_READ((h << 8) + l);
}  // 0x66

void i8080::opcode_movha(){
  h = a;
}  // 0x67

void i8080::opcode_movlb(){
  l = b;
}  // 0x68

void i8080::opcode_movlc(){
  l = c;
}  // 0x69

void i8080::opcode_movld(){
  l = d;
}  // 0x6a

void i8080::opcode_movle(){
  l = e;
}  // 0x6b

void i8080::opcode_movlh(){
  l = h;
}  // 0x6c

void i8080::opcode_movll(){
  return;
}  // 0x6d

void i8080::opcode_movlm(){
  l = MEMORY_READ((h << 8) + l);
}  // 0x6e

void i8080::opcode_movla(){
  l = a;
}  // 0x6f


void i8080::opcode_movmb(){
  MEMORY_WRITE((h << 8) + l, b);
}  // 0x70

void i8080::opcode_movmc(){
  MEMORY_WRITE((h << 8) + l, c);
}  // 0x71

void i8080::opcode_movmd(){
  MEMORY_WRITE((h << 8) + l, d);
}  // 0x72

void i8080::opcode_movme(){
  MEMORY_WRITE((h << 8) + l, e);
}  // 0x73

void i8080::opcode_movmh(){
  MEMORY_WRITE((h << 8) + l, h);
}  // 0x74

void i8080::opcode_movml(){
  MEMORY_WRITE((h << 8) + l, l);
}  // 0x75

void i8080::opcode_hlt(){
  halt = true;
}    // 0x76

void i8080::opcode_movma(){
  MEMORY_WRITE((h << 8) + l, a);
}  // 0x77

void i8080::opcode_movab(){
  a = b;
}  // 0x78

void i8080::opcode_movac(){
  a = c;
}  // 0x79

void i8080::opcode_movad(){
  a = d;
}  // 0x7a

void i8080::opcode_movae(){
  a = e;
}  // 0x7b

void i8080::opcode_movah(){
  a = h;
}  // 0x7c

void i8080::opcode_moval(){
  a = l;
}  // 0x7d

void i8080::opcode_movam(){
  a = MEMORY_READ((h << 8) + l);
}  // 0x7e

void i8080::opcode_movaa(){
  return;
}  // 0x7f


void i8080::opcode_addb(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + b;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x80

void i8080::opcode_addc(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + c;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x81

void i8080::opcode_addd(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + d;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x82

void i8080::opcode_adde(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + e;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x83

void i8080::opcode_addh(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + h;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x84

void i8080::opcode_addl(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + l;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x85

void i8080::opcode_addm(){
  // Obtain the value from memory address hl
  uint8_t mem = MEMORY_READ((h << 8) + l);

  // Use uint16_t to capture the carry
  std::uint16_t value = a + mem;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x86

void i8080::opcode_adda(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + a;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x87

void i8080::opcode_adcb(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + b + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x88

void i8080::opcode_adcc(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + c + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x89

void i8080::opcode_adcd(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + d + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x8a

void i8080::opcode_adce(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + e + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x8b

void i8080::opcode_adch(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + h + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x8c

void i8080::opcode_adcl(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + l + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x8d

void i8080::opcode_adcm(){
  // Obtain the value from memory address hl
  uint8_t mem = MEMORY_READ((h << 8) + l);

  // Use uint16_t to capture the carry
  std::uint16_t value = a + mem + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x8e

void i8080::opcode_adca(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a + a + IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x8f


void i8080::opcode_subb(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - b;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x90

void i8080::opcode_subc(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - c;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x91

void i8080::opcode_subd(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - d;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x92

void i8080::opcode_sube(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - e;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x93

void i8080::opcode_subh(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - h;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x94

void i8080::opcode_subl(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - l;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x95

void i8080::opcode_subm(){
  // Obtain the value from memory address hl
  uint8_t mem = MEMORY_READ((h << 8) + l);

  // Use uint16_t to capture the carry
  std::uint16_t value = a - mem;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x96

void i8080::opcode_suba(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - a;
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x97

void i8080::opcode_sbbb(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - b - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x98

void i8080::opcode_sbbc(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - c - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x99

void i8080::opcode_sbbd(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - d - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x9a

void i8080::opcode_sbbe(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - e - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x9b

void i8080::opcode_sbbh(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - h - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x9c

void i8080::opcode_sbbl(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - l - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x9d

void i8080::opcode_sbbm(){
  // Obtain the value from memory address hl
  uint8_t mem = MEMORY_READ((h << 8) + l);

  // Use uint16_t to capture the carry
  std::uint16_t value = a - mem - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x9e

void i8080::opcode_sbba(){
  // Use uint16_t to capture the carry
  std::uint16_t value = a - a - IS_CARRY(flags);
  SET_ZERO(!value, &flags);
  SET_SIGN(value & 0x80, &flags);
  SET_PARITY((getParity(value)), &flags);
  SET_CARRY(value > 0xFF, &flags);
  SET_AUX((a & 0x0F) > (value & 0x000F), &flags);
  a = value;
}   // 0x9f


void i8080::opcode_anab(){
    // Do Nothing
}   // 0xa0

void i8080::opcode_anac(){
    // Do Nothing
}   // 0xa1

void i8080::opcode_anad(){
    // Do Nothing
}   // 0xa2

void i8080::opcode_anae(){
    // Do Nothing
}   // 0xa3

void i8080::opcode_anah(){
    // Do Nothing
}   // 0xa4

void i8080::opcode_anal(){
    // Do Nothing
}   // 0xa5

void i8080::opcode_anam(){
    // Do Nothing
}   // 0xa6

void i8080::opcode_anaa(){
    // Do Nothing
}   // 0xa7

void i8080::opcode_xrab(){
    // Do Nothing
}   // 0xa8

void i8080::opcode_xrac(){
    // Do Nothing
}   // 0xa9

void i8080::opcode_xrad(){
    // Do Nothing
}   // 0xaa

void i8080::opcode_xrae(){
    // Do Nothing
}   // 0xab

void i8080::opcode_xrah(){
    // Do Nothing
}   // 0xac

void i8080::opcode_xral(){
    // Do Nothing
}   // 0xad

void i8080::opcode_xram(){
    // Do Nothing
}   // 0xae

void i8080::opcode_xraa(){
    // Do Nothing
}   // 0xaf


void i8080::opcode_orab(){
    // Do Nothing
}   // 0xb0

void i8080::opcode_orac(){
    // Do Nothing
}   // 0xb1

void i8080::opcode_orad(){
    // Do Nothing
}   // 0xb2

void i8080::opcode_orae(){
    // Do Nothing
}   // 0xb3

void i8080::opcode_orah(){
    // Do Nothing
}   // 0xb4

void i8080::opcode_oral(){
    // Do Nothing
}   // 0xb5

void i8080::opcode_oram(){
    // Do Nothing
}   // 0xb6

void i8080::opcode_oraa(){
    // Do Nothing
}   // 0xb7

void i8080::opcode_cmpb(){
    // Do Nothing
}   // 0xb8

void i8080::opcode_cmpc(){
    // Do Nothing
}   // 0xb9

void i8080::opcode_cmpd(){
    // Do Nothing
}   // 0xba

void i8080::opcode_cmpe(){
    // Do Nothing
}   // 0xbb

void i8080::opcode_cmph(){
    // Do Nothing
}   // 0xbc

void i8080::opcode_cmpl(){
    // Do Nothing
}   // 0xbd

void i8080::opcode_cmpm(){
    // Do Nothing
}   // 0xbe

void i8080::opcode_cmpa(){
    // Do Nothing
}   // 0xbf


void i8080::opcode_rnz(){
    // Do Nothing
}    // 0xc0

void i8080::opcode_popb(){
    // Do Nothing
}   // 0xc1

void i8080::opcode_jnz(){
    // Do Nothing
}    // 0xc2

void i8080::opcode_jmp(){
    // Do Nothing
}    // 0xc3

void i8080::opcode_cnz(){
    // Do Nothing
}    // 0xc4

void i8080::opcode_pushb(){
    // Do Nothing
}  // 0xc5

void i8080::opcode_adid(){
    // Do Nothing
}   // 0xc6

void i8080::opcode_rst0(){
    // Do Nothing
}   // 0xc7

void i8080::opcode_rz(){
    // Do Nothing
}     // 0xc8

void i8080::opcode_ret(){
    // Do Nothing
}    // 0xc9

void i8080::opcode_jz(){
    // Do Nothing
}     // 0xca

void i8080::opcode_cz(){
    // Do Nothing
}     // 0xcc

void i8080::opcode_call(){
    // Do Nothing
}   // 0xcd

void i8080::opcode_acid(){
    // Do Nothing
}   // 0xce

void i8080::opcode_rst1(){
    // Do Nothing
}   // 0xcf


void i8080::opcode_rnc(){
    // Do Nothing
}    // 0xd0

void i8080::opcode_popd(){
    // Do Nothing
}   // 0xd1

void i8080::opcode_jnc(){
    // Do Nothing
}    // 0xd2

void i8080::opcode_outd(){
    // Do Nothing
}   // 0xd3

void i8080::opcode_cnc(){
    // Do Nothing
}    // 0xd4

void i8080::opcode_pushd(){
    // Do Nothing
}  // 0xd5

void i8080::opcode_suid(){
    // Do Nothing
}   // 0xd6

void i8080::opcode_rst2(){
    // Do Nothing
}   // 0xd7

void i8080::opcode_rc(){
    // Do Nothing
}     // 0xd8

void i8080::opcode_jc(){
    // Do Nothing
}     // 0xda

void i8080::opcode_ind(){
    // Do Nothing
}    // 0xdb

void i8080::opcode_cc(){
    // Do Nothing
}     // 0xdc

void i8080::opcode_sbid(){
    // Do Nothing
}   // 0xde

void i8080::opcode_rst3(){
    // Do Nothing
}   // 0xdf


void i8080::opcode_rpo(){
    // Do Nothing
}    // 0xe0

void i8080::opcode_poph(){
    // Do Nothing
}   // 0xe1

void i8080::opcode_jpo(){
    // Do Nothing
}    // 0xe2

void i8080::opcode_xthl(){
    // Do Nothing
}   // 0xe3

void i8080::opcode_cpo(){
    // Do Nothing
}    // 0xe4

void i8080::opcode_pushh(){
    // Do Nothing
}  // 0xe5

void i8080::opcode_anid(){
    // Do Nothing
}   // 0xe6

void i8080::opcode_rst4(){
    // Do Nothing
}   // 0xe7

void i8080::opcode_rpe(){
    // Do Nothing
}    // 0xe8

void i8080::opcode_pchl(){
    // Do Nothing
}   // 0xe9

void i8080::opcode_jpe(){
    // Do Nothing
}    // 0xea

void i8080::opcode_xchg(){
    // Do Nothing
}   // 0xeb

void i8080::opcode_cpe(){
    // Do Nothing
}    // 0xec

void i8080::opcode_xrid(){
    // Do Nothing
}   // 0xee

void i8080::opcode_rst5(){
    // Do Nothing
}   // 0xef


void i8080::opcode_rp(){
    // Do Nothing
}     // 0xf0

void i8080::opcode_poppsw(){
    // Do Nothing
} // 0xf1

void i8080::opcode_jp(){
    // Do Nothing
}     // 0xf2

void i8080::opcode_di(){
  interuptEnabled = false;
}     // 0xf3

void i8080::opcode_cp(){
    // Do Nothing
}     // 0xf4

void i8080::opcode_pushpsw(){
    // Do Nothing
}// 0xf5

void i8080::opcode_orid(){
    // Do Nothing
}   // 0xf6

void i8080::opcode_rst6(){
    // Do Nothing
}   // 0xf7

void i8080::opcode_rm(){
    // Do Nothing
}     // 0xf8

void i8080::opcode_sphl(){
    // Do Nothing
}   // 0xf9

void i8080::opcode_jm(){
    // Do Nothing
}     // 0xfa

void i8080::opcode_ei(){
  interuptEnabled = true;
}     // 0xfb

void i8080::opcode_cm(){
    // Do Nothing
}     // 0xfc

void i8080::opcode_cpid(){
    // Do Nothing
}   // 0xfe

void i8080::opcode_rst7(){
    // Do Nothing
}   // 0xff
