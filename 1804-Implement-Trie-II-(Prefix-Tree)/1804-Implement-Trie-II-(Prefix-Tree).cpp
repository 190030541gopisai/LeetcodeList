#include<iostream>
const int N = 26;

using namespace std;

struct TrieNode{
	TrieNode *links[N];
	bool flag;
	int endCount, keyCount;
	TrieNode(){
		for(int i = 0; i < N; i++){
			links[i] = nullptr;
		}
		flag = false;
		endCount = keyCount = 0;
	}
	bool contains(char ch){
		return links[ch - 'a'] != nullptr;
	}
	void insertKey(char ch){
		links[ch - 'a'] = new TrieNode();
	}
	TrieNode* getNode(char ch){
		return links[ch - 'a'];
	}
	void increaseKeyCount(){
		keyCount++;
	}
	void increaseEndCount(){
		endCount++;
	}
	void decreaseKeyCount(){
		keyCount--;
	}
	void decreaseEndCount(){
		endCount--;
	}
	int getKeyCount(){
		return keyCount;
	}
	int getEndCount(){
		return endCount;
	}
	void setEnd(){
		flag = true;
	}
	bool isEnd(){
		return flag;
	}
};
class Trie{
private:
	TrieNode *root;
public:
	Trie(){
		root = new TrieNode();
	}
	void insert(string word){	
		TrieNode *node = root;
		int n = word.size();
		for(int i = 0; i < n; i++){
			if(!node->contains(word[i])){
				node->insertKey(word[i]);
			}
			node = node->getNode(word[i]);
			node->increaseKeyCount();
		}
		node->setEnd();
		node->increaseEndCount();
	}
	int countWordsEqualTo(string word){
		TrieNode *node = root;
		int n = word.size();
		for(int i = 0; i < n; i++){
			if(!node->contains(word[i])){
				return 0;
			}
			node = node->getNode(word[i]);
		}
		return node->getEndCount();
	}
	int countWordsStartingWith(string prefix){
		TrieNode *node = root;
		int n = prefix.size();
		for(int i = 0; i < n; i++){
			if(!node->contains(prefix[i])){
				return 0;
			}
			node = node->getNode(prefix[i]);
		}
		return node->getKeyCount();
	}
	void erase(string word){
		TrieNode *node = root;
		int n = word.size();
		for(int i = 0; i < n; i++){
			if(!node->contains(word[i])){
				return;
			}
			node = node->getNode(word[i]);
			node->decreaseKeyCount();
		}
		node->decreaseEndCount();
	}
};

int main(){
	Trie t;
	t.insert("apple");
	t.insert("apple");
	cout << t.countWordsEqualTo("apple") << endl;
	cout << t.countWordsStartingWith("app") << endl;
	t.erase("apple");
	cout << t.countWordsEqualTo("apple") << endl;
	cout << t.countWordsStartingWith("appl") << endl;
	
}