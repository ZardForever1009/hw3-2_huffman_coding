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
	int freq=100000;
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
void str_result(int symbol_count, Node* arr){
	// print input array in format way
	cout<<"Symbol: ";
	for(int i=0;i<symbol_count;i++){
		cout<<arr[i].data<<" ";
	}
	cout<<"\nFrequency: ";
	for(int i=0;i<symbol_count;i++){
		cout<<arr[i].freq<<" ";
	}
	cout<<endl;
	return;
}

// rebuild array to normal form (filled empty element with data '~')
void refactor_arr(int symbol_count, Node*& arr){
	for(int i;i<symbol_count-1;i++){
		if(arr[i].data=='~'){
			swap(arr[i], arr[i+1]);
		}
	}
	return;
}

// get minimum frequency node out of array
Node* min_freq_node(int symbol_count, Node*& arr){
	Node* min_node=new Node();
	// find the minimum freq node
	int idx=0;
	for(int i=0;i<symbol_count;i++){
		if((arr[i].freq<min_node->freq)&&(arr[i].data!='~')){
			*min_node=arr[i];
			idx=i; // reset array item index
		}
	}
	arr[idx].data='~'; // reset arr[i]
	arr[idx].freq=100000;
	// refactor array
	refactor_arr(symbol_count, arr);
	return min_node;
}

// build huffman tree
void build_huffman_tree(int symbol_count, Node*& arr){
	
}

// print huffman tree result
void huffman_result(){
	cout<<"Huffman Tree:\n";
	
	return;
}

// all function combination
void huffman_coding(){
	/*--------------------Prepararion---------------------*/
	string str, code; // str: input string / code: huffman code
	/* cin>>str; */
	/* cin>>code; */
	str="ccccccbbbaadddddddeeeeeeeeeevgsdfvdjsfhdsfhdsfhdsfh";
	code="110011000001";
	int* alphabet=new int[26]; // store letters' appearance counts
	int symbol_count=diff_char_count(str, alphabet); // different letters' counts
	Node* arr=new Node[symbol_count]; // create Node array
	build_node_arr(arr, alphabet);
	str_result(symbol_count, arr);
	
	cout<<min_freq_node(symbol_count, arr)->data<<endl;
	str_result(symbol_count, arr);
	cout<<min_freq_node(symbol_count, arr)->data<<endl;
	str_result(symbol_count, arr);
	cout<<min_freq_node(symbol_count, arr)->data<<endl;
	str_result(symbol_count, arr);
	cout<<min_freq_node(symbol_count, arr)->data<<endl;
	str_result(symbol_count, arr);
	cout<<min_freq_node(symbol_count, arr)->data<<endl;
	str_result(symbol_count, arr);
	cout<<min_freq_node(symbol_count, arr)->data<<endl;
	str_result(symbol_count, arr);
	
	huffman_result();
	return;
}

int main(){
	
	huffman_coding();
	
	system("pause");
	return 0;
}
