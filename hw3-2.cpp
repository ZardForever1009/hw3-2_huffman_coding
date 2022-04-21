// hw3-2: Huffman encoding implementation
// environment: Notepad++ 8.2.1(64bits X64)
// C++ type: C++ 14
// g++ type: g++ version 6.3.0
#include <iostream>
#include <string>

using namespace std;

// Node class
class Node{
public:
	char data;
	int freq;
	Node* left=nullptr;
	Node* right=nullptr;
};

// Letters class
class Letter{
public:
	char data='#';
	int count=-1;
};

// differnet letters of input string analyze 
int diff_char_count(string str, int*& alphabet){
	// from 'a' to 'z' check freq
	int char_count=0;
	for(int i=0;i<26;i++){
		alphabet[i]=0;
		for(int jj=0;jj<str.size();jj++){
			if(str[jj]==char(i+97))alphabet[i]++;
		}
	}
	// calculate how many different char exist in string
	for(int i=0;i<26;i++){
		if(alphabet[i]!=0)char_count++;
	}
	return char_count;
}

// build non-zero char arr
void build_char_arr(Letter*& arr, int* alphabet){
	int idx=0;
	for(int i=0;i<26;i++){
		if(alphabet[i]!=0){
			arr[idx].data=char(i+97);
			arr[idx].count=alphabet[i];
			idx++;
		}
	}
	return;
}

// build tree

// analyze encoding code

// print result

// all function combination
huffman_coding(){
	/*--------------------Prepararion---------------------*/
	string str, code; // str: input string / code: huffman code
	str="ccccccbbbaadddddddeeeeeeeeee";
	code="110011000001";
	int* alphabet=new int[26]; // store letters' appearance counts
	int char_count=diff_char_count(str, alphabet); // different letters' counts
	Letter* arr=new Letter[char_count]; // different letter's count & symbol
	build_char_arr(arr, alphabet);
	
}

int main(){
	
	huffman_coding();
	
	system("pause");
	return 0;
}