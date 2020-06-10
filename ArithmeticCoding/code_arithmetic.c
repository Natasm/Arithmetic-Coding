#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "File.h"
#include "coder.h"

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

void compress(char* buffer){
    LinkedList ll = newLinkedList();
    ll = count_freq(buffer, strlen(buffer), ll);

    LinkedList ll_freq_prof = newLinkedList();
    ll_freq_prof = freq_prob(ll_freq_prof, ll, strlen(buffer));

    Configuration config = getConfig();
    //update(ll_freq_prof, 'a', 10, &config);
    //create_or_open_file("test_arithmetic.dat");
    //close_file();
}

void main(){
   compress("abbcccddefffffffffffffffffffffffffffgggghijfgggggmmmsadhduifhsiduhfiusdhiufhiushdsncsdcmmmmcmmmasidojaosidjejdwoeijoiewfoiwroiuweoiuroiweuoriuweoiuroiewhoifhiwudhcvuwrdhiuvohudli");
}
