#pragma once
#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include<sstream>

#include "User.h"
#include "Server.h"
#include "HnadleInput.h"
#include "Song.h"
#include "Playlist.h"


int main() {

	HandleInput input;
	input.play();
	
	return 0;
}
