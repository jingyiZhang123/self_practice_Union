#ifndef UNION1_H
#define UNION1_H

#include <stdbool.h>

struct UnionFind1{
    int* id;
    int count;
};

typedef struct UnionFind1 UnionFind1_t;
typedef UnionFind1_t* UnionFind1_p;

extern UnionFind1_p UnionFind1_Init(int n);
extern int UnionFind1_QuickFind(UnionFind1_p uf, int target);
extern bool UnionFind1_IsConnected(UnionFind1_p uf, int a, int b);
extern void UnionFind1_UnionElems(UnionFind1_p uf, int a, int b);
extern void UnionFind1_Destruct(UnionFind1_p uf);


#endif
