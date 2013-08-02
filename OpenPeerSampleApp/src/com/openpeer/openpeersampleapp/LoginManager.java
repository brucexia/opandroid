package com.openpeer.openpeersampleapp;

import android.util.Log;

import com.openpeer.javaapi.OPAccount;
import com.openpeer.javaapi.OPStack;
import com.openpeer.javaapi.OPStackMessageQueue;

public class LoginManager {

	public static void LoginWithFacebook (){
		//TODO: Add delegate when implement mechanism to post events to the android GUI thread
		//stackMessageQueue = OPStackMessageQueue.singleton(); 
		stackMessageQueue = new OPStackMessageQueue();
		stackMessageQueue.interceptProcessing(null);
		
		//TODO: After interception is done, we can call setup
		stack = new OPStack();
		stack.setup(null, null, null, null, null, null, null, null, null, null);
		
		//TODO: Now we can start login procedure
		setAccount(OPAccount.login(null, null, null, null, null, null, null, null, null));//delegate, conversationThreadDelegate, callDelegate, namespaceGrantOuterFrameURLUponReload, namespaceGrantServiceDomain, grantID, grantSecret, lockboxServiceDomain, forceCreateNewLockboxAccount)
	}
	
	
	
	public static OPAccount getAccount() {
		return account;
	}
	public static void setAccount(OPAccount account) {
		LoginManager.account = account;
	}

	private static OPStack stack;
	private static OPStackMessageQueue stackMessageQueue;
	private static OPAccount account;
}
