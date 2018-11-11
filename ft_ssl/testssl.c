#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include "ft_ssl.h"

//+ == x & (2n -1) ex: 17 (0x11) modulo 16(0x10) equals 0x11 & 0xF = 0x1

//RR# == Rotate Right (#ofBits)
//SR# == Shift Right (#ofBits)

//Ch(x, y, z) = (x&y) ^ (~x&z)
//Maj(x, y, z) = (x&y) ^ (x&z) ^ (y&z)
//E0(x) = (RR2)(x) ^ (RR13)(x) ^ (R22)(x)
//E1(x) = (RR6)(x) ^ (RR11)(x) ^ (RR25)(x)
//O0(x) = (RR7)(x) ^ (RR18)(x) ^ (SR3)(x)
//01(x) = (RR17)(x) ^ (RR19)(x) ^ (SR10)(x)

//START

//Initial Value(32bitWords)
//H1 = 6a09e667
//H2 = bb67ae85
//H3 = 3c6ef372
//H4 = a54ff53a
//H5 = 510e527f
//H6 = 9b05688c
//H7 = 1f83d9ab
//H8 = 5be0cd19

//Initial Registers
//a = H1
//b = H2
//c = H3
//d = H4
//e = H5
//f = H6
//g = H7
//h = H8

//Compression Function
//while j < 64
//T1 = h (mod2/32add) E1(e) (mod2/32add) Ch(e, f, g) (mod2/32add) Kj (mod2/32add) Wj
//T2 = E0(a) (mod2/32add) Maj(a, b, c)
//h = g
//g = f
//f = e
//e = d (mod2/32add) T1
//d = c
//c = b
//b = a
//a = T1 (mod2/32add) T2

//while ++j < 16
//Wj = Mj  /* M represents the input message to be digested(the first 512 bit chunk)*/
//while ++j >= 16 < 64
//Wj = O1(Wj-2) (mod2/32add) Wj-7 (mod2/32add) 0o(Wj-15) (mod2/32add) Wj-16 

//constants(K)(64)
//428a2f98 71374491 b5c0fbcf e9b5dba5 3956c25b 59f111f1 923f82a4 ab1c5ed5
//d807aa98 12835b01 243185be 550c7dc3 72be5d74 80deb1fe 9bdc06a7 c19bf174
//e49b69c1 efbe4786 0fc19dc6 240ca1cc 2de92c6f 4a7484aa 5cb0a9dc 76f988da
//983e5152 a831c66d b00327c8 bf597fc7 c6e00bf3 d5a79147 06ca6351 14292967
//27b70a85 2e1b2138 4d2c6dfc 53380d13 650a7354 766a0abb 81c2c92e 92722c85
//a2bfe8a1 a81a664b c24b8b70 c76c51a3 d192e819 d6990624 f40e3585 106aa070
//19a4c116 1e376c08 2748774c 34b0bcb5 391c0cb3 4ed8aa4a 5b9cca4f 682e6ff3
//748f82ee 78a5636f 84c87814 8cc70208 90befffa a4506ceb bef9a3f7 c67178f2






//FINAL OPS
//H1 = a (mod2/32add) H1
//H2 = b (mod2/32add) H2
//H3 = c (mod2/32add) H3
//H4 = d (mod2/32add) H4
//H5 = e (mod2/32add) H5
//H6 = f (mod2/32add) H6
//H7 = g (mod2/32add) H7
//H8 = h (mod2/32add) H8

int       sha256_pad_start(m_s *pre_image, char **argv)
{
    int i;

    i = pre_image->count;
    printf("ARGV IS %s\n", *(argv + pre_image->count));
    if (ft_strcmp("-p", argv[2]) == 0)
        pre_image->flags[0] = pre_image->STREAMS = 1;
    printf("%i\n", pre_image->flags[1]);
    printf("!STREAMS %s\n", pre_image->stream);
    if (pre_image->STREAMS != FALSE || pre_image->flags[0] == 1)
    {
        pre_image->bit_size = (ft_strlen(pre_image->stream) * 8);
        printf("HEL\n");
        padding(pre_image);
        printf("HELLOOO\n");
        print_digest(pre_image->digest, pre_image, argv);
        pre_image->STREAMS = pre_image->bit_size = 0;
        //free(pre_image->stream);
    }
    if (pre_image->input != NULL)
    {
        pre_image->bit_size = (ft_strlen(pre_image->input) * 8);
        printf("HERE\n");
        printf("BIT SIZE %llu\n", pre_image->bit_size);
        padding(pre_image);
        print_digest(pre_image->digest, pre_image, argv);
        //pre_image->input = NULL;
    }
    if (pre_image->s_error == TRUE)
        error_code(3);
    //destroy_data(pre_image);
    return (i += 1);
}