## FastSBE

Command line Python code generator that generates C++ codec for [SBE](https://github.com/FIXTradingCommunity/fix-simple-binary-encoding) messages from XML declaration schemas.

## Features
5X faster encoding 2X faster decoding compared to widely used sbe-tool. 
Benchmark tests are included in the repository

## Why it is Faster
* Zero copy and Zero allocation in Decoding 
* Constant time access to variable length fields and repeating groups 

## Author
[Janitha Meedeniya](https://www.linkedin.com/in/janitha-meedeniya) 

## Limitations
Variable length fields are not supported within repeating groups (due to performance) 

