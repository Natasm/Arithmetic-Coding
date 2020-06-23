#include <stdio.h>
#include <stdlib.h>
#include "LimitsConfig.h"
#include "File.h"
#include "coder.h"
#include "Node.h"

#define SIZE_ALPHABETIC 256

void count_freq(FILE* input, ArithmeticConfig ac){
    int ch = getc(input);

    while(ch != EOF){
        insertNode(ac, ch);
        ch = getc(input);
    }
}

void freq_prob(ArithmeticConfig ac, int sizeBuffer){
    long double acc = 0;

    for(int i = 0; i < SIZE_ALPHABETIC; i++){
        Node node = getNode(ac, i);
        if(node == NULL) continue;

        int content = getContentNode(node);
        insertLimitConfig(ac, i, acc, acc + content / (double) sizeBuffer);

        acc = acc + content / (double) sizeBuffer;
    }
}

void compress(char* inputPathFile, char* outputPathFile){
    FILE* file_input = fopen(inputPathFile, "rt");
    fseek(file_input, 0L, SEEK_END);
    int sizeBuffer = ftell(file_input);

    rewind(file_input);

    ArithmeticConfig ac = newArithmeticConfig();

    count_freq(file_input, ac);
    freq_prob(ac, sizeBuffer);

    Configuration config = getConfig(outputPathFile, "wb");

    writeInt(config.fs, getSizeNodesValid(ac));
    for(int i = 0; i < SIZE_ALPHABETIC; i++){
        if(getNode(ac, i) != NULL){
           writeChar(config.fs, getKeyNode(getNode(ac, i)));
           writeInt(config.fs,  getContentNode(getNode(ac, i)));
        }
    }

    writeInt(config.fs, sizeBuffer);

    rewind(file_input);

    int ch = getc(file_input);
    while(ch != EOF){
        write(ac, ch, sizeBuffer, &config);
        ch = getc(file_input);
    }

    close_file(config.fs, "wb");
    fclose(file_input);
}
