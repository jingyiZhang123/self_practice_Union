#ifndef UNION3_H
#define UNION3_H

#include <stdbool.h>

struct UnionFind3{
    int* parent;
    int count;
    int* sz;
};

typedef struct UnionFind3 UnionFind3_t;
typedef UnionFind3_t* UnionFind3_p;

extern UnionFind3_p UnionFind3_Init(int n);
extern int UnionFind3_QuickFind(UnionFind3_p uf, int target);
extern bool UnionFind3_IsConnected(UnionFind3_p uf, int a, int b);
extern void UnionFind3_UnionElems(UnionFind3_p uf, int a, int b);
extern void UnionFind3_Destruct(UnionFind3_p uf);


#endif
