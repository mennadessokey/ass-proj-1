//
//  risk.cpp
//  assemblyprojectA
//
//  Created by Menna  Dessokey on 3/19/18.
//  Copyright © 2018 Menna  Dessokey. All rights reserved.
//

#include "risk.hpp"
using namespace std;
risk::risk()
{
    flag = false;
    greencardfile.open("/Users/mennadessokey/Desktop/AUC/sem 4/Assembly/Assembly project /assemblyprojectA/assemblyprojectA/greenb.txt");
    if(greencardfile.fail())
    {
        cout << " the greencard file has failed to open" << endl;
    }
    registerfile.open("/Users/mennadessokey/Desktop/AUC/sem 4/Assembly/Assembly project /assemblyprojectA/assemblyprojectA/greenb.txt");
    if(registerfile.fail())
    {
        cout << " the register file has failed to open" << endl;
    }

    trans =" ";
   
    rstruct.opcode = " ";
    rstruct.rd = " ";
    rstruct.func3 = " ";
    rstruct.func7 = " ";
    rstruct.rs1 = " ";
    rstruct.rs2 = " ";
    

}
string risk::conversionDtoB(string num1)
{
    int  num = stoi(num1), bin, counter =0;
    string f = "", tazbeet= "";
    string temp;
    cout << "Enter the number : ";
    cin >> num;
    cout << "The binary equivalent of " << num << " is ";
    while (num > 0)
    {
        bin = num % 2;
        f +=  to_string(bin);
        num /= 2;
    }
    
    for ( long i= f.length() -1 ; i>=0; i--)
    {
        tazbeet += f[i] ;
    }
    
    if  ( tazbeet.length() < 4 )
    {
        //cout<<endl<< f.length();
        temp = tazbeet;
        counter += tazbeet.length();
        tazbeet = "";
        
        
        for (int i = 0; i < 4 - counter ; i++)
        {
            tazbeet += "0";
            cout<<" ana ha add"<<endl;
        }
    }
    tazbeet += temp;
    
    cout<<tazbeet;
    

    
    return tazbeet;

}
string risk::coversionBtoH(string x)
{
    string  binary;
    cin >> binary;
    
    {
        string hex, newHex = "";
        string::reverse_iterator iterate;
        
        long  incr = 1;
        
        long  exponent = 0;
        
        long total = 0;
        
        for (iterate = binary.rbegin(); iterate != binary.rend(); iterate++)
        {
            if (*iterate == '1')
                total += pow (2.0, exponent);
            
            if (incr == 4)
            {
                switch (total)
                {
                    case 1:
                        hex += '1';
                        break;
                    case 2:
                        hex += '2';
                        break;
                    case 3:
                        hex += '3';
                        break;
                    case 4:
                        hex += '4';
                        break;
                    case 5:
                        hex += '5';
                        break;
                    case 6:
                        hex += '6';
                        break;
                    case 7:
                        hex += '7';
                        break;
                    case 8:
                        hex += '8';
                        break;
                    case 9:
                        hex += '9';
                        break;
                    case 10:
                        hex += 'A';
                        break;
                    case 11:
                        hex += 'B';
                        break;
                    case 12:
                        hex += 'C';
                        break;
                    case 13:
                        hex += 'D';
                        break;
                    case 14:
                        hex += 'E';
                        break;
                    case 15:
                        hex += 'F';
                        break;
                }
                
                incr = 0;
                exponent = -1;
                total = 0;
            }
            
            incr++;
            exponent++;
        }
        
        newHex += "0x";
        
        for (iterate = hex.rbegin(); iterate != hex.rend(); iterate++)
        {
            newHex += *iterate;
        }
        
        return newHex;
    }

}

string risk::compare( string operation)
{
    bool flag = true;
    string x, eq = " "; // el instruction names
    
    string str2 = operation.substr (0,operation.find(" "));
    cout<< " deh el str2"<< str2<<endl;// "think"
    
    
    
    while ( !greencardfile.eof() && flag)
    {
        cout<< " ana da5lt fel while loop"<<endl;
        getline(greencardfile, x);
        string str3 = x.substr (0, x.find(" "));
           // "think"
        cout<<" this is str3"<< str3<<endl<< " this is x " << endl << x;
        if ( str3 == str2  && str3 != "")
        {
            cout<< " howa eq ";
            cout << " this is x" << x << endl;
            cout << " this is str2" << '{'<<str2 <<'{'<< endl;
            cout << " this is str1" << str3 << endl;
            flag = false;
            eq = x;
            return eq;
        }
        //cout<<eq;
   
       // break;
    }

    
    
   return " not found ";
}
string risk::insert(string line, string instline ) // element fel struct
{
    
    rstruct.opcode = " ";
    rstruct.rd = " ";
    rstruct.func3 = " ";
    rstruct.func7 = " ";
    rstruct.rs1 = " ";
    rstruct.rs2 = " ";

    istruct.opcode=" ";
    istruct.immediate=" ";
    
    
    // the registers in the struct will contain only the decimal number of the structs without the x
    int counter=0;
    int findline;
    int pos= line.find(" ");
    int posinst= instline.find(" ");
    char c;
    string rdstr="";
    string rs1str="";
    string rs2str="";
    int i=0;
  
    char type= line.at(pos+1);

    if ( type == 'R')
    {
        string func7str= line.substr(pos+3, 7);
        string func3str= line.substr(pos+11, 3);
        string opcodestr= line.substr(pos+15, 7);
     

        instline.erase(0, posinst+5);

        while (counter<=instline.length() && instline.at(i)!=',')
        {
           if(instline.at(i)!='x')
           {
               rdstr+=instline.at(i);
           }
            i++;
        }
         instline.erase(0, i+1);

        i=0;
        while (counter<=instline.length() && instline.at(i)!=',')
        {
            if(instline.at(i)!='x')
            {
                rs1str+=instline.at(i);
            }
            i++;
        }
        instline.erase(0, i+1);


        instline.erase(instline.begin());
        rs2str=instline;


        

        rstruct.rd=rdstr;
        rstruct.opcode=opcodestr;
        rstruct.func3=func3str;
        rstruct.func7=func7str ;
        rstruct.rs1=rs1str;
        rstruct.rs2=rs2str ;
        
    }
    
   addtofile(rstruct, istructempty, sstructempty, sbstructempty, ustructempty, ujstructempty, "R");
   
    return " " ;
    
   
    
}


bool risk::addtofile(R_format outputsr, I_format outputsi, S_format outputss, SB_format outputsb, U_format outputsu, UJ_format outputsuj, string type)
{
    cout<<" da5lt el addtofile";
    
    string addtofile = "";
    string afterconversion = "";
    string convertItoB = "";
    string convertItoB2 = "";
    string convertItoB3 = "";
    string convertItoB4 = "";
    
    ofstream outputfile;
    
    // howa e7na hena lazm n7ot kolo f string convert it then put in file
    
    outputfile.open("/Users/mennadessokey/Desktop/AUC/sem 4/Assembly/Assembly project /assemblyprojectA/assemblyprojectA/outputfile");
    
    

//    if(!outputfile.is_open())
//        
//    {
//        
//        cout<<" OUTPUT FILE COULD NOT BE OPENED";
//        
//    }
//    
//    else
    
    {
        
        if ( type == "R")
            
        {
            
            addtofile += outputsr.func7;
            
            addtofile += outputsr.rs2;
            
            addtofile += outputsr.rs1;
            
            addtofile += outputsr.func3;
            
            addtofile += outputsr.rd;
            
            addtofile += outputsr.opcode;
            
            afterconversion += "0x" + coversionBtoH(addtofile);
            
           // outputfile<<afterconversion<<endl;
            cout<<endl<<afterconversion;

            afterconversion = "";
            
        }
        
        else if ( type == "I") // special ttpe is 3ashen el shift amount
            
        {
            
            convertItoB = conversionDtoB(outputsi.immediate);
            
            addtofile += convertItoB;
            
            convertItoB = "";
            
            addtofile += outputsi.rs1;
            
            addtofile += outputsi.func3;
            
            addtofile += outputsi.rd;
            
            addtofile += outputsi.opcode;
            
            
            
            afterconversion += "0x" + coversionBtoH(addtofile);
            
            outputfile<<afterconversion<<endl;
            
            afterconversion = "";
            
        }
        
        else if ( type == "S")
            
        {
            
            convertItoB = conversionDtoB(outputss.immediate1);
            
            convertItoB2 = conversionDtoB(outputss.immediate2);
            
            addtofile += convertItoB;
            
            convertItoB = "";
            
            addtofile += outputss.rs2;
            
            addtofile += outputss.rs1;
            
            addtofile += outputss.func3;
            
            addtofile += convertItoB2;
            
            convertItoB2 = "";
            
            addtofile += outputss.opcode;
            
            
            
            afterconversion += "0x" + coversionBtoH(addtofile);
            
            outputfile<<afterconversion<<endl;
            
            afterconversion = "";
            
        }
        
        else if (type == "SB")
        {
            
            convertItoB = conversionDtoB(outputsb.immediate1);
            
            convertItoB2 = conversionDtoB(outputsb.immediate2);
            
            addtofile += convertItoB;
            
            convertItoB = "";
            
            addtofile += outputsb.rs2;
            
            addtofile += outputsb.rs1;
            
            addtofile += outputsb.func3;
            
            addtofile += convertItoB2;
            
            convertItoB2 = "";
            
            addtofile += outputsb.opcode;
            
            
            
            afterconversion += "0x" + coversionBtoH(addtofile);
            
            outputfile<<afterconversion<<endl;
            
            afterconversion = "";
            
        }
        
        else if( type == "U")
            
        {
            
            convertItoB = conversionDtoB(outputsu.immediate);
            
            addtofile += convertItoB;
            
            convertItoB = "";
            
            addtofile += outputsu.rd;
            
            addtofile += outputsu.opcode;
            
            afterconversion += "0x" + coversionBtoH(addtofile);
            
            outputfile<<afterconversion<<endl;
            
            afterconversion = "";
            
        }
        
        else if (type == "UJ")
            
        {
            
            convertItoB = conversionDtoB(outputsuj.immediate1);
            
            convertItoB2 = conversionDtoB(outputsuj.immediate2);
            
            convertItoB3 = conversionDtoB(outputsuj.immediate3);
            
            convertItoB4 = conversionDtoB(outputsuj.immediate4);
            
            addtofile += convertItoB;
            
            convertItoB = "";
            
            addtofile += convertItoB2;
            
            convertItoB2 = "";
            
            addtofile += convertItoB3;
            
            convertItoB3 = "";
            
            addtofile += convertItoB4;
            
            convertItoB4 = "";
            
            addtofile += outputsuj.rd;
            
            convertItoB2 = "";
            
            addtofile += outputsuj.opcode;
            
            afterconversion += "0x" + coversionBtoH(addtofile);
            
            outputfile<<afterconversion<<endl;
            
            afterconversion = "";
            
        }
        
        
        
        
        
    }
    
    return true; // check this shit
    
}











