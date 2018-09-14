

6 General purpose Registers (uint8_t)
1 Stack pointer (uint16_t)
1 Program Counter (uint16_t)
1 flag register (uint8_t)

3 Memory addressing modes:
immediate, direct and indirect (using HL)
*Also if consider branching we have relative to PC.*

- IMMEDIATE - The opperand (ie low byte is the address ie LDA #$22 22 is loaded)

>> TODO: - Whats next?

* Implement Open
* Implement Run
x Implement Reset
x Implement push
x Implement pop
x Implement Ops 00 - 0f
x Implement Ops 10 - 1f
x Implement Ops 20 - 2f
x Implement Ops 30 - 3f
x Implement Ops 40 - 4f
x Implement Ops 50 - 5f
x Implement Ops 60 - 6f
x Implement Ops 70 - 7f
x Implement Ops 80 - 8f
x Implement Ops 90 - 9f
x Implement Ops a0 - af
x Implement Ops b0 - bf
x Implement Ops c0 - cf
x Implement Ops d0 - df
x Implement Ops e0 - ef
x Implement Ops f0 - ff
* Write Debug Class
* Write Debug Table
* Implement Debugger

* Find / Write tests
* Test / Debug CPU
