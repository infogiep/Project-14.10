#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string arr[] = { "apple","baby","cat","dog","ear","fan","grass","animal","horse","mother","world","iron","build","jacket","work","key","lamp","milk","nose","orange","parrot","think","rose","snow","all","table","unit","then","vision","water", "yoga", "zebra", "run", "wolf", "rabbit", "watch", "dove", "duck", "mango" };

	TrieNode* root = getNewNode();
	for (string item : arr)
	{
		insert(root, item);
	}

	while (true)
	{
		string word1;

		cout << "Enter few letters. To exit enter capital: X" << endl;
		cin >> word1;
		if (word1 == "X") break; // Exit
		cout << endl << endl;
		int comp = autoComplete(root, word1);
		if (comp == -1)
			cout << "No other words found" << endl;
		else if (comp == 0)
			cout << "Similar words not found" << endl;
	}
	return 0;
}
