#include "Trie.h"

TrieNode* getNewNode(void) // ���������� ����� ���� � ������� ������
{
    struct TrieNode* pNode = new TrieNode; // ����� ����

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;

    // �������������� ����� ������� ����������
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;
    return pNode;
}

// ��������� ���� � ������, ���� ��� ���, 
// ����� ���� ���� ������� ��������� ���� ������ 
// �������� � �������� �������� �.�. ����� �����

void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // �������� ������ � �������� ����� �������� ������������ ������ �����
        int index = key[i] - 'a';

        // ���� ��������� ������, �.�. ����� � ����� ��������� ���
        // ������� ����� ����
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    // �������� ��������� ���� ��� ����, �.�. ����� �����
    node->isEndOfWord = true;
}

bool isEmpty(TrieNode* root) //  true ���� root ����� ����, ����� false 
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

int autoComplete(TrieNode* root, const string key) //  �������������� ���������� �����
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