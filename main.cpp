/*************************************************************************
* Title: Blockchain
* File: main.cpp
* Author: James Eli
* Date: 5/1/2019
*
* Blockchain Class Driver Program. Generates a simple blockchain of 100 
* elements.
*
* Notes:
*  (1) STL Hash returns std:size_t, so it’s a 32-bit value on a 32-bit 
*      system, and a 64-bit value on a 64-bit system.
*  (2) Compiled/tested with MS Visual Studio 2017 Community (v141), and
*      Windows SDK version 10.0.17134.0 (32 & 64-bit).
*
*************************************************************************
* Change Log: 
*   11/09/2018: Initial release. JME
*************************************************************************/
#include <iostream>  // cout
#include <string>    // strings
#include "block.h"   // blockchain
#include "list.h"    // my version of a singly-linked list

#ifdef _DEBUG
// Visual Leak Detector for debug build. https://kinddragon.github.io/vld/
#include "C:\Program Files (x86)\Visual Leak Detector\include\vld.h"
#endif

// Demo blockchain size.
constexpr std::size_t BLOCKCHAIN_SIZE{ 100 };
// Difficulty level for mining blocks.
constexpr unsigned int DIFFICULTY = 2;

int main()
{
	// Catch exceptions.
	try
	{
		// Instantiate a list of blocks.
		list<Block> bList;

		std::cout << "Mining " << BLOCKCHAIN_SIZE << " blocks at difficulty level: " << DIFFICULTY << std::endl;

		// String of previous hash. Init with "0" for genesis block.
		std::string hash("0");

		// Iterate mining blocks and fill list with 100 blocks.
		for (unsigned long i = 0; i < BLOCKCHAIN_SIZE; i++)
		{
			// Mine a new block.
			Block newBlock(i, hash, 0);
			newBlock.MineBlock(DIFFICULTY);

			// Save hash to use as previousHash value in next block in chain.
			hash = newBlock.getHash();

			// Add block to list.
			bList.push_back(newBlock);
		}

		// Print out the blockchain.
		std::cout << "\nBlockchain:\n";
		std::cout << bList;

		// Delete.
		bList.~list();
	}
	catch (std::exception& e)
	{
		// Report exception and exit with failure code.
		std::cout << "Encountered exception: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

