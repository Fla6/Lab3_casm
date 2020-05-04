#!/bin/bash

echo -n "Asm file: "
read asmfile
echo -n "C file: "
read cfile
if test -f "$asmfile" || -f "$cfile"
then
nasm -f elf64 -g -F dwarf -o "${asmfile%.*}".o $asmfile 
gcc -Wall -g -c $cfile -o "${cfile%.*}".o
gcc -o "${asmfile%.*}" "${cfile%.*}".o "${asmfile%.*}".o
rm "${asmfile%.*}".o
rm "${cfile%.*}".o
fi
