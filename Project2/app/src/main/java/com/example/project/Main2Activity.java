package com.example.project;


import android.annotation.SuppressLint;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;


import java.io.IOException;
import java.io.OutputStream;


public class Main2Activity extends AppCompatActivity {


    private OutputStream outputStream;

    Button forward, left, right, reverse;

    String command;



    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        forward = (Button) findViewById(R.id.forward);
        left = (Button) findViewById(R.id.left);
        right = (Button) findViewById(R.id.right);
        reverse = (Button) findViewById(R.id.backwards);

        forward.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    command = "F";
                    try {
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
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
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
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
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
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
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP)
                {
                    command = "0";
                    try {
                        MainActivity.btSocket.getOutputStream().write(command.getBytes());
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
