# Huffman-Decoding
Project that decodes files with Huffman's method.
What is Huffman's methode ? 
Huffman coding, named after its designer, is a statistical method of data compression. 
data. Its principle is to replace a character (or symbol) by a sequence of bits of variable length. 
variable length. The underlying idea is to encode what is frequent on few bits and on the contrary what is rare on sequences of bits more
rare on longer sequences of bits. The Huffman coding allows a compression without 
compression, i.e. a sequence of bits strictly identical to the original is restored by 
decompression. It requires however that the frequencies of appearance of the various symbols to be coded are known (or estimated). 
different symbols to be coded. There are thus several variants of the Huffman algorithm (static, 
semi-adaptive or adaptive) used today in file compression algorithms such as 
such as gzip.
This subject concerns the decompression phase of the algorithm in which a compressed text can be decoded if the alphabet is not 
be decoded if the original alphabet is known as well as the frequency distribution of the characters which 
the text.


This project is separed in 3 parts. I use Huffman.cpp to code and decode the string, Node.h is the declaration of the node class, and then Node.cpp is the definition of the methods from Node.h.

