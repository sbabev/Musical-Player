#pragma once
#include<vector>

#include "Song.h"

class Playlist
{
private:
	std::string name;
	std::vector<Song> playlistSongs;
public:
	Playlist(std::string);

	std::string getNameOfPlaylist()const;

	void addSongToPlaylist(Song);
	void printSongsInPlaylist()const;

	bool checkSong(std::string);
};
