
#include "union1.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


extern UnionFind1_p UnionFind1_Init(int n);
extern int UnionFind1_QuickFind(UnionFind1_p uf, int target);
extern bool UnionFind1_IsConnected(UnionFind1_p uf, int a, int b);
extern void UnionFind1_UnionElems(UnionFind1_p uf, int a, int b);
extern void UnionFind1_Destruct(UnionFind1_p uf);


/**************************************
 *                                    *
 * Public functions                   *
 *                                    *
 **************************************/

UnionFind1_p UnionFind1_Init(int n){
    UnionFind1_p new_uf = malloc(sizeof(UnionFind1_t));
    assert(new_uf != NULL);

    new_uf->count = n;
    new_uf->id = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        new_uf->id[i] = i;

    return new_uf;
}

int UnionFind1_QuickFind(UnionFind1_p uf, int target){
    assert(target >= 0 && target < uf->count);
    return uf->id[target];
}

bool UnionFind1_IsConnected(UnionFind1_p uf, int a, int b){
    return UnionFind1_QuickFind(uf, a) == UnionFind1_QuickFind(uf, b);
}

void UnionFind1_UnionElems(UnionFind1_p uf, int a, int b){
    int aID = UnionFind1_QuickFind(uf, a);
    int bID = UnionFind1_QuickFind(uf, b);
    if(aID == bID)
        return;

    for (int i = 0; i < uf->count; i++)
        if (uf->id[i] == aID)
            uf->id[i] = bID;

}

void UnionFind1_Destruct(UnionFind1_p uf){
    free(uf->id);
    free(uf);
}

/**************************************
 *                                    *
 * Private functions                   *
 *                                    *
 **************************************/
