#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define END_OF_STRING_CHAR '\0'
#define NOT_FOUND '\0'

typedef struct _trie_node {
    char character;
    struct _trie_node* children[ALPHABET_SIZE];
    bool end_of_word;
} TrieNode;

typedef struct _trie {
    TrieNode* root;
} Trie;

TrieNode* trie_node_create(char character);
void trie_node_destroy(TrieNode** trienodeptr);

Trie* trie_create();
bool trie_insert(Trie* trie, char* new_word);
bool _trie_insert_word(TrieNode* parent, char* string, int index);

bool trie_delete(Trie* trie, char* word_to_del);
bool _trie_delete_word(TrieNode* cur, char* word, int index); 

bool trie_search(Trie* trie, char* word_to_search);
bool _trie_search_word(TrieNode *node, char *string, int index);

void trie_print(Trie* t);
bool _trie_print_recurse(TrieNode* trienode, int level, bool is_root); 

void trie_destroy(Trie** trieptr);
void _trie_destroy_all_words(TrieNode* parent); 

#endif