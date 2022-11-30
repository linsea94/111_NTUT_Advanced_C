#include "space.h"

tTypeScore score_buf[N]; // preallocated memory space

void get_score_space(tTypeScore **pp_score, int score, int cnt)
{
    (*pp_score) = (tTypeScore *)malloc(sizeof(tTypeScore));
    printf("flaggg\n");
    (*pp_score)->score = score;
    (*pp_score)->loc = cnt;
    (*pp_score)->used = 1;

    printf("     get_score_space(): giving space numbered %d\n", cnt);
}

void return_score_space(int loc)
{
    printf("     return_score_space(): return space numbered %d\n", loc);
}
