# Signature-watermark
User manual:
1.
To compile: gcc main.c hash.c morse.c bmp.c -o main
2.
To create command wm (it's not necessary, you can just use ./main instead): alias wm="./main" 
3.
To run the program in general :wm input.bmp -text "input text" -date -color "input color
in hexadecimal" -pos x y -o output.bmp
4.
Example TO RUN with sign.bmp file: wm sign.bmp -text "Hello" -date -color FFFFFE -pos 10 20 -o
modsign.bmp
