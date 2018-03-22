//
//  main.cpp
//  assemblyprojectA
//
//  Created by Menna  Dessokey and Maha Moussa on 3/19/18.
//  Copyright © 2018 Menna  Dessokey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "risk.hpp"
using namespace std;


int main()
{
    bool flag = false;
    risk assembler;
    string inst, RESULT;
    ifstream userfile;
    userfile.open("/Users/mennadessokey/Desktop/AUC/sem 4/Assembly/Assembly project /assemblyprojectA/assemblyprojectA/instruction");
    if (!userfile.is_open() )
    {
        cout<< " File didnt open ";
    }
    else
    {
         getline(userfile, inst);
         RESULT=assembler.compare(inst);
        assembler.insert(RESULT, inst);
        
        
        
     //   cout<< assembler.insert("add R 0110011 000 0000000", "su	x10,x10,x11");
      //        //do
//        //{
//            getline(userfile, inst);
//            //c//out<< " this is inst " << inst;
//            RESULT = assembler.compare(inst);
//            //cout<< " and da5lt fi el loop" << endl;
//            if (userfile.eof())
//                flag = true;
//       // }// while (!userfile.eof() && !flag);
    }
    
        //cout<< RESULT;
    //cout<<endl<<inst;
    return 0;
}

