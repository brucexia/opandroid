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

#include "com_openpeer_javaapi_OPLogger.h"
#include "openpeer/core/ILogger.h"

#include "globals.h"

using namespace openpeer::core;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    installStdOutLogger
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_installStdOutLogger
  (JNIEnv *, jclass, jboolean colorizeOutput)
{
	ILogger::installStdOutLogger(colorizeOutput);
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    installFileLogger
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_installFileLogger
  (JNIEnv *env, jclass, jstring fileName, jboolean colorizeOutput)
{
	const char *fileNameStr;
	fileNameStr = env->GetStringUTFChars(fileName, NULL);
	if (fileNameStr == NULL) {
		return;
	}

	ILogger::installFileLogger(fileNameStr, colorizeOutput);
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    installTelnetLogger
 * Signature: (IJZ)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_installTelnetLogger
(JNIEnv *, jclass, jint port, jlong maxSecondsWaitForSocketToBeAvailable, jboolean colorizeOutput)
{
	ILogger::setLogLevel(ILogger::Trace);
	ILogger::installTelnetLogger(port, maxSecondsWaitForSocketToBeAvailable, colorizeOutput);
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    installOutgoingTelnetLogger
 * Signature: (Ljava/lang/String;ZLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_installOutgoingTelnetLogger
  (JNIEnv *env, jclass, jstring serverToConnect, jboolean colorizeOutput, jstring stringToSendUponConnection)
{
	const char *serverToConnectStr;
	serverToConnectStr = env->GetStringUTFChars(serverToConnect, NULL);
	if (serverToConnectStr == NULL) {
		return;
	}

	const char *stringToSendUponConnectionStr;
	stringToSendUponConnectionStr = env->GetStringUTFChars(stringToSendUponConnection, NULL);
	if (stringToSendUponConnectionStr == NULL) {
		return;
	}

	ILogger::installOutgoingTelnetLogger(serverToConnectStr, colorizeOutput, stringToSendUponConnectionStr);
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    installDebuggerLogger
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_installDebuggerLogger
  (JNIEnv *, jclass)
{
	ILogger::installDebuggerLogger();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    installCustomLogger
 * Signature: (Lcom/openpeer/javaapi/OPLoggerDelegate;)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_installCustomLogger
  (JNIEnv *, jclass, jobject)
{
	ILogger::installCustomLogger(globalEventManager);
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    uninstallStdOutLogger
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_uninstallStdOutLogger
  (JNIEnv *, jclass)
{
	ILogger::uninstallStdOutLogger();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    uninstallFileLogger
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_uninstallFileLogger
  (JNIEnv *, jclass)
{
	ILogger::uninstallFileLogger();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    uninstallTelnetLogger
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_uninstallTelnetLogger
  (JNIEnv *, jclass)
{
	ILogger::uninstallTelnetLogger();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    uninstallOutgoingTelnetLogger
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_uninstallOutgoingTelnetLogger
  (JNIEnv *, jclass)
{
	ILogger::uninstallOutgoingTelnetLogger();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    uninstallDebuggerLogger
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_uninstallDebuggerLogger
  (JNIEnv *, jclass)
{
	ILogger::uninstallDebuggerLogger();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    isTelnetLoggerListening
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_openpeer_javaapi_OPLogger_isTelnetLoggerListening
  (JNIEnv *, jclass)
{
	return ILogger::isTelnetLoggerListening();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    isTelnetLoggerConnected
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_openpeer_javaapi_OPLogger_isTelnetLoggerConnected
  (JNIEnv *, jclass)
{
	return ILogger::isTelnetLoggerConnected();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    isOutgoingTelnetLoggerConnected
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_openpeer_javaapi_OPLogger_isOutgoingTelnetLoggerConnected
  (JNIEnv *, jclass)
{
	return ILogger::isOutgoingTelnetLoggerConnected();
}

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    getApplicationSubsystemID
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_openpeer_javaapi_OPLogger_getApplicationSubsystemID
  (JNIEnv *, jclass);

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    getLogLevel
 * Signature: (I)Lcom/openpeer/javaapi/OPLogLevel;
 */
JNIEXPORT jobject JNICALL Java_com_openpeer_javaapi_OPLogger_getLogLevel
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    setLogLevel
 * Signature: (Lcom/openpeer/javaapi/OPLogLevel;)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_setLogLevel__Lcom_openpeer_javaapi_OPLogLevel_2
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    setLogLevel
 * Signature: (ILcom/openpeer/javaapi/OPLogLevel;)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_setLogLevel__ILcom_openpeer_javaapi_OPLogLevel_2
  (JNIEnv *, jclass, jint, jobject);

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    setLogLevel
 * Signature: (Ljava/lang/String;Lcom/openpeer/javaapi/OPLogLevel;)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_setLogLevel__Ljava_lang_String_2Lcom_openpeer_javaapi_OPLogLevel_2
  (JNIEnv *, jclass, jstring, jobject);

/*
 * Class:     com_openpeer_javaapi_OPLogger
 * Method:    log
 * Signature: (ILcom/openpeer/javaapi/OPLogSeverity;Lcom/openpeer/javaapi/OPLogLevel;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_com_openpeer_javaapi_OPLogger_log
  (JNIEnv *, jclass, jint, jobject, jobject, jstring, jstring, jstring, jlong);

#ifdef __cplusplus
}
#endif
