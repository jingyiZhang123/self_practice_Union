
#include "union2.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

extern UnionFind2_p UnionFind2_Init(int n);
extern int UnionFind2_QuickFind(UnionFind2_p uf, int target);
extern bool UnionFind2_IsConnected(UnionFind2_p uf, int a, int b);
extern void UnionFind2_UnionElems(UnionFind2_p uf, int a, int b);
extern void UnionFind2_Destruct(UnionFind2_p uf);

/**************************************
 *                                    *
 * Public functions                   *
 *                                    *
 **************************************/

UnionFind2_p UnionFind2_Init(int n){
    UnionFind2_p new_uf = malloc(sizeof(UnionFind2_t));
    assert(new_uf != NULL);

    new_uf->count = n;
    new_uf->parent = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        new_uf->parent[i] = i;

    return new_uf;
}

int UnionFind2_QuickFind(UnionFind2_p uf, int target){
    assert(target >= 0 && target < uf->count);
    while (target != uf->parent[target])
        target = uf->parent[target];

    return target;
}

bool UnionFind2_IsConnected(UnionFind2_p uf, int a, int b){
    return UnionFind2_QuickFind(uf, a) == UnionFind2_QuickFind(uf, b);
}

void UnionFind2_UnionElems(UnionFind2_p uf, int a, int b){
    int aRoot = UnionFind2_QuickFind(uf, a);
    int bRoot = UnionFind2_QuickFind(uf, b);
    if(aRoot == bRoot)
        return;

    uf->parent[aRoot] = bRoot;
    return;

}

void UnionFind2_Destruct(UnionFind2_p uf){
    free(uf->parent);
    free(uf);
}

/**************************************
 *                                    *
 * Private functions                   *
 *                                    *
 **************************************/
