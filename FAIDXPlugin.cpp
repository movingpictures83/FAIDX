#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FAIDXPlugin.h"

void FAIDXPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   if (key.size() != 0)
   parameters[key] = value;
   else
	   break;
 }

}

void FAIDXPlugin::run() {
	//faidx Assembly.fasta -a 1000,50000000 > ../Assembly.fasta
}


void FAIDXPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "faidx "+std::string(PluginManager::prefix())+"/"+parameters["fastafile"]+" -a "+parameters["lo"]+","+parameters["hi"]+" > "+outputfile;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<FAIDXPlugin> FAIDXPluginProxy = PluginProxy<FAIDXPlugin>("FAIDX", PluginManager::getInstance());
