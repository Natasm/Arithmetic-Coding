#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Node.h"
#include "LimitsConfig.h"
#include "coder.h"

#define SIZE_ALPHABETIC 256

Node nodes[256];
LimitsConfig limits_config[256];

void freq_prob_expand(int sizeBuffer){
    long double acc = 0;

    for(int i = 0; i < SIZE_ALPHABETIC; i++){
        if(nodes[i] == NULL) continue;

        int content = getContentNode(nodes[i]);
        if(limits_config[i] == NULL) limits_config[i] = newLimitsConfig(acc, acc + content / (double) sizeBuffer);

        acc = acc + content / (double) sizeBuffer;
    }
}

void expand(char* inputPathFile, char* outputPathFile){
    Configuration config = getConfig(inputPathFile, "rb");

    int size = readInt(config.fs);

    for(int i = 0; i < size; i++){
        char c = readChar(config.fs);
        int i = readInt(config.fs);
        if(nodes[c] == NULL) nodes[c] = newNode(c, i);
    }

    int sizeBuffer = readInt(config.fs);

    freq_prob_expand(sizeBuffer);
}

void maina(){
     expand("test_arithmetic.dat", "text.txt");
}
