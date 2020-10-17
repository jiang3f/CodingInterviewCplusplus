//
// https://practice.geeksforgeeks.org/problems/huffman-decoding/1/?category[]=Greedy&page=1&query=category[]Greedypage1
//
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

namespace HuffmanDecoding
{

	map<char, string> codes;
	map<char, int> freq;
	//MinHeap structure
	struct MinHeapNode
	{
		char data;
		int freq;
		MinHeapNode* left, * right;
		MinHeapNode(char data, int freq)
		{
			left = right = NULL;
			this->data = data;
			this->freq = freq;
		}
	};

	struct compare
	{
		bool operator()(MinHeapNode* l, MinHeapNode* r)
		{
			return (l->freq > r->freq);
		}
	};

	void printCodes(struct MinHeapNode* root, string str)
	{
		if (!root)
			return;
		if (root->data != '$')
			cout << root->data << ": " << str << "\n";
		printCodes(root->left, str + "0");
		printCodes(root->right, str + "1");
	}

	void storeCodes(struct MinHeapNode* root, string str)
	{
		if (root == NULL)
			return;
		if (root->data != '$')
			codes[root->data] = str;
		storeCodes(root->left, str + "0");
		storeCodes(root->right, str + "1");
	}

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	//huffman Code function
	void HuffmanCodes(int size)
	{
		struct MinHeapNode* left, * right, * top;
		for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
			minHeap.push(new MinHeapNode(v->first, v->second));
		while (minHeap.size() != 1)
		{
			left = minHeap.top();
			minHeap.pop();
			right = minHeap.top();
			minHeap.pop();
			top = new MinHeapNode('$', left->freq + right->freq);
			top->left = left;
			top->right = right;
			minHeap.push(top);
		}
		storeCodes(minHeap.top(), "");
	}

	void calcFreq(string str, int n)
	{
		for (int i = 0; i < str.size(); i++)
			freq[str[i]]++;
	}

    // task is to complete this function
    // function should return decoded string from 
    // the given bianry encoded string
    string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
    {
        // Code here
		string ret;

		return ret;
    }
};


int HuffmanDecoding_Test ()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        string str;
        //taking string
        cin >> str;
        string encodedString, decodedString;
        //function calls
		HuffmanDecoding::calcFreq(str, (int)str.length());
		HuffmanDecoding::HuffmanCodes((int)str.length());

        //adding encoded string
        for (auto i : str)encodedString += HuffmanDecoding::codes[i];
        //cout<<encodedString<<endl;

        //decoding encoded string
        decodedString = HuffmanDecoding::decodeHuffmanData(HuffmanDecoding::minHeap.top(), encodedString);
        cout << decodedString << endl;
    }
    return 0;
}

