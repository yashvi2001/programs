package com.nitish.calculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;



public class MainActivity extends AppCompatActivity{

    TextView inp;
    TextView op;
    Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,bp,bdi,bmi,bmu,beq,bcl;
    String exp ="";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        inp=findViewById(R.id.Input);
        op=findViewById(R.id.Output);
        b1=findViewById(R.id.button1);
        b2=findViewById(R.id.button2);
        b3=findViewById(R.id.button3);
        b4=findViewById(R.id.button4);
        b5=findViewById(R.id.button5);
        b6=findViewById(R.id.button6);
        b7=findViewById(R.id.button7);
        b8=findViewById(R.id.button8);
        b9=findViewById(R.id.button9);
        b0=findViewById(R.id.button0);
        bp=findViewById(R.id.buttonpl);
        bdi=findViewById(R.id.buttondi);
        bmi=findViewById(R.id.buttonmi);
        bmu=findViewById(R.id.buttonmu);
        beq=findViewById(R.id.buttoneq);
        bcl=findViewById(R.id.buttond);

        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp.concat("1 ");
                inp.setText(exp);
            }
        });
        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"2 ";
                inp.setText(exp);
            }
        });
        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"3 ";
                inp.setText(exp);
            }
        });
        b4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"4 ";
                inp.setText(exp);
            }
        });
        b5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"5 ";
                inp.setText(exp);
            }
        });
        b6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"6 ";
                inp.setText(exp);
            }
        });
        b7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"7 ";
                inp.setText(exp);
            }
        });
        b8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"8 ";
                inp.setText(exp);
            }
        });
        b9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"9 ";
                inp.setText(exp);
            }
        });
        b0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"0 ";
                inp.setText(exp);
            }
        });
        bp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp.concat("+ ");
                inp.setText(exp);
            }
        });
        bdi.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"/ ";
                inp.setText(exp);
            }
        });
        bmi.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"- ";
                inp.setText(exp);
            }
        });
        bmu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp=exp+"* ";
                inp.setText(exp);
            }
        });
        bcl.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                exp="0 ";
                inp.setText(exp);
                op.setText(exp);
                exp="";
            }
        });
        beq.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view){
                EvaluateString evaluateString = new EvaluateString();
                int t=evaluateString.evaluate(exp);
                String s= String.valueOf(t);
                exp="";
                op.setText(s);
            }
        });


    }
}