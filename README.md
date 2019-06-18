# Blockchain
## Constructs simple demonstartion of a blockchain.

Generates a blockchain of 100 mined elements.

### Blockchain Block Class.

Declares a block class containing an ID, Time Stamp, Hash, Previous Hash and Nonce members. All members are private. Includes accessors (get/set), and provides appropriate ctor for genesis block creation and follow-on chain blocks. Includes a formatted print function.

### Notes:
* STL Hash returns std:size_t, so it’s a 32-bit value on a 32-bit system, and 64-bit on a 64-bit system. This presented a problem.
* The STL library hash function and 3 alternative public domain 32-bit hash functions (FNV-1a 32-bit hash function, CRC32 32-bit cyclic redundancy check, SDBM 32-bit function) are provided. See comments inside the hash_funcs.h file for further information.
* Compiled/tested with MS Visual Studio 2017 Community (v141), and Windows SDK version 10.0.17134.0

### Change Log:
* 09/21/2018: Initial release.
* 10/07/2018: Added isBlockValid.
* 11/01/2018: Changed isBlockValid stoi to stoul.
* 11/09/2018: Added comparison operators.
* 11/09/2018: Moved DIFFICULTY declaration to main.cpp.
* 11/09/2018: Updated << operator per assignment directions.
* 11/09/2018: Changed mineBlock() loop.
* 11/09/2018: Replaced STL hash with user selectable versions.
* 11/11/2018: Removed unused ctors.
