#ifndef UNION5_H
#define UNION5_H

#include <stdbool.h>

struct UnionFind5{
    int* parent;
    int count;
    int* rank;
};

typedef struct UnionFind5 UnionFind5_t;
typedef UnionFind5_t* UnionFind5_p;

extern UnionFind5_p UnionFind5_Init(int n);
extern int UnionFind5_QuickFind(UnionFind5_p uf, int target);
extern bool UnionFind5_IsConnected(UnionFind5_p uf, int a, int b);
extern void UnionFind5_UnionElems(UnionFind5_p uf, int a, int b);
extern void UnionFind5_Destruct(UnionFind5_p uf);


#endif
