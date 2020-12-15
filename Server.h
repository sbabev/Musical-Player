#pragma once
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<stdexcept>
#include<sstream>

#include "User.h"
#include "Song.h" 

class Server
{
private:
	std::vector<User> users;
	std::vector<Song> songs;
	void writeUserToFile(User newUser);

public:
	Server();

	void readClientsFromFile();
	void readSongsFromFile();

	bool registration(User);
	bool login(User);

	void writeSongsToFile(std::string, std::string, std::string, std::string, int , float);
	void deleteSongsInFile();
	void writeVectorOfSongsToFile();
	void ReadAndDeleteSongsFromFile();

	bool IsThisUserFree(User newUser);
	bool IsThisSongFree(Song newSong);
	Song IsSongExist(std::string);

	void updateRatingOfSong(std::string);
	void sortSongsByRating();
	void sortSongsByGanre(std::string);
	
	void printUsers()const;
	void printSongs()const;
	void printSongsInVector(std::vector<Song>);
	
};
