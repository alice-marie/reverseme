# debboguer avec gdb:
gdb ./level2

# desassembler avec objdump:
objdump -d ./level2 > level2.asm

# tracer les appels système avec strace:
strace ./level2

# ----------------Marche à suivre---------------

1) reverse engineering:
- gdb
- strace
- ltrace
- strings
- objdump

tutoriel installation ghidra:
https://www.youtube.com/watch?v=LJz6MdzEmjM
PDF cheat sheet GDB:
https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
Online Decompiler:
https://dogbolt.org/

# ----------------------------------------------

# faire tourner gdb:

gdb ./level2

lay next

# breakpoint pour faire stopper gdb

break main

# start the program
run

# go to the next line 
next
ou nexti ("next instruction")

# go to the next step (not the next line)
step

# clean the screen (?)
ref

# examiner l'instruction
x/i $pc