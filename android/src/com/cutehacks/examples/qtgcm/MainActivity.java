/*
 * Copyright 2013 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.cutehacks.examples.qtgcm;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;

import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.gcm.GoogleCloudMessaging;

import org.qtproject.qt5.android.bindings.QtActivity;

import java.io.IOException;

/**
 * Main UI for the demo app.
 */
public class MainActivity extends QtActivity {

    private static final int PLAY_SERVICES_RESOLUTION_REQUEST = 9000;
    private static final String TAG = "MainActivity";
    private static Context context = null;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        context = this;
    }

    @Override
    protected void onResume() {
        super.onResume();
        // Check device for Play Services APK.
        //checkPlayServices();
    }

    private boolean checkPlayServices() {
        int resultCode = GooglePlayServicesUtil.isGooglePlayServicesAvailable(this);
        if (resultCode != ConnectionResult.SUCCESS) {
            if (GooglePlayServicesUtil.isUserRecoverableError(resultCode)) {
                GooglePlayServicesUtil.getErrorDialog(resultCode, this,
                        PLAY_SERVICES_RESOLUTION_REQUEST).show();
            } else {
                Log.i(TAG, "This device is not supported.");
                finish();
            }
            return false;
        }
        return true;
    }

    public static void registerGCM(String senderId)
    {
        GoogleCloudMessaging gcm = GoogleCloudMessaging.getInstance(context);
        new RegisterTask(gcm, senderId).execute(null, null, null);
    }

    public static void send()
    {
//        new AsyncTask<Void, Void, String>() {
//            @Override
//            protected String doInBackground(Void... params) {
//                String msg = "";
//                try {
//                    Bundle data = new Bundle();
//                    data.putString("my_message", "Hello World");
//                    data.putString("my_action", "com.google.android.m_gcm.demo.app.ECHO_NOW");
//                    String id = Integer.toString(msgId.incrementAndGet());
//                    m_gcm.send(SENDER_ID + "@m_gcm.googleapis.com", id, data);
//                    msg = "Sent message";
//                } catch (IOException ex) {
//                    msg = "Error :" + ex.getMessage();
//                }
//                return msg;
//            }
//
//            @Override
//            protected void onPostExecute(String msg) {
//                mDisplay.append(msg + "\n");
//            }
//        }.execute(null, null, null);

    }
}
