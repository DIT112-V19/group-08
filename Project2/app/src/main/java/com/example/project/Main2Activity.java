package com.example.project;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

public class Main2Activity extends AppCompatActivity {
    
    private final String DEVICE_ADDRESS= "20:15:10:20:05:64"; //MAC Address of the bluetooth module
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");

    private BluetoothDevice device;
    private BluetoothSocket socket;
    private OutputStream outputStream;

    Button forward, left, right, reverse, bluetooth_connect_btn;

    String command;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        forward = (Button) findViewById(R.id.forward);
        left = (Button) findViewById(R.id.left);
        right = (Button) findViewById(R.id.right);
        reverse = (Button) findViewById(R.id.backwards);
        bluetooth_connect_btn = (Button) findViewById(R.id.bluetooth_connect_btn);

        forward.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    command = "F";
                    try {
                        outputStream.write(command.toString().getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        outputStream.write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return false;
            }
        });
        reverse.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    command = "B";
                    try {
                        outputStream.write(command.toString().getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        outputStream.write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
                return false;
            }
        });
        left.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    command = "L";
                    try {
                        outputStream.write(command.toString().getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        outputStream.write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return false;
            }
        });
        right.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    command = "R";
                    try {
                        outputStream.write(command.toString().getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        outputStream.write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return false;
            }
        });
        bluetooth_connect_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (BTinitialize()) {
                    BTconnect();
                }

            }
        });
    }
        public boolean BTinitialize()
        {
            boolean found = false;
            BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
            if(bluetoothAdapter == null)
            {
                Toast.makeText(getApplicationContext(), "Device doesn't support bluetooth", Toast.LENGTH_SHORT).show();
            }
            if(!bluetoothAdapter.isEnabled())
            {
                Intent enableAdapter = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableAdapter,0);
                try
                {
                    Thread.sleep(1000);
                }
                catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            Set<BluetoothDevice> bondedDevices = bluetoothAdapter.getBondedDevices();
            if(bondedDevices.isEmpty())
            {
                Toast.makeText(getApplicationContext(), "Please pair the device first", Toast.LENGTH_SHORT).show();
            }
            else
            {
                for(BluetoothDevice iterator : bondedDevices)
                {
                    if(iterator.getAddress().equals(DEVICE_ADDRESS))
                    {
                        device = iterator;
                        found = true;
                        break;
                    }
                }
            }
            return found;
        }
        public boolean BTconnect()
        {
            boolean connected = true;
            try
            {
                socket = device.createRfcommSocketToServiceRecord(MY_UUID);
                socket.connect();
                Toast.makeText(getApplicationContext(),
                        "Connection to bluetooth device successful", Toast.LENGTH_LONG).show();
            }
            catch(IOException e)
            {
                e.printStackTrace();
                connected = false;
            }
            if(connected)
            {
                try
                {
                    outputStream = socket.getOutputStream();
                }
                catch(IOException e)
                {
                    e.printStackTrace();
                }
            }
            return connected;
        }
        @Override
        protected void onStart()
        {
            super.onStart();
        }
    }
