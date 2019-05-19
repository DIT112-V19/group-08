package com.example.project;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;

import java.io.OutputStream;
import java.util.UUID;

public class Main2Activity extends AppCompatActivity {
    
    private final String DEVICE_ADDRESS= "20:15:10:20:05:64"; //MAC Address of the bluetooth module
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");

    private BluetoothDevice device;
    private BluetoothSocket socket;
    private OutputStream outputStream;

    Button forward, left, right, reverse;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        forward= (Button) findViewById(R.id.forward);
        left= (Button) findViewById(R.id.left);
        right= (Button) findViewById(R.id.right);
        reverse= (Button) findViewById(R.id.backwards);
    }
}
