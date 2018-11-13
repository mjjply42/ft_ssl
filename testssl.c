#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include "ft_ssl.h"

static unsigned int K[64] = 
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void    compress_message(int i, h_s *hash)
{
    uint32_t t[2];

    t[0] = hash->h + EP1(hash->e) + CH(hash->e, hash->f, hash->g) +
        K[i] + hash->exp_message[i];
    t[1] = EP0(hash->a) + MAJ(hash->a, hash->b, hash->c);
    hash->h = hash->g;
    hash->g = hash->f;
    hash->f = hash->e;
    hash->e = hash->d + t[0];
    hash->d = hash->c;
    hash->c = hash->b;
    hash->b = hash->a;
    hash->a = t[0] + t[1];
    printf("%x  %x  %x  %x  %x  %x  %x  %x\n", hash->a, hash->b, hash->c, hash->d, hash->e, hash->f, hash->g, hash->h);
}

void    expand_message(h_s *hash)
{
    int i;

    i = 0;
    while (i < 16)
    {
        hash->exp_message[i] = hash->message[i];
        i++;
    }
    while (i < 64)
    {
        hash->exp_message[i] = SIG1(hash->exp_message[i - 2]) + hash->exp_message[i - 7]
			+ SIG0(hash->exp_message[i - 15])
			+ hash->exp_message[i - 16];
		i++;
    }
}

void  sha256_process(h_s *hash, uint32_t *state)
{
    int i;

    i = -1;
    hash->a = state[0];
    hash->b = state[1];
    hash->c = state[2];
    hash->d = state[3];
    hash->e = state[4];
    hash->f = state[5];
    hash->g = state[6];
    hash->h = state[7];
    expand_message(hash);
    while (++i < 64)
        compress_message(i, hash);
    state[0] = hash->a + state[0];
    state[1] = hash->b + state[1];
    state[2] = hash->c + state[2];
    state[3] = hash->d + state[3];
    state[4] = hash->e + state[4];
    state[5] = hash->f + state[5];
    state[6] = hash->g + state[6];
    state[7] = hash->h + state[7];
    printf("FINAL:");
    printf("%x  %x  %x  %x  %x  %x  %x  %x\n", state[0], state[1], state[2], state[3], state[4], state[5], state[7], state[8]);
}

unsigned char   *sha256_hash(unsigned char *message, unsigned long long byte_count)
{
    h_s *hash;
    unsigned long long bits_done;
    uint32_t state[8];
    char *str;

    hash = ft_memalloc(sizeof(h_s));
    bits_done = 0;
    state[0] = 0x6a09e667;
    state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372;
    state[3] = 0xa54ff53a;
    state[4] = 0x510e527f;
    state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab;
    state[7] = 0x5be0cd19;
    printf("%x  %x  %x  %x  %x  %x  %x  %x\n", state[0], state[1], state[2], state[3], state[4], state[5], state[6], state[7]);
    while (bits_done < (byte_count / 8))
   { 
        ft_char_to_uint32(hash->message, message + bits_done, sizeof(unsigned long long) * 32);
        sha256_process(hash, state);
        ft_uint32_to_chr((unsigned char*)hash->message, (uint32_t*)(message + bits_done) , sizeof(unsigned long long) * 32);
        bits_done += (512 / 8);
   }
    free(hash);
    str = ft_strnew(32);
    return (ft_uint32_to_chr((unsigned char *)str, state, sizeof(unsigned long long) * 4));
}



int       sha256_pad_start(m_s *pre_image, char **argv)
{
    int i;

    i = pre_image->count;
    printf("ARGV IS %s\n", *(argv + pre_image->count));
    if (ft_strcmp("-p", argv[2]) == 0)
        pre_image->flags[0] = pre_image->STREAMS = 1;
    printf("%i\n", pre_image->flags[1]);
    printf("!INPUT %s\n", pre_image->input);
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
        //print_digest(pre_image->digest, pre_image, argv);
        //pre_image->input = NULL;
    }
    if (pre_image->s_error == TRUE)
        error_code(3);
    //destroy_data(pre_image);
    return (i += 1);
}