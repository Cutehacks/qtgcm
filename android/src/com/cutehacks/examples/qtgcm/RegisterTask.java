package com.cutehacks.examples.qtgcm;

import android.os.AsyncTask;
import android.util.Log;

import com.google.android.gms.gcm.GoogleCloudMessaging;

import java.io.IOException;

public class RegisterTask extends AsyncTask<Void, Void, String>
{
    private static final String TAG = RegisterTask.class.getSimpleName();

    private final GoogleCloudMessaging m_gcm;
    private final String m_senderId;
    public RegisterTask(GoogleCloudMessaging gcm, String senderId)
    {
        m_gcm = gcm;
        m_senderId = senderId;
    }

    public RegisterTask() {
        // Default constructor for JNI
        this(null, null);
    }

    @Override
    protected String doInBackground(Void... voids)
    {
        try {
            String regid = m_gcm.register(m_senderId);
            return regid;
        } catch (IOException ex) {
            handleRegisterError(ex.getMessage());
            return "";
        }
    }

    @Override
    protected void onPostExecute(String result) {
        handleRegisterId(result);
    }

    private static native void handleRegisterId(String registrationId);
    private static native void handleRegisterError(String error);
}
