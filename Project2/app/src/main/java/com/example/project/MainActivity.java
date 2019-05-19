package com.example.project;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void CruiseControl(View view){
        Intent startNewActivity = new Intent(this, Main3Activity.class);
        startActivity(startNewActivity);
    }

    public void ManualControl(View view){
        Intent startNewActivity = new Intent(this, Main2Activity.class);
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

}

