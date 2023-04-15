#include "Trie.h"

TrieNode* getNewNode(void) // возвращает новый узел с пустыми детьми
{
    struct TrieNode* pNode = new TrieNode; // новый узел

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым указателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;
    return pNode;
}

// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префиксом узла дерева 
// помечает в качестве литового т.е. конец слова

void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисл¤ем индекс в алфавите через смещение относительно первой буквы
        int index = key[i] - 'a';

        // если указатель пустой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    // помечаем последний узел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

bool isEmpty(TrieNode* root) //  true если root имеет лист, иначе false 
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

void getArrayNode(struct TrieNode* root, string currPrefix)
{
    if (root->isEndOfWord)
        cout << currPrefix << endl;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            getArrayNode(root->children[i], currPrefix + child);
        }
}

int autoComplete(TrieNode* root, const string key) //  автодополнение введенного слова
{
    struct TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    if (isEmpty(node)) {
        cout << key << endl;
        return -1;
    }
    getArrayNode(node, key);
    return 1;
}