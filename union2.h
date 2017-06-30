#ifndef UNION2_H
#define UNION2_H

#include <stdbool.h>

struct UnionFind2{
    int* parent;
    int count;
};

typedef struct UnionFind2 UnionFind2_t;
typedef UnionFind2_t* UnionFind2_p;

extern UnionFind2_p UnionFind2_Init(int n);
extern int UnionFind2_QuickFind(UnionFind2_p uf, int target);
extern bool UnionFind2_IsConnected(UnionFind2_p uf, int a, int b);
extern void UnionFind2_UnionElems(UnionFind2_p uf, int a, int b);
extern void UnionFind2_Destruct(UnionFind2_p uf);


#endif
