#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std;

/*PlaylistNode::~PlaylistNode() {
	delete this;
}*/

void PlaylistNode::InsertAfter(PlaylistNode* newNode) {
	PlaylistNode* swap = nullptr;

	swap = this->next;    
	this->next = newNode;   
	newNode->next = swap;

	return;
}

void PlaylistNode::SetNext(PlaylistNode* nextNode) {

	this->next = nextNode;

	return;
}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << this->ID << endl;
	cout << "Song Name: " << this->songName << endl;
	cout << "Artist Name: " << this->artistName << endl;
	cout << "Song Length (in seconds): " << this->songLength << endl << endl;

	return;
}
