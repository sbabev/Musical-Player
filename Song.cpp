#include "Song.h"

Song::Song(std::string songName, std::string songerName, std::string ganre, std::string album, int year , float rating)
{
	this->songName = songName;
	this->songerName = songerName;
	this->ganre = ganre;
	this->album = album;
	this->year = year;
	this->rating = rating;

}

std::string Song::getSongName() const
{
	return songName;
}

std::string Song::getSongerName() const
{
	return songerName;
}

std::string Song::getGanre() const
{
	return ganre;
}

float Song::getRating()const {
	return rating;
}

void Song::updateRating()
{
	rating++;
}

void Song::print() const
{
	std::cout << songName << "  " << songerName << "  " << ganre << "  " << album << "  " << year << "  " << rating << std::endl;
}
