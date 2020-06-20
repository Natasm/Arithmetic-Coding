#include <stdio.h>
#include <stdlib.h>
#include "LimitsConfig.h"
#include "File.h"
#include "coder.h"
#include "Node.h"

#define SIZE_ALPHABETIC 256

Node nodes[256];
int sizeNodeValid = 0;

LimitsConfig limits_config[256];

void count_freq(FILE* input){
    int ch = getc(input);

    while(ch != EOF){
        if(nodes[ch] == NULL) nodes[ch] = newNode(ch, 1);
        else nodes[ch] = addContentNode(nodes[ch], 1);

        ch = getc(input);
    }
}

void freq_prob(int sizeNode, int sizeBuffer){
    long double acc = 0;

    for(int i = 0; i < sizeNode; i++){
        if(nodes[i] == NULL) continue;

        int content = getContentNode(nodes[i]);
        if(limits_config[i] == NULL) limits_config[i] = newLimitsConfig(acc, acc + content / (double) sizeBuffer);

        acc = acc + content / (double) sizeBuffer;
        sizeNodeValid++;
    }
}

void compress(char* inputPathFile, char* outputPathFile){
    FILE* file_input = fopen(inputPathFile, "rt");
    fseek(file_input, 0L, SEEK_END);
    int sizeBuffer = ftell(file_input);

    rewind(file_input);

    count_freq(file_input);
    freq_prob(SIZE_ALPHABETIC, sizeBuffer);

    Configuration config = getConfig(outputPathFile, "wb");

    writeInt(config.fs, sizeNodeValid);
    for(int i = 0; i < SIZE_ALPHABETIC; i++){
        if(nodes[i] != NULL){
           writeChar(config.fs, getKeyNode(nodes[i]));
           writeInt(config.fs,  getContentNode(nodes[i]));
        }
    }

    writeInt(config.fs, sizeBuffer);

    rewind(file_input);

    int ch = getc(file_input);
    while(ch != EOF){
        write(&limits_config, ch, sizeBuffer, &config);
        ch = getc(file_input);
    }

    close_file(config.fs, "wb");
    fclose(file_input);
}

void main(){
   compress("The_Bible.txt", "test_arithmetic.dat");
}
