package com.example.project;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;


public class Parking extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_parking);

        //This button sends the command of parking to the connected car
        Button park = findViewById(R.id.park);

        park.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (MainPage.btSocket!=null)
                {
                    try
                    {
                        //Sending the string P to the car (P stands for Parallel Parking
                        MainPage.btSocket.getOutputStream().write("P".getBytes());
                    }
                    catch (Exception e)
                    {
                        msg("Error");
                    }
                }
            }
        });
    }

    //Method to write Toasts faster
    private void msg(String s)
    {
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
    }
}
