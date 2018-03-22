//
//  risk.hpp
//  assemblyprojectA
//
//  Created by Menna  Dessokey on 3/19/18.
//  Copyright © 2018 Menna  Dessokey. All rights reserved.
//

#ifndef risk_hpp
#define risk_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
class risk
{

    
    
private:
    
    bool flag ;
    ifstream greencardfile, registerfile;
    string trans;
    struct R_format
    {
        string opcode ;
        string rd ;
        string func3 , func7 ;
        string rs1 , rs2 ;
    };
    R_format rstruct;
    R_format rstructempty;
    //stringstream result;
    struct I_format
    
    {
        
        string immediate;// in deciaml ;
        
        string rs1;
        
        string func3;
        
        string rd;
        
        string opcode;
        
    };
    
    I_format istruct;
    I_format istructempty;
    
    struct S_format
    
    {
        
        string immediate1, immediate2;// in deciaml ;
        
        string rs1;
        
        string rs2;
        
        string func3;
        
        string opcode;
        
    };
    
    S_format sstruct;
    S_format sstructempty;
    
    struct SB_format
    
    {
        
        string immediate1, immediate2, immediate3, immediate4;// in deciaml ;
        
        string rs1;
        
        string rs2;
        
        string func3;
        
        string opcode;
        
    };
    
    SB_format sbstruct;
    SB_format sbstructempty;
    
    struct U_format
    
    {
        
        string immediate;// in deciaml ;
        
        string rd;
        
        string opcode;
        
    };
    
    U_format ustruct;
    U_format ustructempty;
    
    struct UJ_format
    
    {
        
        string immediate1, immediate2, immediate3, immediate4;// in deciaml ;
        
        string rd;
        
        string opcode;
        
    };
    
    UJ_format ujstruct;
    UJ_format ujstructempty;

    
    
public:
    risk(); // hat open the greencard file
    // void openfile(); // open the file recieved from user
    string compare( string operation); // hayrg3 el line kolo men el greencard
    // haykon fee function excute
    string conversionDtoB(string num); // hatrg3 string
    string coversionBtoH(string x);
    string coversionHtoB(string x);
    string insert(string line, string instline); // element fel struct
    bool addtofile(R_format outputsr, I_format outputsi, S_format outputss, SB_format outputsb, U_format outputsu, UJ_format outputsuj, string type);
    // string
    
    //destruct
    
};


#endif /* risk_hpp */
