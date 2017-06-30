
#include "union3.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

extern UnionFind3_p UnionFind3_Init(int n);
extern int UnionFind3_QuickFind(UnionFind3_p uf, int target);
extern bool UnionFind3_IsConnected(UnionFind3_p uf, int a, int b);
extern void UnionFind3_UnionElems(UnionFind3_p uf, int a, int b);
extern void UnionFind3_Destruct(UnionFind3_p uf);

/**************************************
 *                                    *
 * Public functions                   *
 *                                    *
 **************************************/

UnionFind3_p UnionFind3_Init(int n){
    UnionFind3_p new_uf = malloc(sizeof(UnionFind3_t));
    assert(new_uf != NULL);

    new_uf->count = n;
    new_uf->parent = malloc(sizeof(int) * n);
    new_uf->sz = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        new_uf->parent[i] = i;
        new_uf->sz[i] = 1;
    }

    return new_uf;
}

int UnionFind3_QuickFind(UnionFind3_p uf, int target){
    assert(target >= 0 && target < uf->count);
    while (target != uf->parent[target])
        target = uf->parent[target];

    return target;
}

bool UnionFind3_IsConnected(UnionFind3_p uf, int a, int b){
    return UnionFind3_QuickFind(uf, a) == UnionFind3_QuickFind(uf, b);
}

void UnionFind3_UnionElems(UnionFind3_p uf, int a, int b){
    int aRoot = UnionFind3_QuickFind(uf, a);
    int bRoot = UnionFind3_QuickFind(uf, b);
    if(aRoot == bRoot)
        return;

    if(uf->sz[aRoot] < uf->sz[bRoot]){
        uf->parent[aRoot] = bRoot;
        uf->sz[bRoot] += uf->sz[aRoot];
    }
    else{
        uf->parent[bRoot] = aRoot;
        uf->sz[aRoot] += uf->sz[bRoot];
    }
    return;

}

void UnionFind3_Destruct(UnionFind3_p uf){
    free(uf->parent);
    free(uf->sz);
    free(uf);
}

/**************************************
 *                                    *
 * Private functions                   *
 *                                    *
 **************************************/
