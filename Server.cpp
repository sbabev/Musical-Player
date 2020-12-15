#include "Server.h"

Server::Server()
{
	users.clear();
	songs.clear();
}

bool Server::IsThisUserFree(User newUser)
{
	for (User u : users) {
		if (u.getName() == newUser.getName() && u.getPassword() == newUser.getPassword()) {
			return false;
		}
	}
	return true;
}

bool Server::IsThisSongFree(Song newSong)
{
	for (Song s : songs) {
		if (s.getSongName() == newSong.getSongName() && s.getSongerName() == newSong.getSongerName()) {
			return false;
		}
	}
	return true;
}

Song Server::IsSongExist(std::string nameOfSong)
{
	for (Song& s : songs) {
		if (s.getSongName() == nameOfSong) {
			return s;
		}
	}
	std::cout << "This song does not exist" << std::endl;
}

void Server::updateRatingOfSong(std::string nameOfSong)
{
	for (int i = 0; i < songs.size(); i ++) {
		if (songs[i].getSongName() == nameOfSong) {
			songs[i].updateRating();
			break;
		}
	}
}

void Server::sortSongsByRating()
{
	std::vector<Song> copySongs;
	copySongs.insert(copySongs.begin(), songs.begin(), songs.end());

	std::sort(copySongs.begin(), copySongs.end(), [](const Song& lhs, const Song& rhs) {
		return lhs.getRating() > rhs.getRating();
		});
	printSongsInVector(copySongs);
}

void Server::sortSongsByGanre(std::string ganre)
{
	std::vector<Song> songsByGanre;
	for (int i = 0; i < songs.size(); i++) {
		if (songs[i].getGanre() == ganre) {
			songsByGanre.push_back(songs[i]);
		}
	}
	printSongsInVector(songsByGanre);
}

void Server::writeUserToFile(User newUser)
{
	try {
		std::ofstream g("Users.txt", std::ios::app);
		g << newUser;
		g.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void Server::writeSongsToFile(std::string songName, std::string songerName, std::string ganre, std::string album, int year , float rating)
{
	Song newSong(songName, songerName, ganre, album, year , rating);
	try {
		std::ofstream g("Songs.txt", std::ios::app);
		g << newSong;
		g.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void Server::deleteSongsInFile()
{
	try {
	std::fstream ofs;
	ofs.open("Songs.txt", std::ios::out | std::ios::trunc);
	ofs.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void Server::writeVectorOfSongsToFile()
{
	try {
		std::ofstream g("Songs.txt", std::ios::app);
		for (int i = 0; i < songs.size(); i++) {
			g << songs[i];
		}
		g.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void Server::ReadAndDeleteSongsFromFile()
{
	readSongsFromFile();
	deleteSongsInFile();
}

void  Server::readClientsFromFile()
{
	try {
		std::string line;
		std::string newName;
		std::string newPassword;
		std::ifstream f("Users.txt");
		while (std::getline(f, line)) {
			std::istringstream is(line);
			is >> newName >> newPassword;
			users.push_back(User(newName, newPassword));
		}
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

void Server::readSongsFromFile()
{
	try {
		std::string line;
		std::string songName;
		std::string songerName;
		std::string ganre;
		std::string album;
		int year;
		float rating;
		std::ifstream f("Songs.txt");
		while (std::getline(f, line)) {
			std::istringstream is(line);
			is >> songName >> songerName >> ganre >> album >> year >> rating;
			songs.push_back(Song(songName, songerName, ganre, album, year , rating));
		}
	}
	catch (std::exception const& e) {
		std::cout << "There was error:" << e.what() << std::endl;
	}
}

bool Server::registration(User newUser)
{
	if (IsThisUserFree(newUser)) {
		users.push_back(newUser);
		writeUserToFile(newUser);
		return true;
	}
	else {
		std::cout << "This user already exist" << std::endl;
		return false;
	}
}

bool Server::login(User newUser)
{
	if (!IsThisUserFree(newUser)) {
		return true;
	}
	else {
		std::cout << "Not registered client";
		return false;
	}
}

void Server::printUsers() const
{
	for (User u : users) {
		u.print();
	}
}

void Server::printSongs() const
{
	for (Song s : songs) {
		s.print();
	}
}

void Server::printSongsInVector(std::vector<Song> newSongsVector)
{
	if (!newSongsVector.empty()) {
		for (Song s : newSongsVector) {
		s.print();
	}
	}
	else {
		std::cout << "There are no songs with your information" << std::endl;
	}
}




