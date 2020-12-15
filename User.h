#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Playlist.h"

class User
{
private:
	std::string name;
	std::string password;
	std::vector<Playlist> myPlaylists;
public:
	User();
	User(std::string, std::string);

	std::string getName()const;
	std::string getPassword()const;

	void setName(std::string);
	void setPassword(std::string);

    void readMyPlaylistsFromFile();
	void writePlaylistToFile(Playlist);
	void createFileOfPlaylist(std::string);
	bool createNewPlaylist(std::string);
	void printMyPlaylists();
	bool isPlaylistExist(Playlist);

	void printSongsInPlaylist(std::string&);
	void addSongToPlaylist(std::string, Song&);
	void addSongToFilePlaylist(std::string, Song);
	void readSongsFromPlaylistsFile();
	bool isSongExistInPlaylist(std::string, std::string);

	void readData();
    void print()const;

	friend std::ostream& operator<<(std::ostream& out, User newUser) {
		out << newUser.getName() << "  " << newUser.getPassword() << std::endl;
		return out;
	}
	
};
