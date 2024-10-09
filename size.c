#include <stdint.h>
#include <stdio.h>

void print_as_bin(char c) {
    for(int place = 128; place > 0; place /= 2) {
        if((c & place) == 0) printf("0");
        else printf("1");
    }
}


int main() {   
    printf("sizeof(char): %ld\n", sizeof(char)); //1
    
    //not a function. it's a meat complier feature
    //sizeof(_) takes a type or expression,
    //reports # of bytes taken up by that byte

    printf("sizeof(int8_t): %ld\n", sizeof(int8_t)); //1
    printf("sizeof(uint8_t): %ld\n", sizeof(uint8_t)); //1 --> 8 bits of integere.g 0-255

    printf("sizeof(int16_t): %ld\n", sizeof(int16_t)); //2
    printf("sizeof(uint16_t): %ld\n", sizeof(uint16_t)); //2
                                                         //-2^15 - (2^15 -1)
                                                         //goes 0 - (2^16 -1)
                                                         //ld: long decimal, result of sizeof =: 16 bits integers
    printf("sizeof(int32_t): %ld\n", sizeof(int32_t)); //4

    printf("sizeof(int64_t): %ld\n", sizeof(int64_t)); //8

    printf("sizeof(int): %ld\n", sizeof(int));  //4 codespaces there are systems where int is 8
                                                //4 ieng 6
                                                //4 mac

    

    char c = 128;
    int32_t i = 32;
    char c2 = c + 1; //stored as 1 byte char in c2 despite maybe briefly using 4 bytes for c+1

    printf("sizeof(c): %ld\n", sizeof(c)); //1
    printf("sizeof(i): %ld\n", sizeof(i)); //4
    printf("sizeof(c * 4000): %ld\n", sizeof(c * 4000)); //4        
    printf("sizeof(c + 1): %ld\n", sizeof(c + 1)); //4

    //hey look at 1! that's an integer, the default size for integerts is 4 bytes.
    //hey look at arithmetic! the left is size 1 and the right is size 4,
    //let's use the biggest size operator as the result size.
    printf("sizeof(c2): %ld\n", sizeof(c2)); //1

    //in lecture example
    char arr[] = "hello!";
    printf("sizeof(arr): %ld\n", sizeof(arr));

    char noterm[] = {'y', 'o', 'l', 'o'}; //sizeof is not strlen, 
                                        //strlen: is a function (array of character and how many b4 null-terminator)
                                        //sizeof: not a function; calculates the size based on what it sees (based on the type it sees)
    printf("sizeof(noterm): %d\n", sizeof(noterm));

    unsigned char toobig = 200 + 63;
    printf("sizeof(toobig): %ld; toobig: %d\n", sizeof(toobig), toobig);


    char s = 200;
    unsigned char u = 200;

    printf("s: ");
    print_as_bin(s);
    printf("\t\tu: ");
    print_as_bin(u);
    printf("\n");

    printf("s as hhx: %hhx\t\tu as hhx: %hhx\n", s, u);
    printf("s as x: %x\tu as x: %x\n", s, u);

    printf("s < 127: %d u < 127: %d\n", s > 127, u > 127);

}