#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "File.h"
#include "coder.h"
#include "PriorityQueue.h"
#include "Node.h"

LinkedList count_freq(char* buffer, int size_buffer, LinkedList ll){
    for(int i = 0; i < size_buffer; i++) ll = updateLinkedList(ll, buffer[i], 1);
    return ll;
}

LinkedList freq_prob(LinkedList ll_freq_prob, LinkedList ll, int sizeBuffer){
    LinkedList ll_buffer = ll;
    long double acc = 0;

    while(ll_buffer != NULL){
        int content = getContentLinkedList(ll_buffer);
        LimitsConfig lc = newLimitsConfig(acc, acc + content / (double) sizeBuffer);
        ll_freq_prob = insertLimitsConfigBeginningLinkedList(ll_freq_prob, getKeyLinkedList(ll_buffer), lc);

        acc = acc + content / (double) sizeBuffer;
        ll_buffer = getNextNodeLinkedList(ll_buffer);
    }

    return ll_freq_prob;
}

LinkedList sortLinkedList(LinkedList ll){

    PriorityQueue pq = newPriorityQueue(sizeLinkedList(ll));
    while(ll != NULL){
        Node node = newNode(getKeyLinkedList(ll), getContentLinkedList(ll));
        insertPriorityQueue(pq, getContentLinkedList(ll), node);
        ll = getNextNodeLinkedList(ll);
    }

    LinkedList sortedList = newLinkedList();
    while(!isEmptyPriorityQueue(pq)){
        Node node = removeMinPriorityQueue(pq);
        sortedList = insertAfterLinkedList(sortedList, getKeyNode(node), getContentNode(node));
    }
    return sortedList;
}

void compress(char* inputPathFile, char* outputPathFile){
    FILE* file = fopen(inputPathFile, "rt");
    fseek(file, 0L, SEEK_END);
    int sizeBuffer = ftell(file);
    char buffer[sizeBuffer];
    rewind(file);

    fread(&buffer, sizeof(char), sizeBuffer, file);

    fclose(file);

    LinkedList ll = newLinkedList();
    ll = count_freq(buffer, strlen(buffer), ll);
    //ll = sortLinkedList(ll);

    LinkedList ll_freq_prof = newLinkedList();
    ll_freq_prof = freq_prob(ll_freq_prof, ll, strlen(buffer));

    toString(ll_freq_prof);

    Configuration config = getConfig(outputPathFile);

    create_or_open_file(config.output);

    writeByte(sizeLinkedList(ll_freq_prof));
    LinkedList ll_buffer = ll;
    while(ll_buffer != NULL){
        writeChar(getKeyLinkedList(ll_buffer));
        writeByte(getContentLinkedList(ll_buffer));
        ll_buffer = getNextNodeLinkedList(ll_buffer);
    }

    for(int i = 0; i < sizeBuffer; i++){
        write(ll_freq_prof, buffer[i], strlen(buffer), &config);
    }

    close_file();
}


void main(){

   compress("text_arithmetic.txt", "test_arithmetic.dat");
}
