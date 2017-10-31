var mikModPlayer;

 
function cxMikmod_Init() {
	
	if (mikModPlayer == undefined) {
		mikModPlayer = new ChiptuneJsPlayer(new ChiptuneJsConfig(-1));
	} else {
		mikModPlayer.stop();
	}

}
function cxMikmod_Play(path) {
	
	mikModPlayer.load(path, function(buffer) {
		mikModPlayer.play(buffer);
	});
	
}
function cxMikmod_Stop() {
	
}
function cxMikmod_Pause() {
	mikModPlayer.togglePause();
}
function cxMikmod_Resume() {
	mikModPlayer.togglePause();
}
function cxMikmod_Update() {
	
}
function cxMikmod_Close() {
	
}