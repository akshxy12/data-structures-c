#include "../../../include/data-structures/non-linear-ds/trie.h"
#define T_OR_F(value) value ? "true" : "false"

TrieNode *trie_node_create(char character)
{
    TrieNode *new_node = (TrieNode *)malloc(sizeof(TrieNode));

    if (new_node == NULL)
        return NULL;

    new_node->character = character;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        new_node->children[i] = NULL;
    }
    new_node->end_of_word = false;

    return new_node;
}
void trie_node_destroy(TrieNode **trienodeptr)
{
    if (*trienodeptr == NULL)
        return;

    (*trienodeptr)->character = END_OF_STRING_CHAR;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if ((*trienodeptr)->children[i] != NULL)
        {
            free((*trienodeptr)->children[i]);
            (*trienodeptr)->children[i] = NULL;
        }
    }
    (*trienodeptr)->end_of_word = false;

    free(*trienodeptr);
    *trienodeptr = NULL;
}

Trie *trie_create()
{
    Trie *new_trie = (Trie *)malloc(sizeof(Trie));

    if (new_trie == NULL)
        return NULL;

    new_trie->root = NULL;

    return new_trie;
}

bool trie_insert(Trie *trie, char *new_word)
{
    if (trie == NULL)
        return false;

    //  If the trie is empty
    if (trie->root == NULL)
    {
        trie->root = trie_node_create('^');
    }

    return _trie_insert_word(trie->root, new_word, 0);
}
bool _trie_insert_word(TrieNode *parent, char *string, int index)
{
    if (parent == NULL || index < 0)
        return false;

    if (parent->children[string[index] - 'a'] == NULL)
    {
        parent->children[string[index] - 'a'] = trie_node_create(string[index]);
    }

    if (string[index + 1] != '\0')
    {
        return _trie_insert_word(parent->children[string[index] - 'a'], string, index + 1);
    }

    parent->children[string[index] - 'a']->end_of_word = true;
    return true;
}

bool trie_delete(Trie *trie, char *word_to_del)
{
    if (trie == NULL || trie->root == NULL)
        return false;

    return _trie_delete_word(trie->root, word_to_del, 0);
}
bool _trie_delete_word(TrieNode *cur, char *word, int index)
{
    if(cur == NULL) {
        return false;
    }

    int child_index = -1;
    bool has_other_children = false;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(cur->children[i] != NULL) {
            if(cur->children[i]->character == word[index]) {
                child_index = i;
            } else {
                has_other_children = true;

                if(child_index != -1 || word[index] == '\0') {
                    break;
                }
            }
        }
    }

    bool deleting_child = false;
    if(child_index != -1) {
        deleting_child = _trie_delete_word(cur->children[child_index], word, index+1);
    }

    if(deleting_child) {
        cur->children[child_index] = NULL;
    }

    if(!has_other_children && (child_index == -1 || cur->children[child_index] == NULL)) {
        trie_node_destroy(&cur);
        return true;
    }

    return false;
}

bool trie_search(Trie *trie, char *word_to_search) {
    if(trie == NULL || trie->root == NULL) {
        return NULL;
    }

    return _trie_search_word(trie->root, word_to_search, 0);
}
bool _trie_search_word(TrieNode *node, char *string, int index) {
    if(node == NULL) {
        return false;
    }

    int child_index = -1;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(node->children[i] != NULL) {
            if(node->children[i]->character == string[index]) {
                child_index = i;
                break;
            }
        }
    }

    if(child_index == -1) {
        return false;
    }

    bool child_search = false;
    if(string[index+1] != '\0') {
        child_search = _trie_search_word(node->children[child_index], string, index+1);
    }

    return child_search;
}

void trie_print(Trie *t)
{
    if (t == NULL || t->root == NULL)
        return;

    _trie_print_recurse(t->root, 0, true);
}
bool _trie_print_recurse(TrieNode *trienode, int level, bool is_root)
{
    if (trienode == NULL)
        return false;

    for (int i = 0; i < level; i++)
    {
        printf(" ");
    }

    printf("%c\n", trienode->character);
    if (trienode->end_of_word)
    {
        printf("END OF WORD\n");
    }

    bool printed_child_node = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        printed_child_node = _trie_print_recurse(trienode->children[i], level + 1, false);
        if (is_root && printed_child_node)
        {
            printf("\n");
        }
    }

    if (printed_child_node)
    {
        printf("\n");
    }

    return true;
}

void trie_destroy(Trie **trieptr)
{
    if (*trieptr == NULL)
        return;

    if ((*trieptr)->root != NULL)
    {
        _trie_destroy_all_words((*trieptr)->root);
    }
    free((*trieptr)->root);
    (*trieptr)->root = NULL;

    free(*trieptr);
    *trieptr = NULL;
}
void _trie_destroy_all_words(TrieNode *parent)
{
    if (parent == NULL)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (parent->children[i] != NULL)
        {
            _trie_destroy_all_words(parent->children[i]);
            trie_node_destroy(&parent->children[i]);
        }
    }
}