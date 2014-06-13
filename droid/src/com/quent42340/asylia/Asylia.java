package com.quent42340.asylia;

import android.content.res.AssetManager;
import android.os.Bundle;
import org.libsdl.app.SDLActivity; 

public class Asylia extends SDLActivity {
	private static native void load(AssetManager mgr);
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		AssetManager mgr = getResources().getAssets();
		load(mgr);
	}
}

