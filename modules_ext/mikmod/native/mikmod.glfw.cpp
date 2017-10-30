#include <mikmod.h>

#if defined(_WIN32)
#define MikMod_Sleep(ns) Sleep(ns / 1000)
#else
#include <unistd.h>  /* for usleep() */
#define MikMod_Sleep(ns) usleep(ns)
#endif

MODULE *mikModModule = NULL;

void cxMikmod_Init() {
 
	/* initialize MikMod threads */
	MikMod_InitThreads ();

	/* register all the drivers */
	MikMod_RegisterAllDrivers();

	/* register all the module loaders */
	MikMod_RegisterAllLoaders();

	/* init the library */
	md_mode |= DMODE_SURROUND | DMODE_INTERP | DMODE_FLOAT | DMODE_STEREO | DMODE_16BITS;
	if (MikMod_Init("")) {
		fprintf(stderr, "Could not initialize sound, reason: %s\n",
				MikMod_strerror(MikMod_errno));
	}
	
}

void cxMikmod_Stop() {
	if (mikModModule) {
		Player_Free(mikModModule);
		mikModModule = NULL;
	}
	Player_Stop();
}

void cxMikmod_Play(String path) {
	
		cxMikmod_Stop();
	
		char file[path.Length()];
		size_t ret = std::wcstombs(file, path.Data(), path.Length());
		
		if (ret==path.Length()) file[path.Length()]='\0';
		
		mikModModule = Player_Load( file , 64, 0);

		if (mikModModule) {
			printf("Playing %s (%d chn)\n", mikModModule->songname, (int) mikModModule->numchn);
			Player_Start(mikModModule);

		} else {
			fprintf(stderr, "Could not load module \"%s\", reason: %s\n",
					file, MikMod_strerror(MikMod_errno));
			std::terminate();
		}
	
}


void cxMikmod_Pause() {
	Player_TogglePause();
}
void cxMikmod_Resume() {
	Player_TogglePause();
}

void cxMikmod_Update() {
	MikMod_Update();
}

void cxMikmod_Close() {
	cxMikmod_Stop();
	Player_Stop();
}
