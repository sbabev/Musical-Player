#include "User.h"

User::User()
{
	this->name = "";
	this->password = "";
	this->myPlaylists.clear();
}

User::User(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
}

std::string User::getName() const
{
	return this->name;
}

std::string User::getPassword() const
{
	return this->password;
}

void User::setName(std::string name)
{
     this->name = name;
}

void User::setPassword(std::string password)
{
	this->password = password;
}

void User::writePlaylistToFile(Playlist playlist)
{
	try {
		std::ofstream g(name + "Playlist.txt", std::ios::app);
		g << playlist.getNameOfPlaylist() << std::endl;
		g.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void User::createFileOfPlaylist(std::string fileName)
{
	try {
		std::ofstream g(fileName + ".txt", std::ios::app);
		g.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

bool User::createNewPlaylist(std::string nameOfPlaylist)
{
	Playlist newPlaylist(nameOfPlaylist);
	if (!isPlaylistExist(newPlaylist)) {
		createFileOfPlaylist(nameOfPlaylist);
		myPlaylists.push_back(newPlaylist);
		writePlaylistToFile(newPlaylist);
		std::cout << "Playlist is created successfully" << std::endl;
		return true;
	}
	return false;
}

void User::readMyPlaylistsFromFile()
{
	try {
		std::string line;
		std::string nameOfPlaylist;
		std::ifstream f(name + "Playlist.txt");
		while (std::getline(f, line)) {
			std::istringstream is(line);
			is >> nameOfPlaylist;
			myPlaylists.push_back(Playlist(nameOfPlaylist));
		}
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void User::printMyPlaylists()
{
	for (Playlist& p : myPlaylists) {
		std::cout << p.getNameOfPlaylist() << std::endl;
	}
}

bool User::isPlaylistExist(Playlist newPlaylist)
{
	for (Playlist &p : myPlaylists) {
		if (p.getNameOfPlaylist() == newPlaylist.getNameOfPlaylist()) {
			return true;
		}
	}
	return false;
}

void User::printSongsInPlaylist(std::string& nameOfPlaylist)
{
	for (Playlist& p : myPlaylists) {
		if (p.getNameOfPlaylist() == nameOfPlaylist) {
			p.printSongsInPlaylist();
		}
	}
}

void User::addSongToPlaylist(std::string nameOfPlaylist, Song& newSong)
{
	for (Playlist& p : myPlaylists) {
		if (p.getNameOfPlaylist() == nameOfPlaylist) {
			addSongToFilePlaylist(nameOfPlaylist, newSong);
			p.addSongToPlaylist(newSong);
			return;
		}
	}
	std::cout << "Playlist not found";
}

void User::addSongToFilePlaylist(std::string nameOfFileOfPlaylist, Song newSong)
{
	try {
		std::ofstream g(nameOfFileOfPlaylist + ".txt", std::ios::app);
		g << newSong;
		g.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void User::readSongsFromPlaylistsFile()
{
	for (Playlist& p : myPlaylists) {
		try {
			std::string line;
			std::string songName;
			std::string songerName;
			std::string ganre;
			std::string album;
			int year;
			float rating;
			std::ifstream f(p.getNameOfPlaylist() + ".txt");

			while (std::getline(f, line)) {
				std::istringstream is(line);
				is >> songName >> songerName >> ganre >> album >> year >> rating;
				p.addSongToPlaylist(Song(songName, songerName, ganre, album, year , rating));
			}
		}
		catch (std::exception const& e) {
			std::cout << "There was error:" << e.what() << std::endl;
		}
	}
}

bool User::isSongExistInPlaylist(std::string nameOfPlaylist, std::string newSong)
{
	for (Playlist &p : myPlaylists) {
		if (p.getNameOfPlaylist() == nameOfPlaylist) {
			if (p.checkSong(newSong)) {
				return true;
			}
		}
	}
	return false;
}

void User::readData()
{
	readMyPlaylistsFromFile();
	readSongsFromPlaylistsFile();
}

void User::print() const
{
	std::cout << getName() << " " << getPassword() << std::endl;
}