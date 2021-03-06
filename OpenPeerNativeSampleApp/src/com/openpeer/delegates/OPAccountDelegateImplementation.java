/*
 
 Copyright (c) 2014, SMB Phone Inc.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

package com.openpeer.delegates;

import java.util.List;

import android.util.Log;

import com.openpeer.javaapi.AccountStates;
import com.openpeer.javaapi.OPAccount;
import com.openpeer.javaapi.OPAccountDelegate;
import com.openpeer.javaapi.OPIdentity;
import com.openpeer.openpeernativesampleapp.LoginManager;

public class OPAccountDelegateImplementation extends OPAccountDelegate {

	@Override
	public void onAccountStateChanged(OPAccount account, AccountStates state) {
		// TODO Auto-generated method stub
		switch (state){
		case AccountState_WaitingForAssociationToIdentity:
			break;
		case AccountState_WaitingForBrowserWindowToBeLoaded:
			LoginManager.startAccountLogin();
			break;
		case AccountState_WaitingForBrowserWindowToBeMadeVisible:
			LoginManager.mAccount.notifyBrowserWindowVisible();
			break;
		case AccountState_WaitingForBrowserWindowToClose:
			LoginManager.mAccount.notifyBrowserWindowClosed();
			break;
		case AccountState_Ready:
			Log.w("JNI", "READY !!!!!!!!!!!!");
			List<OPIdentity> identityList = account.getAssociatedIdentities();
			Log.w("JNI", identityList.toString());
			break;
			//LoginManager.loadOuterFrame();
		}
			
	}

	@Override
	public void onAccountAssociatedIdentitiesChanged(OPAccount account) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onAccountPendingMessageForInnerBrowserWindowFrame(
			OPAccount account) {
		// TODO Auto-generated method stub
		LoginManager.pendingMessageForNamespaceGrantInnerFrame();
	}

}
