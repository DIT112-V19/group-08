package com.example.project;


import android.annotation.SuppressLint;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;


import java.io.IOException;
import java.io.OutputStream;


public class ManualControls extends AppCompatActivity {

    //MANUAL CONTROLS
    //Declaring all variables

    private OutputStream outputStream;

    Button forward, left, right, reverse;

    //String that will store different values that will be sent to the car using bluetooth
    String command;



    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        //These buttons are used to send commands for manual control to the connected car

        forward = (Button) findViewById(R.id.forward);
        left = (Button) findViewById(R.id.left);
        right = (Button) findViewById(R.id.right);
        reverse = (Button) findViewById(R.id.backwards);


        forward.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {

                //Here we check if the user is holding the button
                //MotionEvent.ACTION_DOWN is when user is holding the button
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    command = "F";
                    try {

                        //Sending string F to the car (F stands for forward)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());

                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                    //Here we check if the user released the button
                    //MotionEvent.ACTION_UP is when user releases the button
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {

                        //Sending string 0 to the car (0 is used when user releases the button. Speed of the car is set to 0.)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());
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

                        //Sending string B to the car (B stands for backward)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {

                        //Sending string 0 to the car (0 is used when user releases the button. Speed of the car is set to 0.)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());
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

                        //Sending string L to the car (L stands for left)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {

                        //Sending string 0 to the car (0 is used when user releases the button. Speed of the car is set to 0.)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());
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

                        //Sending string R to the car (R stands for right)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {

                        //Sending string 0 to the car (0 is used when user releases the button. Speed of the car is set to 0.)
                        MainPage.btSocket.getOutputStream().write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return false;
            }
        });
    }

        @Override
        protected void onStart()
        {
            super.onStart();
        }
    }
