package com.example.project;

import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import java.io.IOException;
import java.util.UUID;

public class MainPage extends AppCompatActivity {

    private ProgressDialog progress;
    public static BluetoothSocket btSocket = null;
    private BluetoothAdapter myBluetooth = null;
    private boolean isBtConnected = false;
    private static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private final String  address = "20:15:10:20:05:64";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_page);

        //This Button is used to connect to the paired car with the bluetooth
        Button connect = findViewById(R.id.connect);
        connect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //An attempt to connect to the car is executed
                new MainPage.ConnectBT().execute();
            }
        });

        //This Button activates the cruise control functionality of the car (obstacle avoidance)
        Button cruise = findViewById(R.id.CruiseControlBtn);
        cruise.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    //Send the string C to the car (C stands for Cruise control)
                    btSocket.getOutputStream().write("C".getBytes());
                } catch (Exception e) {
                    msg("Error");
                }
            }
        });
    }

    public void ManualControl(View view){
        Intent startNewActivity = new Intent(this, ManualControls.class);
        startActivity(startNewActivity);
    }

    public void Parking(View view){
        Intent startNewActivity = new Intent(this, Parking.class);
        startActivity(startNewActivity);
    }

    public void Bluetooth(View view){
        Intent startNewActivity = new Intent(this, Bluetooth.class);
        startActivity(startNewActivity);
    }

    //Method to write Toasts faster
    private void msg(String s)
    {
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
    }

    //This class is used to connect to the paired car
    private class ConnectBT extends AsyncTask<Void, Void, Void>  // UI thread
    {
        private boolean ConnectSuccess = true; //if it's here, it's almost connected

        @Override
        protected void onPreExecute()
        {
            //show a progress dialog
            progress = ProgressDialog.show(MainPage.this, "Connecting...", "Please wait!!!");
        }

        @Override
        //while the progress dialog is shown, the connection is done in background
        protected Void doInBackground(Void... devices)
        {
            try
            {
                if (btSocket == null || !isBtConnected)
                {
                    //get the mobile bluetooth device
                    myBluetooth = BluetoothAdapter.getDefaultAdapter();

                    //connects to the device's address and checks if it's available
                    BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);

                    //create a RFCOMM (SPP) connection
                    btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);

                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();

                    //start connection
                    btSocket.connect();
                }
            }
            catch (IOException e)
            {
                ConnectSuccess = false;
            }
            return null;
        }

        @Override
        //after the doInBackground, it checks if everything went fine
        protected void onPostExecute(Void result)
        {
            super.onPostExecute(result);

            if (!ConnectSuccess)
            {
                msg("Connection Failed. Is it a SPP Bluetooth? Try again.");
                finish();
            }
            else
            {
                msg("Connected.");
                isBtConnected = true;
            }
            progress.dismiss();
        }
    }
}

