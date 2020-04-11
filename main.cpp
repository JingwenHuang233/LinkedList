#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void PrintMenu(string);

int main() {

	string title;

	cout << "Enter playlist's title:" << endl;
	getline(cin, title);
	cout << endl;
	PrintMenu(title);
	
	
	return 0;
}

void PrintMenu(string title) {
	char c = ' ';
	string ID;
	string songName;
	string artistName;
	int songLength = 0;
	int num = 0;
	int songPosition = 0;
	int newPosition = 0;
	int totalTime =0;
	//PlaylistNode* newSong = 0;
	PlaylistNode* curr = 0;
	PlaylistNode* songNode = 0;
	PlaylistNode* prev = 0;
	PlaylistNode* insertPosNode = 0;
	PlaylistNode* head = 0;
	PlaylistNode* tail = 0;
	PlaylistNode* currPrintNode = 0;
	while (c != 'q') {
		c = ' ';
		cout << title << " PLAYLIST MENU" << endl;
		cout << "a - Add song" << endl;
		cout << "d - Remove song" << endl;
		cout << "c - Change position of song" << endl;
		cout << "s - Output songs by specific artist" << endl;
		cout << "t - Output total time of playlist (in seconds)" << endl;
		cout << "o - Output full playlist" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option:" << endl;
		cin >> c;
		while (c != 'a' && c != 'd' && c != 'c' &&
			c != 's' && c != 't' && c != 'o' && c != 'q') {
			cout << "Choose an option:" << endl;
			cin >> c;
		}

		if (c == 'a') {
			cout << "ADD SONG" << endl << "Enter song's unique ID:" << endl;
			cin >> ID;
			cout << "Enter song's name:" << endl;
			cin.ignore();
			getline(cin,songName);
			cout << "Enter artist's name:" << endl;
			getline(cin,artistName);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> songLength;
			cout << endl;
			++num;
			
			PlaylistNode* newSong= new PlaylistNode(ID, songName, artistName, songLength);
			if (head == nullptr && tail == nullptr) {
				head = newSong;
				tail = newSong;
			}
			else {
				tail->SetNext(newSong);
				tail = newSong;
			}
		}
		else if (c == 'd') {
			string keyID;
			cout << "REMOVE SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin >> keyID;
			curr = head;

			if (keyID == head->GetID()) { 
				if (num = 1) {
					delete head;
					head = 0;
					tail = 0;
				}
				else {
					head = head->GetNext();
					delete curr;
					
					
				}
				cout << '"' << prev->GetNext()->GetSongName() << '"' << " removed." << endl<<endl;
			}
			else {
				prev = curr;
				curr = curr->GetNext();
				for (unsigned int i = 1; i < num; ++i) {
					if (keyID == curr->GetID()) {
						curr = curr->GetNext();
						cout << '"' << prev->GetNext()->GetSongName() << '"' << " removed." << endl<<endl;
						delete prev->GetNext();
						prev->SetNext(curr);
						
					}
				}
			}
			--num;
			
		}
		else if (c == 'c') {
			cout << "CHANGE POSITION OF SONG" << endl << "Enter song's current position:" << endl;
			cin >> songPosition;
			cout << "Enter new position for song:" << endl;
			cin >> newPosition;
			/*prev = head; 
			for (unsigned int i = 0; i < songPosition; ++i) {
				prev = prev->GetNext();
			}*/
			songNode = head;
			for (int i = 0; i < songPosition-1; ++i) {
				songNode = songNode->GetNext();
			}
			insertPosNode = head;
			for (int i = 0; i < newPosition-1; ++i) {
				insertPosNode = insertPosNode->GetNext();
			}
			cout << '"' << songNode->GetSongName() << '"' << " moved to position " << newPosition << endl<<endl;
			if (head == nullptr || head == tail) {
				
			}
			else if (songPosition == 1) { //head
				head = songNode->GetNext();
				//songNode->SetNext(insertPosNode->GetNext());
				insertPosNode->InsertAfter(songNode);
			}
			else if (songPosition == num) { //tail
				prev = head;
				for (unsigned int i = 0; i < songPosition-2; ++i) {
					prev = prev->GetNext();
				}
				tail = prev;
				prev = head;
				for (unsigned int i = 0; i < newPosition - 2; ++i) {
					prev = prev->GetNext();
				}
				prev->InsertAfter(songNode);
			}
			else if (newPosition == 1) { // move to head;
				prev = head;
				for (unsigned int i = 0; i < songPosition - 2; ++i) {
					prev = prev->GetNext();
				}
				prev->SetNext(songNode->GetNext());
				songNode->SetNext(head);
				head = songNode;
			}
			else if(newPosition == num){ // move to tail
				prev = head;
				for (unsigned int i = 0; i < songPosition - 2; ++i) {
					prev = prev->GetNext();
				}
				prev->SetNext(songNode->GetNext());
				insertPosNode->InsertAfter(songNode);

			}
			else if(songPosition<newPosition){ //move down
				prev = head;
				for (unsigned int i = 0; i < songPosition - 2; ++i) {
					prev = prev->GetNext();
				}
				prev->SetNext(songNode->GetNext());
				//songNode->SetNext(insertPosNode->GetNext());
				insertPosNode->InsertAfter(songNode);
			}
			else if (newPosition < songPosition) { //move up
				prev = head;
				for (unsigned int i = 0; i < songPosition - 2; ++i) {
					prev = prev->GetNext();
				}
				prev->SetNext(songNode->GetNext());
				prev = head;
				for (unsigned int i = 0; i < newPosition - 2; ++i) {
					prev = prev->GetNext();
				}
				prev->InsertAfter(songNode);
			}
		}
		else if (c == 's') {
			string keyArtist;
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
			cout << "Enter artist's name:" << endl<<endl;
			cin.ignore();
			getline(cin, keyArtist);
			curr = head;
			for (unsigned int i = 0; i < num; ++i) {
				if (curr->GetArtistName() == keyArtist) {
					cout<< i + 1 << "."<<endl;
					curr->PrintPlaylistNode();
				}
				curr = curr->GetNext();
			}
		}
		else if (c == 't') {
			curr = head;
			for (unsigned int i = 0; i < num; ++i) {
				totalTime = totalTime + curr->GetSongLength();
				curr = curr->GetNext();
			}
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
			cout << "Total time: " << totalTime << " seconds" << endl<<endl;
		}
		else if (c == 'o') {
			cout << title << " - OUTPUT FULL PLAYLIST" << endl;
			if (num == 0) {
				cout << "Playlist is empty" << endl<<endl;
			}
			else {
				curr = head;
				for (unsigned int i = 0; i < num; ++i) {
					cout << i + 1 << "." << endl;
					curr->PrintPlaylistNode();
					curr = curr->GetNext();
				}
				
			}
		}
		
	}

	return;
}
