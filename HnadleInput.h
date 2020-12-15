#pragma once
#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include<sstream>

#include "Server.h" 

class HandleInput
{
private:
	User newUser;
	Server server;

	void  AuthenticatedMenu()const;
	void  MusicPlayerMenu()const;
	std::wstring SongToMelody(const std::string&);

	void registerNewUser();
	void loginUser();

	void printSongsByGanre();
	void createNewPlaylistForUser();
	void addSongToPlaylistForUser();
	void seeSongsInUserPlaylist();
	void playSong();

public:
	void play();
};

