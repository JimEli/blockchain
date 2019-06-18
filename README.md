# Blockchain
## Constructs simple demonstartion of a blockchain.

Generates a blockchain of 100 mined elements.

### Blockchain Block Class.

Declares a block class containing an ID, Time Stamp, Hash, Previous Hash and Nonce members. All members are private. Includes accessors (get/set), and provides appropriate ctor for genesis block creation and follow-on chain blocks. Includes a formatted print function.

### Notes:
* The STL library hash function and 3 alternative public domain 32-bit hash functions (FNV-1a 32-bit hash function, CRC32 32-bit cyclic redundancy check, SDBM 32-bit function) are provided. See comments inside the hash_funcs.h file for further information.
* Compiled/tested with MS Visual Studio 2017 Community (v141), and Windows SDK version 10.0.17134.0

