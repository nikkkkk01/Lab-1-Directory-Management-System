#include <iostream>
#include <direct.h>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

//Main Menu Function
int mainMenu(int choice){
do{
cout<<"\n[1] List Files\n";
cout<<"[2] Create Directory\n";
cout<<"[3] Change Directory\n";
cout<<"[4] Exit\n";
cout<<"Enter choice: ";
cin>>choice;
}while(!(choice >= 1 && choice <= 4));
return choice;
}
//List Files Function
void listFiles(){
int choice;
string path = ".";
string prefix_files = ".\\";
string pattern = "test";
do{
cout<<"\n[1] List All Files\n";
cout<<"[2] List by Extension\n";
cout<<"[3] List by Pattern\n";
cout<<"Enter choice: ";
cin>>choice;
}while(!(choice >= 1 && choice <= 3));

switch(choice){
case 1:
cout<<"Files in current directory:\n";
for(const auto& entry : fs::directory_iterator(path)){
string filePath = entry.path().filename().string();
if(filePath.rfind(prefix_files, 0) == 0 ){
}
cout << "- " << filePath << "\n";
}
break;
case 2:
cout<<"File extension list:\n";
for(const auto& entry : fs::directory_iterator(path)){
if(fs::is_regular_file(entry)){
string ext = entry.path().extension().string();
if(!ext.empty()){
cout << ext << "\n";
}
}
}
break;
case 3:
cout<<"List Pattern: ";
for(const auto& entry : fs::directory_iterator(path)){
if(fs::is_regular_file(entry)){
string fileName = entry.path().filename().string();
if(fileName.find(pattern) != std::string::npos){
cout << fileName << "\n";
}
}
}
break;
}
}
// Create Directory Function
void createDirectory(){
string createDirectoryName;
cout << "Enter directory name: ";
cin.ignore();
getline(cin,createDirectoryName);
if(fs::exists(createDirectoryName)){
std::cout << "Directory already existed.\n";
}else{
if(fs::create_directory(createDirectoryName)){
std::cout << "Directory " << createDirectoryName<< " created successfully.\n";
}else {
std::cout << "Failed to create directory.\n";
}
}
}
//Change Directory Function
void changeDirectory(){
int choice;
fs::path currentPath = fs::current_path();
do{
cout<<"\n[1] Move to Parent\n";
cout<<"[2] Move to Root\n";
cout<<"[3] Enter Custom Path\n";
cout<<"Enter choice: ";
cin>>choice;
}while(!(choice >= 1 && choice <= 4));

switch(choice){
case 1: { //Move to Parent Directory
fs::path parentPath = currentPath.parent_path();
if(_chdir(parentPath.string().c_str()) == 0){
cout << "Move to parent directory: \n" << parentPath << "\n";
}else {
cerr << "Failed to moved to parent directory.\n";
}
break;
}
case 2:{//Move to Root Directory
fs::path rootPath = currentPath.root_path();
if(_chdir(rootPath.string().c_str()) == 0){
cout << "Move to root directory: \n" << rootPath << "\n";
}else {
cerr << "Failed to moved to parent directory.\n";
}
break;
}
case 3:{//Enter Custom Path
string customPath;
cout << "Enter custom path to change to: ";
cin.ignore();
getline(cin,customPath);
if(fs::exists(customPath) && fs::is_directory(customPath)){
if(_chdir(customPath.c_str()) == 0){
cout << "Current directory change to:" << fs::current_path() << "\n";
}else {
cerr << "Failed to change directory.\n";
}
} else {
cerr << "Error: Directory ''" << customPath << " not found!\n";
}
}
break;
}

}

int main(){
cout << "======:Directory Management System:======\n";
int choice;
while(true){
int choice2 = mainMenu(choice);

switch(choice2){
case 1:
listFiles();
break;
case 2:
createDirectory();
break;
case 3:
changeDirectory();
break;
case 4:
cout << "\nExiting Program......";
return 0;
}
}

return 0;
}
