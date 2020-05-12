//---------------------------------------------------------------------------
//File name: Main.cpp
//Author: Jacob Luciani
//Purpose: Serves as an driver for a scanner and parser to process an input file of "source code"
//         checks parse tree for proper static semantics and outputs result
//---------------------------------------------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "inputProcessing.h"
#include "Scanner.h"
#include "node.h"
#include "parser.h"
#include "StaticSem.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	//holds the "base" name related to the source of input
	char *baseName;
	baseName = getBaseName(argc, argv);

	//File pointer to input file
	FILE *input;
	
	//get pointer to a file with input regardless of input source
	input = processArgs(baseName);
	
	//create Scanner object pointing to input file
	Scanner scan (input);
	
	//retrieves full parse tree, using scanner to feed parser tokens
	Node *tree = parser(scan);
	
	//create semantic checker object with the tree created by the parser
	StaticSem semanticChecker(tree);
	//run check on the tree for static semantics errors
	semanticChecker.checkTree();
	
	
	//clean up resources before termination
	fclose(input);
	free(baseName);
	freeTree(tree);
	
	return EXIT_SUCCESS;
}