#pragma once
#include<iostream>
#include<string>

class Song
{
private:
	std::string songName;
	std::string songerName;
	std::string ganre;
	std::string album;
	int year;
	float rating;

public:
	Song(std::string, std::string, std::string, std::string, int , float);

	std::string getSongName()const;
	std::string getSongerName()const;
	std::string getGanre()const;
	float getRating()const;

	void updateRating();
	void print()const;

	friend std::ostream& operator<<(std::ostream& out, Song newSong) {
		out << newSong.songName << "  " << newSong.songerName << "  " << newSong.ganre << "  " << newSong.album << "  " << newSong.year << "  " << newSong.rating << std::endl;
		return out;
	}
};