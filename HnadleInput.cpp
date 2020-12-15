#include "HnadleInput.h"

void  HandleInput::AuthenticatedMenu()const 
{
	std::cout << "*******************************" << std::endl;
	std::cout << "1.Registration                *" << std::endl;
	std::cout << "2.Login                       *" << std::endl;
	std::cout << "*******************************" << std::endl;
}

void HandleInput::MusicPlayerMenu()const {
	std::cout << "*********** WELCOME TO MUSIC PLAYER ***********" << std::endl;
	std::cout << "1.See all songs                               *" << std::endl;
	std::cout << "2.See songs by rating                         *" << std::endl;
	std::cout << "3.See all songs with this ganre               *" << std::endl;
	std::cout << "4.Create new playlist                         *" << std::endl;
	std::cout << "5.See my playlists                            *" << std::endl;
	std::cout << "6.Add new song to playlist                    *" << std::endl;
	std::cout << "7.See my songs in playlist                    *" << std::endl;
	std::cout << "8.Play song                                   *" << std::endl;
	std::cout << "9.Exit                                        *" << std::endl;
	std::cout << "***********************************************" << std::endl;
}

std::wstring HandleInput::SongToMelody(const std::string& songName)
{
	int len;
	int slength = (int)songName.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, songName.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, songName.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void HandleInput::registerNewUser()
{
	do {
		std::string name;
		std::cout << "Enter your name here :";
		std::cin >> name;
		std::string password;
		std::cout << std::endl << "Enter your password here :";
		std::cin >> password;
		newUser.setName(name);
		newUser.setPassword(password);
		server.registration(newUser);
	} while (server.registration(newUser) == true);
}

void HandleInput::loginUser()
{
	do {
		std::string name;
		std::cout << "Enter your name here :";
		std::cin >> name;
		std::string password;
		std::cout << std::endl << "Enter your password here :";
		std::cin >> password;
		newUser.setName(name);
		newUser.setPassword(password);
	} while (server.login(newUser) == false);
}

void HandleInput::printSongsByGanre()
{
	std::string ganre;
	std::cout << "Input your genre here : ";
	std::cin >> ganre;
	server.sortSongsByGanre(ganre);
}

void HandleInput::createNewPlaylistForUser()
{
	std::string newPlaylist;
	std::cout << "Name of the new playlist : ";
	std::cin >> newPlaylist;
	newUser.createNewPlaylist(newPlaylist);
}

void HandleInput::addSongToPlaylistForUser()
{
	std::string nameOfPlaylist;
	std::string nameOfSong;
	std::cout << "Name of the new song : ";
	std::cin >> nameOfSong;
	std::cout << std::endl;
	std::cout << "Name of the  playlist : ";
	std::cin >> nameOfPlaylist;
	Song s = server.IsSongExist(nameOfSong);
	newUser.addSongToPlaylist(nameOfPlaylist, s);
}

void HandleInput::seeSongsInUserPlaylist()
{
	std::string nameOfPlaylist;
	std::cout << "Name of the  playlist : ";
	std::cin >> nameOfPlaylist;
	if (newUser.isPlaylistExist(nameOfPlaylist)) {
		newUser.printSongsInPlaylist(nameOfPlaylist);
	}
	else {
		std::cout << "This playlist does not exist" << std::endl;
	}
}

void HandleInput::playSong()
{
	std::string nameOfPlaylist;
	std::cout << "Name of the playlist" << std::endl;
	std::cin >> nameOfPlaylist;
	std::cout << std::endl;
	std::string nameOfSong;
	std::cout << "Name of song" << std::endl;
	std::cin >> nameOfSong;
	if (newUser.isSongExistInPlaylist(nameOfPlaylist, nameOfSong)) {
		server.updateRatingOfSong(nameOfSong);
		std::wstring stemp = SongToMelody(nameOfSong);
		LPCWSTR result = stemp.c_str();
		PlaySound((result), NULL, SND_FILENAME);
	}
}

void HandleInput::play()
{
	AuthenticatedMenu();
	server.readClientsFromFile();
	unsigned int authenticatedChoice;
	bool isValidated = false;
		do {
			std::cout << "Input your choice here : ";
			std::cin >> authenticatedChoice;
			if (authenticatedChoice == 1 || authenticatedChoice == 2) {
				isValidated = true;
			}
			else {
				std::cout << "Wrong input , try again" << std::endl;
			}
		} while (isValidated != true);
	switch (authenticatedChoice) {
	case 1: {
		registerNewUser();
		break;
	}
	case 2: {
		loginUser();
		break;
	}
  }
		  system("cls"); 
		  MusicPlayerMenu();
		  server.ReadAndDeleteSongsFromFile();
		  newUser.readData();
		  unsigned int functionPlayerChoice;
		  do { 
			 std::cout << "Input your choose here :";
			 std::cin >> functionPlayerChoice;
			 
			  switch (functionPlayerChoice) {
			  case 1: {
				  server.printSongs();
				  break;
			  } 
			  case 2: {
				server.sortSongsByRating();
			break;
			 }
			  case 3: {
				  printSongsByGanre();
				  break;
			  }
			  case 4: {
				  createNewPlaylistForUser();
				  break;
			  }
			  case 5: {
				  newUser.printMyPlaylists();
				  break;
			  }
			  case 6: {
				 addSongToPlaylistForUser();
				 break;
			  }
			  case 7: {
				seeSongsInUserPlaylist();
				break;
			  }
			  case 8: {
				 playSong();
				 break;
			  }
			  } 
		  }while (functionPlayerChoice != 9);		
		  server.writeVectorOfSongsToFile();
}