
#ifndef PLAYLIST_H
#define PLAYLIST_H	

#include <iostream>

using namespace std;

class PlaylistNode {

	public:
		PlaylistNode() : ID("none"), songName("none"), artistName("none"), songLength(0), next(0) {};
		PlaylistNode(string id, string song, string artist, int length) : ID(id), songName(song), artistName(artist), songLength(length), next(0) {};
		//~PlaylistNode();
		void InsertAfter(PlaylistNode*);
		void SetNext(PlaylistNode*);
		string GetID() const {
			return this->ID;
		};
		string GetSongName() const {
			return songName;
		};
		string GetArtistName() const {
			return artistName;
		};
		int GetSongLength() const {
			return songLength;
		};
		PlaylistNode* GetNext() const {
			return next;
		};
		void PrintPlaylistNode();

	private:
		string ID;
		string songName;
		string artistName; 
		int songLength;
		PlaylistNode* next;

};




#endif
