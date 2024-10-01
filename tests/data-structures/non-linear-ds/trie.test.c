#include "include/data-structures/non-linear-ds/trie.h"

int main()
{
    Trie *trie = trie_create();
    /*
    trie_insert(trie, "some");
    trie_insert(trie, "something");
    trie_insert(trie, "akshay");
    trie_insert(trie, "anushka");
    */

    trie_insert(trie, "ac");
    trie_insert(trie, "ad");
    trie_insert(trie, "adw");
    trie_insert(trie, "befg");
    trie_insert(trie, "befh");
    trie_insert(trie, "zxy");
    
    char to_find[] = "befx";

    if(trie_search(trie, to_find)) {
        printf("Found %s\n", to_find);
    } else {
        printf("Did not find %s\n", to_find);
    }

    trie_delete(trie, "befh");
    
    
    trie_destroy(&trie);

    return 0;
}