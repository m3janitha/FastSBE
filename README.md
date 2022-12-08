## FastSBE

Command line Python code generator that generates C++ codec for [SBE](https://github.com/FIXTradingCommunity/fix-simple-binary-encoding) messages from XML declaration schemas.

## Why FastSBE ?
* 5X faster encoding 2X faster decoding compared to sbe-tool
* Benchmark figures available in GitHub Actions. Check CMake workflow logs.

## Why it is Fast ?
* Zero copy and Zero allocation in Decoding 
* Constant time access to variable length fields and repeating groups 

## Performance
```console
2022-11-03T00:51:53+00:00
Running ./benchmark_test
Run on (2 X 2394.45 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 256 KiB (x2)
  L3 Unified 30720 KiB (x1)
Load Average: 1.22, 0.76, 0.31
----------------------------------------------------------------------------------------------
Benchmark                                                    Time             CPU   Iterations
----------------------------------------------------------------------------------------------
FastSBEFixture/BM_Decode_NewOrderSingle                   23.4 ns         23.4 ns     30990496
SbeToolFixture/BM_Decode_NewOrderSingle                   85.3 ns         85.3 ns      8025875
FastSBEFixture/BM_Encode_NewOrderSingle_from_struct       43.9 ns         43.9 ns     15479654
SbeToolFixture/BM_Encode_NewOrderSingle_from_struct        122 ns          121 ns      5462472
```

## Limitations
* variable length fields are not supported within repeating groups
