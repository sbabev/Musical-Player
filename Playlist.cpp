#include "Playlist.h"

Playlist::Playlist(std::string newName)
{
	this->name = newName;
	this->playlistSongs.clear();
}

void Playlist::addSongToPlaylist(Song newSong)
{
	playlistSongs.push_back(newSong);
}

std::string Playlist::getNameOfPlaylist() const
{
	return this->name;
}

void Playlist::printSongsInPlaylist() const
{
	for (Song s : playlistSongs) {
		s.print();
	}
}

bool Playlist::checkSong(std::string newSong)
{
	for (Song& s : playlistSongs) {
		if (s.getSongName() == newSong) {
			return true;
		}
	}
	std::cout << "This song does not exist" << std::endl;
	return false;
}