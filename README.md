## FastSBE

Command line Python code generator that generates C++ codec for [SBE](https://github.com/FIXTradingCommunity/fix-simple-binary-encoding) messages from XML declaration schemas.

## Why FastSBE ?
* 5X faster encoding 2X faster decoding compared to widely used sbe-tool
* Benchmark figures available in GitHub Actions. Check CMake workflow logs.

## Why it is Fast ?
* Zero copy and Zero allocation in Decoding 
* Constant time access to variable length fields and repeating groups 

## Author
[Janitha Meedeniya](https://www.linkedin.com/in/janitha-meedeniya) 

## Limitations
* variable length fields are not supported within repeating groups

