

6 General purpose Registers (uint8_t)
1 Stack pointer (uint16_t)
1 Program Counter (uint16_t)
1 flag register (uint8_t)

3 Memory addressing modes:
immediate, direct and indirect (using HL)
*Also if consider branching we have relative to PC.*

- IMMEDIATE - THe opperand (ie low byte is the address ie LDA #$22 22 is loaded)

>> TODO: - Whats next?

* Implement Open
* Implement Run
x Implement Reset
x Implement push
x Implement pop
* Implement Ops 00 - 0f
* Implement Ops 10 - 1f
* Implement Ops 20 - 2f
* Implement Ops 30 - 3f
* Implement Ops 40 - 4f
* Implement Ops 50 - 5f
* Implement Ops 60 - 6f
* Implement Ops 70 - 7f
* Implement Ops 80 - 8f
* Implement Ops 90 - 9f
* Implement Ops a0 - af
* Implement Ops b0 - bf
* Implement Ops c0 - cf
* Implement Ops d0 - df
* Implement Ops e0 - ef
* Implement Ops f0 - ff
* Write Debug Class
* Write Debug Table
* Implement Debugger

* Find / Write tests
* Test / Debug CPU
