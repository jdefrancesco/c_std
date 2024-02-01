#ifndef TRIE_H_
#define TRIE_H_

#include <stdbool.h>

// Size of English alphabet, note we assume only lowercase
#define ALPHA_SIZE 26

// TrieNode represents a single node in the trie.
typedef struct TrieNode {
    struct TrieNode *children[ALPHA_SIZE];
    bool is_word;
    // For convenience, we store the character that this node represents.
    char data;
} TrieNode;

// Trie data structure, that stores a set of strings.
// as a prefix tree.
typedef struct Trie {
    TrieNode *trie_root;
    size_t word_count;
} Trie;

// Get new trie node
Trie * trie_new(void);
// Insert into trie
bool trie_insert(Trie* t, const char* str);
// Search for string.
bool trie_search(const Trie* t, const char* str);
// Remove entry from trie.
bool trie_node_remove(TrieNode **t, const char* str);
// Return true if node has any children
bool has_children(const TrieNode* t);
// Cleanup and free trie.
void trie_free(Trie* t);
// Holds number of words that have been inserted into trie.
size_t trie_count(const Trie* t);
// Print content of trie
void trie_print(const Trie *t);
// Insert new trie node to trie.
bool trie_node_insert(TrieNode* t, const char* str);
// Create new node and allocate memory for it.
TrieNode * new_trie_node(char c);

void free_trie_node(TrieNode *t);

#endif  // TRIE_H_
