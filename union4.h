#ifndef UNION4_H
#define UNION4_H

#include <stdbool.h>

struct UnionFind4{
    int* parent;
    int count;
    int* rank;
};

typedef struct UnionFind4 UnionFind4_t;
typedef UnionFind4_t* UnionFind4_p;

extern UnionFind4_p UnionFind4_Init(int n);
extern int UnionFind4_QuickFind(UnionFind4_p uf, int target);
extern bool UnionFind4_IsConnected(UnionFind4_p uf, int a, int b);
extern void UnionFind4_UnionElems(UnionFind4_p uf, int a, int b);
extern void UnionFind4_Destruct(UnionFind4_p uf);


#endif
