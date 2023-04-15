#pragma once
#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, если ключ является концом слова
	bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode* root, string key);
bool isEmpty(TrieNode* root);
void getArrayNode(TrieNode* root, string curren_key);
int autoComplete(TrieNode* root, string key);
