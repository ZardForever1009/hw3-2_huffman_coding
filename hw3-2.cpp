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
	char data='#';
	int freq=-1;
	Node* left=nullptr;
	Node* right=nullptr;
};

// differnet letters' counts of input string analyze 
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

// build non-zero char arr (place symbols & data to array)
void build_node_arr(Node*& arr, int* alphabet){
	int idx=0;
	for(int i=0;i<26;i++){
		if(alphabet[i]!=0){
			arr[idx].data=char(i+97);
			arr[idx].freq=alphabet[i];
			idx++;
		}
	}
	return;
}

// print input string result
void str_result(int c_count, Node* arr){
	// print input array in format way
	cout<<"Symbol: ";
	for(int i=0;i<c_count;i++){
		cout<<arr[i].data<<" ";
	}
	cout<<"\nFrequency: ";
	for(int i=0;i<c_count;i++){
		cout<<arr[i].freq<<" ";
	}
	return;
}

// rebuild array to normal form (filled empty element with data '~')
void normalize_arr(Node*& arr){
	
}

// get minimum frequency node out of array
Node* min_freq_node(int c_count, Node*& arr ){
	
}

// print huffman tree result
void huffman_result(){
	cout<<"\nHuffman Tree:\n";
	
	return;
}

// all function combination
void huffman_coding(){
	/*--------------------Prepararion---------------------*/
	string str, code; // str: input string / code: huffman code
	/* cin>>str; */
	/* cin>>code; */
	str="ccccccbbbaadddddddeeeeeeeeee";
	code="110011000001";
	int* alphabet=new int[26]; // store letters' appearance counts
	int symbol_count=diff_char_count(str, alphabet); // different letters' counts
	Node* arr=new Node[symbol_count]; // create Node array
	build_node_arr(arr, alphabet);
	str_result(symbol_count, arr);
	
	huffman_result();
	return;
}

int main(){
	
	huffman_coding();
	
	system("pause");
	return 0;
}
