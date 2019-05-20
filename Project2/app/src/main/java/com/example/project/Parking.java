package com.example.project;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.app.ProgressDialog;
import java.io.IOException;


public class Parking extends AppCompatActivity {

    Button park;

    private ProgressDialog progress;


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_parking);

        //call the widgets

        park = (Button) findViewById(R.id.park);


         //Call the class to connect

        //commands to be sent to bluetooth


        park.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (MainActivity.btSocket!=null)
                {
                    try
                    {
                        MainActivity.btSocket.getOutputStream().write("P".getBytes());
                    }
                    catch (IOException e)
                    {
                        msg("Error");
                    }
                }
            }
        });
    }

    // fast way to call Toast
    private void msg(String s)
    {
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
    }
}
