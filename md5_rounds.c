#include "ft_ssl.h"
#include "constants.h"

extern md5_f		md5_table[4][16];

void	md5_rounds(h_s *hash, int i)
{
	short j;
	md5_f formula;

	j = 0;
	while (j < 16)
	{
		formula = md5_table[i][j];
		if (!(j % 4))
			hash->a = hash->b + ROTATE_LEFT((hash->a + formula.f(hash->b, hash->c, hash->d)
			 + hash->message[formula.block] + formula.signed_constant), formula.step);
		else if (j % 4 == 1)
			hash->d = hash->a + ROTATE_LEFT((hash->d + formula.f(hash->a, hash->b, hash->c)
			 + hash->message[formula.block] + formula.signed_constant), formula.step);
		else if (j % 4 == 2)
			hash->c = hash->d + ROTATE_LEFT((hash->c + formula.f(hash->d, hash->a, hash->b)
			 + hash->message[formula.block] + formula.signed_constant), formula.step);
		else
			hash->b = hash->c + ROTATE_LEFT((hash->b + formula.f(hash->c, hash->d, hash->a)
			 + hash->message[formula.block] + formula.signed_constant), formula.step);
		j += 1;
	}
}

void	md5_process(h_s *hash, uint32_t *state)
{
	int	i;

	i = 0;
	hash->a = state[0];
	hash->b = state[1];
	hash->c = state[2];
	hash->d = state[3];
	i = -1;
	while (++i < 4)
		md5_rounds(hash, i);
	state[0] += hash->a;
	state[1] += hash->b;
	state[2] += hash->c;
	state[3] += hash->d;
}